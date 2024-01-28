cmake_minimum_required(VERSION 3.0.2)
project(test_gec)


find_package(catkin REQUIRED COMPONENTS
  my_robot_manager
  roscpp
)

catkin_package()

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(checker src/checker.cpp)
 target_link_libraries(checker
   ${catkin_LIBRARIES}
)
