#include "ros/ros.h"
#include "std_msgs/Int32.h"
int Ans;

void Res(const std_msgs::Int32::ConstPtr& an)
{
	Ans=an->data;
}

void check(const std_msgs::Int32::ConstPtr& an1)
{
	if(an1->data==Ans)
	ROS_INFO("Correct answer\n");
	
	else
	ROS_INFO("Wrong Answer");
}
int main(int argc,char **argv)
{
	ros::init(argc,argv,"OutputWindow");
	
	ros::NodeHandle n;
	
	ros::Subscriber s1=n.subscribe("UserAns",1000,Res);
	
	ros::Subscriber s2=n.subscribe("Answindow",1000,check);
	
	ros::spin();
	
	return 0;
}
