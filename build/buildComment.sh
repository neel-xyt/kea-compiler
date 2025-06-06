#!/bin/sh
clang++ -std=c++20 -Iinclude src/*.cc main.cc -o build/kea.exe \
  `llvm-config --cxxflags --ldflags --system-libs --libs core`
