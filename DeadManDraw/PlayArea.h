#ifndef PLAYAREA_H
#define PLAYAREA_H

#include "CardContainer.h"
class PlayArea : public CardContainer
{
public:
	PlayArea();
	~PlayArea();

	bool isBust();

	void moveAllCardsTo(CardCollection& container);
};


#endif // PLAYAREA_H