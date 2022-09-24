#!/bin/sh

gcc -o 05-A_00_exhaustive_search ../src/05-A_00_exhaustive_search.c
./05-A_00_exhaustive_search << EOF
5
1 5 7 10 21
4
2 4 17 8
EOF
