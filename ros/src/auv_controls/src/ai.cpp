#include <ros/ros.h>
#include "motor_controller/position.h"
#include "vision/enable_detection.h"

class ai_handler 
{
public:
    ai_handler():
    updated(false),
    pos(object_position())
    {}

    bool hasUpdated()
    {
        return this->updated;
    }

    void updatePosition(const motor_controller::position pos)
    {
        updated = true;
        this->pos = pos;
    }

    motor_controller::position getPosition()
    {
        this->updated = false;
        return this->pos;
    }

private:
    bool updated;
    motor_controller::position pos;

};

int main(int argc, char ** argv)
{
    ros::init(argc, argv, "ai");
    ros::NodeHandle nh("~");
    ai_handler ai_handle;
    /*
    Make a for every vision node we are using
    ros::ServiceClient enableNodeA = nh.serviceClient<vision::enable_detection>("/reciever/enableProcessing");
    ros::Subscriber sub = nh.subscribe<motor_controller::position>("/nodeA/position", 20, &ai_handler::ai_handler, &ai_handle);

    */

    // Start off by doing a quick sweep of the surroundings
    // Enable colout detector
    

    return 0;
}