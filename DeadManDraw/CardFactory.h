#ifndef CARDFACTORY_H
#define CARDFACTORY_H
#include "Card.h"

class CardFactory
{
public:
	CardFactory() = default;
	~CardFactory() = default;

	//create a card of specified type and value 
	static Card* createCard(CardType type, int value);
	//create range of cards of specified type
	static std::vector<Card*> createCardsOfType(CardType type);
	//create all cards of all type
	static std::vector<Card*> createAllCards();

protected:
	static int getMinValue(CardType type);
	static int getMaxValue(CardType type);	

};


#endif // CARDFACTORY_H