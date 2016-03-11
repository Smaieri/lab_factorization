#include "DivisionCook.h"

	int DivisionCook::getDeg()const {
		return deg;
	}
	DivisionCook::DivisionCook(KarM n1_, KarM n2_, int pres_) {
		n1 = n1_;
		n2 = n2_;
		pres = pres_;
	}
	void DivisionCook::find_dec() {
		Reciprocal d(n2, pres);
		d.find_bin();
		deg = d.getDeg();
		n2 = d.getNumber();
		n = n1 * n2;

		KarM r(1);
		for (int i = 1; i <= deg; i++)
			r = r * KarM(5);
		n = n * r;
		n.changeBaseTo(10);
	}
	void DivisionCook::find_bin() {
		Reciprocal d(n2, pres);
		d.find_bin();
		deg = d.getDeg();
		n2 = d.getNumber();
		n = n1 * n2;

	}

