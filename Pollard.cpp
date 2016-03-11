#pragma once
#include "Pollard.h"


	LongNumber Pollard:: GCD(LongNumber a, LongNumber b)
	{
		LongNumber
			t;

		while (b != 0)
		{
			t = a % b;
			a = b;
			b = t;
		}

		return a;
	}
	bool Pollard::isPrime(LongNumber n) {//we don`t control, it is very long
		if (n == 2)
			return true;
		else if (n == 3)
			return true;
		else if (n == 5)
			return true;


		for (size_t i = 2; i < n / 2; i++)
			if (n % i == 0)
				return false;

		return true;

	}
	Pollard::Pollard(const LongNumber &n) {
		number = n;
	}
	LongNumber Pollard::factor() {
		vector<KarM> xi;
		xi.push_back(rand() % number);
		size_t i = 0;
		while (true) {

			xi.push_back((xi[i] * xi[i] + 1) % number);
			i++;
			for (size_t j = 0; j < i; j++) {
				KarM tmt;
				xi[j] > xi[i] ? tmt = xi[j] - xi[i] : tmt = xi[i] - xi[j];
				if (tmt == 0)
					return factor();
				else {
					tmt = GCD(tmt, number);
					if (tmt > 1 && tmt < number)
						return tmt;
				}

			}

		}

	}
