cmake_minimum_required(VERSION 3.0.2)
project(robot_manager_composition)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_srvs
)

catkin_package(
#  INCLUDE_DIRS include
## LIBRARIES ${PROJECT_NAME}
#  CATKIN_DEPENDS roscpp std_srvs
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

# Add standalone executable file
add_executable(system_information_test src/system_information_test_executable.cpp src/system_information.cpp)
target_link_libraries(system_information_test ${catkin_LIBRARIES})

add_executable(robot_manager_composition_node src/robot_manager_composition_node.cpp src/robot_manager_composition.cpp  src/system_information.cpp)
target_link_libraries(robot_manager_composition_node ${catkin_LIBRARIES})