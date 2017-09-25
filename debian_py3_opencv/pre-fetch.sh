#!/bin/bash

# Run this script before docker build to freshen files

# opencv:
wget --no-check-certificate https://github.com/opencv/opencv/archive/master.tar.gz -O opencv-master.tar.gz
wget --no-check-certificate https://github.com/opencv/opencv_contrib/archive/master.tar.gz -O opencv_contrib-master.tar.gz
