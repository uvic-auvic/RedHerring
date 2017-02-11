#include <opencv2/opencv.hpp>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <ros/ros.h>

int main (int argc, char ** argv)
{
  ros::init(argc, argv, "image_publisher");
  ros::NodeHandle nh;
  image_transport::ImageTransport it(nh);
  image_transport::Publisher pub = it.advertise("camera/one/image", 5);

  cv::VideoCapture cap(0);

  if (!cap.isOpened())
    {
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
          pub.publish(msg);
          cv::waitKey(1);
            
        }

      ros::spinOnce();
      loop_rate.sleep();
    }
  
  return 0;
}
