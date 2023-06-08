#include "pch.h"
#include "CppUnitTest.h"
#include "..\include\Player.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PlayerTest {
	TEST_CLASS(PlayerTest) {
	public:
		TEST_METHOD(Construction) {
			//create a player
			//confirm the wallet amount
			//ensure the id is populated
			//ensure the hand is empty
		}

		TEST_METHOD(Wallet_Update) {
			//create a player
			//add money to wallet and verify
		}

		TEST_METHOD(All_In) {
			//if betting equal to or more than player wallet
		}

		TEST_METHOD(Give_Card) {
			//create player to give a card
			//verify the size of the player's hand
		}
	};
}