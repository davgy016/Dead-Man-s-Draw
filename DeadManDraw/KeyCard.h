#ifndef KEYCARD_H
#define KEYCARD_H
#include "Card.h"

class KeyCard : public Card
{
public:
	KeyCard(int value);
	~KeyCard();

	std::string str() const override;
	void play(Game& game, Player& player) override;
	void willAddToBank(Game& game, Player& player) override;
};

#endif // KEYCARD_H