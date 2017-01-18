#!/usr/bin/env bash
export ROS_MASTER_URI=http://auv01:11311
source ~/ROV02/devel/setup.bash
exec "$@"
