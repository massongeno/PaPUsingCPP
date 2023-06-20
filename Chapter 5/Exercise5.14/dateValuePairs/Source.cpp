#include "std_lib_facilities.h"

using namespace std;

bool daysValidation(string dayInput) {

	vector<string> validDays = { "mon", "monday", "tues", "tuesday", "wed", "wednesday", "thurs", "thursday", "fri", "friday", "sat", "saturday", "sun", "sunday" };

	for (int i = 0; i < dayInput.length(); i++) {		//converts input to lowercase
		if (dayInput[i] < 97) {
			dayInput[i] += 32;
		}
	}

	for (int i = 0; i < validDays.size(); i++) {		//if lowercase input lines up with one of the accepted inputs in the vector, return true
		if (dayInput == validDays[i]) {
			return true;
		}
	}

	return false;										//else return false
}
int main() {
	int valueInput;
	string dayInput;

	vector<int> values;
	vector<string> days;

	start:
	cout << endl << "Please enter (day of the week, value): ";
	cin >> dayInput;											//load first string into dayInput
	
	if (dayInput == "output") {									//output function
		cout << "Day Input: " << days[0];						//days vector output
		for (int i = 1; i < days.size(); i++) {
			cout << ", " << days[i];
		}
		
		cout << endl << "Val Input: " << values[0];			//values vector output
		for (int i = 1; i < values.size(); i++) {
			cout << ", " << values[i];
		}
	}
	else if (dayInput[dayInput.length()-1] == ',') {			//check for comma
		dayInput.erase(dayInput.end() - 1);						//if there is one, remove it
		if (!(cin >> valueInput)) {								//load second value into valueInput
			cout << "Invalid value, please use the format (day, value)" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			goto start;
		}
		if (daysValidation(dayInput) == false) {
			cout << "Invalid day, please use the day's full name or accepted abreviation (mon,tues,weds,thurs,fri,sat,sun)" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			goto start;
		}
		values.push_back(valueInput);							//push back first and second value
		days.push_back(dayInput);
	}
	else {
		cout << "Invalid Input, please use the format (day, value)" << endl;
	}
	cin.clear();												//reset for next cycle
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	

	goto start;
}