#ifndef DECK_H
#define DECK_H

#include "CardContainer.h"

/*
* This class stores all the cards of all suits
* Inherits from CardContainer with specific container type
*/

class Deck : public CardContainer< VectorContainer>
{
public:
	Deck();
	~Deck();

	//create all the cards
	void initialise();
	
	//shuffle deck
	void shuffleDeck();
	
	//peek top card of Deck
	Card* peekCard()const;

	//remove card from deck
	Card* removeCard() override;
	
};

#endif // DECK_H
