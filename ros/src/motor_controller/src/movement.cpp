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
#include "motor_controller/movement_command.h"

/********************************************************************
 * Global Variables
/********************************************************************/
bool timer_requested = false;
int countdown_timer = 0;

void convertDegreesToTime()
{
  return;
}

bool Forward( motor_controller::movement_command::Request &req,
              motor_controller::movement_command::Response &res)
{
  return true;
}

bool Backward( motor_controller::movement_command::Request &req,
               motor_controller::movement_command::Response &res)
{
  return true;
}

bool Left( motor_controller::movement_command::Request &req,
           motor_controller::movement_command::Response &res)
{
  return true;
}

bool Right( motor_controller::movement_command::Request &req,
            motor_controller::movement_command::Response &res)
{
  return true;
}

bool RotateClockwise( motor_controller::movement_command::Request &req,
                      motor_controller::movement_command::Response &res)
{
  return true;
}

bool RotateCounterClockwise( motor_controller::movement_command::Request &req,
                             motor_controller::movement_command::Response &res)
{
  return true;
}

bool MoveToPosition( motor_controller::movement_command::Request &req,
                     motor_controller::movement_command::Response &res)
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

    // Services
    ros::ServiceServer MoveForward  = nh.advertiseService("MoveForward", Forward);
    ros::ServiceServer MoveBackward = nh.advertiseService("MoveBackward", Backward);
    ros::ServiceServer MoveLeft     = nh.advertiseService("MoveLeft", Left);
    ros::ServiceServer MoveRight    = nh.advertiseService("MoveRight", Right);
    ros::ServiceServer CW           = nh.advertiseService("YawCW", RotateClockwise);
    ros::ServiceServer CCW          = nh.advertiseService("YawCCW", RotateCounterClockwise);
    ros::ServiceServer Move         = nh.advertiseService("MoveToPosition", MoveToPosition);

    // Motor Left Clients
    ros::ServiceClient leftMotorForwardClient = nh.serviceClient<motor_controller::motor_command>("/motor_left/setMotorForward");
    ros::ServiceClient leftMotorReverseClient = nh.serviceClient<motor_controller::motor_command>("/motor_left/setMotorReverse");
    ros::ServiceClient leftStopMotorsClient = nh.serviceClient<motor_controller::motor_command>("/motor_left/stopAllMotors");
    ros::ServiceClient leftStopMotorClient = nh.serviceClient<motor_controller::motor_command>("/motor_left/stopMotor");
    ros::ServiceClient leftGetRPM = nh.serviceClient<motor_controller::motor_command>("/motor_left/getRPM");

    // Motor Right Clients
    ros::ServiceClient rightMotorForwardClient = nh.serviceClient<motor_controller::motor_command>("/motor_right/setMotorForward");
    ros::ServiceClient rightMotorReverseClient = nh.serviceClient<motor_controller::motor_command>("/motor_right/setMotorReverse");
    ros::ServiceClient rightStopMotorsClient = nh.serviceClient<motor_controller::motor_command>("/motor_right/stopAllMotors");
    ros::ServiceClient rightStopMotorClient = nh.serviceClient<motor_controller::motor_command>("/motor_right/stopMotor");
    ros::ServiceClient rightGetRPM = nh.serviceClient<motor_controller::motor_command>("/motor_right/getRPM");

    // TODO: Parameterize
    // Set default motor speeds
    int motor_speed = 100;
    float reverse_scalar = 0.9;

    /* Wait for callbacks */
    ros::spin();
    return 0;
}
