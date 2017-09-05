FROM debian-dev

MAINTAINER Tom Rafferty <trafferty@cnt.canon.com>

WORKDIR /
USER root

# Add pre-reqs 
RUN apt-get update -qq && apt-get install -y --force-yes \
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
ADD XIMEA_Linux_SP.tgz /home/trafferty/Downloads/
WORKDIR /home/trafferty/Downloads/package
RUN ./install -cam_usb30 -silent

# Opencv:
WORKDIR /home/trafferty/src
RUN wget https://github.com/opencv/opencv/archive/master.zip -O opencv.zip
RUN wget https://github.com/opencv/opencv_contrib/archive/master.zip -O opencv_contrib.zip
RUN unzip opencv.zip
RUN unzip opencv_contrib.zip
WORKDIR /home/trafferty/src/opencv-master
ADD opencv_install /home/trafferty/src/opencv-master
RUN chmod +x opencv_install && ./opencv_install
WORKDIR /home/trafferty/src/opencv-master/release/bin
RUN opencv_test_core; return 0

# Ximea test w/opencv
WORKDIR /home/trafferty/src
ADD ximea_opencv_test.cpp /home/trafferty/src/
RUN g++ -I/usr/local/include/opencv ximea_opencv_test.cpp $(pkg-config --libs opencv) -o ximea_opencv_test && ./ximea_opencv_test; return 0

WORKDIR /home/trafferty
USER trafferty