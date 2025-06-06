#!/bin/sh
mkdir -p build

# Compile using clang++ and LLVM
clang++ -std=c++20 -Iinclude src/*.cc main.cc -o build/kea.exe \
  $(llvm-config --cxxflags --ldflags --system-libs --libs core)

# Exit status check
if [ $? -eq 0 ]; then
  echo " Build succeeded!"
else
  echo " Build failed!"
  exit 1
fi
