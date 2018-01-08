#!/usr/bin/env sh
 #before_install script for travis.ci
sudo add-apt-repository --yes ppa:ubuntu-sdk-team/ppa
sudo add-apt-repository -y ppa:ubuntu-toolchain-r/test
sudo apt-get update -qq
sudo apt-get install qtbase5-dev qtdeclarative5-dev libqt5webkit5-dev libsqlite3-dev
sudo apt-get install qt5-default qttools5-dev-tools