// #ifndef ROBOT_MANAGER_H
// #define ROBOT_MANAGER_H
// You can either use the above two or just pragma once.
#pragma once
#include "nav_msgs/Odometry.h"
#include "ros/service_server.h"
#include <ros/ros.h>
#include <std_srvs/Trigger.h>
#include <string>

class RobotManager {

private:
  std::string robot_name;
  std::string robot_model;
  float battery_capacity_kwh = 99.99;
  int total_operation_hours = 8;
  ros::Subscriber odom_subscriber;
  std::string odometry_topic = "/odom";
  float current_x_position;
  float current_y_position;
  ros::ServiceServer trigger_srv;

public:
  // Static variable
  static int robot_count;
  // parameterized constructor
  RobotManager(ros::NodeHandle *nh,
               std::string topic_name_arg, /*topic name to subscribe*/
               std::string robot_name_arg, std::string robot_model_arg);

  void odom_callback(const nav_msgs::Odometry::ConstPtr &msg);

  void print_specifications() const;
  //   static int robotCount();
  bool trigger_srv_callback(std_srvs::Trigger::Request &req,
                            std_srvs::Trigger::Response &res);
};
