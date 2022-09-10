#!/bin/sh

g++ -o sort_select ../src/sort_select.cc
./sort_select << EOF
< enter input >
EOF
