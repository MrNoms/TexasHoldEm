#include "Game.h"
/*
Game::Game() {
	Ante = 5;
	Pot = 0;
	totalBet = 0;
	tableCards = 0;

	dealer = new Player();
}

Game::~Game()
{
	//delete dealer;
}

void Game::setPot(int fundsIn)
{
	Pot += fundsIn;
}

void Game::setAnte()
{
	Ante = Ante + 5;
}

int Game::getPot()
{
	return Pot;
}

void Game::Play()
{
	// Initialize game, introduce settings
	cout << "===============================" << endl
		 << "|| Welcome to Texas Hold 'Em!||" << endl
		 << "===============================" << endl << endl
		<< "Game Length: " << _ROUNDS << " rounds" << endl;

	cout << "Enter number of players [1-6]> "; {
		int input;
		cin >> input;

		for (int i = 0; i < input; i++) {
			//addToTable();
		}
	}

	
	// Main Game Loop
	RoundPhase phase;
	for (int currRound = 0; currRound < _ROUNDS; currRound++) {

		

		phase = RoundPhase::PRE_FLOP;

		switch (phase) {

		case PRE_FLOP:
			// collect ante
			for (int i = 0; i < table->size(); i++) {

				// Logic Error?
				// if player kicked, does it skip the next players opportunity to ante?
				try {
					setPot(PayIn(table->getNextNode()->data, Ante));
				}
				catch (InsufficientFunds) {
					Kick(table->getCurrPos()->data);
				}
			}
			table->clear();

			// deal hands - separate from collect ante loop b/c player may not be able to ante
			for (int i = 0; i < table->size(); i++) {
				table->getNextNode()->data.setHand(PlayCards.Deal(), PlayCards.Deal());
			}
			table->clear();

			getBets();  // Players should have opportunity to check cards before bet	<---------------- DO THIS
			phase = FLOP;
			
		case FLOP:
			// play 3 card to table
			CommCards[0] = PlayCards.Deal();
			CommCards[1] = PlayCards.Deal();
			CommCards[2] = PlayCards.Deal();
			tableCards = 3;

			// bet round
			getBets();

		case TURN:
			// play 1 card to table
			CommCards[3] = PlayCards.Deal();
			tableCards++;

			// bet round
			getBets();

		case RIVER:
			// play 1 card to table
			CommCards[4] = PlayCards.Deal();
			tableCards++;

			// bet round
			getBets();

		case SHOW:
			// reveal winner
			// distribute winnings
			
		default:
			break;
		} // switch

		setAnte(); // increases Ante by 5 credits

	} // for
	
} // Play()

int Game::PayIn(Player currPlayer, int betIn)
// PayIn takes player and amount the player must contribute to the pot
// returns amount to be placed into pot
{
	if (betIn > currPlayer.getWallet())
		throw InsufficientFunds();
	else {
		currPlayer.subWallet(betIn);
		return betIn;
	}
	return 0;
}

void Game::displayCommCards()
{
	if (tableCards == 3) {
		cout << "Community Cards" << endl;
		cout << CommCards[0].showNum << " " << CommCards[0].showSuit << endl;
		cout << CommCards[1].showNum << " " << CommCards[1].showSuit << endl;
		cout << CommCards[2].showNum << " " << CommCards[2].showSuit << endl;

		cout << "Your Cards" << endl;
		table->getCurrPos()->data.displayHand();
	}
	else if (tableCards == 4) {
		cout << "Community Cards" << endl;
		cout << CommCards[0].showNum << " " << CommCards[0].showSuit << endl;
		cout << CommCards[1].showNum << " " << CommCards[1].showSuit << endl;
		cout << CommCards[2].showNum << " " << CommCards[2].showSuit << endl;
		cout << CommCards[3].showNum << " " << CommCards[3].showSuit << endl;
		cout << "Your Cards" << endl;
		table->getCurrPos()->data.displayHand();
	}
	else if (tableCards = 5) {
		cout << "Community Cards" << endl;
		cout << CommCards[0].showNum << " " << CommCards[0].showSuit << endl;
		cout << CommCards[1].showNum << " " << CommCards[1].showSuit << endl;
		cout << CommCards[2].showNum << " " << CommCards[2].showSuit << endl;
		cout << CommCards[3].showNum << " " << CommCards[3].showSuit << endl;
		cout << CommCards[4].showNum << " " << CommCards[4].showSuit << endl;
		cout << "Your Cards" << endl;
		table->getCurrPos()->data.displayHand();
	}
	else {
		cout << "Your Cards" << endl;
		table->getCurrPos()->data.displayHand();
	}
}

void Game::addToTable() {
// Creates a player, and adds them to the Circular linked list Table
// Input: int to set player number

	//table.putNode(*(new Player));
}

void Game::Kick(Player exitPlayer)
{
	//table->deleteNode(exitPlayer);
	//table->setListSize(-1);
}

void Game::getBets()
{
	table->clear();
	bool totalBetChange = false;

	// for loop of Table.length. Traverse table
	for (int i = 0; i < table->size(); i++) {
		
		// if next player elected to FOLD, skip
		if (table->getCurrPos()->next->data.getPlayerChoice != FOLD) {

			// display cards
			displayCommCards();

			// get player choice
			table->getNextNode()->data.setPlayerChoice();

			switch (table->getCurrPos()->data.getPlayerChoice()) {
			case CHECK:

				// If no new bets have been made
				if (table->getCurrPos()->data.getPlayerBet() == totalBet)
					break;
				else
					// ...Player must meet totalBet or fold
					do {
						cout << "Must meet current bet, or fold!" << endl;
						// display how much more must be bet		<--------------- DO THIS
						table->getCurrPos()->data.setPlayerChoice();
					} while (table->getCurrPos()->data.getPlayerChoice() == CHECK);

			case RAISE:

				totalBetChange = true;
				table->getCurrPos()->data.setPlayerBet();
				setPot(PayIn(table->getCurrPos()->data, table->getCurrPos()->data.getPlayerBet()));
				totalBet += table->getCurrPos()->data.getPlayerBet();
				break;

			case FOLD:

				table->getCurrPos()->data.setFold(true);
				break;

			default:
				return;
			} // switch

		} // if Player.fold() == false
		else
			table->getNextNode();

	} // for loop to traverse table

	if (totalBetChange) // all playerc met totalBet
		getBets();		// traverse list again, skip any players who have folded
}


*/