#include "LongNumber.h"




	
	bool LongNumber::isPositive() const {
		return digit;
	}
	LongNumber LongNumber::operator *(LongNumber &n2) {
		return 1;
	};
	LongNumber::LongNumber() {
		base = BASE_STANDART;
		digit = true;

	}
	LongNumber::LongNumber(vector<long long int> &number_, bool digit_, const int &base_) {
		base = base_;
		digit = digit_;
		number = number_;

	}
	LongNumber::LongNumber(long long int s, const int &base_) {

		base = base_;
		if (s >= 0)
			digit = true;
		else {
			digit = false;
			s = -s;
		}
		if (s == 0)
			number.push_back(0);
		while (s) {
			number.push_back(s % base);
			s = s / base;
		}

	}
	LongNumber LongNumber:: operator -() {
		digit = !digit;
		return *this;
	}
	LongNumber LongNumber::sumPosPos(LongNumber n1, LongNumber n2) {
		size_t  min = n1.size();

		if (min > n2.size())
			min = n2.size();
		int r = 0,
			s;
		LongNumber num;
		for (size_t i = 0; i < min; i++) {

			s = n1.number[i] + n2.number[i];
			num.number.push_back((s + r) % base);
			r = (s + r) / base;
		}
		if (n1.size() < n2.size()) {
			for (size_t j = min; j < n2.size(); j++) {

				s = n2.number[j] + r;
				num.number.push_back(s % base);
				r = s / base;
			}
			if (r != 0)
				num.number.push_back(r);
		}
		else if (n1.size() > n2.size()) {
			for (size_t j = min; j < n1.size(); j++) {
				s = n1.number[j] + r;
				num.number.push_back(s % base);
				r = s / base;
			}
			if (r != 0)
				num.number.push_back(r);
		}
		else if (r != 0)
			num.number.push_back(r);
		return num;
	}
	LongNumber LongNumber::minPosPos(LongNumber n1, LongNumber n2) {
		if (n1 < n2)
			return -minPosPos(n2, n1);
		else if (n1 == n2)
			return LongNumber(0, n1.getBase());
		LongNumber num;

		for (size_t j = 0; j < n2.size(); j++) {

			if (n1.number[j] >= n2.number[j])
				num.number.push_back(n1.number[j] - n2.number[j]);
			else {
				n1.number[j] += n1.getBase();
				size_t k = j + 1;
				if (n1.number[k] == 0) {
					while (n1.number[k] == 0) {
						n1.number[k] = n1.getBase() - 1;
						k++;
					}
					n1.number[k]--;

				}
				else n1.number[k] -= 1;

				num.number.push_back(n1.number[j] - n2.number[j]);
			}

		}

		for (size_t j = n2.size(); j < n1.size(); j++)

			num.number.push_back(n1.number[j]);

		deleteUnpleasantZeros(num);

		return num;
	}
	

	int LongNumber::getBase()const {
		return base;
	}
	void LongNumber::addZero() {
		number.push_back(0);
	}
	size_t LongNumber::size()const {
		return number.size();
	}
	LongNumber::~LongNumber() {
		number.clear();
	}
	
	void LongNumber::changeBaseTo(int b) {
		if (b != base) {
			vector<long long int> tmt;
			do {
				LongNumber t;
				t = *this % b;
				for (long long int i = 0; i < b; i++)
					if (t == i) {
						tmt.push_back(i);
						break;
					}
				*this = *this / b;

			} while (*this > 0);

			number = tmt;
			base = b;
		}
	}
