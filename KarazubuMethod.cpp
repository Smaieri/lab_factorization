#include "KarazubuMethod.h"

	void KarM::theSameLength(LongNumber& n1, LongNumber& n2) {

		size_t max = n1.size();

		if (max < n2.size())
			max = n2.size();

		if (max % 2 != 0)
			max++;
		long long int
			k1 = n1.size(),
			k2 = n2.size();
		for (int i = 1; i <= max - k1; i++)
			n1.addZero();

		for (int i = 1; i <= max - k2; i++)
			n2.addZero();


	}
	LongNumber KarM::multiplication(LongNumber &n1, LongNumber &n2) {
		LongNumber zero(0);
		if (n1 == zero || n2 == zero)
			return zero;
		size_t max = n1.size();

		if (max < n2.size())
			max = n2.size();
		if (max == 1) {
			LongNumber num(n1.number[0] * n2.number[0]);
			return num;
		}
		theSameLength(n1, n2);
		max = n1.size();

		size_t
			k = max / 2;

		vector<long long int>
			Xr_{ n1.number.begin(),  n1.number.begin() + k },
			Xl_{ n1.number.begin() + k,  n1.number.end() },
			Yr_{ n2.number.begin(), n2.number.begin() + k },
			Yl_{ n2.number.begin() + k, n2.number.end() };

		LongNumber
			Xr(Xr_),
			Xl(Xl_),
			Yr(Yr_),
			Yl(Yl_);

		LongNumber
			Prod1 = multiplication(Xl, Yl),
			Prod2 = multiplication(Xr, Yr),
			Prod3 = multiplication(Xl + Xr, Yl + Yr);

		deleteUnpleasantZeros(Prod1);
		deleteUnpleasantZeros(Prod2);
		deleteUnpleasantZeros(Prod3);
		vector<long long int> Pr1;
		for (int i = 0; i < max; i++)
			Pr1.push_back(0);
		for (int i = max; i < max + Prod1.number.size(); i++)
			Pr1.push_back(Prod1.number[i - max]);

		Prod3 = Prod3 - Prod2 - Prod1;

		vector <long long int> Pr3;
		for (int i = 0; i < max / 2; i++)
			Pr3.push_back(0);
		for (int i = max / 2; i < max / 2 + Prod3.number.size(); i++)
			Pr3.push_back(Prod3.number[i - max / 2]);
		LongNumber Pr1_(Pr1),
			Pr3_(Pr3),
			rez;

		rez = Pr1_ + Prod2 + Pr3_;


		return rez;

	}
	void KarM::normolize(LongNumber&n1) {
		int r = 0,
			s;
		for (int j = 0; j < n1.size(); j++) {
			s = n1.number[j] + r;
			n1.number[j] = s % n1.getBase();
			r = s / n1.getBase();
		}
		if (r != 0)
			n1.number.push_back(r);

	}
	LongNumber KarM::operator *(LongNumber &n2) {

		LongNumber rez = multiplication(*this, n2);
		normolize(rez);
		deleteUnpleasantZeros(rez);
		return rez;
	}
	
	KarM::KarM(LongNumber n1) {
		base = n1.getBase();
		number = n1.number;
	}
	KarM::KarM(vector<long long int> &number_, bool digit_, const int &base_) :
		LongNumber(number_, digit_, base_) {};
	KarM::KarM(long long int s, const int &base_) :
		LongNumber(s, base_) {};
