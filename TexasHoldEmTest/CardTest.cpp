#include "pch.h"
#include "CppUnitTest.h"
#include "..\cpp\Card.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CardTest {

	TEST_CLASS(CardTest) {
	public:
		TEST_METHOD(Default_Card) {
			//default construction gives the Ace of Spades
			Card def = Card();
			
			Assert::AreEqual((int)Number::ACE, (int)def.cardNum);
			Assert::AreEqual((int)Suit::SPADE, (int)def.cardSuit);
		}

		TEST_METHOD(Construction) {
			//verify the Suit and Number of some Cards
			Card one(Number::EIGHT, Suit::DIAMOND);

			Assert::AreEqual((int)Number::EIGHT, (int)one.cardNum);
			Assert::AreEqual((int)Suit::DIAMOND, (int)one.cardSuit);
		}

		TEST_METHOD(Suits) {
			//All suits should be spelled out as singular Capital
			Assert::AreEqual(0,
				Card().showSuit().compare("Spade"));
			
			Assert::AreEqual(0,
				Card(Number::ACE, Suit::HEART).showSuit().compare("Heart"));

			Assert::AreEqual(0,
				Card(Number::ACE, Suit::CLUB).showSuit().compare("Club"));

			Assert::AreEqual(0,
				Card(Number::ACE, Suit::DIAMOND).showSuit().compare("Diamond"));
		}

		TEST_METHOD(Numbers) {
			//All numbers are strings of themselves or single CAPS letters
			Assert::AreEqual(0, Card().showNum().compare("A"));

			Assert::AreEqual(0,
				Card(Number::EIGHT, Suit::CLUB).showNum().compare("8"));

			Assert::AreEqual(0,
				Card(Number::TEN, Suit::CLUB).showNum().compare("10"));

			Assert::AreEqual(0,
				Card(Number::QUEEN, Suit::CLUB).showNum().compare("Q"));

			Assert::AreEqual(0,
				Card(Number::JACK, Suit::CLUB).showNum().compare("J"));

			Assert::AreEqual(0, 
				Card(Number::KING, Suit::CLUB).showNum().compare("K"));
		}

		TEST_METHOD(Display) {
			//Ace of Spades = A Spade
			Assert::AreEqual(0, Card().toString().compare("A Spade"));

			//Four of Hearts = 4 Heart
			Assert::AreEqual(0,
				Card(Number::FOUR, Suit::HEART).toString().compare("4 Heart"));

			Assert::AreEqual(0,
				Card(Number::TEN, Suit::SPADE).toString().compare("10 Spade"));
		}

		TEST_METHOD(Compare_Different_Number) {
			//By default, hierarchy is 2 -> 10, J, Q, K, A, regardless of suit
			Card two(Number::TWO, Suit::CLUB);
			Card eit(Number::EIGHT, Suit::DIAMOND);
			Card jak(Number::JACK, Suit::CLUB);
			Card kng(Number::KING, Suit::SPADE);
			Card ace(Number::ACE, Suit::HEART);

			Assert::AreEqual(-1, two.compare(eit));
			Assert::AreEqual(0, two.compare(two));
			Assert::AreEqual(1, eit.compare(two));
			Assert::AreEqual(-1, jak.compare(ace));
			Assert::AreEqual(1, kng.compare(jak));
		}

		TEST_METHOD(Compare_Same_Number) {
			//If numbers are the same, hierarchy is Diamond, Club, Heart, Spade
			Card dim(Number::ACE, Suit::DIAMOND);
			Card clb(Number::ACE, Suit::CLUB);
			Card hrt(Number::ACE, Suit::HEART);
			Card spd(Number::ACE, Suit::SPADE);

			Assert::AreEqual(0, dim.compare(dim));
			Assert::AreEqual(-1, dim.compare(clb));
			Assert::AreEqual(-1, clb.compare(spd));
			Assert::AreEqual(1, hrt.compare(dim));
			Assert::AreEqual(1, spd.compare(clb));
		}

		TEST_METHOD(Equal_To) {
			Card twoC(Number::TWO, Suit::CLUB);
			Card aceH(Number::ACE, Suit::HEART);
			Card aceD(Number::ACE, Suit::DIAMOND);

			//same card, compare returns 0, return true
			Assert::IsTrue(twoC == twoC);

			//otherwise false
			Assert::IsFalse(twoC == aceH);
			Assert::IsFalse(twoC == aceD);
		}

		TEST_METHOD(Greater_Than) {
			Card twoC(Number::TWO, Suit::CLUB);
			Card aceH(Number::ACE, Suit::HEART);
			Card aceD(Number::ACE, Suit::DIAMOND);

			//compare returns 1, return true
			Assert::IsTrue(aceH > aceD);
			Assert::IsTrue(aceH > twoC);
			Assert::IsTrue(aceD > twoC);

			//otherwise false
			Assert::IsFalse(twoC > aceD);
			Assert::IsFalse(aceD > aceH);
		}

		TEST_METHOD(Less_Than) {
			Card twoC(Number::TWO, Suit::CLUB);
			Card aceH(Number::ACE, Suit::HEART);
			Card aceD(Number::ACE, Suit::DIAMOND);

			//compare returns -1, return true
			Assert::IsTrue(twoC < aceH);
			Assert::IsTrue(twoC < aceD);
			Assert::IsTrue(aceD < aceH);

			//other false
			Assert::IsFalse(aceH < aceD);
			Assert::IsFalse(aceD < twoC);
		}
	};

}