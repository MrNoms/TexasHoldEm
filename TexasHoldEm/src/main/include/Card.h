#pragma once
#include <string>

struct Card {

	enum class Suit {DIAMOND, CLUB, HEART, SPADE};

	enum class Number {ACE, TWO, THREE, FOUR, FIVE, SIX,
		SEVEN, EIGHT, NINE, TEN, JACK,
		QUEEN, KING};

	Suit cardSuit;
	Number cardNum;

	Card() {
		*this = Card(Number::ACE, Suit::SPADE);
	}

	Card(Number n, Suit s) {
		cardSuit = s;
		cardNum = n;
	}

	std::string showSuit() {
		switch (cardSuit) {
		case Suit::DIAMOND: return "Diamond";
		case Suit::CLUB: return "Club";
		case Suit::HEART: return "Heart";
		case Suit::SPADE: return "Spade";
		default: return "NONE";
		}
	}

	std::string showNum() {
		std::string num;
		if (cardNum > Number::ACE && cardNum < Number::JACK) {
			num = (char)cardNum + '0';
			return num;
		}
		else switch (cardNum) {
		case Number::JACK: return "J";
		case Number::QUEEN: return "Q";
		case Number::KING: return "K";
		case Number::ACE: return "A";
		default: return "0";
		}
	}

	std::string to_string() {
		return showNum() + " " + showSuit();
	}
};
