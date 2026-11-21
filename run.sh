#!/bin/bash
set -e   # stop immediately if any command fails

if [ ! -f "build/CMakeCache.txt" ]; then
  cmake -S . -B build
fi

cmake --build build

./build/bin/main