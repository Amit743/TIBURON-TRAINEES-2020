#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <sstream>
int ctr=0;
image_transport::Publisher pub;
void imageCallback(const sensor_msgs::ImageConstPtr& msg)
{
    int key=-1;
    cv::Mat frame;
  try
  {
    ROS_INFO("Enter the code for operation : s -> save image p-> publish image in display node");        	  
    frame = cv_bridge::toCvShare(msg,"bgr8")->image;
    cv::imshow("view1",frame);
    key=cv::waitKey(30)&0xff;
 }
  catch (cv_bridge::Exception& e)
  {
    ROS_ERROR("Could not convert from '%s' to 'bgr8'.", msg->encoding.c_str());
    return;
  }
  if(key==27|| key==13|| key=='e')
	ros::shutdown();
  else if(key=='s')
  {
	std::stringstream ss;
	ss << "/home/amit/catkin_workspace/src/task_13_12_19/src/output" << ctr++ <<".jpg";
	cv::imwrite(ss.str(),frame);
  }
  else if(key=='p')
	pub.publish(msg);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "cam_capture");
  ros::NodeHandle nh;
  image_transport::ImageTransport it(nh); 
  image_transport::Subscriber sub = it.subscribe("camera/image1", 1, imageCallback);
  pub=it.advertise("camera/image2",1);
  cv::namedWindow("view1");
  cv::startWindowThread();
  ros::spin();
  cv::destroyWindow("view1");

	return 0;
}

