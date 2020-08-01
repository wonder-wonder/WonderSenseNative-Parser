#!/usr/bin/bash

mkdir -p build
cd build
cmake ..
make

if [[ $? -eq 0 ]]; then
  make test
fi
