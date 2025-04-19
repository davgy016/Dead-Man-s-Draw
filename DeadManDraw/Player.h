#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "PlayArea.h"

class Game;
class Bank;
class Card;

/*
* This is a player class, which manages card additing and removing for PlayArea and Bank.
* Provide each player details along with name, score, existing bank cards, player bust status
*/


class Player
{
protected:
	std::string _name;
	PlayArea* _playArea;
	Bank* _bank;
	bool _busted;


public:
	Player();
	~Player();

	//select player with a random name
	void initialise();

	//get name of player
	const std::string& getName() const;

	//get card collection of playArea
	PlayArea* getPlayArea()const;

	//get card collection of bank
	Bank* getBank() const;

	//get bust
	bool hasBusted() const;

	// plays the card into the play area 
	// returns true if this causes the player to bust,  
	// otherwise the card's ability is performed and this function returns false 
	bool playCard(Card* card, Game& game);

	// Bank the cards from the playe area
	void bankCards(Game& game);

	//display cards of play area
	void printPlayerArea() const;

	//display cards of bank
	void printBank() const;

	//display score of the player
	int getScore() const;

	//allows player select the card from bank e.g. play Hook, Sword, Cannon
	CardType selectCardTypeFromBank(Game& game, Player* targetPlayer);

	//set bust
	void setBusted(bool busted);
};

#endif //PLAYER_H

