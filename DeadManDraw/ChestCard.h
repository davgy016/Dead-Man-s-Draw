#ifndef CHESTCARD_H
#define CHESTCARD_H

#include "Card.h"
class ChestCard : public Card
{
public:
	ChestCard(int value);
	~ChestCard();

	std::string str() const override;
	void play(Game& game, Player& player) override;
	void willAddToBank(Game& game, Player& player) override;
};


#endif // CHESTCARD_H