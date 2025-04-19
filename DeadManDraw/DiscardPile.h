#ifndef DISCARDPILE_H
#define DISCARDPILE_H

#include "CardContainer.h" 

/*
* This class stores discarded cards
* Inherits from CardContainer with specific container type
*/

class DiscardPile : public CardContainer< VectorContainer>
{
public:
	DiscardPile();
	~DiscardPile();

	//add card into discardPile
	void addCard(Card* card) override;

	//bool isEmpty() const override;

	//remove multiple cards. e.g. check MapCardm, Chest-Key ability
	VectorContainer drawCards(int numOfCards);

	// add multiple cards. e.g when it is bust
	void addCards(const VectorContainer& newCards);

	//get card collection of discardPile
	VectorContainer& getCards() override;
};


#endif // DISCARDPILE_H