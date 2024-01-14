#include "robot_commander/robot_commander.h"
#include <iostream>
#include <iterator>
#include <ostream>
#include <ros/ros.h>
#include <sets>
#include <string>
using namespace std;

int main(int argc, char **argv) {
  ros::init(argc, argv, "heading_deque");

  RobotCommander my_robot;

  set<float> coordinates;
  
    

  my_robot.move_forward(5);

  my_robot.turn(1, 5);

  my_robot.move_forward(5);

  my_robot.turn(1, 5);

  my_robot.move_forward(5);

  my_robot.turn(1, 5);

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