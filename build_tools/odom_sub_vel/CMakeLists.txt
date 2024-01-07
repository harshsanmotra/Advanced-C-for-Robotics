cmake_minimum_required(VERSION 3.0.2)
project(odom_sub_vel)


find_package(catkin REQUIRED COMPONENTS
  nav_msgs
  roscpp
  rospy
  vel_library
)

catkin_package()

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(odom_listener_vel src/odom_listener_vel.cpp)
add_dependencies(odom_listener_vel nav_msgs_generate_messages_cpp)
 target_link_libraries(odom_listener_vel
   ${catkin_LIBRARIES}
)