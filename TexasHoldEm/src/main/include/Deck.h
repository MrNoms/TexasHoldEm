#pragma once
#include "Card.h"
#include "Stack.h"

class Deck : public Stack<Card> {
private:
	void transferTo(Deck*, int);

public:
	using Stack<Card>::Stack;

	void getDeck();
	void shuffle();
};