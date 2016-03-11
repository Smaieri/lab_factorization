#pragma once
#include "Dixon.h"


	Dixon::Dixon(long long int number_) {
		number = number_;
		balast1 = 1;
		balast2 = 1;
		answer.push_back(1);
		answer.push_back(1);
		bool isBalast1 = false;
		vector <int> g = { 2,3,5,7,11,13,17 };

		for (int i = 0; i < g.size(); i++)
			while (number %g[i] == 0)
			{
				if (isBalast1) {
					balast2 *= g[i];
					number = number / g[i];
				}
				else {
					isBalast1 = true;
					balast1 *= g[i];
					number = number / g[i];

				}
			}


	}
	vector<long long int> Dixon::eratosphen(long long int n) {

		vector<long long int>
			FBase_(n + 1);

		for (long long int i = 2; i <= n; i++) {

			if (FBase_[i] == 1)
				continue;

			for (long long int j = i + 1; j <= n; j++)
				if (j%i == 0 && FBase_[j] == 0)
					FBase_[j] = 1;
		}

		vector <long long int>
			F;
		for (long long int i = 2; i <= n; i++) {

			if (FBase_[i] == 0)
				F.push_back(i);

		}
		return F;
	}
	vector<long long int> Dixon::isSmoothNumber(long long int n) {//vec[0]==-1 if non

		vector <long long int>
			vec(FBase.size());

		for (long long int i = 0; i < FBase.size(); i++)
			while (n % FBase[i] == 0 && n > 1) {
				vec[i]++;
				n /= FBase[i];
			}
		if (n > 1)
			vec[0] = -1;

		return vec;
	}
	vector<long long int> Dixon::gaussZeroMod2(vector<vector<long long int> > a) {

		long long int k = a[0].size();


		for (long long int i = 0; i < a.size(); i++)
			for (long long int j = 0; j < a[i].size(); j++)
				a[i][j] = a[i][j] % 2;


		long long int position = -1;

		for (long long int i = 0; i < a.size(); i++) {

			for (long long j = position + 1; j < a[i].size(); j++) {
				if (a[i][j]) {
					position = j;

					for (long long int h = 0; h < i; h++)
						if (a[h][j])
							for (long long r = j; r < a[i].size(); r++)
								a[h][r] = (a[h][r] + a[i][r]) % 2;
					for (long long int h = i + 1; h < a.size(); h++)
						if (a[h][j])
							for (long long r = j; r < a[i].size(); r++)
								a[h][r] = (a[h][r] + a[i][r]) % 2;
					break;
				}
				else {
					long long int m;
					for (m = i + 1; m < a.size(); m++) {

						if (a[m][j]) {
							long long int tmt;
							for (long long int r = j; r < a[i].size(); r++) {
								tmt = a[i][r];
								a[i][r] = a[m][r];
								a[m][r] = tmt;
							}

							position = j;

							for (long long int h = 0; h < i; h++)
								if (a[h][j])
									for (long long r = j; r < a[i].size(); r++)
										a[h][r] = (a[h][r] + a[i][r]) % 2;
							for (long long int h = i + 1; h < a.size(); h++)
								if (a[h][j])
									for (long long r = j; r < a[i].size(); r++)
										a[h][r] = (a[h][r] + a[i][r]) % 2;
							j = a[0].size() - 1;
							break;
						}

						if (m == a.size() - 1) {
							position++;

						}

					}

				}

				if (position >= a[0].size() - 1)
					break;



			}
		}

		vector<long long int> vec(k);// 0 - independent, 1 - dependent
		position = -1;

		for (long long int i = 0; i < a.size(); i++) {
			for (long long j = position + 1; j < a[i].size(); j++)
				if (a[i][j]) {
					position = j;
					vec[j] = 1;
					break;
				}
		}

		vector<long long int> answers(k);

		for (long long int i = 0; i < answers.size(); i++)
			if (!vec[i])
				answers[i] = 1;
		position = -1;

		for (long long int i = 0; i < a.size(); i++) {
			for (long long j = position + 1; j < a[i].size(); j++)
				if (a[i][j] && vec[j] == 1) {
					position = j;
					long long int sum = 0;
					for (long long int r = j + 1; r < a[i].size(); r++)
						sum += a[i][r] * answers[r];

					answers[j] = sum % 2;
					break;
				}
		}

		return
			answers;


	}

	bool Dixon::isPrime(long long int n) {
		if (n == 2)
			return true;
		else if (n == 3)
			return true;
		else if (n == 5)
			return true;


		for (long long int i = 2; i < n / 2; i++)
			if (n % i == 0)
				return false;

		return true;

	}
	LongNumber Dixon::GCD(LongNumber a, LongNumber b)
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

	vector <KarM> Dixon::division() {

		long long int  L = sqrt(exp(sqrt(log(number)* log(log(number)))));
		FBase = eratosphen(L);

		for (long long int i = 0; i < FBase.size(); i++) {
			if (balast1 > 1)
				while (number% FBase[i] == 0) {

					number /= FBase[i];
					balast2 *= FBase[i];

				}
			else
				while (number% FBase[i] == 0) {

					number /= FBase[i];

					if (balast1 > 1)
						balast2 *= FBase[i];
					else
						balast1 *= FBase[i];
				}


		}


		if (isPrime(number)) {
			answer[0] = balast1;
			answer[1] = number * balast2;
			return answer;
		}

		if (number == 1) {
			answer[0] = balast1;
			answer[1] = balast2;
			return answer;
		}

		vector <long long int>
			vecMi(FBase.size() + 1);


		vector < vector<long long int> > Matrix;

		long long int counter = 0;

		while (counter < vecMi.size()) {
			long long int con = sqrt(number);
			long long int mi = rand() % (number - con - 1) + con + 1;

			vector <long long int>
				vec = isSmoothNumber(mi*mi % number);

			for (long long int r = 0; r < vecMi.size(); r++)
				if (mi == vecMi[r]) {
					vec[0] = -1;
					break;
				}

			if (vec[0] >= 0) {

				vecMi[counter] = mi;

				Matrix.push_back(vec);

				counter++;
			}

		}

		vector < vector<long long int> > Matrix_;

		for (long long int j = 0; j < Matrix[0].size(); j++) {

			vector<long long int> tmt(Matrix.size());

			for (long long int i = 0; i < tmt.size(); i++)
				tmt[i] = Matrix[i][j];

			Matrix_.push_back(tmt);

		}

		vector <long long int>
			solution = gaussZeroMod2(Matrix_);


		KarM
			x(1),
			y(1);

		for (long long int i = 0; i < vecMi.size(); i++)
			for (long long int j = 0; j < solution[i]; j++)
				x = x * vecMi[i];



		for (long long i = 0; i < FBase.size(); i++) {
			long long int degree = 0;

			for (long long j = 0; j < Matrix.size(); j++)
				degree += Matrix[j][i] * solution[j];

			degree /= 2;

			for (long long int j = 0; j < degree; j++)
				y = y * FBase[i];
		}

		if (x < y) {
			KarM t = x;
			x = y;
			y = t;
		}



		answer[0] = GCD(x + y, number);
		answer[1] = GCD(x - y, number);


		if (answer[0] > 1 && answer[0] < number &&
			answer[1] > 1 && answer[1] < number) {

			answer[0] = answer[0] * balast1;
			answer[1] = answer[1] * balast2;
			return answer;

		}
		else {
			answer[0] = 1;
			answer[1] = 1;
			return division();
		}
	}

	KarM Dixon::getFirst()const { 
		return answer[0]; 
	}
	KarM Dixon::getSecond()const { 
		return answer[1]; 
	}

