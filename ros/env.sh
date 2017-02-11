#!/bin/bash

#TODO: Add a -h or --help argument

#CONSTANTS
DEFAULT_HOST=`hostname -I`
ROS_DEFAULT_PORT=11311

# We only want 1 argument, anything more is invalid
if [[ $# -gt 1 ]]
then
    echo "Too many arguments"
    exit 1
fi

# Set the default hostname, if no arguments are passed in
HOST=$DEFAULT_HOST
PORT=$ROS_DEFAULT_PORT

# TODO: Replace this with a regex test to test
#       whether the argument is in valid IP address format
# XXX.XXX.XX.XX
if [[ $# -eq 1 ]]
then
    HOST=$1
fi

export ROS_MASTER_URI="http://$HOST:$PORT"
export ROS_IP=$DEFAULT_HOST

echo "Using ROS_MASTER_URI $ROS_MASTER_URI"
echo "Using ROS_IP $ROS_IP"


source devel/setup.bash
