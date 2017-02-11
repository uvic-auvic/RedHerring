##############################################################################
# CMake                                                                      #
##############################################################################
cmake_minimum_required(VERSION 2.8.3)
project(vision)
set(CMAKE_CXX_FLAGS "-std=c++11")

##############################################################################
# Catkin                                                                     #
##############################################################################

find_package(catkin REQUIRED COMPONENTS
  cv_bridge
  image_transport
  roscpp
  sensor_msgs
  std_msgs
)

# This is useful when we want other packages to be able to use this package
# E.g. if another package wanted to include a few headers from here
# To run in their own nodes, they would include this package "vision"
# And we would uncomment INCLUDE_DIRS, but generally everything happens here
# SO theres no need (for now)
catkin_package(
#  INCLUDE_DIRS include
  LIBRARIES vision
  CATKIN_DEPENDS cv_bridge image_transport roscpp sensor_msgs
#  DEPENDS system_lib
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

##############################################################################
# Binaries                                                                   #
##############################################################################

# Required packages
find_package(OpenCV REQUIRED)

# Separate nodes in the package
add_executable(image_sender src/image_sender.cpp)
target_link_libraries(image_sender ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})

add_executable(image_reciever src/image_reciever.cpp)
target_link_libraries(image_reciever ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})
