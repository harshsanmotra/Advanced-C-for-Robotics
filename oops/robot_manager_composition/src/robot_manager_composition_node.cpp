#include "robot_manager_composition/robot_manager_composition.h"
#include <ros/ros.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "robot_manager_using_composition");
  ros::NodeHandle nh;
  ComputerUnit computer_unit1;
  RobotManagerComposition rm = RobotManagerComposition(&nh, computer_unit1);
  ros::spin();
}