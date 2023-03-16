#pragma once
#include "ArrStack.cpp"
#include "Card.h"

class Deck : public ArrStack<Card> {
private:
	const int MAX = 52;

public:
	Deck() : ArrStack<Card>(MAX) {}
	~Deck();

	Deck* getDeck();
	void ShuffleInto(Deck &);
};