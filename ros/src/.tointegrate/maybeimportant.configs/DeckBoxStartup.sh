#!/bin/bash
source ~/ROV02/devel/setup.bash
roslaunch DeckBoxStartup.launch
exec "$@"

