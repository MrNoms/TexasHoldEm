#include "Game.h"

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
		// collect ante
		// deal hands
		// bet round
		// play 3 card to table
		// bet round
		// play 1 card to table
		// bet round
		// play 1 card to table
		// bet round
		// reveal winner
	}
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


