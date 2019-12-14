#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <sstream>

int main(int argc, char** argv)
{

  ros::init(argc, argv, "cam_feed");
  
  ros::NodeHandle nh;
  
  image_transport::ImageTransport it(nh);
  
  image_transport::Publisher pub = it.advertise("camera/image1",1);

  ros::Rate loop_rate(30);
  
  cv::VideoCapture cap(0);
  
  if(!cap.isOpened()) return -1;
  
  cv::Mat frame;
  
  sensor_msgs::ImagePtr msg;
	
 
  
  while (nh.ok()) {
    
     cap >> frame;
    
       if(!frame.empty()){ 	
     
        msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", frame).toImageMsg();
      
        pub.publish(msg);
      
 	cv::waitKey(1);
    
    }

    ros::spinOnce();
    
    loop_rate.sleep();
  }
  return 0;
}
