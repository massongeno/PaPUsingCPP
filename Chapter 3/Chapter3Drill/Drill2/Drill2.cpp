#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

inline void keep_window_open() { char ch; cin >> ch; }

int main()
{
	string signature;
	string firstName;
	string friendName;
	char friendSex;
	int age;

	cout << "Enter the name of the person you wish to write to: ";
	cin >> firstName;
	cout << "Dear " << firstName << "," << endl;

	cout << "	How are you? I hope you are doing well." << endl;

	cout << endl << "Please enter the name of an additional friend : ";
	cin >> friendName;
	cout << endl << "Please enter the gender of your additional friend as a single character (m/f): ";
	cin >> friendSex;

	gender:
	if (friendSex == 'm') {
		cout << "If you see " << friendName << " please ask him to call me.";
	}
	else if (friendSex == 'f')
	{
		cout << "If you see " << friendName << " please ask her to call me.";
	} 
	else
	{
		cout << "Invalid gender. Please resubmit gender: ";
		cin >> friendSex;
			goto gender;
	}

	cout << endl << "Please enter age of recipient in integer form: ";
	cin >> age;

	age:
	if (age > 0 && age < 110) 
	{
		if (age < 12) {
			cout << "Next year you will be " << age + 1 << "!";
		}
		else if (age == 17) {
			cout << "Next year you will be able to vote!";
		}
		else if (age > 70) {
			cout << "I hope you are enjoying your retirement.";
		}
	}
	else
	{
		cout << "You're kidding! Please resubmit age: ";
			cin >> age;
			goto age;
	}

	cout << endl << "Please enter your signature: ";
	cin >> signature;
	cout << "Your's sincerely," << endl << endl << signature;

	return 0;

}