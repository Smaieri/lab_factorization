#pragma once
#include <iostream>
#include "Reciprocal.h"
using namespace std;

class DivisionCook {

	KarM
		n1,
		n2,
		n;
	int
		pres,
		deg;
public:
	int getDeg()const;
	DivisionCook(KarM n1_, KarM n2_, int pres_);
	void find_dec();
	void find_bin();

	friend ostream &operator<<(ostream &output, const DivisionCook & m) {

		if (m.getDeg() <= m.n.number.size()) {
			for (int i = m.n.size() - 1; i >= m.getDeg(); i--)
				output << m.n.number[i];

			output << '.';
			for (int i = m.getDeg() - 1; i >= 0; i--)
				output << m.n.number[i];
		}
		else {
			output << "0.";
			for (int i = 0; i < m.getDeg() - m.n.size(); i++)
				cout << "0";
			for (int i = m.n.size() - 1; i >= 0; i--)
				output << m.n.number[i];


		}

		return output;

	}


};