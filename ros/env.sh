#!/bin/bash

#TODO: Add a -h or --help argument

#CONSTANTS
DEFAULT_HOST="localhost"
DEFAULT_IP=`hostname -I`
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

# This environment varaible will be read by the launch file
# And determine which packages to launch
# If it's local, it will launch the local nodes with local settings
# In the event that this name conflicts with something in the ROS official namespace then change it
ROS_MASTER_LOC="local"

# TODO: Replace this with a regex test to test
#       whether the argument is in valid IP address format
# XXX.XXX.XX.XX
if [[ $# -eq 1 ]]
then
    HOST=$1
    ROS_MASTER_LOC="remote"
fi

export ROS_MASTER_URI="http://$HOST:$PORT"
export ROS_IP="${DEFAULT_IP// /}"
export ROS_MASTER_LOC

echo "Using ROS_MASTER_URI $ROS_MASTER_URI"
echo "Using ROS_IP $ROS_IP"

source devel/setup.bash

# This part might seem pointless, but trust me it makes sense
# Launch files won't get parsed as XML by an editor (such as emacs)
# so I decided to keep the xml extension and have this script make a copy with the .launch extension
pushd launchfiles > /dev/null
for f in *.xml; do
    cp "$f" "../${f%.xml}.launch"
done
popd > /dev/null

# In case you're wondering about the name 'herring-red...'
# So because ros is packed with hundreds of packages
# typing `roslaunch <TAB>` will not get you anywhere (even if there is only 1 launch file in the directory)
# the next best thing is to only have to type 1 character then <TAB> for autocomplete
# But again because there are so many packages there are only 4 characters that no package name starts with
# 'h' 'w' 'x' 'y' 
# So if anyone can come up with a better name that describes the entire project do tell
