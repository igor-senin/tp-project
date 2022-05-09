#! /bin/bash

./install.sh &> log_file.txt
cd bin
./proj &>> log_file.txt
cd ..
