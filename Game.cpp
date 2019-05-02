#include "Game.h"

void Game::setAnte()
{
	Ante = Ante + 5;
}

void Game::Play()
{
	// Initialize game, introduce settings
	cout << "===============================" << endl;
	cout << "|| Welcome to Texas Hold 'Em!||" << endl;
	cout << "===============================" << endl;
	cout << endl << "Game Length: 10 rounds" << endl;

	cout << "Enter number of players [1-6]: ";
	cin >> numPlayers;

	for (int i = 0; i < numPlayers; i++) {
		Add2Table(i+1); // adds a player to Table for each iteration
	}

	// Main Game Loop
	for (int currRound = 1; currRound < Rounds; currRound++) {

		while (phase != SHOW) {

			switch (phase) {

			case (PRE_FLOP):
				// collect ante
				for (int i = 0; i < Table.getListSize(); i++) {
				//	setPot(PayIn(Table.getNextNode, Ante));
				//	How do I access the current Player in Table?
				//  shouldn't it be Table.getNextNode(), not Table.getNextNode?
				}
				// deal hands
				// bet round
				break;
			case (FLOP):
				// play 3 card to table
				// bet round
				break;
			case (TURN):
				// play 1 card to table
				// bet round
				break;
			case (RIVER):
				// play 1 card to table
				// bet round
				break;
			case (SHOW):
				// reveal winner
				// distribute winnings
				break;
			default:

			} // switch

		} // while

		setAnte(); // increases Ante by 5 credits

	} // for

} // Play()

Game::Game()
{
	phase = PRE_FLOP;
	numPlayers = 0;
	Ante = 5;
	Pot = 0;
	totalBet = 0;
}

Game::~Game()
{
	// don't forget to delete Table!!
}

void Game::Add2Table(int playerNum)
// Creates a player, and adds them to the Circular linked list Table
// Input: int to set player number
{
	Player * newPlayer = new Player();
	newPlayer->setPlayerNumber(playerNum);

	Table.putNode(*newPlayer);			// is *newPlayer a correct parameter logically for this function?
}


