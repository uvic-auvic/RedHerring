#include <ros/ros.h>
#include <string>
#include <sstream>
#include <serial/serial.h>
#include "motor_controller/motor_command.h"

#define MAX_NUMBER_OF_MOTORS 6
#define MAX_INDEX_OF_MOTORS (MAX_NUMBER_OF_MOTORS-1)

bool setMotorForward(motor_controller::motor_command::Request &req,
                     motor_controller::motor_command::Response &res)
{
    /* Check whether the motor exists */
    if (req.motor_number > MAX_INDEX_OF_MOTORS)
    {
        ROS_ERROR("No Motor %d. Max Motor index is %d", req.motor_number, MAX_INDEX_OF_MOTORS);
        return false;
    }

    /* process request and send to serial */
    ROS_DEBUG("Creating serial output string");
    std::ostringstream ostr;
    ostr << "M" << (int) req.motor_number << "F" << (int) req.command_param << "\\n";
    std::string serial_out = ostr.str();

    /* Sending serial output. Replace with actuall serial*/
    ROS_INFO("Serial Output: %s", serial_out.c_str());

    /* Check for any arguements */
    res.motor_response = "success";

    /* Default to true */
    res.motor_success = true;

  return true;
}


bool setMotorReverse(motor_controller::motor_command::Request &req,
                     motor_controller::motor_command::Response &res)
{
    /* Check whether the motor exists */
    if (req.motor_number > MAX_INDEX_OF_MOTORS)
    {
        ROS_ERROR("No Motor %d. Max Motor index is %d", req.motor_number, MAX_INDEX_OF_MOTORS);
        return false;
    }

    /* process request and send to serial */
    ROS_DEBUG("Creating serial output string");
    std::ostringstream ostr;
    ostr << "M" << (int) req.motor_number << "R" << (int) req.command_param << "\\n";

    /* Sending serial output. Replace with actuall serial*/
    ROS_INFO("Serial Output: %s", ostr.str().c_str());

    /* Check for any arguements */
    res.motor_response = "success";

    /* Default to true */
    res.motor_success = true;

  return true;
}

bool stopAllMotors(  motor_controller::motor_command::Request &req,
                     motor_controller::motor_command::Response &res)
{
     ROS_INFO("Stopping all motors");
    ROS_DEBUG("Creating serial output string");
    std::string serial_out = "STP\\n" ;

    /* Sending serial output. Replace with actuall serial*/
    ROS_INFO("Serial Output: %s", serial_out.c_str());

    /* Check for any arguements */
    res.motor_response = "success";

    /* Default to true */
    res.motor_success = true;

  return true;
}

bool stopMotor(      motor_controller::motor_command::Request &req,
                     motor_controller::motor_command::Response &res)
{
    /* Check whether the motor exists */
    if (req.motor_number > MAX_INDEX_OF_MOTORS)
    {
        ROS_ERROR("No Motor %d. Max Motor index is %d", req.motor_number, MAX_INDEX_OF_MOTORS);
        return false;
    }

    /* process request and send to serial */
    ROS_DEBUG("Creating serial output string");
    std::ostringstream ostr;
    ostr << "SM" << (int) req.motor_number << "\\n";

    /* Sending serial output. Replace with actuall serial*/
    ROS_INFO("Serial Output: %s", ostr.str().c_str());

    /* Check for any arguements */
    res.motor_response = "success";

    /* Default to true */
    res.motor_success = true;

  return true;
}

bool getRPM(         motor_controller::motor_command::Request &req,
                     motor_controller::motor_command::Response &res)
{
    /* Check whether the motor exists */
    if (req.motor_number > MAX_INDEX_OF_MOTORS)
    {
        ROS_ERROR("No Motor %d. Max Motor index is %d", req.motor_number, MAX_INDEX_OF_MOTORS);
        return false;
    }

    /* process request and send to serial */
    ROS_DEBUG("Creating serial output string");
    std::ostringstream ostr;
    ostr << "RV" << (int) req.motor_number << "\\n";

    /* Sending serial output. Replace with actuall serial*/
    ROS_INFO("Serial Output: %s", ostr.str().c_str());

    /* Check for any arguements */
    //TODO: replace with an implementation
    res.motor_response = "1234";

    /* Default to true */
    res.motor_success = true;

  return true;
}

bool setPWM(         motor_controller::motor_command::Request &req,
                     motor_controller::motor_command::Response &res)
{
    /* Check whether the motor exists */
    if (req.motor_number > MAX_INDEX_OF_MOTORS)
    {
        ROS_ERROR("No Motor %d. Max Motor index is %d", req.motor_number, MAX_INDEX_OF_MOTORS);
        return false;
    }

    /* process request and send to serial */
    ROS_DEBUG("Creating serial output string");
    std::ostringstream ostr;
    ostr << "PW" << (int) req.motor_number << (int) req.command_param << "\\n";

    /* Sending serial output. Replace with actuall serial*/
    ROS_INFO("Serial Output: %s", ostr.str().c_str());

    /* Check for any arguements */
    res.motor_response = "success";

    /* Default to true */
    res.motor_success = true;

  return true;
}

bool calibrateMotor( motor_controller::motor_command::Request &req,
                     motor_controller::motor_command::Response &res)
{
    /* Check whether the motor exists */
    if (req.motor_number > MAX_INDEX_OF_MOTORS)
    {
        ROS_ERROR("No Motor %d. Max Motor index is %d", req.motor_number, MAX_INDEX_OF_MOTORS);
        return false;
    }

    /* process request and send to serial */
    ROS_DEBUG("Creating serial output string");
    std::ostringstream ostr;
    ostr << "CL" << (int) req.motor_number << "\\n";

    /* Sending serial output. Replace with actuall serial*/
    ROS_INFO("Serial Output: %s", ostr.str().c_str());

    /* Check for any arguements */
    res.motor_response = "success";

    /* Default to true */
    res.motor_success = true;

  return true;
}


int main(int argc, char ** argv)
{
  ros::init(argc, argv, "motor_controller_node");
  ros::NodeHandle nh;

  /* Setup all the Different services/commands which we  can call. Each service does its own error handling */
  ros::ServiceServer setMotorForwardService = nh.advertiseService("setMotorForward", setMotorForward);
  ros::ServiceServer setMotorReverseService = nh.advertiseService("setMotorReverse", setMotorReverse);
  ros::ServiceServer stopAllMotorsService   = nh.advertiseService("stopAllMotors"  , stopAllMotors);
  ros::ServiceServer stopMotorService       = nh.advertiseService("stopMotor"      , stopMotor);
  ros::ServiceServer getRPMService          = nh.advertiseService("getRPM"         , getRPM);
  ros::ServiceServer setPWMService          = nh.advertiseService("setPWM"         , setPWM);
  ros::ServiceServer calibrateMotorService  = nh.advertiseService("calibrateMotor" , calibrateMotor);

  /* Wait for callbacks */
  ros::spin();
  return 0;
}
