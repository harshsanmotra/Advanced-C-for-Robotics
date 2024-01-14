#include "robot_commander/robot_commander.h"
#include <iostream>
#include <ostream>
#include <ros/ros.h>
#include <vector>

int main(int argc, char **argv) {
  ros::init(argc, argv, "heading_vector");

  RobotCommander my_robot;

  my_robot.move_in_circles();

  std::vector<float> headings;

  int total_value;

  std::cout << "Enter the number of heading values that you want to capture: ";
  // get user input from the keyboard
  std::cin >> total_value;

  while (headings.size() < (total_value)) {
    headings.push_back(my_robot.get_heading());

    std::cout << "Collecting heading value: " << headings.back() << std::endl;

    ros::Duration(1).sleep();
  }

  my_robot.stop_moving();

  for (const float &i : headings) {
    std::cout << i << "  ";
  }

  std::cout << std::endl;
  return 0;
}