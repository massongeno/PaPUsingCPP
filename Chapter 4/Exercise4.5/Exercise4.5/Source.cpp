//Calculator that receives two double values and an operator (+,-,/,*), then performs the operation using a switch case. 
//Also performs simple input validation via while loops for the double values and an if else statement for the operator.

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<functional>
#include<unordered_map>

using namespace std;

inline void keep_window_open() { char ch; cin >> ch; }

int main() {
	string input;
	double double1 = 0;
	double double2 = 0;
	char operation;
	double solution = 0;

	cout << "Enter first number: ";
	while (!(cin >> double1)){
		cout << "Invalid input, please try again." << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Enter first number: "; 
	}

operationInput:
	cout << "Enter operation (+,-,*,/): ";
	cin >> input;
	if (input[input.length() - 1] == '+' || input[0] == '-' || input[0] == '*' || input[0] == '/')
	{
		operation = input[input.length() - 1];
	}
	else
	{
		cout << "Invalid Input, please try again." << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		goto operationInput;
	}
	
	cout << "Enter second number: ";
	while (!(cin >> double2)) {
		cout << "Invalid input, please try again." << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Enter second number: ";
	}



	switch (operation) {
	case '+':
		solution = double1 + double2;
		break;
	case '-':
		solution = double1 - double2;
		break;
	case '/':
		solution = double1 / double2;
		break;
	case '*':
		solution = double1 * double2;
		break;
	}


	cout << double1 << " " << operation << " " << double2 << " = " << solution;


}