#pragma once
#include "Card.h"
#include <string>

enum class PlayerChoice { CHECK, RAISE, FOLD }; 

class Player {
private:
	int const CARD_LIMIT = 2;
	int const BUY_IN = 1000;

	Card* hand; // two cards in players hand
	int wallet; // total $ in wallet

public:
	Player();
	~Player();

	void updateWallet(int);
	void setHand(Card, Card);

	int getWallet();
	Card* getHand();

	std::string displayHand();
};

