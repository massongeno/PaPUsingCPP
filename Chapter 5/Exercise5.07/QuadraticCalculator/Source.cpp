#include "std_lib_facilities.h"

using namespace std;

int main() {
	double a;
	double b;
	double c;
	double d;
	double e;
	double sqrtAnswer;

	cout << "Quadratic Equation Calculator" << endl << "a: ";
	cin >> a;
	cout << "b: ";
	cin >> b;
	cout << "c: ";
	cin >> c;

	d = sqrt(abs((b * b) - (4 * a * c)));

	e = (b * b) - (4 * a * c);
	
	sqrtAnswer =(d)/(2*a);

	cout << endl;
	cout << a << "x^2 + " << b << "x + " << c << " = " << endl << endl;
	if (e > 0) {	//if greater than zero, two real roots
		cout << 0 - (b / (2 * a)) + sqrtAnswer << " or " << 0 - (b / (2 * a)) - sqrtAnswer << endl;+
	}
	else if ( e < 0) { //if less than zero, two complex roots
		cout << 0 - (b/(2*a)) << "+" << sqrtAnswer << "i or " << 0 - (b / (2 * a)) << "-" << sqrtAnswer << "i" << endl;
	}
	else { //if equal to zero, one real root
		cout << 0 - (b / (2 * a)) << endl;
	}

}