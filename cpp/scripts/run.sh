#!/bin/bash

# MAKE DIRECTORY
cd ..
mkdir build
mkdir build/debug

# COMPILE UTILITES INTO LIB
cd packages/utilities/
g++ -c *.cpp 
ar rvs utilities.a *.o
mv *.o *.a ../../build/debug/
cd .. 
cd ..

# COMPILE STRUCTURES INTO LIB
# COMPILE SOURCE
cd ./source
g++ -c *.cpp
mv *.o ../build/debug/
cd ..

# LINK AND COMPILE BINARY
g++ \
    ./build/debug/AdventOfCode.o \
    ./build/debug/CodeGenerator.o \
    ./build/debug/utilities.a \
    -o AdventOfCode.out 


# Execute Binary
# cd ./build/debug/
./AdventOfCode.out
# ./AdventOfCode.out --puzzle01
# ./AdventOfCode.out --puzzle01 --sample