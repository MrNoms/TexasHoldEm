#include <random>

#include "Deck.h"

using namespace std;

void Deck::getDeck() {
	for (int i = 0; i < 52; i++) {
		this->add(Card(Number(i % 13), Suit(i / 13)));
	}
}

void Deck::shuffle() {
	//set up random numbers
	random_device rd;
	mt19937 eng(rd());
	uniform_int_distribution<> distro(-9, 9);
	
	//Cut the deck at 26 +- random, result is two smaller decks
	int cut = distro(eng);
	Deck* halves = new Deck[2];

	transferTo(halves, 26 + cut);
	transferTo(halves + 1, 26 - cut);

	//Put few cards from one stack back in original
	distro.param(uniform_int_distribution<>::param_type(1, 4));

	int deck = 0;
	while (!(halves[0].isEmpty() && halves[1].isEmpty())) {
		halves[deck].transferTo(this, distro(eng));
		deck = (deck + 1) % 2;
		//Switch off randomly
	}

	delete[] halves;
}

void Deck::transferTo(Deck* d, int cards) {
	try {
		for (int i = 0; i < cards; i++) { d->add(this->pop()); }
	}
	catch (std::logic_error) {}
}