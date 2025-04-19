#include "PlayArea.h"
#include <iostream>

PlayArea::PlayArea():
	CardContainer<VectorContainer>()
{
}

PlayArea::~PlayArea()
{
	cards.clear();
	std::cout << "Play Area Destroyed" << std::endl;
}

//add card into play area
void PlayArea::addCard(Card* card)
{
	if (card != nullptr) {
		cards.push_back(card);		
	}
}

//contains game rule to check if play area is busted for specific card
bool PlayArea::isBust(Card* newCard) const
{
	for (Card* existingCard : cards) {
		if (existingCard->getType() == newCard->getType()) {
			return true;
		}
	}
	return false;
}

//void PlayArea::clear()
//{
//	cards.clear();
//}


//remove all cards from PlayArea when is busted and stored in target container.
//allows to move bunch of cards from one container to another
void PlayArea::moveAllCardsTo(VectorContainer& container)
{
	for (Card* card : cards) {
		container.push_back(card);
	}
	cards.clear();
	
}
