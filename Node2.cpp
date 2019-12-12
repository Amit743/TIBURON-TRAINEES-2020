#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Int32.h"
#include <sstream>
ros::Publisher answer;
void Ques(const std_msgs::String ques)
{
	ROS_INFO("Question : %s\n",ques.data.c_str());
	ROS_INFO("1-> Virat Kohli 2-> Chris Gayle 3-> AB de villiers\n");
	ROS_INFO("Answer : ");
	int ans;
	std_msgs::Int32 Ans;
	std::cin>>Ans.data;
	answer.publish(Ans);
}
int main(int argc,char **argv)
{
	ros::init(argc,argv,"UI");
	
	ros::NodeHandle n;
	
	ros::Subscriber sub=n.subscribe("Quesput",1000,Ques);
	
	answer=n.advertise<std_msgs::Int32>("UserAns",1000);
	
	ros::spin();
	
	return 0;
} 
