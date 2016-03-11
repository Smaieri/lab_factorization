#include"Reciprocal.h"


	void Reciprocal::start() {

		for (size_t i = 0; i < pres * 2; i++)
			num.number.insert(num.number.begin(), 0);

		size_t i = num.number.size() - 1;

		z = 32 / (4 * num.number[i] + 3 * num.number[i - 1] + num.number[i - 3]);
		z.changeBaseTo(2);
		deg = 2;
		k = 0;
		deg2k = 1;
		t = 1;


	}
	bool Reciprocal::R2() {

		KarM z2(1, 2);
		z2 = z * z;
		int deg_z2 = deg + deg;


		vector<long long int> Vk_;

		t *= 2;
		t += 3;
		size_t dif = 0;
		for (size_t j = t; j >= 1; j--)
			Vk_.push_back(num.number[num.number.size() - j]);

		KarM Vk(Vk_, 2);
		int deg_Vk = Vk.number.size();

		KarM mul(1, 2);;
		mul = Vk * z2;
		int
			deg_mul = deg_Vk + deg_z2,
			deg_2z = deg - 1;
		if (deg_mul >= deg_2z) {
			for (int i = 1; i <= deg_mul - deg_2z; i++)
				z.number.insert(z.number.begin(), 0);

			z = z - mul;


			deg = deg_mul;
		}
		else {
			for (int i = 1; i <= deg_mul - deg_2z; i++)
				mul.number.insert(mul.number.begin(), 0);
			z = z - mul;
		}

		for (size_t i = 0; i < deg - (t - 2); i++)
			z.number.erase(z.number.begin());
		deg = t - 2;
		k++;
		t -= 3;

		deg2k = deg2k * KarM(2, 2);
		if (deg2k < pres)
			return true;
		else
			return false;


	}
	KarM Reciprocal::getNumber()const {
		return z;
	}
	Reciprocal::Reciprocal(KarM num_, int pres_) {
		num = num_;
		num_size = num.number.size();
		pres = pres_;
		num.changeBaseTo(2);
	}
	void Reciprocal::find_bin() {

		start();
		while (R2());

	}
	void Reciprocal::find_dec() {

		find_bin();
		int deg_ = getDeg();
		KarM r(1);
		for (int i = 1; i <= deg_; i++)
			r = r * KarM(5);
		z = z * r;
		z.changeBaseTo(10);
		deg = deg_;
		num_size = 0;

	}
	int Reciprocal::getDeg()const {
		return deg + num_size;
	}
	