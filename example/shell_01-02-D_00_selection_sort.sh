#!/bin/sh

g++ -o selection_sort ../src/selection_sort.cc
./selection_sort << EOF
6
5 6 4 2 1 3
EOF
