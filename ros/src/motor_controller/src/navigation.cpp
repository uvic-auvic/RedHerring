/********************************************************************
 * @file /src/motor_controller.cpp
 * @brief The program that interfaces with the motor controllers
 * @date February 2017
/********************************************************************/

/********************************************************************
 * Includes
/********************************************************************/
#include <ros/ros.h>
#include <string>
#include <serial/serial.h>
#include "motor_controller/motor_command.h"

bool moveForward( motor_controller::motor_command::Request &req,
                  motor_controller::motor_command::Response &res)
{
  return true;
}

bool moveBackward( motor_controller::motor_command::Request &req,
                   motor_controller::motor_command::Response &res)
{
  return true;
}

bool moveLeft( motor_controller::motor_command::Request &req,
               motor_controller::motor_command::Response &res)
{
  return true;
}

bool moveRight( motor_controller::motor_command::Request &req,
                motor_controller::motor_command::Response &res)
{
  return true;
}

/********************************************************************
 * Implementation [Main]
 * @Args     argc is the number of command-line arguments provided
 * @Args     argv is a pointer to the argument strings
/********************************************************************/
int main(int argc, char ** argv)
{

    ros::init(argc, argv, "motor_controller_navigation");
    ros::NodeHandle nh("~");

    ros::ServiceServer MoveForward  = nh.advertiseService("MoveForward", moveForward);
    ros::ServiceServer MoveBackward = nh.advertiseService("MoveBackward", moveBackward);
    ros::ServiceServer MoveLeft     = nh.advertiseService("MoveLeft", moveLeft);
    ros::ServiceServer MoveRight    = nh.advertiseService("MoveRight", moveRight);

    /* Wait for callbacks */
    ros::spin();
    return 0;
}
