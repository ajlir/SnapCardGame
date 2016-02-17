#ifndef H_deckOfCards
#define H_deckOfCards

#include "card.h"
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

const int CARDS_PER_DECK = 52;

class deckOfCards
{
public:
	deckOfCards();
	void shuffle();
	void printDeck() const;
	card dealCard();
private:
	card *deck;
	int currentCard;
};

deckOfCards::deckOfCards()
{
	string faces[] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
	string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};

	deck = new card[CARDS_PER_DECK]; // a deck is an array of cards in here.
	currentCard = 0; // points to top of the deck
	for (int i = 0; i < CARDS_PER_DECK; i++)
	{
		// populate cards in order
		deck[i] = card(faces[i % 13], suits[i / 13]);
	}
}

void deckOfCards::shuffle() // randomize the order of cards
{
	currentCard = 0; //points to top of the deck
	for (int i = 0; i < CARDS_PER_DECK; i++)
	{
		// time(0) returns system time in seconds
		// rand() returns a number from 0 to RAND_MAX (whatever number that is).
		int j = (rand() + time(0)) % CARDS_PER_DECK; // randomize numbers but within the number of cards in deck
		// swap
		card temp = deck[i];
		deck[i] = deck[j];
		deck[j] = temp;
	}
}

void deckOfCards::printDeck() const // For debugging purposes
{
	for (int i = 0; i < CARDS_PER_DECK; i++)
	{
		cout << deck[i].print();
		cout << endl;
	}
}

card deckOfCards::dealCard() // Increments by 1 each time this function is called.
{
	if (currentCard < CARDS_PER_DECK)
	{
		return deck[currentCard++];
	}
	
	return deck[0]; // If for whatever reason the pointer went negative or past 52.
}
#endif