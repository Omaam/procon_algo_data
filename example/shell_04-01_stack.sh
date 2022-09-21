#!/bin/sh

gcc -o 04-01_stack ../src/04-01_stack.c
./04-01_stack << EOF
1 2 + 3 4 - *
EOF
