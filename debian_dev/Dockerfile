FROM debian:stretch

MAINTAINER Tom Rafferty <trafferty@cnt.canon.com>

########################################
#
# Basic dev environment
#
#######################################

# Add dev basics
RUN apt-get update -qq && apt-get install -y --force-yes \
    g++ \
    build-essential \
    git \
    tmux \
    vim \
    sudo \
    unzip \
    locales \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists

# Setup home environment
RUN useradd -ms /bin/bash trafferty && \
    echo "trafferty:trafferty" | chpasswd && \
    adduser trafferty sudo && \
    chown -R trafferty:trafferty /home/trafferty

ADD vimrc /home/trafferty/.vimrc
ADD tmux.conf /home/trafferty/.tmux.conf
ADD bashrc /home/trafferty/.bashrc
ADD bash_aliases /home/trafferty/.bash_aliases
ADD gitconfig /home/trafferty/.gitconfig
ADD gitignore_global /home/trafferty/.gitignore_global

WORKDIR /home/trafferty
USER trafferty