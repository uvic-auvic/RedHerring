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

motor_controller::motor_command generateMotorCommand(int motor_number, int command_param)
{
    motor_controller::motor_command srv;
    srv.request.motor_number = motor_number;
    srv.request.command_param = command_param;
    return srv;
}

void convertDegreesToTime()
{
  return;
}

class motor_client
{
public:
    ros::NodeHandle nh;
    ros::ServiceClient forward;
    ros::ServiceClient reverse;
    ros::ServiceClient stopMotors;
    ros::ServiceClient stopMotor;
    ros::ServiceClient getRPM;
    motor_client(std::string motor_conn_name)
    {
        forward = nh.serviceClient<motor_controller::motor_command>("/" + motor_conn_name + "/setMotorForward");
        reverse = nh.serviceClient<motor_controller::motor_command>("/" + motor_conn_name + "/setMotorReverse");
        stopMotors = nh.serviceClient<motor_controller::motor_command>("/" + motor_conn_name + "/stopAllMotors");
        stopMotor = nh.serviceClient<motor_controller::motor_command>("/" + motor_conn_name + "/stopMotor");
        getRPM = nh.serviceClient<motor_controller::motor_command>("/" + motor_conn_name + "/getRPM");
    }

};

class movement_controller
{
public:
    motor_client left_controller = motor_client("motor_left");
    motor_client right_controller = motor_client("motor_right");

    // Service Call Definitions
    bool Forward( motor_controller::movement_command::Request &req,
                  motor_controller::movement_command::Response &res)
    {

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

};


/********************************************************************
 * Implementation [Main]
 * @Args     argc is the number of command-line arguments provided
 * @Args     argv is a pointer to the argument strings
/********************************************************************/
int main(int argc, char ** argv)
{
    ros::init(argc, argv, "motor_controller_navigation");
    ros::NodeHandle nh("~");
    movement_controller controller;

    // Services
    ros::ServiceServer MoveForward  = nh.advertiseService("MoveForward", &movement_controller::Forward, &controller);
    ros::ServiceServer MoveBackward = nh.advertiseService("MoveBackward", &movement_controller::Backward, &controller);
    ros::ServiceServer MoveLeft     = nh.advertiseService("MoveLeft", &movement_controller::Left, &controller);
    ros::ServiceServer MoveRight    = nh.advertiseService("MoveRight", &movement_controller::Right, &controller);
    ros::ServiceServer CW           = nh.advertiseService("YawCW", &movement_controller::RotateClockwise, &controller);
    ros::ServiceServer CCW          = nh.advertiseService("YawCCW", &movement_controller::RotateCounterClockwise, &controller);
    ros::ServiceServer Move         = nh.advertiseService("MoveToPosition", &movement_controller::MoveToPosition, &controller);

    // TODO: Parameterize
    // Set default motor speeds
    int motor_speed = 100;
    float reverse_scalar = 0.9;

    /* Wait for callbacks */
    ros::spin();
    return 0;
}
