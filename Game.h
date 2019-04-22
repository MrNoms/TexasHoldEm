#pragma once
#include "Card.h"
#include "CircleList.h"	//can be ported to look like they are part
#include "Stack.h"		//of this game, rather than generic code

class Player {};
	// Private: handRank, hand
class Deck {};	//would use stack

class Game {
public:
	Deck PlayCards; // Deck of game cards? 
		// functions to initialize deck, shuffle, pass out
	int PayIn(Player *);	// input circular list of players. return to Pot
	int PayOut(Player *);	// mutator for Pot
	int splitPot(Player *, Player *); // input two players who split the pot

	void calcHand(Player *); // input player circular list, traverse list & assign hand value to each player

private:
	enum RoundPhase { PRE_FLOP, FLOP, TURN, RIVER, SHOW };
	enum handRank { HIGH_CARD, PAIR, TWO_PAIR, THREE_OF_KIND, STRAIGHT, FLUSH, FULL_HOUSE, FOUR_OF_KIND, STRAIGHT_FLUSH, ROYAL_FLUSH };
	int const Rounds = 10;

	Card CommCards[5]; // Array for the "River"
		// need functions to add cards from deck to this & to empty array

	CircleList<Player> Table;	//the Player class is coming
	Player * Add2Table();		//return type and arguments up for debate
	void Kick(Player *);
	Player * DealerButton;		//Pointer type may have to be tweaked
	Player * BigBlind;			//May not
	Player * SmallBlind;		//keep these

	int Pot;
	int Ante;	// Do we need this if we're using blinds?
};