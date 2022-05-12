#! /bin/bash

./install.sh  &> log_files/log_file_install.txt;
cd bin;
./proj  &> ../log_files/log_file_exe.txt;
cd ..;
