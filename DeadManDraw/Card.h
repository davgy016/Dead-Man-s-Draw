#ifndef CARD_H
#define CARD_H
#include <vector>
#include <string>
#include "Game.h"
#include "Player.h"

enum CardType { Cannon, Chest, Key, Sword, Hook, Oracle, Map, Mermaid, Kraken };

class Card
{
public:
	
	Card(int value);
	virtual ~Card();
	
	int getValue() const;
	virtual std::string str() const = 0;
	const CardType& type() const;
	virtual void play(Game& game, Player& player) = 0;
	virtual void willAddToBank(Game& game, Player& player) {};

protected:
	int _pointValue;
	
};


#endif //CARD_H