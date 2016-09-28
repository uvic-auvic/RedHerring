#include <ros/ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Bool.h>
#include <serial/serial.h>
#include "thrusters/Sensitivity.h"
#include "thrusters/thrusterValues.h"
#include "thrusters/thrusterTemperatures.h"
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <fstream>
#include <unistd.h>

#define MAXINT16 32767
#define InvMAXINT16Percent 100/32767
#define InvMAXINT16 1/32767/100

/*strings for the thruster/temperature commands
 */
#define GetuCdieTemperature "TG\n"
#define GetOilTemperatureCommand "AG0\n"

/*
 * Thruster Control Node
 * Node takes in data from one of the AUV or ROV control nodes and outputs
 * command to the thrusters.
 *
 * GUI switches between AUV and ROV control modes. The node defaults to ROV control mode.
 *
 */

class Thruster
{
private:
    ros::NodeHandle nh_;


    ros::Subscriber GUI_sub_;
    ros::Publisher GUI_pub_;

    ros::Subscriber Control_sub_;

    ros::Subscriber GUILockout_sub_;
    ros::Publisher GUITemperatures_pub_;

    int baud_;
    std::string port_;
    serial::Serial thrusterSerial_;


    thrusters::thrusterTemperatures temperatures_;

    bool throttleLockout_, thrusterIdleSendFlag_;

    int downwardThruster_, portUpwardThruster_, starboardUpwardThruster_, portThruster_, starboardThruster_;
    int downwardThrusterChannel_, starboardThrusterChannel_, portThrusterChannel_, portUpwardThrusterChannel_, starboardUpwardThrusterChannel_;

    int base_command_, forwardTrim_, pitchTrim_, rollTrim_, yawTrim_;

    int temperatureSendTime_;

    int thrusterREVUpper_, thrusterREVLower_, thrusterFWDUpper_, thrusterFWDLower_;
public:

    Thruster()
    {
        /* Initialization of the Thruster class. Thruster Constructor.
         */
        GUI_pub_ = nh_.advertise<std_msgs::String>("/GUI/general", 1);

        GUITemperatures_pub_ = nh_.advertise<thrusters::thrusterTemperatures>("/input/thrusterTemperature", 1);
        GUILockout_sub_ = nh_.subscribe("/GUI/throttleLockout", 1, &Thruster::lockoutCb, this);

        Control_sub_ = nh_.subscribe("/thrusters/thrusterValues",1, &Thruster::thrusterCb, this);

        temperatureSendTime_ = 5000;
        /* Variables controlling the amount of thrust to be sent to the thrusters.
         */

        throttleLockout_ = true;

        thrusterIdleSendFlag_ = false;
        downwardThruster_ = 0;
        portUpwardThruster_ = 0;
        starboardUpwardThruster_ = 0;
        portThruster_ = 0;
        starboardThruster_ = 0;

        downwardThrusterChannel_ = 1;
        starboardThrusterChannel_ = 2;
        portThrusterChannel_ = 3;
        portUpwardThrusterChannel_ = 4;
        starboardUpwardThrusterChannel_ = 5;

        base_command_ = 0;

        baud_ = 115200;
        port_ = "/dev/ttyAMA0";

        thrusterREVUpper_ = 0;
        thrusterREVLower_ = -100;
        thrusterFWDUpper_ = 100;
        thrusterFWDLower_ = 0;

        forwardTrim_ = 0;
        pitchTrim_ = 0;
        yawTrim_ = 0;
        rollTrim_ = 0;

        if(this->setConfig())
        {
            ROS_INFO("Configuration complete!");
        }
        else
        {
            ROS_ERROR("Configuration failed! Using Defaults...");
        }

        /* initialize the thruster serial */
        thrusterSerial_.setPort(port_);
        thrusterSerial_.setBaudrate(baud_);
        thrusterSerial_.setTimeout(serial::Timeout::max(),10,0,10,0);

        thrusterSerial_.open();
        if(!thrusterSerial_.isOpen())
        {
            ROS_INFO("Serial Failed to initialize. Shutting Node down.");
            ros::shutdown();
        }
        else
            ROS_INFO("Serial Initialized!");
        //Reset the servos to insure they are set to defaults.
        thrusterSerial_.write("RE\n");
    }

