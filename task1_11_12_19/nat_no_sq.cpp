#include "ros/ros.h"
#include "std_msgs/Int32.h"
ros::Publisher number_sq;
void inputCallback(const std_msgs::Int32 No) /*squaring function*/
{
	ROS_INFO("I received : %d",No.data);
	
	int Sq=(No.data)*(No.data);
	
	std_msgs::Int32 sq;
	
	sq.data=Sq;
	
	ROS_INFO("Publishing : %d ",sq.data);
	
	number_sq.publish(sq);
}
int main(int argc,char **argv)
{
	ros::init(argc,argv,"process");
	
	ros::NodeHandle n1;
	
	ros::Subscriber sq=n1.subscribe("NatNo",1000,inputCallback);
	
	number_sq=n1.advertise<std_msgs::Int32>("NoSq",1000);
	
	ros::spin();
	
	return 0;
} 
