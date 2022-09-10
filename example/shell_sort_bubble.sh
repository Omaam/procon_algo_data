#!/bin/sh

g++ -o sort_bubble ../src/sort_bubble.cc
./sort_bubble << EOF
5
3 9 8 10 3
EOF
