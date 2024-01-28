#include "robot_manager_inheritance/base_robot_manager.h"
#include <ros/ros.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "robot_manager_using_composition");
  ros::NodeHandle nh;
  RobotManagerBase rm = RobotManagerBase(&nh);
  ros::spin();
}