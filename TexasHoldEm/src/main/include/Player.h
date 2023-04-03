#pragma once
#include "Deck.h"
#include <string>

enum class PlayerChoice { CHECK, RAISE, FOLD }; 

class Player {
private:
	Deck hand; // two cards in players hand
	int wallet; // total $ in wallet

public:
	Player(int);

	int getWallet();
	Deck getHand();

	void updateWallet(int);
};

