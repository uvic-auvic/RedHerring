#include <ros/ros.h>
#include "motor_controller/motor_command.h"

int main(int argc, char ** argv)
{
    // This node is only for testing purposes
    ros::init(argc, argv, "motor_controller_client");
    ros::NodeHandle nh;

    ros::ServiceClient setMotorForwardclient = nh.serviceClient<motor_controller::motor_command>("setMotorForward");
    ros::ServiceClient setMotorReverseclient = nh.serviceClient<motor_controller::motor_command>("setMotorReverse");
    ros::ServiceClient stopAllMotorsclient   = nh.serviceClient<motor_controller::motor_command>("stopAllMotors");
    ros::ServiceClient stopMotorclient       = nh.serviceClient<motor_controller::motor_command>("stopMotor");
    ros::ServiceClient getRPMclient          = nh.serviceClient<motor_controller::motor_command>("getRPM");
    ros::ServiceClient setPWMclient          = nh.serviceClient<motor_controller::motor_command>("setPWM");
    ros::ServiceClient calibrateMotorclient  = nh.serviceClient<motor_controller::motor_command>("calibrateMotor");

    motor_controller::motor_command srv;
    srv.request.motor_number = 4;
    srv.request.command_param = 100;

    if (setMotorForwardclient.call(srv))
    {
        ROS_INFO("%s", srv.response.motor_response.c_str());
    }
    else
    {
        ROS_WARN("Failed");
    }

    if (setMotorReverseclient.call(srv))
    {
        ROS_INFO("%s", srv.response.motor_response.c_str());
    }
    else
    {
        ROS_WARN("Failed");
    }

    if (getRPMclient.call(srv))
    {
        ROS_INFO("%s", srv.response.motor_response.c_str());
    }
    else
    {
        ROS_WARN("Failed");
    }

    if (stopMotorclient.call(srv))
    {
        ROS_INFO("%s", srv.response.motor_response.c_str());
    }
    else
    {
        ROS_WARN("Failed");
    }

    if (stopAllMotorsclient.call(srv))
    {
        ROS_INFO("%s", srv.response.motor_response.c_str());
    }
    else
    {
        ROS_WARN("Failed");
    }

    if (setPWMclient.call(srv))
    {
        ROS_INFO("%s", srv.response.motor_response.c_str());
    }
    else
    {
        ROS_WARN("Failed");
    }

    if (calibrateMotorclient.call(srv))
    {
        ROS_INFO("%s", srv.response.motor_response.c_str());
    }
    else
    {
        ROS_WARN("Failed");
    }
  
  return 0;
}
