#!/bin/sh

g++ -o 03-02_insertion_sort ../src/03-02_insertion_sort.cc
./03-02_insertion_sort << EOF
6
5 2 4 6 1 3
EOF
