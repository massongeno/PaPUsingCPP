//Write a program that bleeps out words you dont like.

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

inline void keep_window_open() { char ch; cin >> ch; }

int main() {
	vector<string> words;
	vector<string> dislikedWords;
	string temp;;

	dislikedWords.push_back("a"); //filter example (a, b, c)
	dislikedWords.push_back("b");
	dislikedWords.push_back("c");

	cout << "Please enter the list of words you would like to be put through the filter, submit ctrl +z to finalize : " << endl; // request for user input
	while (cin >> temp) {
		words.push_back(temp); //moving user input(temp) into a vector titled words

		for (int i = 0; i < words.size(); i++) {
			for (int j = 0; j < dislikedWords.size(); j++) {
				if (words[i] == dislikedWords[j]) {
					words[i] = "BLEEP";								//replace disliked words with BLEEP
				}
			}
		}
	}
	for (int i = 0; i < words.size(); i++) {
		cout << words[i] << " ";
	}
	cout << endl;

	return 0;
}
