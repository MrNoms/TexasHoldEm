#pragma once

	enum Suit {NONE, DIAMOND, CLUB, HEART, SPADE};
	enum Number {ZERO, TWO, THREE, FOUR, FIVE, SIX, SEVEN,
		EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE};

struct Card {
	Suit thisSuit = NONE;
	Number thisNum = ZERO;
};
