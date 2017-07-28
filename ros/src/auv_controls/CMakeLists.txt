cmake_minimum_required(VERSION 2.8.3)
project(auv_controls)
set(CMAKE_CXX_FLAGS "-std=c++11")

find_package(catkin REQUIRED
  roscpp
  rospy
  std_msgs
  )

catkin_package(
   CATKIN_DEPENDS message_runtime std_msgs
)

## Declare a C++ executable
add_executable(ai src/ai.cpp)
add_dependencies(ai ${motor_controller_EXPORTED_TARGETS} ${vision_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(ai ${catkin_LIBRARIES})
