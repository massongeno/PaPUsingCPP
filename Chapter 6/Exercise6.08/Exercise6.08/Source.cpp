//Altered version of "Bulls and Cows" from Chapter 5 Exercise 12.
//The original version used digits while this one uses letters.

//Turns out altering the original to use letters only required me to adjust the randomString function to pull from a list of letters.
//Since I was already using a char datatype, everything else transfered smoothly.
//Some input validation could be added to prevent a user from typing punctuation, numbers, and other inputs that arent contained within the list.
//However I would consider that user error, since the instructions of the game are clearly stated and it will still give the correct number of bulls and cows.


#include "std_lib_facilities.h"

using namespace std;

string randomString(int length) {
	string randString;
	srand(time(0));
	vector<char> letters = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

	for (int i = 0; i < length; i++) {
		int randNum = (rand() % letters.size());
		randString.push_back(letters[randNum]);
		letters.erase(letters.begin() + randNum);
	}

	return randString;
}

int main() {
	string guess;
	string answer;
	int target;
	int compareTo;
	char playAgain;
	int bulls = 0;
	int cows = 0;

	cout << "Bulls and Cows" <<
		endl << "Your goal is to correctly guess a string consisting of 4 letters." <<
		endl << "Each guess will give you a number of bulls and a number of cows." <<
		endl << "Bulls are correct values in the correct position." <<
		endl << "Cows are integers that are the correct value but placed in the incorrect position." <<
		endl << "Good luck!" <<
		endl;

start:
	answer = randomString(4);



guess:
	bulls = 0;
	cows = 0;
	cin.clear();
	cout << endl << "Guess: ";
	cin >> guess;
	if (guess == "debug") {
		goto debug;
	}
	else if (guess == "exit") {
		return 0;
	}
	for (int i = 0; i < guess.size(); i++) {		//added function to convert the guess to lowercase in case user uses capital letters.
		if (guess[i] < 97) {
			guess[i] += 32;
		}
	}
	for (int i = 0; i < 4; i++) {
		target = guess[i];
		for (int j = 0; j < 4; j++) {
			compareTo = answer[j];
			if (target == compareTo) {
				if (i == j) {
					bulls++;
					break;
				}
				else {
					cows++;
					break;
				}
			}
		}
	}
	cin.ignore(1000, '\n');
	cin.clear();

	cout << bulls << " bull(s) and " << cows << " cow(s)." << endl;
	if (bulls == 4) {
	debug:
		cout << endl << "You win!" << " The answer was: " << answer << ". Congratulations!" << endl;

		cout << "Play again? (Y/N)" << endl;
	retry:
		cin >> playAgain;
		if (playAgain == 'Y' || playAgain == 'y') {
			goto start;
		}
		if (playAgain == 'N' || playAgain == 'n') {
			return 0;
		}
		else {
			cout << endl << "Invalid Input, please enter Y or N." << endl;
			cin.ignore(1000, '\n');
			cin.clear();
			goto retry;
		}
	}
	else {
		cows = 0;
		bulls = 0;
		goto guess;
	}
}