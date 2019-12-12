#include "ros/ros.h"
#include "std_msgs/Int32.h"
int main(int argc,char **argv)
{
	ros::init(argc,argv,"input");

	ros::NodeHandle n;

	ros::Publisher nat_number=n.advertise<std_msgs::Int32>("NatNo",1000); /*input -----> process topic:NatNo*/

	ros::Rate loop_rate(0.5);
	
	int N=1;  /*counter for natural number*/
	
	while(ros::ok())
	{
		std_msgs::Int32 No;
		
		No.data=N;
		
		ROS_INFO("Number  : %d",No.data);
		
		nat_number.publish(No);
		
		ros::spinOnce();

		loop_rate.sleep();
		
		++N;
	}
	return 0;
}
