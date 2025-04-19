#ifndef CARDCONTAINER_H
#define CARDCONTAINER_H
#include "Card.h"
#include <string>
#include <vector>
#include <map>

typedef std::vector<Card*> VectorContainer;
typedef std::map<CardType, std::vector<Card*>> MapContainer;

template<typename ContainerType>


/*This is the abstract template class for card containers. 
* This common functionalieties can be override in child classes
* some methods are commented and have not been used but left for future development
*/
class CardContainer
{
protected:
	ContainerType cards;

public:
	CardContainer() {};
	virtual ~CardContainer() = 0;
	
	//add card into the target card container
	virtual void addCard(Card* card) {};
	//virtual Card* removeCard(int index) { return nullptr; }
	
	//remove card from the card container by specific card type
	virtual Card* removeCardByType(CardType type) { return nullptr; };

	//simple removes card from the card container
	virtual Card* removeCard() { return nullptr; };

	//get size of the card container
	virtual int size() const { return cards.size(); }
	
	//virtual bool isEmpty() const { return cards.empty(); }
	
	//get top card of specific type
	//virtual Card* getTopCardOfType(CardType type) { return nullptr; }
	
	//virtual void clear() {};

	//get all cards from card container
	virtual ContainerType& getCards() { return cards; }	

};
// Template destructor implementation
template<typename ContainerType>
CardContainer<ContainerType>::~CardContainer() {}


#endif // CARDCONTAINER_H
