# one time setup

```bash
python3 install.py --tool --ot
```

# compile

```bash
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX=../install/ ..
make -j4
```

Executable is then in build/bin/test_sha256:

Usage: build/bin/test_sha256 <party> <num_parties> <threads>

# network config

emp-agmpc/cmpc_config.h

# example

see test_local.sh
