#!/usr/python
import subprocess
import os
install_packages = '''
if [ "$(uname)" == "Darwin" ]; then
	brew list openssl || brew install openssl
 	brew list pkg-config || brew install pkg-config
 	brew list cmake || brew install cmake
else
    if command -v apt-get >/dev/null; then
        sudo apt-get install -y software-properties-common
        sudo apt-get update
        sudo apt-get install -y cmake git build-essential libssl-dev
    elif command -v yum >/dev/null; then
        sudo yum install -y python3 gcc make git cmake gcc-c++ openssl-devel
    else
        echo "System not supported yet!"
    fi
fi
'''

wd = os.getcwd()

install_template = '''
git clone https://github.com/emp-toolkit/xxx.git --branch yyy
cd xxx
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX=DIRDIR/install/ ..
make -j4
make install
cd ../..
'''

import argparse
parser = argparse.ArgumentParser()
parser.add_argument('-install', '--install', action='store_true')
parser.add_argument('-deps', '--deps', action='store_true')
parser.add_argument('--tool', nargs='?', const='master')
parser.add_argument('--ot', nargs='?', const='master')
parser.add_argument('--sh2pc', nargs='?', const='master')
parser.add_argument('--ag2pc', nargs='?', const='master')
parser.add_argument('--agmpc', nargs='?', const='master')
parser.add_argument('--zk', nargs='?', const='master')
args = parser.parse_args()

if vars(args)['install'] or vars(args)['deps']:
	subprocess.call(["bash", "-c", install_packages])

for k in ['tool', 'ot', 'zk', 'sh2pc', 'ag2pc', 'agmpc']:
	if vars(args)[k]:
		template = install_template.replace("xxx", "emp-"+k).replace("yyy", vars(args)[k]).replace("DIRDIR", wd)
		print(template)
		subprocess.call(["bash", "-c", template])