    ~Thruster()
    {
        /* De-initialization of the Thruster class. Thruster Destructor.
         */
    }

    bool setConfig()
    {
        /* open config file and pull out configuration data */
        std::ifstream thrusterConfigFile;
        std::string fileLocation( (std::string(getenv("HOME")) + "/ROV02/src/thrusters/include/thrusters/thrusterConfig.txt") );
        thrusterConfigFile.open(fileLocation.c_str());
        if(thrusterConfigFile.is_open()){
            std::string line;
            char* lineChar;
            while(getline(thrusterConfigFile, line)){
                lineChar = (char*)line.c_str();
                line = strtok(lineChar, ";");

                if(line == "baud_")
                {
                    line = strtok(NULL,";");
                    baud_ = abs(strtol(line.c_str(),0,10));
                }
                else if(line == "port_")
                {
                    line = strtok(NULL,";");
                    port_ = line.c_str();
                }
                else if(line == "base_command_"){
                     line = strtok(NULL,";");
                     base_command_ = strtol(line.c_str(),0,10); // Base value that set motors to stopped.
                }
                else if(line == "downwardThrusterChannel_")
                {
                    line = strtok(NULL,";");
                    downwardThrusterChannel_ = abs(strtol(line.c_str(),0,10));
                }
                else if(line == "starboardThrusterChannel_")
                {
                    line = strtok(NULL,";");
                    starboardThrusterChannel_ = abs(strtol(line.c_str(),0,10));
                }
                else if(line == "portThrusterChannel_")
                {
                    line = strtok(NULL,";");
                    portThrusterChannel_ = abs(strtol(line.c_str(),0,10));
                }
                else if(line == "portUpwardThrusterChannel_")
                {
                    line = strtok(NULL,";");
                    portUpwardThrusterChannel_ = abs(strtol(line.c_str(),0,10));
                }
                else if(line == "starboardUpwardThrusterChannel_")
                {
                    line = strtok(NULL,";");
                    starboardUpwardThrusterChannel_ = abs(strtol(line.c_str(),0,10));
                }
                else if(line == "throttleLockout_")
                {
                    line = strtok(NULL,";");
                    throttleLockout_ = abs(strtol(line.c_str(),0,10));
                }
                else if(line == "thrusterREVUpper_")
                {
                    line = strtok(NULL,";");
                    thrusterREVUpper_ = strtol(line.c_str(),0,10);
                }
                else if(line == "thrusterREVLower_")
                {
                    line = strtok(NULL,";");
                    thrusterREVLower_ = strtol(line.c_str(),0,10);
                }
                else if(line == "thrusterFWDUpper_")
                {
                    line = strtok(NULL,";");
                    thrusterFWDUpper_ = strtol(line.c_str(),0,10);
                }
                else if(line == "thrusterFWDLower_")
                {
                    line = strtok(NULL,";");
                    thrusterFWDLower_ = strtol(line.c_str(),0,10);
                }
                else if(line == "temperatureSendTime_")
                {
                    line = strtok(NULL,";");
                    temperatureSendTime_ = strtol(line.c_str(),0,10);
                }
                else if(line == "forwardTrim_")
                {
                    line = strtok(NULL,";");
                    forwardTrim_ = strtol(line.c_str(),0,10);
                }
                else if(line == "pitchTrim_")
                {
                    line = strtok(NULL,";");
                    pitchTrim_ = strtol(line.c_str(),0,10);
                }
                else if(line == "yawTrim_")
                {
                    line = strtok(NULL,";");
                    yawTrim_ = strtol(line.c_str(),0,10);
                }
                else if(line == "rollTrim_")
                {
                    line = strtok(NULL,";");
                    rollTrim_ = strtol(line.c_str(),0,10);
                }
                else
                {
                    ROS_WARN("Unknown config input: %s", lineChar);
                }
            }
            thrusterConfigFile.close();
        }
        else
        {
            return false;
        }
        return true;
    }

