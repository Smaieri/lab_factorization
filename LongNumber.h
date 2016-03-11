#pragma once
#include <vector>
#include <string>
using namespace std;
#define  BASE_STANDART 10
class LongNumber {
protected:
	
	int base;
	bool digit; // true positive, false negative
public:
	vector <long long int> number;
	
	friend ostream &operator<<(ostream &output, const LongNumber &n) {
		
		if (!n.isPositive())
			output << '-';

			for (int i = n.number.size() - 1; i >= 0; i--)
				output << n.number[i];

			return output;
		
	}
	bool isPositive() const;
	virtual  LongNumber operator *(LongNumber &n2);
	LongNumber();
	LongNumber(vector<long long int> &number_, bool digit_ = true, const int &base_ = BASE_STANDART);
	LongNumber(long long int s, const int &base_ = BASE_STANDART);
	LongNumber operator -();
	friend bool operator == (LongNumber n1, LongNumber n2) {
		if (!n1.isPositive() && n2.isPositive())
			return false;
		else if (!n2.isPositive() && n1.isPositive())
			return false;
		else if (!n2.isPositive() && !n1.isPositive())
			return (((-n2) == (-n1)));
		
		
		if (n1.size() < n2.size())
			return (n2 == n1);

		size_t 
			min = n2.size();

			size_t j;
			for (j = 0; j < min; j++)
				if (n1.number[j] != n2.number[j])
					return false;

			for (j = min; j < n1.size(); j++)
				if (n1.number[j] != 0)
					return false;
			return true;	
		
	
	}
	friend bool operator > ( LongNumber n1,  LongNumber n2) {

		if (!n1.isPositive() && n2.isPositive())
			return false;
		else if (!n2.isPositive() && n1.isPositive())
			return true;
		else if (!n2.isPositive() && !n1.isPositive())
			return ( ((-n2) > (-n1)) );
		
		int r1 = n1.size() - 1,
			r2 = n2.size() - 1;
		//find first nonzero;

		while (r1 >= 0 && n1.number[r1] == 0)
			r1--;
		while (r2 >= 0 && n2.number[r2] == 0)
			r2--;

		if (r1 > r2)
			return true;
		else if (r1 < r2)
			return false;
		else if (r1 == r2) {
			
			while (r1 >= 0 && n1.number[r1] == n2.number[r1])
				r1--;

			if (r1 >= 0)
			{
				if (n1.number[r1] > n2.number[r1])
					return true;
				else
					return false;
			}
			else
				return false;


		}

	
	}
	friend bool operator < (LongNumber n1, LongNumber n2) {
		return (!(n1 > n2) && !(n1 == n2));
	}
	friend bool operator >= (LongNumber n1, LongNumber n2) {
		return ((n1 > n2) ||(n1 == n2));
	}
	friend bool operator <= (LongNumber n1, LongNumber n2) {
		return ((n1 < n2) || (n1 == n2));
	}
	friend bool operator != (LongNumber n1, LongNumber n2) {
		return (!(n1 == n2));
	}
	LongNumber sumPosPos(LongNumber n1, LongNumber n2);
	LongNumber minPosPos(LongNumber n1, LongNumber n2);
	friend LongNumber operator + ( LongNumber n1,  LongNumber n2) {

		if (n1.isPositive() && n2.isPositive())
			return n1.sumPosPos(n1, n2);
		else if (n1.isPositive() && !n2.isPositive())
			return n1.minPosPos(n1, -n2);
		else if (!n1.isPositive() && n2.isPositive())
			return n1.minPosPos(n2, -n1);
		else if (!n1.isPositive() && !n2.isPositive())
			return -n1.sumPosPos(n1, n2);
	}
	friend LongNumber operator - (LongNumber n1, LongNumber n2) {
		if (n1.isPositive() && n2.isPositive())
			return n1.minPosPos(n1, n2);
		else if (n1.isPositive() && !n2.isPositive())
			return n1.sumPosPos(n1, -n2);
		else if (!n1.isPositive() && n2.isPositive())
			return -n1.sumPosPos(n2, -n1);
		else if (!n1.isPositive() && !n2.isPositive())
			return n1.minPosPos(-n2, -n1);
	}
	friend void deleteUnpleasantZeros(LongNumber&n) {
		
		while (!n.number.empty() && n.number.back() == 0)
			n.number.pop_back();
		if (n.number.empty())
			n.number.push_back(0);
	}
	int getBase()const;
	void addZero();
	size_t size()const;
	~LongNumber();
	friend LongNumber operator %(LongNumber n1, LongNumber n2) {
	
		if (n2 == n1)
			return 0;
		else if (n2 > n1)
			return n1;
		else {
				

			LongNumber n2_(n2);
			while (n1 > n2_) 
				n2_.number.insert(n2_.number.begin(), 0);
			
			
			n2_.number.erase(n2_.number.begin());
			while (n2_.size() != n2.size()) {
				while (n1 > 0)
					n1 = n1 - n2_;
				
				n1 = n1 + n2_;

				n2_.number.erase(n2_.number.begin());

			}

			while (n1 > 0)
				n1 = n1 - n2;

			if (n1 == 0)
				return 0;
			else 
				return n1 + n2;

		
		
		}
	}

	friend LongNumber operator /(LongNumber n1, long long int n2) {
		long long int
			i = n1.number.size() - 1,
			c = 0,
			t = 0;

		LongNumber ans;

		while (i >= 0) {
			c = c * n1.getBase() + n1.number[i];
			i--;
			t = c;
			c = t % n2;
			ans.number.insert(ans.number.begin(), t/n2);
		}
		deleteUnpleasantZeros(ans);
		return ans;
	
	}
	void changeBaseTo(int b);
};