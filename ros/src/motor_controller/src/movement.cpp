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

class motor_client
{
public:
    ros::NodeHandle nh;
    ros::ServiceClient forward;
    ros::ServiceClient reverse;
    ros::ServiceClient stopMotors;
    ros::ServiceClient stopMotor;
    ros::ServiceClient getRPM;

    motor_client(std::string motor_conn_name) :
        nh(ros::NodeHandle("~")),
        forward(nh.serviceClient<motor_controller::motor_command>("/" + motor_conn_name + "/setMotorForward")),
        reverse(nh.serviceClient<motor_controller::motor_command>("/" + motor_conn_name + "/setMotorReverse")),
        stopMotors(nh.serviceClient<motor_controller::motor_command>("/" + motor_conn_name + "/stopAllMotors")),
        stopMotor(nh.serviceClient<motor_controller::motor_command>("/" + motor_conn_name + "/stopMotor")),
        getRPM(nh.serviceClient<motor_controller::motor_command>("/" + motor_conn_name + "/getRPM"))
    {
        reverse_motor_multiplier = nh.getParam("reverse_multiplier", reverse_motor_multiplier);
    }

    motor_controller::motor_command generateMotorCommand(int motor_number, int command_param)
    {
        motor_controller::motor_command srv;
        srv.request.motor_number = motor_number;
        srv.request.command_param = command_param;
        return srv;
    }

    void setBothForward(int power, bool reduce_power=false)
    {
        if (reduce_power) {
            power = getReducedPower(power);
        }
        motor_controller::motor_command mf = generateMotorCommand(motor_front, power);
        motor_controller::motor_command mb = generateMotorCommand(motor_back, power);
        this->forward.call(mf);
        this->forward.call(mb);
    }

    void setBothBackward(int power)
    {
        motor_controller::motor_command mf = generateMotorCommand(motor_front, power);
        motor_controller::motor_command mb = generateMotorCommand(motor_back, power);
        this->reverse.call(mf);
        this->reverse.call(mb);
    }

    void setFrontForwardBackBackward(int base_power)
    {
        int reduced_power = getReducedPower(base_power);
        motor_controller::motor_command mf = generateMotorCommand(motor_front, reduced_power);
        motor_controller::motor_command mb = generateMotorCommand(motor_back, base_power);
        this->forward.call(mf);
        this->reverse.call(mb);
    }

    void setFrontBackwardBackForward(int base_power)
    {
        motor_controller::motor_command mf = generateMotorCommand(motor_front, base_power);
        int reduced_power = getReducedPower(base_power);
        motor_controller::motor_command mb = generateMotorCommand(motor_back, reduced_power);
        this->reverse.call(mf);
        this->forward.call(mb);
    }

    void up(int power)
    {
        setMotorForward(motor_side, power);
    }

    void down(int power)
    {
        setMotorReverse(motor_side, power);
    }

    void setMotorForward(int motor, int power)
    {
        motor_controller::motor_command mup = generateMotorCommand(motor, power);
        this->forward.call(mup);
    }

    void setMotorReverse(int motor, int power)
    {
        motor_controller::motor_command mdown = generateMotorCommand(motor, power);
        this->reverse.call(mdown);
    }

    int getReducedPower(int speed)
    {
        return (int) speed * reverse_motor_multiplier;
    }

private:
    float reverse_motor_multiplier;

    // Motor positions, parameterize
    int motor_front = 0;
    int motor_back = 2;
    int motor_side = 1;

};

class movement_controller
{
public:
    movement_controller() :
        nh(ros::NodeHandle("~")),
        left_controller(motor_client("motor_left")),
        right_controller(motor_client("motor_right"))
    {
        nh.getParam("default_power", default_power);
    }

    // Service Call Definitions
    bool Forward( motor_controller::movement_command::Request &req,
                  motor_controller::movement_command::Response &res)
    {
        left_controller.setBothForward(default_power);
        right_controller.setBothForward(default_power);
        return true;
    }

    bool Backward( motor_controller::movement_command::Request &req,
                   motor_controller::movement_command::Response &res)
    {
        left_controller.setBothBackward(default_power);
        right_controller.setBothBackward(default_power);
        return true;
    }

    bool Left( motor_controller::movement_command::Request &req,
               motor_controller::movement_command::Response &res)
    {
        left_controller.setFrontBackwardBackForward(default_power);
        right_controller.setFrontForwardBackBackward(default_power);
        return true;
    }

    bool Right( motor_controller::movement_command::Request &req,
                motor_controller::movement_command::Response &res)
    {
        right_controller.setFrontBackwardBackForward(default_power);
        left_controller.setFrontForwardBackBackward(default_power);
        return true;
    }

    bool RotateClockwise( motor_controller::movement_command::Request &req,
                          motor_controller::movement_command::Response &res)
    {
        left_controller.setBothForward(default_power, true);
        right_controller.setBothBackward(default_power);
        return true;
    }

    bool RotateCounterClockwise( motor_controller::movement_command::Request &req,
                                 motor_controller::movement_command::Response &res)
    {
        right_controller.setBothForward(default_power, true);
        left_controller.setBothBackward(default_power);
        return true;
    }

    bool MoveToPosition( motor_controller::movement_command::Request &req,
                         motor_controller::movement_command::Response &res)
    {
      return true;
    }

    void convertDegreesToTime()
    {
      return;
    }

private:
    ros::NodeHandle nh;
    motor_client left_controller;
    motor_client right_controller;
    int default_power;
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
    ros::ServiceServer CW           = nh.advertiseService("RotateClockwise", &movement_controller::RotateClockwise, &controller);
    ros::ServiceServer CCW          = nh.advertiseService("RotateCounterClockwise", &movement_controller::RotateCounterClockwise, &controller);
    ros::ServiceServer Move         = nh.advertiseService("MoveToPosition", &movement_controller::MoveToPosition, &controller);

    /* Wait for callbacks */
    ros::spin();
    return 0;
}
