#include "Game.h"

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

			switch(phase) {

			case PRE_FLOP :
				// collect ante
				for (int i = 0; i < Table->getListSize(); i++) {

					// Logic Error?
					// if player kicked, does it skip the next players opportunity to ante?
					try {
						setPot(PayIn(Table->getNextNode()->data, Ante));
					}
					catch (InsufficientFunds) {
						Kick(Table->getCurrPos()->data);
					}
				}
				Table->resetList();

				// deal hands - separate from collect ante loop b/c player may not be able to ante
				for (int i = 0; i < Table->getListSize(); i++) {
					Table->getNextNode()->data.setHand(PlayCards.Deal(), PlayCards.Deal());
				}
				Table->resetList();

				// bet round
				// go around table
				// check Player fold?
				// get player choice - check, raise fold
				// go around until all even/checked
				getBets();

				break;
			case FLOP :
				// play 3 card to table
				// bet round
				break;
			case TURN :
				// play 1 card to table
				// bet round
				break;
			case RIVER :
				// play 1 card to table
				// bet round
				break;
			case SHOW :
				// reveal winner
				// distribute winnings
				break;
			default :
				break;
			} // switch
		
		} // while

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
}

Game::Game()
{
	//Table = new CircleList<Player>();
	phase = PRE_FLOP;
	numPlayers = 0;
	Ante = 5;
	Pot = 0;
	totalBet = 0;
	betsComplete = false;
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

	Table->putNode(*newPlayer);			// is *newPlayer a correct parameter logically for this function?
}

void Game::Kick(Player)
{
	// Table.listSize()--;
}

void Game::getBets()
{
	Table->resetList();
	bool totalBetChange = false;

	// while (!betsComplete) { 
	// for loop of Table.length, recursive whenever someone folds?
	for (int i = 0; i < Table->getListSize(); i++) {
		
		// if next player elected to FOLD, skip
		if (Table->getCurrPos()->next->data.getPlayerChoice != FOLD) {

			Table->getNextNode()->data.setPlayerChoice();

			switch (Table->getCurrPos()->data.getPlayerChoice()) {
			case CHECK:
				// if all check cont
				if (Table->getCurrPos()->data.getPlayerBet() == totalBet)
					break;
				else
					// ...Player must meet totalBet or fold
					do {
						cout << "Must meet current bet, or fold!" << endl;
						// display how much more must be bet
						Table->getCurrPos()->data.setPlayerChoice();
					} while (Table->getCurrPos()->data.getPlayerChoice() == CHECK);
			case RAISE:
				totalBetChange = true;
				Table->getCurrPos()->data.setPlayerBet();
				setPot(PayIn(Table->getCurrPos()->data, Table->getCurrPos()->data.getPlayerBet()));
				totalBet += Table->getCurrPos()->data.getPlayerBet();
				break;
			case FOLD:
				Table->getCurrPos()->data.setFold(true);
				break;
			default:
				return;
			}
		}
		else
			Table->getNextNode();

	}

	if (totalBetChange) // all playerc met totalBet
		getBets();		// traverse list again, skip any players who have folded
}


