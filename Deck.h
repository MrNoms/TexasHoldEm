#pragma once
#include "ArrStack.cpp"
#include "Card.h"

class Deck {
private:
	ArrStack<Card> Pile;
	ArrStack<Card> Discard;
public:
	Deck();
	~Deck();
	Card Deal();
	void Reset();
	void Shuffle();
};
