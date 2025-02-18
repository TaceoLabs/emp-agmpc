#ifndef EMP_AGMPC_TEST_H__
#define EMP_AGMPC_TEST_H__
const string circuit_file_location = macro_xstr(EMP_CIRCUIT_PATH) + string("bristol_format/");


template<int nP>
int communication(NetIOMP<nP> * ios[2]) {
	return ios[0]->count() + ios[1]->count();
}

template<int nP>
void bench_once(int party, NetIOMP<nP> * ios[2], ThreadPool * pool, string filename) {
	cout <<"CIRCUIT:    "<<filename<<endl;
	//string file = circuit_file_location+"/"+filename;
	BristolFormat cf(filename.c_str());

    double offline = 0.;
	auto start = clock_start();
	CMPC<nP>* mpc = new CMPC<nP>(ios, pool, party, &cf);
	ios[0]->flush();
	ios[1]->flush();
	double t2 = time_from(start);
//	ios[0]->sync();
//	ios[1]->sync();
	cout <<"Setup   :    "<<t2/1000.<<" ms\n"<<flush;
    offline += t2;

	start = clock_start();
	mpc->function_independent();
	ios[0]->flush();
	ios[1]->flush();
	t2 = time_from(start);
	cout <<"FUNC_IND:    "<<t2/1000.<<" ms\n"<<flush;
    offline += t2;

	start = clock_start();
	mpc->function_dependent();
	ios[0]->flush();
	ios[1]->flush();
	t2 = time_from(start);
	cout <<"FUNC_DEP:    "<<t2/1000.<<" ms\n"<<flush;
    offline += t2;
    cout <<"OFFLINE:     "<<offline/1000.<<" ms\n"<<flush;
	cout << "Offline Communication:    "<<communication<nP>(ios)/1000.0/1000.0<<" MB"<<endl;

	bool *in = new bool[cf.n1+cf.n2]; bool *out = new bool[cf.n3];
	memset(in, false, cf.n1+cf.n2);
	start = clock_start();
	mpc->online(in, out);
	ios[0]->flush();
	ios[1]->flush();
	t2 = time_from(start);
    //	uint64_t band2 = io.count();
    //	if(party == 1)cout <<"bandwidth    "<<band2<<endl;
    cout <<"ONLINE:      "<<t2/1000.<<" ms\n"<<flush;
    cout <<"TOTAL:       " <<(t2+offline)/1000.<<" ms\n"<<flush;
	cout << "Total Communication:    "<<communication<nP>(ios)/1000.0/1000.0<<" MB"<<endl;
	delete mpc;
}

#endif// EMP_AGMPC_TEST_HHH
