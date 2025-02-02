#!/bin/bash

echo "Setting up C++ for dev."
sudo apt-get install clang clang-tidy gdb valgrind -y
sudo apt-get autoremove -y
sudo apt-get clean
echo "Done."