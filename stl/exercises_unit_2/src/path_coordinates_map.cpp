#include "robot_commander/robot_commander.h"
#include <iostream>
#include <map>
#include <ostream>
#include <ros/ros.h>
#include <vector>
using namespace std;

/*In your code you will have to:

Make the robot trace a polygonal path (of your choice).
Use the methods move_forward(int time) to move forward for n seconds and
move_backward(int time) to move backwards for n seconds. Use the method
turn(float velocity_value, int n_secs) to turn the robot. Specify the velocity
(in rad/s) with velocity_value and the duration of the turn with n_secs. Use the
method stop_moving() for stopping the robot. Store the (X,Y) coordinates of the
vertex of the plygon traced in a map. Use the methods get_x_position() and
get_y_position() to get the current coordinates. Each vertex will be stored
using an integer key (starting from 1 and increasing in 1). (first_vertex) -> 1
(second_vertex) -> 2
(third_vertex) -> 3
and so on...
*/

int main(int argc, char **argv) {
  ros::init(argc, argv, "heading_deque");

  RobotCommander my_robot;
  // empty map container
  map<int, vector<float>> vertex_;

  vertex_[1].push_back(my_robot.get_x_position());
  vertex_[1].push_back(my_robot.get_y_position());

  my_robot.move_forward(5);

  vertex_[2].push_back(my_robot.get_x_position());
  vertex_[2].push_back(my_robot.get_y_position());

  my_robot.turn(1, 2);
  my_robot.move_forward(5);

  vertex_[3].push_back(my_robot.get_x_position());
  vertex_[3].push_back(my_robot.get_y_position());

  my_robot.turn(1, 2);
  my_robot.move_forward(5);

  vertex_[4].push_back(my_robot.get_x_position());
  vertex_[4].push_back(my_robot.get_y_position());

  my_robot.turn(1, 2);
  my_robot.move_forward(5);

  vertex_[5].push_back(my_robot.get_x_position());
  vertex_[5].push_back(my_robot.get_y_position());

  for (const auto &entry : vertex_) {
    int key = entry.first;
    const std::vector<float> &values = entry.second;

    std::cout << "Vertex " << key << ": ";

    // Print the values in the vector
    for (const float &value : values) {
      std::cout << value << " ";
    }

    std::cout << std::endl;
  }

  return 0;
}