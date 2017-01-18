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

/* AUV Control Node for the Thrusters. Disabled by default and turned on through the GUI */
/* TODO: All the autonomous control logic/math for the thruster outputs */

class AUV
{
private:
    ros::NodeHandle nh_;

    ros::Subscriber GUI_AUV_sub_;
    ros::Publisher GUI_pub_;
    ros::Publisher GUI_Thruster_pub_;

    ros::Publisher thruster_pub_;


    bool AUV_Enabled_;

public:
    AUV()
    {
        GUI_AUV_sub_ = nh_.subscribe("/GUI/ROVtoAUV", 4, &AUV::AUVControlCb, this);
        GUI_pub_ = nh_.advertise<std_msgs::String>("/GUI/general", 1); //Publishes general messages to the GUI text box
        GUI_Thruster_pub_ = nh_.advertise<thrusters::thrusterValues>("/GUI/thrusterValues", 1);


        thruster_pub_ = nh_.advertise<thrusters::thrusterValues>("/thrusters/thrusterValues",1);

        AUV_Enabled_ = false;
    }

    ~AUV()
    {
        /* AUV Destructor */
    }

    void AUVControlCb(const std_msgs::Int16 controlState)
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
            AUV_Enabled_ = false;
            ROS_INFO("AUV_Enabled_ true");
            break;
        case 2:
            /* Control State 2 is AUV mode */
            AUV_Enabled_ = true;
            ROS_INFO("AUV_Enabled_ false");
            break;
        default:
            /* Undefined/Unset State. Both AUV and ROV are disabled and no control is input to the thrusters */
            AUV_Enabled_ = false;
            ROS_WARN("Undefined Case for AUV Control");
            break;
        }
        ss << "AUV Control State: " << AUV_Enabled_;
        msg.data = ss.str();
        GUI_pub_.publish(msg);
        return;
    }

    void update()
    {
        if(AUV_Enabled_ == true)
        {
            /* TODO AUV stuff */
            this->thrusterSend();
        }
        else
        {
            /* Don't do AUV stuff */
            ROS_INFO("AUV_Enabled_ == false");
        }

        return;
    }

    void thrusterSend()
    {
        /* Sends thrusterValues to the thruster control node */
        /* TODO: Change thrustValues assignment to meaningful data instead of just 0; */
        thrusters::thrusterValues thrustValues;
        thrustValues.forwardThruster = 0;
        thrustValues.pitchThruster = 0;
        thrustValues.yawThruster = 0;
        thrustValues.rollThruster = 0;
        thrustValues.ascent = 0;

        GUI_Thruster_pub_.publish(thrustValues);
        thruster_pub_.publish(thrustValues);

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
    ros::init(argc, argv, "auv_thruster_control");
    AUV auv;
    ros::Rate loop_rate(5000);
    int count = 0;
    while(ros::ok)
    {
        auv.update();
        ros::spinOnce();
        loop_rate.sleep();
        ++count;
    }
    return 0;
}
