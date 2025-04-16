#ifndef MAPCARD_H
#define MAPCARD_H


#include "Card.h"
class MapCard : public Card
{
public:
	MapCard(int value);
	~MapCard();

	std::string str() const override;
	void play(Game& game, Player& player) override;

};


#endif // MAPCARD_H