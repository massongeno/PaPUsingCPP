//Program that finds the first n prime numbers or all prime numbers up to a user inputted upper limit.
//Uses the "Sieve of Eratosthenes," an algorithm that takes each prime number and removes its multiples, thus creating a list of exclusively prime numbers
//by the end.

#include "std_lib_facilities.h"

using namespace std;

int main() {
	vector<int> primeNumbers;
	int upperLimit = 0;
	int target;
	int largestPos;
	int n;

	cout << "Please enter an upper limit: ";
	cin >> upperLimit;

	cout << "Please enter how many primes you would like to view or 0 if you would like to view all of them: ";
	cin >> n;

	for (int i = 0; i <= upperLimit; i++) {
		primeNumbers.push_back(i);
	}

	for (int i = 2; i < primeNumbers.size() - 1; i++) {
		target = primeNumbers[i];
		largestPos = primeNumbers.size() - 1;
		for (int j = ((upperLimit / target) - ((upperLimit / target) % 2)); j > 1; j--) {		//find how many times the upperlimit can be split into i parts, rounding down.
			auto it = find(primeNumbers.begin(), primeNumbers.end(), target * j);				//find all multiples of the target prime number within the vector.
			if (it != primeNumbers.end()) {														//if the iterator does not equal a null value, erase.
				primeNumbers.erase(it);
			}
		}
	}
	if (n != 0) {
		while (primeNumbers.size() > n + 1) {
				primeNumbers.erase(primeNumbers.end() - 1);
		}
	}
	cout << "List of prime numbers: ";
	cout << primeNumbers[0];
	for (int i = 1; i < primeNumbers.size() - 1; i++) {
		cout << ", " << primeNumbers[i];
	}
	return 0;
}