cmake_minimum_required(VERSION 2.8.3)
project(thrusters)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  serial
  std_msgs
  message_generation
)

add_message_files(FILES
    Sensitivity.msg
    thrusterValues.msg
    thrusterTemperatures.msg
)

generate_messages(DEPENDENCIES
    std_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES thrusters
#  CATKIN_DEPENDS roscpp serial std_msgs thruster_node
  CATKIN_DEPENDS message_runtime std_msgs
#  DEPENDS system_lib
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(thruster_node src/thruster_node.cpp)
target_link_libraries(thruster_node ${catkin_LIBRARIES})
add_dependencies(thruster_node thrusters)

add_executable(rov_thruster_control src/rov_thruster_control.cpp)
target_link_libraries(rov_thruster_control ${catkin_LIBRARIES})
add_dependencies(rov_thruster_control thrusters)

add_executable(auv_thruster_control src/auv_thruster_control.cpp)
target_link_libraries(auv_thruster_control ${catkin_LIBRARIES})
add_dependencies(auv_thruster_control thrusters)
