#pragma once
#include "LongNumber.h"
#include "KarazubuMethod.h"
class Reciprocal {
	
	KarM
		z,
		deg2k;
		
	int deg,
		pres,
		k,
		num_size;
	size_t t;//2^(k+1)

	
	void start();
	bool R2();
public:
	KarM
		num;
	KarM getNumber()const;
	Reciprocal(KarM num_, int pres_);
	void find_bin();
	void find_dec();
	int getDeg()const;
	friend ostream &operator<<(ostream &output, const Reciprocal &n) {
		
		if (n.getDeg() <= n.z.number.size()) {
			for (int i = n.z.size() - 1; i >= n.getDeg(); i--)
				output << n.z.number[i];

			output << '.';
			for (int i = n.getDeg() - 1; i >= 0; i--)
				output << n.z.number[i];
		}
		else {
			output << "0.";
			for (int i = 0; i < n.getDeg() - n.z.size(); i++)
				output << "0";
			for (int i = n.z.size() - 1; i >= 0; i--)
				output << n.z.number[i];

		
		}

		return output;

	}


};