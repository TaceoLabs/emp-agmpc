#!/usr/bin/env bash
python3 install.py --tool --ot
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX=../install/ ..
make -j4
