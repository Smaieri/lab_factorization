#pragma once
#include "LongNumber.h"
#include "KarazubuMethod.h"

class QS {
	vector<long long int> FBase;
	bool isPrime(long long int n);
	vector <KarM> answer;
	long long int number;
	long long int
		balast1,
		balast2;
	 int countMax_;
public:
	QS(long long int number_);
	LongNumber GCD(LongNumber a, LongNumber b);
	vector<long long int> eratosphen(long long int n);
	vector<long long int> gaussZeroMod2(vector<vector<long long int> > a);
	LongNumber LegendreSymbol(KarM a, long long int p);
	void funVectorBase(int countMAX = 4);
	vector<long long int> solve(long long int k, long long int p);
	vector<vector <long long int>>sieve();
	vector <KarM> division();

	KarM getFirst() const;
	KarM getSecond()const;


	
};