#pragma once
#include "Deck.h"
#include <string>

enum class PlayerChoice { CHECK, RAISE, FOLD }; 

class Player {
private:
	Deck hand; // two cards in players hand
	int wallet; // total $ in wallet
	std::string name;

	PlayerChoice decision;

public:
	Player();

	int getWallet();
	Deck getHand();
	std::string getName();

	void setDecision(PlayerChoice);
	PlayerChoice getDecision();

	void updateWallet(int);
};

