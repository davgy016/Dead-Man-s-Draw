#ifndef DECK_H
#define DECK_H


#include "CardContainer.h"


class Deck : public CardContainer< VectorContainer>
{
public:
	Deck();
	~Deck();

	//create all the cards
	void initialise();
	
	void shuffleDeck();
	
	//peek top card of Deck
	Card* peekCard()const;

	Card* removeCard() override;
	
};

#endif // DECK_H
