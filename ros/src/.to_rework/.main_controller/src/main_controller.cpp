#include <ros/ros.h>
#include "std_msgs/String.h"
#include <signal.h>
#include <unistd.h>
#include <termios.h>
#include <stdio.h>
#include <ros/console.h>
#include <string.h>

//#include "main_controller/main_controller.h"

#include "main_controller/turnRight.h"
#include "main_controller/turnLeft.h"
#include "main_controller/moveUp.h"
#include "main_controller/moveDown.h"
#include "main_controller/moveForward.h"
#include "main_controller/moveReverse.h"

#include "main_controller/longRateUp.h"
#include "main_controller/longRateDown.h"
#include "main_controller/longRateFull.h"
#include "main_controller/longRateReset.h"

#include "main_controller/yawRateUp.h"
#include "main_controller/yawRateDown.h"
#include "main_controller/yawRateFull.h"
#include "main_controller/yawRateReset.h"

#include "main_controller/vertRateUp.h"
#include "main_controller/vertRateDown.h"
#include "main_controller/vertRateFull.h"
#include "main_controller/vertRateReset.h"

#include "main_controller/allStop.h"

#include "main_controller/setMotor.h"


//  Global Variables    //
//Directional throttle values



//Services
//Individual Motor Drives
bool setMotor(main_controller::setMotor::Request &req,
               main_controller::setMotor::Response &res)
{
    ROS_INFO("Set Motor 1: ");
    return true;
}

//Movement Commands
bool moveForward(main_controller::moveForward::Request &req,
				 main_controller::moveForward::Response &res)
{
	ROS_INFO("Move Forward");
    return true;


}

bool moveReverse(main_controller::moveReverse::Request &req,
				 main_controller::moveReverse::Response &res)
{
	ROS_INFO("Move Reverse");
    return true;


}

bool moveUp(main_controller::moveUp::Request &req,
			main_controller::moveUp::Response &res)
{
	ROS_INFO("Move Up");
    return true;


}

bool moveDown(main_controller::moveDown::Request &req,
			  main_controller::moveDown::Response &res)
{
	ROS_INFO("Move Down");
    return true;


}

bool turnLeft(main_controller::turnLeft::Request &req,
			  main_controller::turnLeft::Response &res)
{
	ROS_INFO("Turn Left");
    return true;


}

bool turnRight(main_controller::turnRight::Request &req,
			   main_controller::turnRight::Response &res)
{
	ROS_INFO("Turn Right");
    return true;


}

bool allStop(main_controller::allStop::Request &req,
			   main_controller::allStop::Response &res)
{
	ROS_INFO("All Stop");
    return true;


}

//Throttle Commands

//Adjust Longitudinal Rate
bool longRateUp(main_controller::longRateUp::Request &req,
			  	main_controller::longRateUp::Response &res)
{
	ROS_INFO("Long Rate Up");
    return true;


}

bool longRateDown(main_controller::longRateDown::Request &req,
				  main_controller::longRateDown::Response &res)
{
	ROS_INFO("Long Rate Down");
    return true;


}

bool longRateFull(main_controller::longRateFull::Request &req,
			      main_controller::longRateFull::Response &res)
{
	ROS_INFO("Long Rate Full");
    return true;


}

bool longRateReset(main_controller::longRateReset::Request &req,
			   	   main_controller::longRateReset::Response &res)
{
	ROS_INFO("Long Rate Reset");
    return true;


}

//Adjust Vertical Rate
bool vertRateUp(main_controller::vertRateUp::Request &req,
			  	main_controller::vertRateUp::Response &res)
{
	ROS_INFO("vert Rate Up");
    return true;


}

bool vertRateDown(main_controller::vertRateDown::Request &req,
				  main_controller::vertRateDown::Response &res)
{
	ROS_INFO("vert Rate Down");
    return true;


}

bool vertRateFull(main_controller::vertRateFull::Request &req,
			      main_controller::vertRateFull::Response &res)
{
	ROS_INFO("vert Rate Full");
    return true;


}

bool vertRateReset(main_controller::vertRateReset::Request &req,
			   	   main_controller::vertRateReset::Response &res)
{
	ROS_INFO("vert Rate Reset");
    return true;


}

//Adjust Yaw Rate
bool yawRateUp(main_controller::yawRateUp::Request &req,
			  	main_controller::yawRateUp::Response &res)
{
	ROS_INFO("yaw Rate Up");
    return true;


}

bool yawRateDown(main_controller::yawRateDown::Request &req,
				  main_controller::yawRateDown::Response &res)
{
	ROS_INFO("yaw Rate Down");
    return true;


}

bool yawRateFull(main_controller::yawRateFull::Request &req,
			      main_controller::yawRateFull::Response &res)
{
	ROS_INFO("yaw Rate Full");
    return true;


}

bool yawRateReset(main_controller::yawRateReset::Request &req,
			   	   main_controller::yawRateReset::Response &res)
{
	ROS_INFO("yaw Rate Reset");
    return true;


}



//Main Functions
void quit(int sig)
{
    (void)sig;
    ROS_INFO("Shutting down");
    ros::shutdown();
    exit(0);
}

int main(int argc, char **argv)
{
    //Variables
    char KB_char = '\0';

    //Actual Code
    ros::init(argc,argv,"rov_keyboard");
    ros::NodeHandle nodeHand;

    ros::Rate loop_rate(1);
    std_msgs::String msg;
    std::stringstream guiss;

    //Service Advertisements
    //ros:ServiceServer motor1srv = nodeHand.advertiseService("set_motor_1",setMotor1);
    //ros:ServiceServer motor2srv = nodeHand.advertiseService("set_motor_2",setMotor2);
    //ros:ServiceServer motor3srv = nodeHand.advertiseService("set_motor_3",setMotor3);
    //ros:ServiceServer motor4srv = nodeHand.advertiseService("set_motor_4",setMotor4);
    //ros:ServiceServer motor5srv = nodeHand.advertiseService("set_motor_5",setMotor5);

	ros:ServiceServer 


    signal(SIGINT,quit);

    ROS_INFO("TEST");

    while(ros::ok())
    {
        ROS_INFO("BOOP");

        ros::spinOnce();
        loop_rate.sleep();
    }

    return(0);
}
