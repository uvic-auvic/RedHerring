# This script installs the full desktop suite of ROS (Robotic Operating System) on Ubuntu 14.04 based systems
# It should be run as root in order to run uninhibited

# Add ROS and Gazebo7 to sources.list
sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'
sudo sh -c 'echo "deb http://packages.osrfoundation.org/gazebo/ubuntu-stable `lsb_release -cs` main" > /etc/apt/sources.list.d/gazebo-stable.list'

# Add ROS Key to list
sudo apt-key adv --keyserver hkp://ha.pool.sks-keyservers.net:80 --recv-key 421C365BD9FF1F717815A3895523BAEEB01FA116
wget http://packages.osrfoundation.org/gazebo.key -O - | sudo apt-key add -

# Update package list
sudo apt-get update

# Install whole ROS desktop application
sudo apt-get install ros-indigo-desktop-full
sudo apt-get install ros-indigo-gazebo7-ros-pkgs

# Install all the required packages
source package-setup.sh

# Initialize ROSDEP
sudo rosdep init
rosdep update

# Replace symlink with file
pushd ../ros/src
FILENAME="CMakeLists.txt"
FILE_LOC=`readlink -f $FILENAME`
rm $FILENAME
cp $FILE_LOC $FILENAME
popd

# Setup environment
echo "source /opt/ros/indigo/setup.bash" >> ~/.bashrc
source ~/.bashrc

# Install rosinstall
sudo apt-get install python-rosinstall
