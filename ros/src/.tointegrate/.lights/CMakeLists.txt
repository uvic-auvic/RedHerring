cmake_minimum_required(VERSION 2.8.3)
project(lights)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES lights
#  CATKIN_DEPENDS roscpp std_msgs
#  DEPENDS system_lib
)

include_directories(
  ${catkin_INCLUDE_DIRS}
    /usr/local/include/
)

add_executable(lights_node src/lights_node.cpp)
target_link_libraries(lights_node ${catkin_LIBRARIES} /usr/local/lib/libwiringPi.so)
add_dependencies(lights_node lights)
