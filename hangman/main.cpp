/*
Simple hangman game
Do not use caps
*/

#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;

void mainMenu();
int ShowSubMenu();
void playGame();
void WriteToScoreFile(string, int);
void ReadScoreFile();


string userName;
int score;
int choice = 1;
int main()
{
	//welcome message
	cout << "Welcome to Hangman!" << endl;
	//ask the user for their name
	cout << "Enter your name" << endl;
	cin >> userName;
	//display menu
	mainMenu();
	cin.get();
	cin.get();

	return 0;
}
int PlayGame() {
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
			cin.get();
			return (wrong);
		}

		cout << Underscore << endl;
		cout << "There are " << word.length() << " letters with spaces" << endl;
		cout << "You have " << 6 - wrong << " more tries left" << endl;

		if (Underscore == word) {
			cout << "You win!" << endl;
			cin.get();
			return (wrong);
		}

		cout << "Guess a letter or a word" << endl;
		getline(cin, guess);

		if (guess.length() > 1) {
			if (guess == word) {
				cout << "That's right, you win!" << endl;
				cin.get();
				return (wrong);
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
}

int ShowMenu()
{
	int choice;
	system("cls");
	cout << "  	Hangman Menu\n";
	cout << "= = = = = = = =\n";
	cout << "  1  Play Game:\n";
	cout << "  2  Show Score List:\n";
	cout << "  3  End program: \n";
	cout << "\nEnter your choice: ";
	while (!(cin >> choice))
	{
		cout << "\nThat's invalid option, please try again."
			<< "\nRe-Enter your choice: ";
		cin.get();
		cin.get();
		cin.clear();
		fflush(stdin);
	}
	return choice;

} // end function ShowMenu

void mainMenu()
{
	while (choice != 3)
	{
		do {
			if (choice > 3 || choice <= 0)
			{
				cout << "\We don't have that option. Please select again. \n";
				cout << "\nPress <Enter> key to continue ... ";
				fflush(stdin);
				cin.get();
				cin.get();
			}

			choice = ShowMenu();

		} while (choice < 0 || choice > 3);


		if (choice != 3)
			switch (choice)  // branch to an appropriate selection
			{
			case 1:
				cin.get();
				//returns wrongs

				WriteToScoreFile(userName, PlayGame());
				break;
			case 2:

				ReadScoreFile();
				cin.get();
				cin.get();
				break;

		
			}
		else //choice 3 was selected
		{
			cout << "\nprogram is over. Thanks for using.\n";
			cout << "\nPress <Enter> key to end the program. ";
		}


	} // end of while 
	fflush(stdin);
	cin.get();

}
void WriteToScoreFile(string user, int numberWrongs) {

	ofstream myfile;
	myfile.open("score.txt", ios_base::app);
	myfile << user << "          " << numberWrongs <<"\n";
	myfile.close();
}
void ReadScoreFile() {

	system("CLS");
	cout << "Name          Losses" << endl;
	cout << "-----------------" << endl;
	string line;
	ifstream myfile("score.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			cout << line << '\n';
		}
		myfile.close();
	}

	else cout << "Unable to open file";
}
