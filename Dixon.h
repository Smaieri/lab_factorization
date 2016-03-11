#pragma once
#include <math.h>
#include <vector>
#include <cstdlib>
#include "KarazubuMethod.h"
using namespace std;

class Dixon {

	vector<long long int> FBase;
	
	vector <KarM> answer;
	long long int number;
	long long int 
		balast1,
		balast2;
	
public:
	Dixon(long long int number_);
	vector<long long int> eratosphen(long long int n);
	vector<long long int> isSmoothNumber(long long int n);

	vector<long long int> gaussZeroMod2(vector<vector<long long int> > a);
	
	bool isPrime(long long int n);
	LongNumber GCD(LongNumber a, LongNumber b);
	
	vector <KarM> division();
		
	KarM getFirst()const;
	KarM getSecond()const;


};