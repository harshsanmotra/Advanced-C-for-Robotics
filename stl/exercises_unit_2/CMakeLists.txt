cmake_minimum_required(VERSION 3.0.2)
project(exercises_unit_2)


find_package(catkin REQUIRED COMPONENTS
  robot_commander
  roscpp
)

catkin_package()

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(robot_position_as_array src/robot_position_as_array.cpp)
 target_link_libraries(robot_position_as_array
   ${catkin_LIBRARIES}
)

add_executable(robot_heading_as_vector src/robot_heading_as_vector.cpp)
 target_link_libraries(robot_heading_as_vector
   ${catkin_LIBRARIES}
)

add_executable(robot_heading_as_deque src/robot_heading_as_deque.cpp)
 target_link_libraries(robot_heading_as_deque
   ${catkin_LIBRARIES}
)

add_executable(lists src/lists.cpp)
 target_link_libraries(lists
   ${catkin_LIBRARIES}
)


add_executable(path_coordinates_map src/path_coordinates_map.cpp)
 target_link_libraries(path_coordinates_map
   ${catkin_LIBRARIES}
)
