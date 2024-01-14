#include "robot_commander/robot_commander.h"
#include <deque>
#include <iostream>
#include <ostream>
#include <ros/ros.h>

void display_dq_(const std::deque<float> &N) {
  for (const auto &value : N)
    std::cout << ' ' << value;
  std::cout << '\n';
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "heading_deque");

  RobotCommander my_robot;

  my_robot.move_in_circles();

  std::deque<float> headings_q;

  int total_value;

  std::cout << "Enter the number of heading values that you want to capture: ";
  // get user input from the keyboard
  std::cin >> total_value;

  while (headings_q.size() < (total_value)) {
    headings_q.push_front(my_robot.get_heading());

    std::cout << "Collecting heading value: " << headings_q.front()
              << std::endl;

    ros::Duration(1).sleep();
  }

  my_robot.stop_moving();

  display_dq_(headings_q);

  std::cout << std::endl;
  return 0;
}