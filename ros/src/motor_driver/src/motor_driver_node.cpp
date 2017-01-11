#include "ros/ros.h"
#include "motor_driver/MotorDriverCommand.h"
#include "serial/serial.h"
#include <string>
#include <stdint.h>

serial::Serial *ser = nullptr;

bool issueCommand(motor_driver::MotorDriverCommand::Request &req, motor_driver::MotorDriverCommand::Response &res)
{
	res.command = req.command;
	res.param = req.param;
	res.motor = req.motor;
	res.success = true;

	std::string command;
	unsigned response_len = 0;
	std::string response;

	if(req.command == "")
	{
		command = std::string("\n");
		response_len = 2;
	}
	else if(req.command == "MF")
	{
		command = std::string("M");
		command += std::to_string(req.motor);
		command += std::string("F");
		command += req.param;
		command += std::string("\n");
	}
	else if (req.command == "MR")
	{
		command = std::string("M");
		command += std::to_string(req.motor);
		command += std::string("R");
		command += req.param;
		command += std::string("\n");
	}
	else if (req.command == "STP")
	{
		command = std::string("STP\n");
		response_len = 3;
	}
	else if (req.command == "SM")
	{
		command = std::string("SM");
		command += std::to_string(req.motor);
		command += std::string("\n");
		response_len = 3;
	}
	else if (req.command == "RV")
	{
		command = std::string("RV");
		command += std::to_string(req.motor);
		command += std::string("\n");
		response_len = 4; // ???
	}
	else if (req.command == "PW")
	{
		command = std::string("PW");
		command += std::to_string(req.motor);
		command += req.param;
		command += std::string("\n");
	}
	else if (req.command == "FWD")
	{
		command = std::string("FWD");
		command += req.param;
		command += std::string("\n");
	}
	else if (req.command == "REV")
	{
		command = std::string("REV");
		command += req.param;
		command += std::string("\n");
	}
	else if (req.command == "UUP")
	{
		command = std::string("UUP");
		command += req.param;
		command += std::string("\n");
	}
	else if (req.command == "DWN")
	{
		command = std::string("DWN");
		command += req.param;
		command += std::string("\n");
	}
	else if (req.command == "MCC")
	{
		command = std::string("MCC");
		command += req.param;
		command += std::string("\n");
	}
	else if (req.command == "CL")
	{
		command = std::string("CL");
		command += std::to_string(req.motor);
		command += std::string("\n");
		response_len = 4;
	}
	else
	{
		ROS_WARN("Unrecognised command: %s", req.command.c_str());
		res.success = false;
	}

	ROS_INFO("command: %s", command.c_str());
	
	ser->write(command);

	if(response_len != 0)
	{
		response = ser->read(response_len);
	}
	
	res.response = response;

	return true;
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "motor_driver_node");
	ros::NodeHandle n;

	if(argc < 3)
	{
		ROS_ERROR("Usage: rosrun motor_driver motor_driver_node <port> <baud>");
		return 1;
	}

	std::string port(argv[1]);
	unsigned baud = std::stoi(argv[2]);

	ser = new serial::Serial(port, baud, serial::Timeout::simpleTimeout(1000));

	ROS_INFO("Opened %s at baud %d", port.c_str(), baud);

	ros::ServiceServer service = n.advertiseService("motor_driver_command", issueCommand);

	ros::spin();

	return 0;
}
