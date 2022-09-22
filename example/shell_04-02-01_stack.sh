#!/bin/sh

g++ -o 04-01-01_stack ../src/04-01-01_stack.cc
./04-01-01_stack << EOF
1 2 + 3 4 - *
EOF
