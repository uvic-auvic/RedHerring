#include <ros/ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Bool.h>
#include <std_msgs/Int16.h>
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

/*
 * ROV Control for the thrusters
 * Node takes commands in from the joystick and outputs the control to the thruster_node which
 * then sends the data out to the thrusters.
 *
 * GUI is to switch between ROV and AUV control modes.
 */
class ROV
{
private:
    ros::NodeHandle nh_;
    ros::Subscriber joystick_sub_;
    ros::Publisher joystick_pub_;

    ros::Subscriber GUI_sub_;
    ros::Subscriber GUI_ROV_sub_;
    ros::Publisher GUI_pub_;

    ros::Publisher thruster_pub_;

    int eventNumber_, eventValue_;


    int forward_command_, pitch_command_, roll_command_, yaw_command_;
    int fwd_factor_, pitch_factor_, roll_factor_, yaw_factor_, ascent_factor_;
    bool roll_, roll_button_inverse_, ROV_Enabled_;

    int ascent_command_, ascent_, descent_;


    int forward_axis_, pitch_axis_, yaw_roll_axis_, ascent_button_, descent_button_;

public:

    ROV()
    {
        /* Initialization of the Thruster class. Thruster Constructor.
         */
        joystick_pub_ = nh_.advertise<thrusters::thrusterValues>("/GUI/thrusterValues", 1);
        joystick_sub_ = nh_.subscribe("/input/joystick", 10, &ROV::thrusterCb, this);

        GUI_sub_ = nh_.subscribe("/GUI/thrusterSensitivity", 4, &ROV::sensitivityCb, this);
        GUI_ROV_sub_ = nh_.subscribe("/GUI/ROVtoAUV", 4, &ROV::ROVControlCb, this);
        GUI_pub_ = nh_.advertise<std_msgs::String>("/GUI/general", 1);

        thruster_pub_ = nh_.advertise<thrusters::thrusterValues>("/thrusters/thrusterValues",1);

        eventNumber_ = 0;
        eventValue_ = 0;

        /* Variables controlling the amount of thrust to be sent to the thrusters.
         */
        forward_command_ = 0;
        pitch_command_ = 0;
        roll_command_ = 0;
        yaw_command_ = 0;

        ROV_Enabled_ = true;
        roll_ = false;

        /*
         * Setup factors to be controlled in the gui to have adjustable sensitivity
         * These are to be read from a configuration file. They will be overriden by the GUI.
         */
        /* Set default values -- incase they are not included in config/config is entered incorrectly. */
        fwd_factor_ = 0; // Variable to control how sensitive forwad/reverse is.
        pitch_factor_ = 0; // Variable to control how sensitive pitch is.
        roll_factor_ = 0; // Variable to control how sensitive roll is.
        yaw_factor_ = 0; // Variable to control how sensitive yaw is.
        ascent_factor_ = 0; // Variable to control how sensitive ascent is.

        ascent_ = 10000;
        descent_ = -5000;
        ascent_command_ = 0;

        forward_axis_ = 2;
        pitch_axis_ = 1;
        yaw_roll_axis_ = 0;



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
                if(line == "fwd_factor_"){
                    line = strtok(NULL,";");
                    fwd_factor_ = strtol(line.c_str(),0,10); // Variable to control how sensitive forwad/reverse is.
                }
                else if(line == "pitch_factor_"){
                    line = strtok(NULL,";");
                    pitch_factor_ = strtol(line.c_str(),0,10); // Variable to control how sensitive pitch is.
                }
                else if(line == "roll_factor_"){
                    line = strtok(NULL,";");
                    roll_factor_ = strtol(line.c_str(),0,10); // Variable to control how sensitive roll is.
                }
                else if(line == "yaw_factor_"){
                    line = strtok(NULL,";");
                    yaw_factor_ = std::strtol(line.c_str(),0,10); // Variable to control how sensitive yaw is.
                }
                else if(line == "ascent_factor_"){
                    line = strtok(NULL,";");
                    ascent_factor_ = std::strtol(line.c_str(),0,10); // Variable to control how sensitive yaw is.
                }
                else if(line == "ascent_"){
                    line = strtok(NULL,";");
                    ascent_ = strtol(line.c_str(),0,10);
                    if(ascent_ < 0)
                        ascent_ = -1*ascent_;
                    if(ascent_ > 100)
                        ascent_ = 100;

                }
                else if(line == "descent_"){
                    line = strtok(NULL,";");
                    descent_ = strtol(line.c_str(),0,10);
                    if(descent_ > 0)
                        descent_ = -1*descent_;
                    if(descent_ < -100)
                        descent_ = -100;

                }
                else if(line == "forward_axis_")
                {
                    line = strtok(NULL,";");
                    forward_axis_ = abs(strtol(line.c_str(),0,10));
                }
                else if(line == "pitch_axis_")
                {
                    line = strtok(NULL,";");
                    pitch_axis_ = abs(strtol(line.c_str(),0,10));
                }
                else if(line == "yaw_roll_axis_")
                {
                    line = strtok(NULL,";");
                    yaw_roll_axis_ = abs(strtol(line.c_str(),0,10));
                    line = strtok(NULL,";");
                    roll_button_inverse_ = strtol(line.c_str(),0,10);
                }

                else
                {
                    ROS_INFO("Unknown config input: %s", lineChar);
                }
            }
            thrusterConfigFile.close();
            ROS_INFO("Configuration complete.");
        }
        else
        {
            ROS_INFO("Thruster Config file not found... Using defaults.");
        }

    }

    ~ROV()
    {
        /* De-initialization of the Thruster class. Thruster Destructor.
         */
    }

    void sensitivityCb(const thrusters::Sensitivity msg)
    {
        /* Sensitivity controls from GUI
         */
        fwd_factor_ = msg.forwardSensitivity ;
        if(abs(fwd_factor_) > 100)
            fwd_factor_ = copysign(100, fwd_factor_);
        pitch_factor_ = msg.pitchSensitivity;
        if(abs(pitch_factor_) > 100)
            pitch_factor_ = copysign(100, pitch_factor_);
        roll_factor_ = msg.rollSensitivity;
        if(abs(roll_factor_) > 100)
            roll_factor_ = copysign(100,roll_factor_);
        yaw_factor_ = msg.yawSensitivity;
        if(abs(yaw_factor_) > 100)
            yaw_factor_ = copysign(100, yaw_factor_);
        ascent_factor_ = msg.ascentSensitivity;
        if(abs(ascent_factor_) > 100)
            ascent_factor_ = copysign(100, ascent_factor_);
        return;
    }

    void ROVControlCb(const std_msgs::Int16 controlState)
    {
        /* Call back function for control mode (ROV or AUV)
         * If ROV mode, ROV_Enabled == true and this node controls the submarine
         * else if AUV mode, ROV_Enabled == false and this node does not output control data;
         */
        std::stringstream ss;
        std_msgs::String msg;
        switch (controlState.data){
        case 1:
            /* Control State 1 is ROV mode */
            ROV_Enabled_ = true;
            ROS_INFO("ROV_Enabled_ true");
            break;
        case 2:
            /* Control State 2 is AUV mode */
            ROV_Enabled_ = false;
            ROS_INFO("ROV_Enabled_ false");
            break;
        default:
            /* Undefined/Unset State. Both AUV and ROV are disabled and no control is input to the thrusters */
            ROV_Enabled_ = false;
            ROS_WARN("Undefined Case for ROV Control");
            break;
        }
        ss << "ROV Control State: " << ROV_Enabled_;
        msg.data = ss.str();
        GUI_pub_.publish(msg);
        return;
    }


    void thrusterCb(const std_msgs::String::ConstPtr& msg)
    {
        /* Expected messages from joystick are of type
         * Axis;eventNumber;eventValue or Button;eventNumber;eventValue
         * eventNumber defines which Axis/Button and eventValue defines the value
         * For Buttons, eventValue == 1 is button "down" and eventValue == 0 is button "up"
         */
        std::cout<<ROV_Enabled_<<std::endl;
        if(ROV_Enabled_ == true)
        {
            std::string token;
            char* msgString = strdup(msg->data.c_str());
            bool dirtyButton = false;
            bool dirtyAxis = false;

            token = strtok(msgString,";");
            if(token == "Button")
            {
                /* Joystick command is a button
                 */
                token = strtok(NULL,";");
                eventNumber_ = strtol(token.c_str(),0,10);
                token = strtok(NULL,";");
                eventValue_ = strtol(token.c_str(),0,10);
                dirtyButton = true;
            }
            else if(token == "Axis")
            {
                /* Joystick command is an Axis
                 */
                token = strtok(NULL,";");
                eventNumber_ = strtol(token.c_str(),0,10);
                token = strtok(NULL,";");
                eventValue_ = strtol(token.c_str(),0,10);
                dirtyAxis = true;
            }

            else
            {
                /* Unexepected value. Should not occur.
                 */
                ROS_DEBUG("Unexpected joystick command %s", msg->data.c_str());
            }
            if(dirtyButton == true)
            {
                /* Joystick Button command was found, time to send to thrusters
                 */
                this->thrusterButton();
            }
            else if(dirtyAxis == true)
            {
                /* Joystick Axis command was found, time to send to thrusters
                 */
                this->thrusterAxis();
            }

            this->thrusterSend();
        }
        else
        {
            ROS_INFO("ROV Mode Disabled");
        }
        return;
    }

    void thrusterAxis()
    {
        /* Axis 0 -l/r+
         * Axis 1 -f/b+
         */
        if(eventNumber_ == yaw_roll_axis_){
            if(roll_ != roll_button_inverse_)
            {
                roll_command_ = eventValue_;
                yaw_command_ = 0;
            }
            else if(roll_ == roll_button_inverse_)
            {
                roll_command_ = 0;
                yaw_command_ = eventValue_;
            }
        }
        else if(eventNumber_ == pitch_axis_){
            pitch_command_ = eventValue_;
        }
        else if(eventNumber_ == forward_axis_){
            forward_command_ = eventValue_;
        }
        else
        {
            ROS_INFO("Unknown joystick Axis %d", eventNumber_);
        }
        return;
    }

    void thrusterSend()
    {

        thrusters::thrusterValues thrustValues;

        thrustValues.forwardThruster = (float) remap((fwd_factor_*forward_command_),-3300000,3300000,-100,100);
        thrustValues.pitchThruster = (float)remap((pitch_factor_*pitch_command_),-3300000,3300000,-100,100);
        thrustValues.yawThruster = (float)remap((yaw_factor_*yaw_command_),-3300000,3300000,-100,100);
        thrustValues.rollThruster = (float)remap((roll_factor_*roll_command_),-3300000,3300000,-100,100);
        if(ascent_command_ == ascent_)
        {
            thrustValues.ascent = ascent_factor_;
        }
        else if(ascent_command_ == descent_)
        {
            thrustValues.ascent = -ascent_factor_;
        }
        else
        {
            thrustValues.ascent = 0;
        }

        std::cout << thrustValues << std::endl;
        joystick_pub_.publish(thrustValues);
        thruster_pub_.publish(thrustValues);

        return;
    }

    void thrusterButton()
    {

        switch(eventNumber_)
        {
        case 1:
            //ascent
            if(eventValue_ == 1)
                ascent_command_ = ascent_;
            else
                ascent_command_ = 0;
            break;
        case 2:
            //descent
            if(eventValue_ == 1)
                ascent_command_ = descent_;
            else
                ascent_command_ = 0;
            break;
        case 3:
            //change from yaw to roll
            if(eventValue_ == 1)
                roll_ = true;
            else
                roll_ = false;
            break;
        default:
            if (eventValue_ == 1)
            {
                std::stringstream ss;
                ss << "Joystick Button " << eventNumber_ << " is not mapped.";
                std_msgs::String msg;
                msg.data = ss.str();
                GUI_pub_.publish(msg);
                ROS_INFO("%s", ss.str().c_str());
            }
            break;
        }
        return;
    }

    int remap(int value, int from1, int to1, int from2, int to2)
    {
        float result = value - from1;
        result = result * (to2 - from2);
        result = result / (to1 - from1);
        result = result + from2;

        return (int)result;
    }
};



int main(int argc, char** argv)
{
    ros::init(argc, argv, "rov_thruster_control");
    ROV rov;
    ros::spin();
    return 0;
}
