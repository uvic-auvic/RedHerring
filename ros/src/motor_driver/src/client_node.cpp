#include "ros/ros.h"
#include "motor_driver/MotorDriverCommand.h"
#include <cstdlib>

/**
 * Example of how to send a command to the grabber's service_node
 * (could also be used to control the grabber from a terminal)
 */

int main(int argc, char **argv)
{
  ros::init(argc, argv, "client_node");
  if (argc != 4)
  {
    ROS_INFO("usage: client_node <command> <motor> <param>");
    return 1;
  }

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<motor_driver::MotorDriverCommand>("motor_driver_command");
  motor_driver::MotorDriverCommand srv;
  srv.request.command = argv[1];
  srv.request.motor = atoi(argv[2]);
  srv.request.param = atoi(argv[3]);
  if (client.call(srv))
  {
      ROS_INFO("GOOD");
      if(!srv.response.success)
      {
          ROS_WARN("Unrecognized command and/or parameters");
      }
  }
  else
  {
      ROS_INFO("BAD");
      return 1;
  }
  
  if(srv.response.response.size() > 0)
      ROS_INFO("Response: %s", srv.response.response.c_str());

  return 0;
}
