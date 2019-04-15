#pragma once
#include "Card.h"
#include "CircleList.h"	//can be ported to look like they are part
#include "Stack.h"		//of this game, rather than generic code

class Player {};
class Deck {};	//would use stack

class Game {
	Deck PlayCards;
	Card CommCards[5];
	CircleList<Player> Table;	//the Player class is coming
	Player * DealerButton;		//Pointer type may have to be tweaked
	Player * BigBlind;			//May not
	Player * SmallBlind;		//keep these
	enum RoundPhase {PRE_FLOP, FLOP, TURN, RIVER, SHOW};
	int const Rounds = 10;
	int Pot;
	int Ante;
	int PayOut(Player *);
	int PayIn();
	Player * Add2Table();			//return type and arguments up for debate
	void Kick(Player *);
};