#pragma once
#include "Card.h"

enum PlayerChoice { CHECK, RAISE, FOLD };

class Player
{
private:
	int handRank; // value of hand
	Card hand[2]; // two cards in players hand
	bool winner; // true if winner of round, possible split winner
	int wallet; // total $ in wallet
	int bet; // amount player is betting in a given round, taken from wallet

public:
	Player();
	~Player();

	int getHandRank(Card *); // takes commCards[] from game.h, and player.hand[], and calculates player.handRank
	int getPlayerChoice(); // returns enum check, raise, fold
};