    void thrusterCb(const thrusters::thrusterValues thrustValues)
    {
        /* TODO:
         * Decode thrusterValue data and apply math to them
         */
        this->thrusterMath(thrustValues);
        this->thrusterSend();
        this->temperatureSend();
        return;
    }

    void thrusterMath(const thrusters::thrusterValues thrustValues)
    {
        if(throttleLockout_ == false)
        {
            downwardThruster_ = base_command_ + thrustValues.ascent + (thrustValues.pitchThruster + pitchTrim_);
            portUpwardThruster_ = base_command_ - thrustValues.ascent + (thrustValues.rollThruster - rollTrim_) -  (thrustValues.pitchThruster - pitchTrim_)/2;
            starboardUpwardThruster_ = base_command_ - thrustValues.ascent + (thrustValues.rollThruster + rollTrim_)-  (thrustValues.pitchThruster - pitchTrim_)/2;
            portThruster_ = base_command_ + (thrustValues.forwardThruster - forwardTrim_) + (thrustValues.yawThruster - yawTrim_);
            starboardThruster_ = base_command_ + (thrustValues.forwardThruster + forwardTrim_) - (thrustValues.yawThruster + yawTrim_);
        }
        else if(throttleLockout_ == true)
        {
            downwardThruster_ = 0;
            portUpwardThruster_ = 0;
            starboardUpwardThruster_ = 0;
            portThruster_ = 0;
            starboardThruster_ = 0;
        }
        /* TODO: Change -100, 0 and 0, 100 values to a config input variable.
         * Remap all the thrusters values to match the motor controller range */
        if( downwardThruster_ < 0 )
            downwardThruster_ = remap(downwardThruster_, -250, 0, thrusterREVLower_, thrusterREVUpper_);
        else
            downwardThruster_ = remap(downwardThruster_, 0, 250, thrusterFWDLower_, thrusterFWDUpper_);

        if( starboardThruster_ < 0 )
            starboardThruster_ = remap(starboardThruster_, -300, 0, thrusterREVLower_, thrusterREVUpper_);
        else
            starboardThruster_ = remap(starboardThruster_, 0, 300, thrusterFWDLower_, thrusterFWDUpper_);

        if( portThruster_ < 0 )
            portThruster_ = remap(portThruster_, -300, 0, thrusterREVLower_, thrusterREVUpper_);
        else
            portThruster_ = remap(portThruster_, 0, 300, thrusterFWDLower_, thrusterFWDUpper_);

        if( starboardUpwardThruster_ < 0 )
            starboardUpwardThruster_ = remap(starboardUpwardThruster_, -325, 0, thrusterREVLower_, thrusterREVUpper_);
        else
            starboardUpwardThruster_ = remap(starboardUpwardThruster_, 0, 325, thrusterFWDLower_, thrusterFWDUpper_);

        if( portUpwardThruster_ < 0 )
            portUpwardThruster_ = remap(portUpwardThruster_, -325, 0, thrusterREVLower_, thrusterREVUpper_);
        else
            portUpwardThruster_ = remap(portUpwardThruster_, 0, 325, thrusterFWDLower_, thrusterFWDUpper_);

        return;
    }

