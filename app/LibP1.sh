#!/bin/bash
#script para la instalacion de xlnt y xlsxwriter 

#directorio general
cd ~

#xlnt

#actualizamos repositorios
sudo apt-get update
sudo apt-get upgrade 
sudo apt-get install cmake
sudo apt-get install zlibc
sudo add-apt-repository ppa:ubuntu-toolchain-r/test
sudo apt update
sudo apt-get upgrade
sudo apt-get install g++
sudo apt install libomp-dev
sudo apt-get install libopenmpi-dev
sudo apt-get install wget
wget https://github.com/tfussell/xlnt/archive/master.zip
cd ~
unzip master.zip
cd xlnt-master
cmake .
make -j 2
sudo make install
sudo ldconfig

#segunda libreria xlsxwriter
cd 
sudo apt-get install -y zlib1g-dev
git clone https://github.com/jmcnamara/libxlsxwriter.git 
cd libxlsxwriter
make 
sudo make install
sudo ldconfig
#y eso es todo :D
