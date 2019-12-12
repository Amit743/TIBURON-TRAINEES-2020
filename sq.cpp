#include "ros/ros.h"
#include "std_msgs/Int32.h"
void processCallback(const std_msgs::Int32 No)
{
	ROS_INFO("Squared Number : %d",No.data);
}
int main(int argc,char **argv)
{
	ros::init(argc,argv,"output");
	
	ros::NodeHandle n;
	
	ros::Subscriber Sq=n.subscribe("NoSq",1000,processCallback); /*process ----> output topic:NoSq*/
	
	ros::spin();
	
	return 0;
}
