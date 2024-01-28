#pragma once
#include "robot_manager_composition/system_information.h"
#include <ros/ros.h>
#include <std_srvs/SetBool.h>

class RobotManagerComposition {

  /*RobotManagerComposition is a C++ class.

  It has two constructors: a default constructor (RobotManagerComposition(){})
  and a parameterized constructor (RobotManagerComposition(ros::NodeHandle
  *node_handle, ComputerUnit computer_unit)).

  The class has three protected members:

  ros::NodeHandle *nh: A pointer to a ROS NodeHandle, which is likely used for
  communication with the ROS system. void init_config_output_srv(): A method for
  initializing a service (similar to the previous version). bool output_enabled:
  A boolean flag indicating whether console output is enabled or disabled. The
  class has two private members:

  ros::ServiceServer config_output_srv: An object representing the ROS service
  server. This will be used to handle requests from clients. ComputerUnit
  c_unit: An instance of the ComputerUnit class, which is presumably used to
  manage information about the robot's computer system.*/

public:
  RobotManagerComposition(){};
  RobotManagerComposition(ros::NodeHandle *node_handle,
                          ComputerUnit computer_unit);

protected:
  ros::NodeHandle *nh;
  void init_config_output_srv();
  bool output_enabled = false;

private:
  ros::ServiceServer config_output_srv;

private:
  ComputerUnit c_unit;
  bool ConfigOutputCallback(std_srvs::SetBoolRequest &req,
                            std_srvs::SetBoolResponse &response);
};