#pragma once
#include "Card.h"
#include "CircleList.h"	//can be ported to look like they are part
#include "Stack.h"		//of this game, rather than generic code
#include "Deck.h"
#include "Player.h"

class Game {
public:
	Deck PlayCards; // Deck of game cards? 
		// functions to initialize deck, shuffle, pass out
	int PayIn(Player *);	// input circular list of players. return to Pot
	int PayOut(Player *);	// mutator for Pot
	int splitPot(Player *, Player *); // input two players who split the pot

	void checkPlayerChoice(Player *); // not sure on return type...
		// if fold, take cards from player.hand[] and put into deck.discard[]
		// if check, do nothing. allow Play() to advance to next player
		// if raise, increase totalBet

	//void calcHand(Player *); // input player circular list, traverse list & assign hand value to each player
		// unneccisary? see Player.getHandRank()

private:
	enum RoundPhase { PRE_FLOP, FLOP, TURN, RIVER, SHOW };
	// Play() uses RoundPhase for readability 
	enum HandRank { HIGH_CARD, PAIR, TWO_PAIR, THREE_OF_KIND, STRAIGHT, FLUSH, FULL_HOUSE, FOUR_OF_KIND, STRAIGHT_FLUSH, ROYAL_FLUSH };
	int const Rounds = 10;

	Card CommCards[5]; // Array for the "River" // Community Cards
		// need functions to add cards from deck to this & to empty array

	CircleList<Player> Table;	//the Player class is coming
	Player * Add2Table();		//return type and arguments up for debate
	void Kick(Player *);
	Player * DealerButton;		//Pointer type may have to be tweaked

	int Pot;
	int Ante;
	int totalBet; // Player.bet must equal totalBet, fold, or raise
		// if Player raises, totalBet = raise - Player.bet
};
