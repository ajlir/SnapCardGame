#ifndef H_card
#define H_card

#include <string>
#include <iostream>

using namespace std;

class card
{
public:
	card(string cardFace, string cardSuit);
	string print() const;
	card();
private:
	string face;
	string suit;

};
// constructor
card::card()
{

}
// constructor with 2 arguments
card::card(string cardFace, string cardSuit)
{
	// takes in face and suit
	face = cardFace;
	suit = cardSuit;
}

string card::print() const // cards are represented by strings
{
	return(face + " of " + suit);
}
#endif