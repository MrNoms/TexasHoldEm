#include "Player.h"
#include <sstream>


Player::Player() {
	hand = Deck();
	wallet = 0;
	name = std::to_string((unsigned long long)(void**)this);
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