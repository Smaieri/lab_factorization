#pragma once
#include <vector>
#include<string>
#include"LongNumber.h"
#include <ostream>
using namespace std;


class KarM : public LongNumber {
public:
	void theSameLength(LongNumber& n1, LongNumber& n2);
	LongNumber multiplication(LongNumber &n1, LongNumber &n2);
	void normolize(LongNumber&n1);
	LongNumber operator *(LongNumber &n2);
    friend LongNumber operator *(KarM &n1, KarM &n2) {
		
		LongNumber
			n2_(n2.number, n2.getBase());
		return n1 * n2_;

	}
	friend LongNumber operator *(KarM &n1, long long int &n2) {
		LongNumber n2_(n2, n1.getBase());
			return n1 * n2_;

	}
	KarM() :LongNumber(){}
	KarM(LongNumber n1);
	KarM(vector<long long int> &number_, bool digit_ = true, const int &base_ = BASE_STANDART);
	KarM(long long int s, const int &base_ = BASE_STANDART);

};