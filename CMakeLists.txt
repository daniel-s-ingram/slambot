cmake_minimum_required(VERSION 2.8.3)
project(slambot)

find_package(catkin REQUIRED COMPONENTS
  rospy
  roscpp
  tf
)
add_executable(tf_broadcaster src/autonomous/tf_broadcaster.cpp)
target_link_libraries(tf_broadcaster ${catkin_LIBRARIES})

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

