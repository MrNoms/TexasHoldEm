#include "Player.h"
#include <sstream>


Player::Player(int buyIn) {
	wallet = buyIn;

	hand = Deck();
	name = std::to_string((int)this);
}

void Player::updateWallet(int funds)
{
	wallet += funds;
}

Deck Player::getHand()
{
	return hand;
}

std::string Player::getName() {
	return name;
}

void Player::setDecision(PlayerChoice choice) {
	decision = choice;
}

PlayerChoice Player::getDecision() {
	return decision;
}

int Player::getWallet() {
	return wallet;
}