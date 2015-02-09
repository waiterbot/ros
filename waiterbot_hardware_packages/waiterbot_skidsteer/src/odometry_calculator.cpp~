#include "ros/ros.h"

void encoderCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "waiterbot_odometry");
    ros::NodeHandle n;

    // We don't want a big message queue for odometry, because if the system
    // delays a frame, it will be outdated, at which point it is more useful to
    // publish the next available odometry frame.
    ros::Publisher odom_pub = n.advertise<nav_msgs::Odometry>("odom", 1);

    // Publish odometry 20 times per second
    ros::Rate loop_rate(20);


    // This ensures that the node can be killed
    while (ros::ok())
    {
        // We call spinOnce first so we have the latest and greatest odometry info.
        ros::spinOnce();
        nav_msgs::Odometry odom_msg;


        odom_pub.publish(odom_msg);
        loop_rate.sleep();
  }


  return 0;
}
