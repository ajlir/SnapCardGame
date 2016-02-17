#include "deckOfCards.h"
#include <fstream>
using namespace std;

int main()
{
	// 2 objects of decks
	deckOfCards deck_one;
	deckOfCards deck_two;

	// Set pointer for each
	card currentCard_one;
	card currentCard_two;
	card Jokers_End; // for sanity check purposes

	bool valid; // another sanity check for the switch operation

	char choice;	// for simple GUI console purposes

	// holds players score
	int player_one_score;
	int player_two_score;

	ofstream out; // use to establish link to txt file

	out.open("results.txt", ios::app);	// opens txt file with append properties
	cout << "WELCOME TO SNAP!" << endl;
	do
	{
		cout << "1. Start New Game" << endl;
		cout << "2. View history" << endl;
		cout << "3. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;	// User's input goes here

		switch (choice)
		{
		case '1':
			// Shuffle the 2 decks
			deck_one.shuffle();
			deck_two.shuffle();

			// Reset score to 0
			player_one_score = 0;
			player_two_score = 0;

			// Begin with a card (Assume that Player 1 start first)
			currentCard_one = deck_one.dealCard();
			Jokers_End = currentCard_one;
			cout << setw(19) << currentCard_one.print() << endl;
			out << setw(19) << currentCard_one.print() << endl;

			// Everything else after a card is turned up
			for (int i = 0; i < CARDS_PER_DECK; i++)
			{
				currentCard_two = deck_two.dealCard();
				cout << setw(38) << currentCard_two.print();
				out << setw(38) << currentCard_two.print();

				// Compare the latest card and the previous one (case of Player 2's card snaps Player 1's card)
				if (currentCard_one.print() == currentCard_two.print())
				{
					player_two_score++;
					cout << setw(64) << "SNAP" << endl;
					out << setw(64) << "SNAP" << endl;
				}
				else
				{
					cout << endl;
					out << endl;
				}

				currentCard_one = deck_one.dealCard();
				// Case where the game should end with Player 2's last card
				if (currentCard_one.print() == Jokers_End.print())
				{
					cout << endl << endl << "Player 1's score: " << player_one_score << endl;
					out << endl << endl << "Player 1's score: " << player_one_score << endl;
					cout << "Player 2's score: " << player_two_score << endl << endl;
					out << "Player 2's score: " << player_two_score << endl;
					out << "=================================================================" << endl;
				}
				else
				{
					cout << setw(19) << currentCard_one.print();
					out << setw(19) << currentCard_one.print();
					// Case of Player 1's card snaps Player 2's card
					if (currentCard_one.print() == currentCard_two.print())
					{
						player_one_score++;
						cout << setw(57) << "SNAP" << endl;
						out << setw(57) << "SNAP" << endl;
					}
					else
					{
						cout << endl;
						out << endl;
					}
				}
			}
			valid = false;
			break;
		case '2':
			system("notepad.exe results.txt");
			valid = false;
			break;
		case '3':
			valid = true;
			break;
		default:
			cout << "Choose only 1 and 2, please." << endl;
			valid = false;
			break;
		}
	} while (!valid);
	
	
	system("PAUSE");
	return 0;
}

