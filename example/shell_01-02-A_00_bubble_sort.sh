#!/bin/sh

g++ -o bubble_sort ../src/bubble_sort.cc
./bubble_sort << EOF
5
3 9 8 10 3
EOF
