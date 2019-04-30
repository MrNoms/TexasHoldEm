#pragma once
#include "ArrStack.cpp"
#include "Card.h"

class Deck {
private:
	ArrStack<Card> Pile =
		ArrStack<Card> (MAX);
public:
	const int MAX = 52;
	Deck();
	Card Deal();
	void Reset(Deck &);
	void Shuffle(Deck &);
};
