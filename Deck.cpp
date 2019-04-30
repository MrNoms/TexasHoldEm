#include "Deck.h"

Deck::Deck() {
	Suit s = DIAMOND;
	while (s <= SPADE) {
		Number n = TWO;
		while (n <= ACE) {
			Card newCard(s, n);
			Pile.add(newCard);
			n = static_cast<Number> (n + 1);
		}
		s = static_cast<Suit> (s + 1);
	}
}

Card Deck::Deal() {
	return Pile.pop();
}

void Deck::Reset(Deck & other) {
	while (!Pile.isEmpty())
		other.Pile.add(Deal());
}

void Deck::Shuffle(Deck & other) {
	Deck waiting;
	//check the top card of other deck
	Card check = other.Deal();
	//its number will be how many we skip
	int skip = check.thisNum;
	//put that card in this deck
	this->Pile.add(check);
	while (!other.Pile.isEmpty()) {
		//move # of cards to waiting deck
		for (int i = 0; i < skip && !other.Pile.isEmpty(); i++) {
			waiting.Pile.add(other.Deal());
		}
		//put current top of other deck into this
		this->Pile.add(other.Deal());
	}
	if (!this->Pile.isFull()) this->Shuffle(waiting);
}
