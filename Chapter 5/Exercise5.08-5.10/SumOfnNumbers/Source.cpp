#include "std_lib_facilities.h"

using namespace std;

int main() {
	int n;
	vector<double> numbersList;
	char inputChar;
	string inputString;
	double sum = 0;

	cout << "Please enter the number of values you would like to sum: ";
	cin >> n;

	cout << endl;
	cout << "Please enter a list of values separated by commas, use ';' to terminate: ";
	try {
		while (cin >> inputChar) {
			if (inputChar != ',' && inputChar != ';') {
				inputString += inputChar;
			}
			else if (inputChar == ';') {
				numbersList.push_back(stod(inputString));
				inputString.clear();
				break;
			}
			else {
					numbersList.push_back(stod(inputString));
					inputString.clear();
			}
		}
		if (!cin >> inputChar) {
			throw std::invalid_argument("Error, all values must be a double.");
		}
		else if (n > numbersList.size()) {
			throw std::invalid_argument("Error, n is greater than list of values.");
		}
		else if (n < 0) {
			throw std::invalid_argument("Error, number of values cannot be negative.");
		} else if (!cin >> n) {
			throw std::invalid_argument("Error, n must be a number.");
		}
	}

	catch (std::invalid_argument& e) {
		cerr << endl << endl << e.what() << endl;
		return 1;
	}

	for (int i = 0; i < n; i++) {
		sum += numbersList[i];
	}

	cout << "List of values representing the difference between the nth value and n-1 value within the list: " << endl << numbersList[0];
	for (int i = 1; i < numbersList.size(); i++) {
		cout << ", " << numbersList[i] - numbersList[i - 1];
	}
	cout << endl;
	cout << "Sum: " << sum << endl;
}