#!/bin/bash

make re CPPFLAGS+=' -DGNUPLOT'
./train.out 0.1 100 > training_output.txt
gnuplot plot.plt
