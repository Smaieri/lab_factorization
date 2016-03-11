#include <iostream>
#include "LongNumber.h"
#include "KarazubuMethod.h"
#include "Dixon.h"
#include "ToomCook.h"
#include "Pollard.h"
#include "Reciprocal.h"
#include "QS.h"
#include "DivisionCook.h"
using namespace std;

int main() {
	
	/*//karaz method
		long long int a, b;
		cin >> a >> b;
		KarM a_1(a),
			b_1(b);
		cout << a_1*b_1 << endl;

	
	
	//toom cook method
		//long long int a, b;
		//cin >> a >> b;
	ToomCook
			a_2(a),
			b_2(b);
		cout << a_2*b_2 << endl;
*/
	
	
/*	while (true) {//Reciprocal method, do base_standart = 2 in long number 

		long long int a_;
		cin >> a_;
		KarM a(a_, 2);
		Reciprocal d(a, 8);
		d.find_bin();
		cout << d << endl;
	}
	
	*/
/*	while (true) {//DivisionCook method do base_standart 2;
		long long int
			a_,
			b_;
		cin >> a_ >> b_;
		KarM
			a(a_, 2),
			b(b_, 2);
		DivisionCook d(a, b, 20);
		d.find_bin();
		cout << d << endl;
	
	}
	*/
	
	/*while (true) {//Dixon method
		long long int 
			a_;
		cin >> a_;
		Dixon d(a_);
		d.division();
		cout << d.getFirst() << " * " << d.getSecond() << endl;
		
	}
	*/
	
	/*while (true) {//Pollard method
		long long int
			a_;
		cin >> a_;
		LongNumber a(a_);
		Pollard d(a);
		cout << d.factor() << endl;
	
	}
	*/

	while (true) {//QS method
		long long int
			a_;
		cin >> a_;
		QS d(a_);
		d.division();
		cout << d.getFirst() << " * " << d.getSecond() << endl;
	}

	system("pause");
	return 0;

}