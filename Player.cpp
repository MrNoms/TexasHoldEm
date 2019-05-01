#include "Player.h"



Player::Player()
{
	int handRank = 0; // value of hand
	Card hand[2] = { {hand[0].thisSuit = NONE, hand[0].thisNum = ZERO }, {hand[1].thisSuit = NONE, hand[1].thisNum = ZERO } }; // two cards in players hand
	bool winner = false; // true if winner of round, possible split winner
	int wallet = 1000; // total $ in wallet
	int bet = 0; // amount player is betting in a given round, taken from wallet
	int playerNumber = 0;
}


Player::~Player()
{
}

void Player::setPlayerNumber(int playerNum)
{
	playerNumber = playerNum;
}
