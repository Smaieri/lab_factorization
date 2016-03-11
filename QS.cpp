#include "QS.h"

	bool QS::isPrime(long long int n) {
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
	QS::QS(long long int number_) {
		countMax_ = 4;
		number = number_;
		answer.push_back(1);
		answer.push_back(number);
		bool isBalast1 = false;
		balast1 = 1;
		balast2 = 1;
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
		if (isPrime(number)) {
			balast2 *= number;
			number = 1;
		}


	}
	LongNumber QS::GCD(LongNumber a, LongNumber b)
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
	vector<long long int> QS::eratosphen(long long int n) {

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
	vector<long long int> QS::gaussZeroMod2(vector<vector<long long int> > a) {

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
	LongNumber QS::LegendreSymbol(KarM a, long long int p) {

		KarM s(1, a.getBase());

		for (size_t i = 1; i <= (p - 1) / 2; i++)
			s = (s * a) % p;
		LongNumber r = s % p;
		if (r != 1)
			return -1;
		else
			return 1;
	}
	void QS::funVectorBase(int countMAX ) {
		long long int L = exp(sqrt(log(number) * log(log(number))));
		FBase = eratosphen(L);
		long long int count = 1;
		for (size_t i = 1; i < FBase.size(); i++) {
			if (count < countMAX) {
				LongNumber t = LegendreSymbol(number, FBase[i]);

				if (t != 1)
					FBase[i] = -1;
				else
					count++;
			}
			else
				FBase[i] = -1;

		}

		size_t k = 0;
		for (size_t i = 0; i < FBase.size(); i++)
			if (FBase[i] == -1)
				k++;
			else
				FBase[i - k] = FBase[i];

		for (size_t i = 0; i < k; i++)
			FBase.pop_back();
	}
	vector<long long int> QS::solve(long long int k, long long int p) {//y(x) = (x + k)^2 - number == 0 mod p;
		vector < long long int> answers(2);
		if (p == 2) {
			answers[0] = (number - k) % 2;
			answers[1] = -1;
			return answers;
		}
		size_t r = 0;

		for (long long int i = 0; i < p; i++)

			if ((i + k) * (i + k) % p == number % p)
				if (r == 1) {
					answers[r] = i;
					return answers;
				}
				else {
					answers[r] = i;
					r++;
				}

				return answers;


	}
	vector<vector <long long int>>QS::sieve() {
		long long int L = exp(sqrt(log(number) * log(log(number))));
		vector <long long int> V;
		long long int k = sqrt(number);
		k++;

		for (long long int i = 0; i <= L; i++)
			V.push_back((i + k) * (i + k) - number);

		for (size_t i = 0; i < FBase.size(); i++) {

			vector < long long int> answers = solve(k, FBase[i]);

			long long int j = answers[0];

			if (answers[0] > 0)
				while (j  < V.size()) {
					while (V[j] % FBase[i] == 0)
						V[j] /= FBase[i];
					j += FBase[i];

				}
			else if (answers[0] == 0)
				while (V[0] % FBase[i] == 0)
					V[0] /= FBase[i];

			j = answers[1];

			if (answers[1] > 0)
				while (j  < V.size()) {
					while (V[j] % FBase[i] == 0)
						V[j] /= FBase[i];
					j += FBase[i];
				}
			else if (answers[1] == 0)
				while (V[0] % FBase[i] == 0)
					V[0] /= FBase[i];


		}


		vector<vector <long long int>> V_;
		for (size_t i = 0; i < V.size(); i++)

			if (V[i] == 1) {

				vector<long long int> u(2);
				u[0] = i + k;
				u[1] = (i + k) * (i + k) - number;
				V_.push_back(u);

			}

		return V_;
	}
	vector <KarM>QS::division() {

		if (number == 1) {
			answer[0] = balast1;
			answer[1] = balast2;
			return answer;
		}


		long long int L = exp(sqrt(log(number) * log(log(number))));
		vector <long long int> FBase_ = eratosphen(L);

		for (long long int i = 0; i < FBase_.size(); i++) {
			if (balast1 > 1)
				while (number% FBase_[i] == 0) {

					number /= FBase_[i];
					balast2 *= FBase_[i];

				}
			else
				while (number% FBase_[i] == 0) {

					number /= FBase_[i];

					if (balast1 > 1)
						balast2 *= FBase_[i];
					else
						balast1 *= FBase_[i];
				}
		}

		if (number == 1) {
			answer[0] = balast1;
			answer[1] = balast2;
			return answer;
		}


		if (isPrime(number)) {
			answer[0] = balast1;
			answer[1] = balast2 * number;
			return answer;

		}

		funVectorBase(countMax_);
		vector<vector <long long int>>
			V_ = sieve(),
			V = V_,
			Matrix;
		if (V.size() == 0) {
			countMax_++;
			return division();

		}

		for (size_t i = 0; i < V_.size(); i++) {

			Matrix.push_back(vector<long long int>(FBase.size()));

			for (size_t j = 0; j < FBase.size(); j++)
				while (V_[i][1] % FBase[j] == 0) {
					Matrix[i][j] += 1;
					V_[i][1] /= FBase[j];
				}

		}
		vector < vector<long long int> > Matrix_;

		for (long long int j = 0; j < Matrix[0].size(); j++) {

			vector<long long int> tmt(Matrix.size());

			for (long long int i = 0; i < tmt.size(); i++)
				tmt[i] = Matrix[i][j];

			Matrix_.push_back(tmt);

		}

		vector<long long int>
			xi = gaussZeroMod2(Matrix_);
		KarM
			x(1),
			y(1);

		vector<long long int>
			xi_(FBase.size());

		for (size_t i = 0; i < xi_.size(); i++) {
			for (size_t j = 0; j < Matrix.size(); j++)
				xi_[i] += xi[j] * Matrix[j][i];
			xi_[i] /= 2;
		}

		for (size_t i = 0; i < xi_.size(); i++)

			while (xi_[i] > 0) {
				x = x * FBase[i];
				xi_[i]--;
			}

		for (size_t i = 0; i < V.size(); i++)
			y = y * V[i][0];


		answer[0] = GCD(x + y, number);
		x > y ? answer[1] = GCD(x - y, number) : answer[1] = GCD(y - x, number);


		if (answer[0] > 1 && answer[0] < number &&
			answer[1] > 1 && answer[1] < number) {

			answer[0] = answer[0] * balast1;
			answer[1] = answer[1] * balast2;

			return answer;

		}
		else {
			answer[0] = 1;
			answer[1] = 1;
			countMax_++;
			return division();
		}










	}
	KarM QS::getFirst()const {
		return answer[0]; 
	}
	KarM QS::getSecond()const {
		return answer[1]; 
	}

