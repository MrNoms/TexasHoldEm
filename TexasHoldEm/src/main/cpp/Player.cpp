#include "Player.h"



Player::Player() {
	hand = new Card[CARD_LIMIT];
	wallet = BUY_IN;
}


Player::~Player() {
	delete[] hand;
}

void Player::updateWallet(int funds)
{
	wallet += funds;
}

void Player::setHand(Card card1, Card card2)
{
	hand[0] = card1;
	hand[1] = card2;
}

int Player::getWallet() {
	return wallet;
}

std::string Player::displayHand() {
	std::string out = "";
	for (int i = 0; i < CARD_LIMIT; i++) {
		out += hand[i].to_string() + "\n";
	}

	return out;
}