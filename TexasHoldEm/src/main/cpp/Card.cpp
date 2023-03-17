#include <sstream>

#include "Card.h"

Card::Card() {
	*this = Card(Number::ACE, Suit::SPADE);
}

Card::Card(Number n, Suit s) {
	cardSuit = s;
	cardNum = n;
}

string Card::showSuit() {
	switch (cardSuit) {
	case Suit::DIAMOND: return "Diamond";
	case Suit::CLUB: return "Club";
	case Suit::HEART: return "Heart";
	case Suit::SPADE: return "Spade";
	default: return "SUIT";
	}
}

string Card::showNum() {
	if (cardNum < Number::JACK) {
		return to_string((int)cardNum + 2);
	}
	else switch (cardNum) {
	case Number::JACK: return "J";
	case Number::QUEEN: return "Q";
	case Number::KING: return "K";
	case Number::ACE: return "A";
	default: return "NUMBER";
	}
}

int Card::compare(Card other) {
	if (this->cardNum < other.cardNum) return -1;
	else if (this->cardNum > other.cardNum) return 1;
	else {
		if (this->cardSuit < other.cardSuit) return -1;
		else if (this->cardSuit > other.cardSuit) return 1;
		else return 0;
	}
}

string Card::toString() {
	ostringstream strm;
	strm << showNum() << " " << showSuit();
	return strm.str();
}

bool operator == (const Card& lhs, const Card& rhs) {
	return lhs.cardNum == rhs.cardNum && lhs.cardSuit == rhs.cardSuit;
}

bool operator > (const Card& lhs, const Card& rhs) {
	return lhs.cardNum > rhs.cardNum ||
		(lhs.cardNum == rhs.cardNum && lhs.cardSuit > rhs.cardSuit);
}

bool operator < (const Card& lhs, const Card& rhs) {
	return lhs.cardNum < rhs.cardNum ||
		(lhs.cardNum == rhs.cardNum && lhs.cardSuit < rhs.cardSuit);
}

ostream& operator << (ostream& lhs, Card& rhs) {
	lhs << rhs.toString();
	return lhs;
}