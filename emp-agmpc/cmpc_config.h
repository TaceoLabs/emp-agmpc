#ifndef __CMPC_CONFIG
#define __CMPC_CONFIG
const static int abit_block_size = 1024;
const static int fpre_threads = 1;
// #define LOCALHOST

#ifdef __clang__
	#define __MORE_FLUSH
#endif

//#define __debug
const static char *IP[] = {
    "127.0.0.1",
    "127.0.0.1",
    "127.0.0.1",
    "127.0.0.1",
    "127.0.0.1",
    "127.0.0.1",
    "127.0.0.1",
    "127.0.0.1",
    "127.0.0.1",
    "127.0.0.1",
    "127.0.0.1",
    "127.0.0.1",
    "127.0.0.1",
    "127.0.0.1",
    "127.0.0.1",
    "127.0.0.1",
};

const static int PORT[] = {
    12000,
    12100,
    12200,
    12300,
    12400,
    12500,
    12600,
    12700,
    12800,
    12900,
    13000,
    13100,
    13200,
    13300,
    13400,
    13500,
    13600,
};

const static bool lan_network = false;
#endif// __C2PC_CONFIG
