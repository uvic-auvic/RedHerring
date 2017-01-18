#!/usr/bin/env bash
source ~/ROV02/devel/setup.bash
export ROS_HOSTNAME=ubuntu
export ROS_MASTER_URI=http://ubuntu:11311
roslaunch ROV02.launch
exec "$@"
