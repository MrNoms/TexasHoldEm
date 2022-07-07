#include "Game.h"

int main(int argc, char* argv[]) {
	SingleLink<Card> cl = SingleLink<Card>(Card());
	cl.next = new SingleLink<Card>(Card(Card::Number::KING, Card::Suit::DIAMOND));
	cout << cl.to_string() << cl.next->to_string() << endl;

	return 0;
}