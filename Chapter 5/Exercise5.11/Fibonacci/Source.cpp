#include "std_lib_facilities.h"

using namespace std;

int main() {
	int current;
	int previous = 1;
	int n;
	vector<int> fibonacci = { 1 , 1 };

	cout << "Please enter how many numbers of the fibonacci sequence you wish to view: ";
	cin >> n;
	cout << endl << "1";

	for (int i = 1; i < n; i++) {
		current = fibonacci[i];
		fibonacci.push_back(current + previous);
		previous = current;
		if (fibonacci[i] < 0) {
			cout << "..." << endl << endl << "Error: Int Overflow." << endl << "Highest value displayable is the " << i << "th value.";
			break;
		}
		cout << "," << fibonacci[i];
	}

}