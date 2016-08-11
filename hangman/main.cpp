/*
Simple hangman game
Do not use caps
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	cout << "Enter the word for other player to guess" << endl;

	string word;
	getline(cin, word);

	string copy = word;

	string Underscore;

	for (int i = 0; i != word.length(); i++) {

		if (word.at(i) == ' ') {
			Underscore += " ";
		}
		else {
			Underscore += "_";
		}
	}
	
	

	string guess;
	int wrong = 0;

	while (1) {
		/*padding*/
		system("CLS");

		if (wrong == 0) {
			for (int i = 0; i != 7; ++i) {
				cout << endl;
			}
		}
		if (wrong >= 1) {
			//first line
			cout << "    =======" << endl;
			//head
			cout << "    ";
			if (wrong >= 2) {
				cout << "|";
			}
			else {
				cout << " ";
			}
			cout << "    || " << endl;
			
			cout << "    ";
			if (wrong >= 2) {
				cout << "O";
			}
			else {
				cout << " ";
			}
			cout << "    || " << endl;
			//body
			cout << "   ";
			if (wrong >= 3) {
				cout << "/";
			}
			else {
				cout << " ";
			}
			if (wrong >= 2) {
				cout << "|";
			}
			else {
				cout << " ";
			}
			if (wrong >= 4) {
				cout << "\\";
			}
			else {
				cout << " ";
			}
			cout << "   || " << endl;
			//legs
			cout << "   ";
			if (wrong >= 5) {
				cout << "/";
			}
			else {
				cout << " ";
			}
			cout << " ";
			if (wrong >= 6) {
				cout << "\\";
			}
			else {
				cout << " ";
			}
			cout << "   || " << endl;
			cout << "         ||" << endl;
			cout << "===================" << endl;

			
		}

		//writing padding
		for (int i = 0; i != 3; ++i) {
			cout << endl;
		}

		if (wrong == 6) {
			cout << "You Lose! The word was: " << word << endl;
			break;
		}

		cout << Underscore << endl;
		cout << "There are " << word.length() << " letters with spaces" << endl;
		cout << "You have " << 6 - wrong << " more tries left" << endl;

		if (Underscore == word) {
			cout << "You win!" << endl;
			break;
		}

		cout << "Guess a letter or a word" << endl;
		getline(cin, guess);

		if (guess.length() > 1) {
			if (guess == word) {
				cout << "That's right, you win!" << endl;
				break;
			}
			else {
				cout << "wrong word " << endl;
				wrong++;
			}
		}
		else if (copy.find(guess) != -1) {
			while (copy.find(guess) != -1) {
				Underscore.replace(copy.find(guess), 1, guess);
				copy.replace(copy.find(guess), 1, "_");
			}
		}
		else {
			cout << "That's wrong" << endl;
			wrong++;
		}
		cout << endl;
	}
	cin.get();
	cin.get();

	return 0;
}