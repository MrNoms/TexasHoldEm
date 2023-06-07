#include "Game.h"

int main(int argc, char* argv[]) {
	SingleLink<Card> cl = SingleLink<Card>(Card());
	cl.next = new SingleLink<Card>(Card(Number::KING, Suit::DIAMOND));
	cout << cl.toString() << cl.next->toString() << endl;

	return 0;
}