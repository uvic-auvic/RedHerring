#include <ros/ros.h>
#include <iostream>
#include "motor_controller/motor_command.h"
#include "motor_controller/keyboard.h"

using keyboard_msg = motor_controller::keyboard;

class message_reciever {
public:
    void setMessage(const keyboard_msg message) {this->direction = message.direction; this->recieved_new_msg = true; std::cout << "test\n";}
    int getMessage() {this->recieved_new_msg = false; return this->direction;}
    bool recieved() {return this->recieved_new_msg;}
private:
    int direction;
    bool recieved_new_msg = false;
};

int main(int argc, char ** argv)
{
    ros::init(argc, argv, "motor_controller_client");
    ros::NodeHandle nh("~");
    message_reciever msg;
    ros::Subscriber sub = nh.subscribe<motor_controller::keyboard>("/rov_keyboard/keyboard_input", 20, &message_reciever::setMessage, &msg);

    ros::ServiceClient setMotorForwardclient = nh.serviceClient<motor_controller::motor_command>("/motor_con/setMotorForward");
    ros::ServiceClient setMotorReverseclient = nh.serviceClient<motor_controller::motor_command>("/motor_con/setMotorReverse");
    ros::ServiceClient stopAllMotorsclient   = nh.serviceClient<motor_controller::motor_command>("/motor_con/stopAllMotors");
    ros::ServiceClient stopMotorclient       = nh.serviceClient<motor_controller::motor_command>("/motor_con/stopMotor");
    ros::ServiceClient getRPMclient          = nh.serviceClient<motor_controller::motor_command>("/motor_con/getRPM");
    ros::ServiceClient setPWMclient          = nh.serviceClient<motor_controller::motor_command>("/motor_con/setPWM");
    ros::ServiceClient calibrateMotorclient  = nh.serviceClient<motor_controller::motor_command>("/motor_con/calibrateMotor");
    
    motor_controller::motor_command srv;
    srv.request.motor_number = 4;
    srv.request.command_param = 100;


    while (ros::ok())
    {
        if (msg.recieved())
        {
            int kb_msg = msg.getMessage();
            
            switch(kb_msg)
            {
            case motor_controller::keyboard::Forward:
                if (setMotorForwardclient.call(srv))
                {
                    ROS_INFO("%s", srv.response.motor_response.c_str());
                }
                else
                {
                    ROS_WARN("Failed");
                }
                break;

            case motor_controller::keyboard::Backward:
                if (setMotorReverseclient.call(srv))
                {
                    ROS_INFO("%s", srv.response.motor_response.c_str());
                }
                else
                {
                    ROS_WARN("Failed");
                }

                break;

            case motor_controller::keyboard::left:
                if (stopAllMotorsclient.call(srv))
                {
                    ROS_INFO("%s", srv.response.motor_response.c_str());
                }
                else
                {
                    ROS_WARN("Failed");
                }
                break;
                   
            case motor_controller::keyboard::right:
                if (stopAllMotorsclient.call(srv))
                {
                    ROS_INFO("%s", srv.response.motor_response.c_str());
                }
                else
                {
                    ROS_WARN("Failed");
                }
                break;
                
            }
            
        }
        ros::spinOnce();
    }
    
  return 0;
}
