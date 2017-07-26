cmake_minimum_required(VERSION 2.8.3)
project(auv_controls)

find_package(catkin REQUIRED)

## Generate messages in the 'msg' folder
# add_message_files(
#   FILES
#   Message1.msg
#   Message2.msg
# )

## Generate services in the 'srv' folder
# add_service_files(
#   FILES
#   Service1.srv
#   Service2.srv
# )

## Generate actions in the 'action' folder
# add_action_files(
#   FILES
#   Action1.action
#   Action2.action
# )

## Generate added messages and services with any dependencies listed here
# generate_messages(
#   DEPENDENCIES
#   std_msgs  # Or other packages containing msgs
# )

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES auv_controls
#  CATKIN_DEPENDS other_catkin_pkg
#  DEPENDS system_lib
)
## Declare a C++ library
# add_library(auv_controls
#   src/${PROJECT_NAME}/auv_controls.cpp
# )

# add_dependencies(auv_controls ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Declare a C++ executable
# add_executable(auv_controls_node src/auv_controls_node.cpp)
# add_dependencies(auv_controls_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
# target_link_libraries(auv_controls_node ${catkin_LIBRARIES}
