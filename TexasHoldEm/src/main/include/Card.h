#pragma once
#include <string>
#include <sstream>
using namespace std;

enum class Suit {DIAMOND, CLUB, HEART, SPADE};

enum class Number {TWO, THREE, FOUR, FIVE, SIX,
	SEVEN, EIGHT, NINE, TEN, JACK,
	QUEEN, KING, ACE};

struct Card {
	Suit cardSuit;
	Number cardNum;

	Card();
	Card(Number n, Suit s);

	string showSuit();

	string showNum();

	int compare(Card);

	string toString();

	friend bool operator == (const Card&, const Card&);

	friend bool operator > (const Card&, const Card&);

	friend bool operator < (const Card&, const Card&);

	friend ostream& operator << (ostream&, Card&);
};
