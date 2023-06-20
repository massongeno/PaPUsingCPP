//Write a program that is capable of converting numbers to their word form and vice versa using the same loop.

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<unordered_map>

using namespace std;

inline void keep_window_open() { char ch; cin >> ch; }

const static std::unordered_map<string, char> stringToChar{
	{"zero", '0'},
	{"one", '1'},
	{"two", '2'},
	{"three", '3'},
	{"four", '4'},
	{"five", '5'},
	{"six", '6'},
	{"seven", '7'},
	{"eight", '8'},
	{"nine", '9'}
};

int main()
{
	string input;

	cout << "Please enter an integer 1-10 or a word one through ten: " << endl;
	while (cin >> input) {
		if (isdigit(input[0])) {
			switch (input[0]) {
			case '0':
				cout << "Zero";
				break;
			case '1':
				cout << "One";
				break;
			case '2':
				cout << "Two";
				break;
			case '3':
				cout << "Three";
				break;
			case '4':
				cout << "Four";
				break;
			case '5':
				cout << "Five";
				break;
			case '6':
				cout << "Six";
				break;
			case '7':
				cout << "Seven";
				break;
			case '8':
				cout << "Eight";
				break;
			case '9':
				cout << "Nine";
				break;
			}
			cout << endl;
		}
		else {
			for (int i = 0; i < input.length(); i++) {
				if (isupper(input[i])) {
					input[i] += 32;
				}
			}
			switch (stringToChar.count(input) ? stringToChar.at(input) : 0) {
			case '0':
				cout << "0";
				break;
			case '1':
				cout << "1";
				break;
			case '2':
				cout << "2";
				break;
			case '3':
				cout << "3";
				break;
			case '4':
				cout << "4";
				break;
			case '5':
				cout << "5";
				break;
			case '6':
				cout << "6";
				break;
			case '7':
				cout << "7";
				break;
			case '8':
				cout << "8";
				break;
			case '9':
				cout << "9";
				break;
			}
			cout << endl;
		}
	}
}

