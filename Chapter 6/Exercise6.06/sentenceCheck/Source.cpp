#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

inline void keep_window_open() { char ch; cin >> ch; }

void error(string s) {
	throw runtime_error(s);
}

string conj();
string sentence();
string verb();

string noun() {
	string right;
	cin >> right;
	if (right == "birds" || right == "fish" || right == "C++") {
		return right;
	}
	else {
		error("noun expected");
	}
}

string verb() {
	string left = noun();
	string right;
	cin >> right;
	if (right == "rules" || right == "fly" || right == "swim") {
		return left + right;
	}
	else {
		error("verb expected after noun");
		return 1;
	}
}

string conj(string right) {
	if (right == "but" || right == "and" || right == "or") {
		string left = sentence();
	}
	else {
		error("sentence expected after conjunction");
		return 1;
	}
}

string sentence() {
	string left = verb();
	string right;
	cin >> right;
	if (right == ".") {
		return "OK!";
	}
	else {
		string left = conj(right);
	}
}



int main() {
	try {
		while (cin) {
			cout << sentence() << endl;
		}
	}
	catch (exception& e) {
		cerr << e.what() << endl;
		return 1;
	}
	catch (...) {
		cerr << "exception \n";
		return 2;
	}
}




