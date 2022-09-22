#!/bin/sh

gcc -o 04-03-00_queue ../src/04-03-00_queue.c
./04-03-00_queue << EOF
5 100
p1 150
p2 80
p3 200
p4 350
p5 20
EOF
