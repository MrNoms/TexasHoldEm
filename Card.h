#pragma once
#include <string>

	enum Suit
	{NONE, DIAMOND, CLUB, HEART, SPADE};
	enum Number
	{ZERO, TWO, THREE, FOUR, FIVE, SIX,
		SEVEN, EIGHT, NINE, TEN, JACK,
		QUEEN, KING, ACE};

struct Card {
	Suit thisSuit = NONE;
	Number thisNum = ZERO;

	std::string showSuit() {
		switch (thisSuit) {
		case DIAMOND: return "Diamond";
			break;
		case CLUB: return "Club";
			break;
		case HEART: return "Heart";
			break;
		case SPADE: return "Spade";
			break;
		}
	}

	char showNum() {
		char num = '0';
		if (thisNum && thisNum < JACK)
			return thisNum + num;
		switch (thisNum) {
		case JACK: return 'J';
			break;
		case QUEEN: return 'Q';
			break;
		case KING: return 'K';
			break;
		case ACE: return 'A';
			break;
		}
	}
};