    void thrusterSend()
    {
        thrusterIdleSendFlag_ = false;
        thrusters::thrusterValues thrustValues;

        /*If throttleLockout is true, these values should be set to 0 and still sent out, otherwise the thrusters will turn off
         * Else if throttleLockout is false, these values should be set to a calculated value and set out.
         */

        std::stringstream ss;
        /* Send Data out for the downward thruster */
        ss << std::hex << "SS" << downwardThrusterChannel_ << downwardThruster_ << "\n";
        thrusterSerial_.write(ss.str());
        /* clear the stringstream for use with other channels */
        ss.str( std::string());
        ss.clear();

        /* Send Data out for the port thruster */
        ss << "SS" << portThrusterChannel_ << portThruster_ << "\n";
        thrusterSerial_.write(ss.str());
        /* clear the stringstream for use with other channels */
        ss.str( std::string());
        ss.clear();

        /* Send Data out for the starboard thruster */
        ss << "SS" << starboardThrusterChannel_ << starboardThruster_ << "\n";
        thrusterSerial_.write(ss.str());
        /* clear the stringstream for use with other channels */
        ss.str( std::string());
        ss.clear();

        /* Send Data out for the port upward thruster */
        ss << "SS" << portUpwardThrusterChannel_ << portUpwardThruster_ << "\n";
        thrusterSerial_.write(ss.str());
        /* clear the stringstream for use with other channels */
        ss.str( std::string());
        ss.clear();

        /* Send Data out for the starboard upward thruster */
        ss << "SS" << starboardUpwardThrusterChannel_ << starboardUpwardThruster_ << "\n";
        thrusterSerial_.write(ss.str());
        /* clear the stringstream for use with other channels */
        ss.str( std::string());
        ss.clear();


        /*
         * Send Thruster Values to the serial device.
         */
        return;
    }

    void lockoutCb(const std_msgs::Bool lockoutState)
    {
        /* Safety Lockout. Thrusters should not change from 0.
         */
        std::stringstream ss;
        std_msgs::String msg;
        ss << "Throttle Lockout state: " << (int)lockoutState.data;
        msg.data = ss.str();
        ROS_INFO("Lockout State: %d", lockoutState.data);
        GUI_pub_.publish(msg);
        throttleLockout_ = lockoutState.data;
        thrusters::thrusterValues thrustValues;
        thrustValues.forwardThruster = 0;
        thrustValues.pitchThruster = 0;
        thrustValues.rollThruster = 0;
        thrustValues.yawThruster = 0;
        thrustValues.ascent = 0;

        this->thrusterMath(thrustValues);
        this->thrusterSend();
    }

    void temperatureSend()
    {
        thrusterSerial_.write(GetuCdieTemperature);
        thrusterSerial_.read(temperatures_.UCDieTemperature);
        thrusterSerial_.write(GetOilTemperatureCommand);
        thrusterSerial_.read(temperatures_.oilTemperature);
        GUITemperatures_pub_.publish(temperatures_);
        return;
    }

    int temperatureSendTime()
    {
        return temperatureSendTime_;
    }

    int thrusterSendTime()
    {
        return thrusterIdleSendFlag_;
    }

    void thrusterSendTime(bool enable)
    {
        thrusterIdleSendFlag_ = enable;
    }

    int remap(int value, int from1, int to1, int from2, int to2)
    {
        //(from2 + (value-from1) * ((to2 - from2)/(to1 - from1)))
        float result = value - from1;
        result = result * (to2 - from2);
        result = result / (to1 - from1);
        result = result + from2;

        return (int)result;
    }
};



int main(int argc, char** argv)
{
    ros::init(argc, argv, "thruster_node");
    Thruster thruster;
    ros::Rate loop_rate(5000);
    int count = 0;
    while(ros::ok)
    {
        /* after a set time (~1 second) send temperature data */
        if(count > thruster.temperatureSendTime())
        {
            thruster.temperatureSend();
            /* If thrusters data hasn't been sent since the last temperature send, send thruster data so they don't fall asleep.
             */
            if(thruster.thrusterSendTime())
            {
                thruster.thrusterSend();
            }
            else
            {
                thruster.thrusterSendTime(true);
            }
            count = 0;
        }
        ros::spinOnce();
        loop_rate.sleep();
        ++count;
    }
    return 0;
}
