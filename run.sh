#!/bin/bash

filepath=$1
filedir=$(dirname $filepath)
outname="$filedir/program"
printf "Performing static analysis, compiling to $outname and Debug executing $filepath using valgrind \n"

printf "Running clang-tidy for static analysis \n"
clang-tidy "$filepath" -- -std=c++23

printf "Running clang++ to generate compiled executable \n"
clang++ -std=c++23 -Wall -Wno-missing-prototypes -pedantic -O1 -g -o "$outname" "$filepath" #O1 because valgrind can use it for better error messages https://valgrind.org/docs/manual/quick-start.html#quick-start.intro

printf "Debug running $outname (in local testing mode) with valgrind \n"
ulimit -n 1024 && valgrind --leak-check=full --show-leak-kinds=all "$outname" "LOCAL" #Local is an arg for local test mode, as is defined in the files. The ulimit is set because valgrind doesn't like huge file descriptor limits, https://stackoverflow.com/a/75293014/13036358
