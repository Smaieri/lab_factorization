#pragma once
#include "LongNumber.h"

class ToomCook: public LongNumber{
public:
	ToomCook() :LongNumber() {};
	
	ToomCook(LongNumber n1);
	ToomCook(vector<long long int> &number_, bool digit_ = true, const int &base_ = BASE_STANDART);
	ToomCook(long long int s, const int &base_ = BASE_STANDART);
	void theSameLength(LongNumber& n1, LongNumber& n2);
	void normolize(LongNumber&n1);
	LongNumber multiplication(LongNumber n1, LongNumber n2);
	LongNumber operator * (LongNumber &n2);
	friend LongNumber operator * (LongNumber &n1, long long int n2) {
		LongNumber n2_(n2, n1.getBase());
		return n1*n2_;


	}
};