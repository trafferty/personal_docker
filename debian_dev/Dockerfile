FROM debian:stretch

MAINTAINER Tom Rafferty <trafferty@cnt.canon.com>

########################################
#
# Basic dev environment
#
#######################################

# Add dev basics
RUN apt-get update -qq && apt-get install -y --force-yes \
    curl \
    git \
    g++ \
    autoconf \
    automake \
    build-essential \
    cmake \
    wget \
    tmux \
    vim \
    sudo \
    unzip; \
    apt-get clean

# Setup home environment
RUN useradd -ms /bin/bash trafferty && echo "trafferty:trafferty" | chpasswd && adduser trafferty sudo

ADD vimrc /home/trafferty/.vimrc
ADD tmux.conf /home/trafferty/.tmux.conf
ADD bashrc /home/trafferty/.bashrc
ADD bash_aliases /home/trafferty/.bash_aliases
ADD gitconfig /home/trafferty/.gitconfig
ADD gitignore_global /home/trafferty/.gitignore_global

RUN chown -R trafferty:trafferty /home/trafferty

WORKDIR /home/trafferty
USER trafferty