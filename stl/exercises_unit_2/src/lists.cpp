#include "robot_commander/robot_commander.h"
#include "ros/assert.h"
#include "ros/console.h"
#include <forward_list>
#include <iostream>
#include <iterator>
#include <ostream>
#include <ros/ros.h>
#include <string>
using namespace std;

void show_fl(list<string> k) {
  for (auto i : k) {
    cout << i << " ";
  }
  cout << "\n";
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "heading_deque");

  RobotCommander my_robot;

  my_robot.move_in_circles();

  std::list<string> laser{"range_max", "range_min", "angle_max", "angle_min"};
  cout << "The forward list : ";
  show_fl(laser);

  auto laser_front = laser.begin();

  cout << *laser_front << endl;

  advance(laser_front, 2);

  cout << *laser_front << endl;

  laser_front = laser.end();

  laser_front = next(laser_front, -3);

  cout << *laser_front << endl;
  return 0;
}