#!/bin/bash

# g++ --help -v 2>/dev/null|grep std=
VERSION="-std=c++23"

# MAKE DIRECTORY
cd ..
mkdir build
mkdir build/debug

# COMPILE UTILITES INTO LIB
echo "Compiling Utilites..."
cd packages/utilities/
g++ $VERSION -c *.cpp 
ar rvs utilities.a *.o
mv *.o *.a ../../build/debug/
cd .. 
cd ..

# COMPILE STRUCTURES INTO LIB

# COMPILE SOLUTIONS
echo "Compiling Solutions..."
cd ./source/solutions
g++ $VERSION -c *.cpp
mv *.o ../../build/debug/
cd ..
cd ..

# COMPILE SOURCE
echo "Compiling Source..."
cd ./source
g++ $VERSION -c *.cpp
mv *.o ../build/debug/
cp *.txt ../build/debug/
cd ..

# LINK AND COMPILE BINARY
g++ $VERSION \
        ./build/debug/*.o \
        ./build/debug/utilities.a \
    -o ./build/debug/AdventOfCode.exe  

# Execute Binary
# cd ./build/debug/
# ./build/debug/AdventOfCode.exe
./build/debug/AdventOfCode.exe --solution01
# ./build/debug/AdventOfCode.exe --solution01 --sample