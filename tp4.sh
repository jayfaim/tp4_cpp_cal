#! /bin/bash
#g++ -o tp4 ./tp4.cpp ./tp4.hpp -std=c++11
#./tp4
#!/bin/bash
# Commande pour compiler un programme c++
#g++ --std=c++11 -c main.cpp fonctions.cpp #  <---------------- UBUNTU
g++ -o start  ./tp4.cpp ./tp4.hpp #<--------------------- Mint / Cygwin
sleep 2
./start.exe
exit 0