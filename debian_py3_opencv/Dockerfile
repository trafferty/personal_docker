FROM debian-dev

MAINTAINER Tom Rafferty <trafferty@cnt.canon.com>

WORKDIR /
USER root

# Add pre-reqs 
RUN apt-get update -qq && apt-get install -y --force-yes \
    cmake \
    libgtk2.0-dev \
    pkg-config \
    libavcodec-dev \
    libavformat-dev \
    libswscale-dev \
    python-dev \
    python-numpy \
    python3-dev \
    python3-numpy \
    libtbb2 \
    libtbb-dev \
    libjpeg-dev \
    libpng-dev \
    libtiff5-dev \
    libdc1394-22-dev; \
    apt-get clean

#removed:
#gtk+-2.0 gir1.2-gtk-2.0 libspice-client-gtk-2.0-1 libva-glx libva-dev libjasper-dev libva-x11 libva-glx libva

# python extras
RUN apt-get update -qq && apt-get install -y --force-yes \
    python-pip \
    python3-pip \
    python-cairocffi \
    python3-cairocffi; \
    apt-get clean

RUN pip install matplotlib
RUN pip3 install matplotlib

# Ximea:
RUN apt-get update -qq && apt-get install -y --force-yes \
    vainfo \
    i965-va-driver
WORKDIR /home/trafferty/Downloads
ADD XIMEA_Linux_SP.tar.gz /home/trafferty/Downloads/
WORKDIR /home/trafferty/Downloads/package
RUN ./install -cam_usb30 -silent

# OpenCV:
WORKDIR /home/trafferty/src
# copy over pre-fetched tarballs. Remember, docker automagically un-tars after copying...
ADD opencv-master.tar.gz /home/trafferty/src
ADD opencv_contrib-master.tar.gz /home/trafferty/src
# cd to the un-tarred dir, copy build script and run it
WORKDIR /home/trafferty/src/opencv-master
ADD opencv_install /home/trafferty/src/opencv-master
RUN chmod +x opencv_install && ./opencv_install
# run test so we can see if build was okay, but always return 0
WORKDIR /home/trafferty/src/opencv-master/release/bin
RUN opencv_test_core; return 0
# cleanup
WORKDIR /home/trafferty/src
RUN rm -rf opencv-master
RUN rm -rf opencv_contrib-master

# Ximea test w/opencv
WORKDIR /home/trafferty/src
ADD ximea_opencv_test.cpp /home/trafferty/src/
RUN g++ -I/usr/local/include/opencv ximea_opencv_test.cpp $(pkg-config --libs opencv) -o ximea_opencv_test && ./ximea_opencv_test; return 0

RUN apt-get update -qq && apt-get install -y --force-yes x11-apps

RUN apt-get update -qq && apt-get install -y --force-yes dbus-x11 terminator

WORKDIR /home/trafferty
USER trafferty