//Rock paper scissors

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

inline void keep_window_open() { char ch; cin >> ch; }

int main()
{
	char user;
	int computer;
	int win = 0;
	int loss = 0;
	int tie = 0;

start:
	cout << "Please input 1 for rock, 2 for paper, 3 for scissors, or 0 for stats: ";
	cin >> user;
		  computer = (rand() % 3) + 1;
		  switch (user) {
		  case '1':
			  switch (computer) {
			  case 1:
				  cout << "The computer selects rock. Tie!" << endl;
				  tie++;
				  break;
			  case 2:
				  cout << "The computer selects paper. You lose!" << endl;
				  loss++;
				  break;
			  case 3:
				  cout << "The computer selects scissors. You win!" << endl;
				  win++;
				  break;
			  }
			  break;
		  case '2':
			  switch (computer) {
			  case 1:
				  cout << "The computer selects rock. You win!" << endl;
				  win++;
				  break;
			  case 2:
				  cout << "The computer selects paper. Tie!" << endl;
				  tie++;
				  break;
			  case 3:
				  cout << "The computer selects scissors. You lose!" << endl;
				  win++;
				  break;
			  }
			  break;
		  case '3':
			  switch (computer) {
			  case 1:
				  cout << "The computer selects rock. You lose!" << endl;
				  loss++;
				  break;
			  case 2:
				  cout << "The computer selects paper. You win!" << endl;
				  win++;
				  break;
			  case 3:
				  cout << "The computer selects scissors. Tie!" << endl;
				  tie++;
				  break;
			  }
			  break;
		  case '0':
			  cout << "Wins: " << win << endl;
			  cout << "Losses: " << loss << endl;
			  cout << "Ties: " << tie << endl;
			  break;
		  default:
			  cout << "Invalid Input, please try again." << endl;
		  }
		  cout << endl;
		  goto start;
}

