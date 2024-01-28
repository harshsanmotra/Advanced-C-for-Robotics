#include "my_robot_manager/robot_manager.h"
#include "ros/node_handle.h"

// Initialize static member of class
int RobotManager::robot_count = 0;

int main(int argc, char **argv) {
  ros::init(argc, argv, "rosbot_manager");
  ros::NodeHandle nh;

  const RobotManager robot_cp(&nh, "/robot1/odom", "C3PO", "BOOSTER");
  const RobotManager robot_cp1(&nh, "/robot2/odom", "C3P1", "BOOSTER");

  robot_cp.print_specifications();
  robot_cp1.print_specifications();

  ros::spin();

  return 0;
}