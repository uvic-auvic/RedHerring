/***************************************************************
 * @file image_sender.cpp
 * @brief The node which provides a video source of some kind
 * @date February 2017
/***************************************************************/

/***************************************************************
 * Includes
/***************************************************************/
#include <opencv2/opencv.hpp>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <ros/ros.h>
#include<string>

/*************************************************************
 * Implementation [Image Sender]
/*************************************************************/
int main (int argc, char ** argv)
{
    ros::init(argc, argv, "image_publisher");
    ros::NodeHandle nh("~");
    image_transport::ImageTransport it(nh);

    std::string name, fd, pub;
    nh.getParam("name", name);
    nh.getParam("fd", fd);
    nh.getParam("pub", pub);
    image_transport::Publisher publisher = it.advertise(pub, 5);

    /* The file descripter will be something like /dev/video0, but we want the last char 0 as an int */
    char last_char = fd.back();
    int device_index = last_char - '0';
    cv::VideoCapture cap(device_index);

    if (!cap.isOpened())
    {
        ROS_ERROR("%s failed to open device on %s", name.c_str(), fd.c_str());
        return -1;
    }

    cv::Mat frame;
    sensor_msgs::ImagePtr msg;

    ros::Rate loop_rate(10);
    while(nh.ok())
    {  
        cap >> frame;
      
        // check if we recieved anything
        if (!frame.empty())
        {
            msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", frame).toImageMsg();
            publisher.publish(msg);
            // delay for 1 ms
            cv::waitKey(1);
        }

        ros::spinOnce();
        loop_rate.sleep();
    }
  
    return 0;
}
