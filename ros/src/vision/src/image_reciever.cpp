#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/opencv.hpp>
#include <cv_bridge/cv_bridge.h>
#include <ctime>

int count = 0;
std::clock_t start;

void imageCallback(const sensor_msgs::ImageConstPtr& msg)
{
    if (count == 0)
      {
        start = std::clock();
      }
      
    count++;

  try {
    cv::imshow("Webcam", cv_bridge::toCvShare(msg, "bgr8")->image);
    cv::waitKey(30);
  }
  catch (cv_bridge::Exception e)
    {
      ROS_ERROR("Couldn't convert from '%s' to 'bgr8'.", msg->encoding.c_str());
    }

  if (count == 10) {
    double duration = (std::clock() - start) / ( (double) CLOCKS_PER_SEC);
    ROS_INFO("FPS: %f", 10 / duration);
    count = 0;
  }
    
}

int main(int argc, char ** argv)
{
  ros::init(argc, argv, "image_reciever");
  ros::NodeHandle nh;
  cv::namedWindow("Webcam");
  cv::startWindowThread();
  image_transport::ImageTransport it(nh);
  image_transport::Subscriber sub = it.subscribe("camera/one/image", 5, imageCallback);
  ros::spin();
  cv::destroyWindow("Webcam");

  return 0;
}
