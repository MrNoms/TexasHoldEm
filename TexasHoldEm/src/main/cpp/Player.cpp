#include "Player.h"
#include <sstream>


Player::Player(int buyIn) {
	wallet = buyIn;
}

void Player::updateWallet(int funds)
{
	wallet += funds;
}

Deck Player::getHand()
{
	return hand;
}

int Player::getWallet() {
	return wallet;
}