#include "std_lib_facilities.h"

using namespace std;

int main() {
	bool prime = true;
	vector<int> primeNumbers = {2};
	int upperLimit;

	cout << "Select an upper limit and the program will output all prime numbers up to that limit: ";
	cin >> upperLimit;

	for (int i = 3; i < upperLimit;i++) {
		for (int j = i-1; j >= 2; j--) {
			if ((i % j) == 0) {
				prime = false;
			}
		}
		if (prime == true) {
			primeNumbers.push_back(i);
		}
		prime = true;
	}
	cout << "List of prime numbers: ";
	for (int i = 0; i < primeNumbers.size(); i++) {
		cout << primeNumbers[i] << ", ";
	}
	return 0;
}