#ifndef PLAYAREA_H
#define PLAYAREA_H

#include "CardContainer.h"

/*
* This is the class where player plays the cards 
* Contains the rule of the game when it has bust
* Inherits from CardContainer with specific container type
*/

class PlayArea : public CardContainer<VectorContainer>
{
public:
	PlayArea();
	~PlayArea();

	//add card into play area
	void addCard(Card* card) override;
	
	//check play area is busted or not
	bool isBust(Card* newCard) const;

	//void clear() override;	

	//remove all cards when is busted
	void moveAllCardsTo(VectorContainer& container);
};


#endif // PLAYAREA_H