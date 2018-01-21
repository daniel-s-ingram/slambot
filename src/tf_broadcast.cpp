#include <ros/ros.h>
#include <tf/transform.h>

int main(int argc, char** argv)
{
  float x_offset = 0.0, y_offset = 0.16, z_offset = 0.225;

  ros::init(argc, argv, "slambot_tf_publisher");
  ros::NodeHandle nh;

  ros::Rate rate(40);

  tf::TransformBroadcaster broadcaster;

  while(nh.ok())
  {
    broadcaster.sendTransform(tf::StampedTransform(tf::Transform(tf::Quaternion(0, 0, 0, 1), 
                                                    tf::Vector3(x_offset, y_offset, z_offset)), 
                                                  ros::Time::now(), 
                                                  "base_link", 
                                                  "laser_link"));
    rate.sleep()
  }
}