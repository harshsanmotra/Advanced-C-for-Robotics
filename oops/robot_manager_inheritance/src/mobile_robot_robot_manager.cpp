#include "robot_manager_inheritance/mobile_robot_robot_manager.h"
#include "robot_manager_inheritance/base_robot_manager.h"
#include <ros/ros.h>

MobileRobotRobotManager::MobileRobotRobotManager(ros::NodeHandle *node_handle) {
  // assign NodeHandle to nh variable from parent class
  nh = node_handle;
  init_config_output_srv();
}