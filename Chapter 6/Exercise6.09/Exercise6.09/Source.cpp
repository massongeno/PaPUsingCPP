//Write a program that reads digits and composes them into integers. For example, 123 is read as the characters 1, 2, and 3. The program
//should output 123 is 1 hundred and 2 tens and 3 ones. The number should be output as an int value. Handle numbers with one, two, three,
//or four digits.

#include "std_lib_facilities.h"

using namespace std;

int main() {
	char input;
	vector<char> intVector;

	cout << "Please enter a number 0-9999 followed by an equal sign: ";
	while (cin) {
		cin >> input;
		switch (input) {
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
			intVector.push_back(input);
			break;
		case '=':
			if (intVector.size() == 4) {
					cout << intVector[intVector.size() - 4] - '0';;
					if (intVector[intVector.size() - 4] == '1'){
						cout << " thousand ";
					}
					else {
						cout << " thousands ";
					}
				}
				if (intVector.size() >= 3 && intVector.size() <= 5) {
					cout << intVector[intVector.size() - 3] - '0';
					if (intVector[intVector.size() - 3] == 1) {
						cout << " hundred ";
					}
					else {
						cout << " hundreds ";
					}
				}
				if (intVector.size() >= 2 && intVector.size() <= 5) {
					cout << intVector[intVector.size() - 2] - '0';
					if (intVector[intVector.size() - 2] == 1) {
						cout << " ten and ";
					}
					else {
						cout << " tens and ";
					}
				}
				if (intVector.size() >= 1 && intVector.size() <= 5) {
					cout << intVector[intVector.size() - 1] - '0';
					if (intVector[intVector.size() - 1] == 1) {
						cout << " one.";
					}
					else {
						cout << " ones.";
					}
				} else {
					cout << "Invalid Input.";
				}
				cout << endl;
				intVector.clear();
				break;
		case 'q':
			return 0;
		}
	}

}
