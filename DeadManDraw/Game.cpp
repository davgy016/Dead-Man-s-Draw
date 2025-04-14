#include "Game.h"
#include <iostream>


Game::Game() :
	_currentPlayerIndex(0),
	_currentRound(1),
	_currentTurn(1),
	_maxTurns(20)
{
	_deck = nullptr;
	_discardPile = nullptr;
}

Game::~Game()
{
	delete _deck;
	delete _discardPile;	
	for (Player* player : _players) {
		delete player;
	}
	
}

//ensure only one game instance exists at all time
Game& Game::getInstance()
{
	static Game instance;
	return instance;
}
//initialise all necessary components for the game
void Game::initialiseGame()
{
	_deck = new Deck();
	_discardPile = new DiscardPile();

	_deck->initialise();
	_deck->shuffleDeck();
	

	_players.push_back(new Player());
	_players.push_back(new Player());

	_currentPlayerIndex = 0;
	_currentRound = 0;
	_currentTurn = 0;
}

void Game::startGame()
{
	
}

void Game::endGame()
{
	
}

Deck* Game::getDeck() const
{
	return _deck;
}

DiscardPile* Game::getDiscardPile() const
{
	return _discardPile;
}

Player* Game::getCurrentPlayer() const
{
	return _players[_currentPlayerIndex];
}

Player* Game::getOtherPlayer() const
{
	return _players[(_currentPlayerIndex+1)%2];
}

int Game::getCurrentRound() const
{
	return _currentRound;
}

int Game::getCurrentTurn() const
{
	return _currentTurn;
}

void Game::handlePlayerTurn()
{
	
}

void Game::nextPlayer()
{	
}

void Game::handleBust(Player* player)
{
	
}

void Game::printGameState()
{
	
}
