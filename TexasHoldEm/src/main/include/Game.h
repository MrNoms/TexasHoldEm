#pragma once
#include "CircleList.h"
#include "Deck.h"
#include "Player.h"
#include <iostream>
using namespace std;

class Game {/*
private:
	enum class RoundPhase { PRE_FLOP, FLOP, TURN, RIVER, SHOW };	// Play() uses RoundPhase for readability 
	enum class HandRank { HIGH_CARD, PAIR, TWO_PAIR, THREE_OF_KIND,
		STRAIGHT, FLUSH, FULL_HOUSE, FOUR_OF_KIND,
		STRAIGHT_FLUSH, ROYAL_FLUSH };

	int const _ROUNDS = 10;

	Deck PlayCards;				//Cards that are dealt to the players

	Card CommCards[5];			// Community Cards A.K.A. 3-5 cards on table
	int tableCards;
	void displayCommCards();

	CircleList<Player> table;
	Player * dealer;		//Pointer type may have to be tweaked

	int Pot;
	int Ante;
	int totalBet; // Player.bet must equal totalBet, fold, or raise
		// if Player raises, totalBet = raise - Player.bet

	void preFlopRound();

	void addToTable();		// adds Player to Table
	void  Kick(Player);
	void getBets();

public:

	void setPot(int);
	void setAnte();

	int getPot();

	// util
	void Play();
	int PayIn(Player, int);	// input circular list of players & payIn amount. return to Pot
	int PayOut(Player*);	// mutator for Pot
	int splitPot(Player*, Player*); // input two players who split the pot

	// constructor & destructor
	Game();
	~Game();
	*/
};