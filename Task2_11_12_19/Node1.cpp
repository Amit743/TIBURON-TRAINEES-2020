#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Int32.h"
#include <sstream>
int main(int argc,char **argv)
{
	ros::init(argc,argv,"Question");
	ros::NodeHandle n;
	ros::Publisher ques=n.advertise<std_msgs::String>("Quesput",1000);
	ros::Publisher Ans=n.advertise<std_msgs::Int32>("Answindow",1000);
	ros::Rate loop_rate(0.5);
	while(ros::ok())
	{
	    std_msgs::String Ques;
	    std_msgs::Int32 an;
	    ROS_INFO("Who is currently the highest run getter T20Is ?\n");
	    Ques.data="Who is currently the highest run getter T20Is ?\n";
	    an.data=1;
	    ques.publish(Ques);
	    Ans.publish(an);
	    ros::spinOnce();
	    loop_rate.sleep();
	}
	return 0;
}
