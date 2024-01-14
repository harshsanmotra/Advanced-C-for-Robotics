#include "robot_commander/robot_commander.h"
#include <array>
#include <iostream>
#include <ros/ros.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "position_array");

  RobotCommander my_robot;

  std::array<float, 3> my_array;

  my_array.fill(12);

  for (int i = 0; i < 3; i++)
    std::cout << my_array.at(i) << " ";
  std::cout << std::endl;

  my_array.at(0) = my_robot.get_x_position();
  my_array.at(1) = my_robot.get_y_position();
  my_array.at(3) = my_robot.get_z_position();

  for (int i = 0; i < 3; i++)
    std::cout << my_array.at(i) << " ";
  std::cout << std::endl;
  return 0;
}