#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Deck.h"
#include "DiscardPile.h"
#include <vector>


/*
* This is the central contoller class and uses Singleton pattern, has only one instance at any time
* Manages all the game components and game flow
*/

class Game
{
protected:
	Deck* _deck;
	DiscardPile* _discardPile;
	std::vector<Player*> _players;
	int _currentPlayerIndex;
	int _currentRound;
	int _currentTurn;
	int _maxTurns;
	Game();
	Game& operator=(const Game&) = delete;
	Game(const Game&) = delete;

public:
	~Game();
	
	//create Game instance
	static Game& getInstance();

	//initialise players, deck and dicardPile
	void initialiseGame();

	//start game and manage game round and turn
	void startGame();

	//end game with showing winner
	void endGame();

	//get deck card collection
	Deck* getDeck()const;

	//get DiscardPile card collection
	DiscardPile* getDiscardPile() const;

	//get current player
	Player* getCurrentPlayer() const;

	//get opponent player
	Player* getOtherPlayer() const;

	//get current round number
	int getCurrentRound() const;

	//get current turn number
	int getCurrentTurn() const;

	//manage game flow and player turns
	void handlePlayerTurn();

	//get next player
	void nextPlayer();	

	//display game state such as round and turn
	void printGameState();



};

#endif // GAME_H
