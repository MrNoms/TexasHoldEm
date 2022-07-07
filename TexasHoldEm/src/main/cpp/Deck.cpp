#include "Deck.h"

Deck::~Deck() {
	delete[] getStack();
}

Deck* Deck::getDeck() {
	Card::Suit s = Card::Suit::DIAMOND;
	while (s <= Card::Suit::SPADE) {
		Card::Number n = Card::Number::ACE;
		while (n <= Card::Number::KING) {
			add(Card(n,s));
			n = Card::Number((int)n + 1);
		}
		s = Card::Suit((int)s + 1);
	}
	return this;
}

void Deck::ShuffleInto(Deck & other) {
	Deck waiting;

	int skip;
	while (!this->isEmpty()) {
		other.add(this->pop());
		skip = (int)other.peek().cardNum + 1;
		for (int i = 0; i < skip; i++) waiting.add(this->pop());
	}
	if(!other.isFull()) waiting.ShuffleInto(other);
}