#include <ros/ros.h>
#include <std_msgs/String.h>
#include <stdio.h>
#include <wiringPi.h>
#include <std_msgs/Bool.h>
#include <fstream>
/*
 * Can use the command line function gpio export [pin] to set up a pin to not need to be called in root/
 * Otherwise, gpio access requires root access.
 */
class Lights
{
    ros::NodeHandle nh_;
    ros::Subscriber GUI_sub_;
    ros::Publisher GUI_pub_;
private:
    int lightGPIO_PWR_Enable_; // GPIO pin to enable the 12V power supply to the lights board. Does not provide power.
    int lightGPIO_Enable_; // GPIO pin to turn on/off the lights.
public:
    Lights()
    {
        wiringPiSetupSys();
        GUI_sub_ = nh_.subscribe("/GUI/lights", 1, &Lights::lightsCb, this);
        GUI_pub_ = nh_.advertise<std_msgs::String>("/GUI/general",1);

        if(this->setConfig())
        {
            ROS_INFO("Configuration complete!");
        }
        else
        {
            ROS_ERROR("Configuration failed! Using Defaults...");
        }

        std::stringstream ss;
        ss << "gpio export " << lightGPIO_PWR_Enable_ << " OUTPUT";
        system(ss.str().c_str());
        ss.str( std::string() );
        ss.clear();
        ss << "gpio export " << lightGPIO_Enable_ << " OUTPUT";
        system(ss.str().c_str());
        pinMode(lightGPIO_PWR_Enable_, OUTPUT);
        pinMode(lightGPIO_Enable_, OUTPUT);
    }

    ~Lights()
    {
        system("gpio unexportall");
        ros::shutdown();
    }

    bool setConfig()
    {

        std::ifstream lightsConfigFile;
        std::string fileLocation( (std::string(getenv("HOME")) + "/ROV02/src/lights/include/lights/lightsConfig.txt") );
        lightsConfigFile.open(fileLocation.c_str());
        if(lightsConfigFile.is_open())
        {
            std::string line;
            char* lineChar;
            while(getline(lightsConfigFile, line)){
                lineChar = (char*)line.c_str();
                line = strtok(lineChar, ";");
                if(line == "lightGPIO_PWR_Enable_"){
                        line = strtok(NULL,";");
                        lightGPIO_PWR_Enable_ = strtol(line.c_str(),0,10);
                }
                else if( line == "lightGPIO_Enable_")
                {
                    line = strtok(NULL,";");
                    lightGPIO_Enable_ = strtol(line.c_str(),0,10);

                }
                else
                {
                    ROS_WARN("Unknown config input: %s", lineChar);
                }
            }
        }
        else
        {
            return false;
        }
        lightsConfigFile.close();
        return true;
    }

    void lightsCb(std_msgs::Bool boolLightState)
    {
        //send gpio signal to turn on or off lights.
        std::stringstream ss;
        std_msgs::String msg;
        ss << "Light state: " << (int)boolLightState.data;
        msg.data = ss.str();
        GUI_pub_.publish(msg);

        digitalWrite(lightGPIO_Enable_, boolLightState.data);
        digitalWrite(lightGPIO_PWR_Enable_, boolLightState.data);
        return;
    }
};

int main(int argc, char** argv)
{
    ros::init(argc, argv, "lights_node");
    Lights light;
    ros::spin();
    ros::shutdown();
    return 0;
}
