#pragma once
#include "KarazubuMethod.h"

class Pollard {
	LongNumber number;
	LongNumber GCD(LongNumber a, LongNumber b);
	bool isPrime(LongNumber n);
public:
	Pollard(const LongNumber &n);
	LongNumber factor();
};