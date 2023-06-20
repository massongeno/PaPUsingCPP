//Write a program that lists repeated words given a user inputted phrase.

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

inline void keep_window_open() { char ch; cin >> ch; }

int main()
{

	string previous = "";
	string current;
	string input;


	while (cin >> current) {
		


		const int add = 32; //difference in ascii value between capital and lowercase characters
		const int max = 127; //maximum ascii value to prevent overflow

		
		
		for (int i = 0; i <= current.length(); i++) //for loop that processes each individual character of the string 'current'
		{

			char ch = current[i];

			if ((int)ch >= 65 && (int)ch <= 90) //scans for capital letters (ascii values between 65 and 90)
			{
				int ascii = (int)ch; //converts char to ascii value
				std::replace(current.begin(), current.end(), (char)ascii, (char)(ascii + 32)); //replaces original capital letter with its lowercase counterpart.
			}

			if (ispunct(ch)) //checks if the char is punctuation
			{
				current.erase(i--, 1); //removes the punctuation and sets i back 1 to prevent overflow since a char was removed.
			
			}
			
			
		}
		
		
		if (previous == current) //checks if previous word == current word
		{
			cout << "Repeated word: " << current << endl; //outputs word if true
		}
		previous = current; //copies current word into previous for next cycle
		
	}
	return 0;

}
