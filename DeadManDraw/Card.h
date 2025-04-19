#ifndef CARD_H
#define CARD_H
#include <vector>
#include <string>
class Game;
class Player;

enum CardType { Cannon, Chest, Key, Sword, Hook, Oracle, Map, Mermaid, Kraken, Invalid=-1};

/*
* This is the abstract class and allows child classes to override the methods
*/
class Card
{
public:
	
	Card(int value, CardType type);
	virtual ~Card();

	//get point value of card
	int getValue() const;
	
	//display card with its value
	virtual std::string str() const = 0;

	//get card type
	const CardType& getType() const;

	//play card behaviour
	virtual void play(Game& game, Player& player) = 0;

	////play card behaviour in Key-Chest combination
	virtual void willAddToBank(Game& game, Player& player) {};

protected:
	int _pointValue;
	CardType _type;
	
};


#endif //CARD_H