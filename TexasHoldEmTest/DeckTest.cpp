#include "pch.h"
#include "CppUnitTest.h"
#include "..\cpp\Deck.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DeckTest {
	TEST_CLASS(DeckTest) {
	public:

		TEST_METHOD(Construction) {
			//start a deck of cards
			Deck d = Deck();

			//verify it's empty
			Assert::IsTrue(d.isEmpty());
		}

		TEST_METHOD(Creation) {
			//start and get a deck of cards
			Deck d = Deck(); d.getDeck();

			//verify its size
			Assert::AreEqual(52, d.getSize());

			//peek the top card is A Spade
			Assert::IsTrue(Card() == d.peek());

			// ensure there are no duplicates
			Assert::IsFalse(duplicatesPresent(d));
		}

		TEST_METHOD(Shuffle) {
			Deck d = Deck(); d.getDeck();
			int check = d.getSize();
			d.shuffle();

			//ensure the deck is the same size
			Assert::AreEqual(check, d.getSize());

			//ensure there are no duplicates
			Assert::IsFalse(duplicatesPresent(d));
		}

	private:
		bool duplicatesPresent(Deck& d) {
			int suits = 0, nums = 0;

			//when checking a full deck, there are 52 cards
			while (!d.isEmpty()) {
				Card c = d.pop();
				//suits add up to 13*SUM(0->3) = 13 * 6 = 78
				suits += (int)c.cardSuit;

				//numbers add up to 4*SUM(0->12) = 4 * 72 = 288
				nums += (int)c.cardNum;
			}

			return !(suits == 78 && nums == 312);
		}
	};
}