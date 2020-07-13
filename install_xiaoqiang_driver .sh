#!/usr/bin/env bash

set -e

source /opt/ros/$(dir /opt/ros)/setup.bash

cd $HOME/interfacesystechrobot_ws/src
git clone https://github.com/jarubank/interfacesystechserial_server.git
git clone https://github.com/jarubank/interfacesystech_serial_server.git
git clone https://github.com/jarubank/interfacesystech_log.git

cd $HOME/interfacesystechrobot_ws

catkin_make
