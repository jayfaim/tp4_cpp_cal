#! /bin/bash
#g++ -o tp4 ./tp4.cpp ./tp4.hpp -std=c++11
#./tp4

#!/bin/bash
# Commande pour compiler un programme c++
#g++ --std=c++11 -c main.cpp fonctions.cpp #  <---------------- UBUNTU
g++ -c tp4.cpp #<--------------------- Mint / Cygwin
sleep 1
g++ -o start tp4.o
./start.exe
exit 0