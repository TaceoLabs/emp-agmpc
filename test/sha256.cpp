#include <emp-tool/emp-tool.h>
#include "emp-agmpc/emp-agmpc.h"
#include "test/test.h"
using namespace std;
using namespace emp;


template<int nP>
int program(int party, int threads) {
    if (party > nP) {
        return 0;
    }

	NetIOMP<nP> io(party);
	NetIOMP<nP> io2(party);
	NetIOMP<nP> *ios[2] = {&io, &io2};

	ThreadPool pool(threads);

	bench_once<nP>(party, ios, &pool, circuit_file_location+"sha-256.txt");
	return 0;
}

int main(int argc, char** argv) {
    if (argc != 4) {
        std::cout << "Usage: <./bin> <party> <num_parties> <threads>" << std::endl;
        return -2;
    }
    int party = atoi(argv[1]);
    int nP = atoi(argv[2]);
    int threads = atoi(argv[3]);
    switch (nP) {
        case 2: return program<2>(party, threads);
        case 3: return program<3>(party, threads);
        case 4: return program<4>(party, threads);
        case 5: return program<5>(party, threads);
        case 6: return program<6>(party, threads);
        case 7: return program<7>(party, threads);
        case 8: return program<8>(party, threads);
        case 9: return program<9>(party, threads);
        case 10: return program<10>(party, threads);
        case 11: return program<11>(party, threads);
        case 12: return program<12>(party, threads);
        case 13: return program<13>(party, threads);
        case 14: return program<14>(party, threads);
        case 15: return program<15>(party, threads);
        case 16: return program<16>(party, threads);
    }
    std::cout << "Only max 16 parties allowed" << std::endl;
    return -1;
}
