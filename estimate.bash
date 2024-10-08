#!/bin/bash

make re
./estimate.out $(./train.out 0.1 100)
