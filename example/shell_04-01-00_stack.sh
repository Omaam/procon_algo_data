#!/bin/sh

gcc -o 04-01-00_stack ../src/04-01-00_stack.c
./04-01-00_stack << EOF
1 2 + 3 4 - *
EOF
