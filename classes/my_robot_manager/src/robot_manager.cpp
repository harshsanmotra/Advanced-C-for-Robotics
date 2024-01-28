#include "my_robot_manager/robot_manager.h"

RobotManager::RobotManager(
    ros::NodeHandle *nh, std::string topic_name_arg, /*topic name to subscribe*/
    std::string robot_name_arg, std::string robot_model_arg) {

  odometry_topic = topic_name_arg;
  robot_name = robot_name_arg;
  robot_model = robot_model_arg;
  odom_subscriber =
      nh->subscribe(odometry_topic, 1000, &RobotManager::odom_callback, this);
  // Increase every time object is created
  robot_count++;

  ROS_INFO("%d Robot Created.", robot_count);
  trigger_srv = nh->advertiseService(robot_name + "/log_current_position",
                                     &RobotManager::trigger_srv_callback, this);
}

void RobotManager::print_specifications() const {

  ROS_INFO("Robot Name\t: %s", robot_name.c_str());
  ROS_INFO("Robot Model\t: %s", robot_model.c_str());
  ROS_INFO("Robot Battery Capacity: %.2f", battery_capacity_kwh);
  ROS_INFO("Total Operating Hours: %d", total_operation_hours);
  ROS_INFO("Robot subscribed to topic: %s", odometry_topic.c_str());
}

void RobotManager::odom_callback(const nav_msgs::Odometry::ConstPtr &msg) {
  this->current_x_position = msg->pose.pose.position.x;
  this->current_y_position = msg->pose.pose.position.y;

  ROS_INFO("%s position (x,y): %lf , %lf", robot_name.c_str(),
           current_x_position, current_y_position);
}

// static int RobotManager::robotCount() { return robot_count; }

// check robot_manager_node
// also package test_gec

//  Trigger service callback
bool RobotManager::trigger_srv_callback(std_srvs::Trigger::Request &req,
                                        std_srvs::Trigger::Response &res) {

  ROS_INFO("%s position (x,y): %lf , %lf", robot_name.c_str(),
           this->current_x_position, this->current_y_position);

  res.success = true;
  res.message = "Position logged";
  return true;
}
