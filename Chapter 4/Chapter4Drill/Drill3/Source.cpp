//This drill includes manual vector sorting, vector manipulating, storing of unit values, unit conversions, and value comparisons
//Primarily intended to add lengths with units to a expanding vector and compare them.


#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

inline void keep_window_open() { char ch; cin >> ch; }

void valueCloseCheck(double larger, double smaller) {			//unused value comparison function for determining whether current-
	double difference = larger - smaller;						//-input was close in value to most recent input
	if (difference < .01) {
		cout << "The numbers are almost equal." << endl;
	}
}

void valueCheck(double num1, double num2) {						//unused value comparison funtion for determining whether current-
	if (num1 < num2) {											//-input was larger or smaller than most recent input
		cout << "The smaller value is: " << num1 << endl;
		cout << "The larger value is: " << num2 << endl;
		valueCloseCheck(num2, num1);
	}
	else if (num1 > num2)
	{
		cout << "The smaller value is " << num2 << endl;
		cout << "The larger value is " << num1 << endl;
		valueCloseCheck(num1, num2);

	}
	else
	{
		cout << "The numbers are equal." << endl;
	}
}

int main() {
	vector<double> doubleList;
	double userDouble;
	vector<string> unitList;
	string unit;
	vector<double> sortedList;
	double sortedDouble;
	int n = 0;
	char submitCheck;
	int sum = 0;



start:
	cout << "Please enter a double, then a unit, then the | character (ex: 25 cm | ): ";
	while (cin >> userDouble >> unit >> submitCheck)
	{

		if (submitCheck == '|') {
			if (unit == "cm") {
				sortedDouble = userDouble;
			}
			else if (unit == "m") {
				sortedDouble = userDouble * 100;
			}
			else if (unit == "in") {
				sortedDouble = userDouble * 2.54;
			}
			else if (unit == "ft") {
				sortedDouble = userDouble * 2.54 * 12;
			}
			else {
				cout << "Invalid unit, please use cm, m, in, or ft" << endl;
				std::cin.ignore(100, '\n');
				goto start;
			}
			cout << "Number submitted: " << userDouble << " " << unit << endl;
			
			if (sortedList.size() == 0) {							//checks if the list is empty
				unitList.push_back(unit);							//adds unit to the unit vector
				sortedList.push_back(sortedDouble);					//adds actual double value to the sorted double vector
				doubleList.push_back(userDouble);					//adds user double value to the user double vector
				goto begin;											//goto visual output
			}

			for (int i = 1; i <= sortedList.size(); i++)				//for each element inside of the vector
			{

				if (sortedDouble < sortedList[sortedList.size() - i])		//check if user input is less than each element
				{
					++n;				//for each element the check passes, increment potentialInt
				}
			}

			sortedList.insert(sortedList.end() - n, sortedDouble); //inserts user input at a the end - n position
			unitList.insert(unitList.end() - n, unit);
			doubleList.insert(doubleList.end() - n, userDouble);

			if (n == 0) {
				cout << "Largest so far" << endl;
			} else if (n == sortedList.size() - 1) {
				cout << "Smallest so far" << endl;
			}
		begin:

			cout << "Sorted List: ";						//visual output vvvv

			for (int i = 0; i < sortedList.size(); i++)
			{
				cout << doubleList[i] << unitList[i] << ", ";  //displaying list
				sum += sortedList[i];							//calculating sum
			}
			cout << endl;
			cout << "Largest Value: " << doubleList[sortedList.size() - 1] << unitList[sortedList.size() - 1] << endl;
			cout << "Smallest Value: " << doubleList[0] << unitList[0] << endl;
			cout << "Median: " << doubleList[sortedList.size() / 2] << unitList[sortedList.size() / 2] << endl;
			cout << "Mean: " << (sum / 100.0) / sortedList.size() << "m" << endl;
			cout << "Sum: " << (sum / 100.0) << "m";
			cout << endl << endl;									//visual output ^^^^


			n = 0;										//clears n for next cycle
			sum = 0;									//clears sum for next cycle

			goto start;
		}
		else
		{
			cout << "Invalid input" << endl;	//invalid input error catch
			std::cin.ignore(100, '\n');
			goto start;
		}


	}
	return 0;
}