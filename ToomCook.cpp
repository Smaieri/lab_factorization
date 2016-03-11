#include "ToomCook.h"

	ToomCook::ToomCook(LongNumber n1) {
		base = n1.getBase();
		number = n1.number;
	}
	ToomCook::ToomCook(vector<long long int> &number_, bool digit_ , const int &base_ ) :
		LongNumber(number_, digit_, base_) {};
	ToomCook::ToomCook(long long int s, const int &base_) :
		LongNumber(s, base_) {};
	void ToomCook::theSameLength(LongNumber& n1, LongNumber& n2) {

		size_t max = n1.size();

		if (max < n2.size())
			max = n2.size();

		while (max % 3 != 0)
			max++;
		long long int
			k1 = n1.size(),
			k2 = n2.size();
		for (int i = 1; i <= max - k1; i++)
			n1.addZero();

		for (int i = 1; i <= max - k2; i++)
			n2.addZero();


	}
	void ToomCook::normolize(LongNumber&n1) {
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
	LongNumber ToomCook::multiplication(LongNumber n1, LongNumber n2) {


		if (n1 == 0 || n2 == 0)
			return 0;
		size_t max = n1.size();

		if (max < n2.size())
			max = n2.size();
		if (max == 1)
			return n1.number[0] * n2.number[0];

		theSameLength(n1, n2);

		size_t
			length = n1.size(),
			k = length / 3;
		vector<long long int>
			U0_{ n1.number.begin(),  n1.number.begin() + k },
			U1_{ n1.number.begin() + k, n1.number.begin() + 2 * k },
			U2_{ n1.number.begin() + 2 * k , n1.number.end() },
			V0_{ n2.number.begin(),  n2.number.begin() + k },
			V1_{ n2.number.begin() + k, n2.number.begin() + 2 * k },
			V2_{ n2.number.begin() + 2 * k , n2.number.end() };

		LongNumber
			U0(U0_),
			U1(U1_),
			U2(U2_),
			V0(V0_),
			V1(V1_),
			V2(V2_);

		vector <LongNumber> W(5);
		for (long long int i = 0; i <= 4; i++) {
			LongNumber a1, a2, a3, a4, a5, a6;
			a1 = multiplication(U2, LongNumber(i*i, U2.getBase()));
			a2 = multiplication(U1, LongNumber(i, U1.getBase()));
			a4 = multiplication(V2, LongNumber(i*i, V2.getBase()));
			a5 = multiplication(V1, LongNumber(i, V1.getBase()));

			a3 = a1 + a2 + U0;
			a6 = a4 + a5 + V0;

			W[i] = multiplication(a3, a6);
		}
		vector <LongNumber> W_(5);
		W_ = W;
		for (int i = 1; i <= 4; i++) {
			for (size_t j = i; j < W.size(); j++)
				W_[j] = (W[j - 1] - W[j]) / i;
			W = W_;
		}
		int i = W.size();
		i *= -1;
		i += 2;

		for (; i <= -1; i++) {
			vector <LongNumber> W_(5);
			W_ = W;
			for (int j = 1; j <= i + W_.size() - 1; j++) {
				LongNumber a = multiplication(W[W_.size() - j], LongNumber(i, W_[0].getBase()));
				W_[W_.size() - 1 - j] = W_[W_.size() - 1 - j] - a;
			}
			W = W_;
		}
		for (size_t i = 0; i < W.size(); i++)
			deleteUnpleasantZeros(W[i]);

		vector <long long int> an(2 * length);

		for (size_t i = 0; i < W.size(); i++)

			for (size_t j = i * k; j < i* k + W[i].number.size(); j++)
				if (j - i * k < W[i].number.size())
					an[j] += W[i].number[j - i * k];

		LongNumber num(an, W[0].getBase());
		normolize(num);
		deleteUnpleasantZeros(num);
		return num;
	}
	LongNumber ToomCook:: operator * (LongNumber &n2) {
		return multiplication(*this, n2);
	}
