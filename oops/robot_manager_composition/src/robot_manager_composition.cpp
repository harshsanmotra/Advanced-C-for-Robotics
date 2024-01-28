#include "robot_manager_composition/robot_manager_composition.h"
#include <ros/ros.h>

// This is the constructor for the RobotManagerComposition class. It takes a
// ros::NodeHandle pointer (node_handle) and a ComputerUnit object
// (computer_unit) as parameters. The constructor initializes class members (nh,
// c_unit) and calls the init_config_output_srv() function.
RobotManagerComposition::RobotManagerComposition(ros::NodeHandle *node_handle,
                                                 ComputerUnit computer_unit) {
  nh = node_handle;
  init_config_output_srv();
  c_unit = computer_unit;
}

// The init_config_output_srv() function is responsible for initializing a
// service. It uses the ROS advertiseService method to create a service named
// "robot_manager_output" and associates it with the ConfigOutputCallback member
// function.
void RobotManagerComposition::init_config_output_srv() {
  config_output_srv = nh->advertiseService(
      "robot_manager_output", &RobotManagerComposition::ConfigOutputCallback,
      this);
  ROS_INFO("Enable output service created");
}

// The ConfigOutputCallback function is a callback for the service created
// earlier. It takes a request (std_srvs::SetBoolRequest) and a response
// (std_srvs::SetBoolResponse) as parameters. The function handles the request
// to enable or disable console output based on the req.data value. It also
// updates the response accordingly. Additionally,it checks if the requested
// configuration is the same as the current one andnhandles the response accordingly.
// If the configuration changes, it updates the output_enabled flag and prints
// information about the robot's CPU and RAM using the c_unit.print_info()
// method.

bool RobotManagerComposition::ConfigOutputCallback(
    std_srvs::SetBoolRequest &req, std_srvs::SetBoolResponse &response) {
  bool request = req.data;

  // Check if request is same as current output configuration
  if (request == output_enabled) {
    response.success = false;
    response.message = "Output configuration request is the same as the "
                       "current output configuration.";
    return true;
  }

  response.success = true;
  output_enabled = request;
  if (output_enabled == false) {
    response.message = "Console output disabled.";
    ROS_INFO("Robot Manager console output disabled.");
  } else {
  
    response.message = "Console output enabled.";
    ROS_INFO("Robot Manager console output enabled.");
    // Print CPU and RAM information
    c_unit.print_info();
  }
  return true;
}