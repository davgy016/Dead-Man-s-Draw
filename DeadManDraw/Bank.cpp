#include "Bank.h"
#include <algorithm>
#include <iostream>

Bank::Bank():
	
    CardContainer<MapContainer>()
{
}

Bank::~Bank()
{
    for (auto&pair : cards) {
        for (Card* c : pair.second) {
            delete c;
        }
        pair.second.clear();        
    }    
    cards.clear();
    std::cout << "Bank Destroyed" << std::endl;
}


// sort cards by value for specific suit 
void Bank::sortCardsByValue(CardType type)
{
    auto iter = cards.find(type);
    if (iter != cards.end()) {
        std::sort(iter->second.begin(), iter->second.end(), [](Card* a, Card* b) {
            return a->getValue() > b->getValue(); 
            });
    }
}

//add card into bank and then sort the entire type of added card. 
//This allows to have always sorted cards in bank 
void Bank::addCard(Card* card)
{
	if (card == nullptr) {
		return;
	}
	cards[card->getType()].push_back(card);

    sortCardsByValue(card->getType());
}

//Card* Bank::removeCard(int index)
//{
//
//	return nullptr;
//}

//removes the card for specific type, for example when player selects the card from options
Card* Bank::removeCardByType(CardType type)
{
    auto iter = cards.find(type);
    if (iter != cards.end() && !iter->second.empty()) {
        //store cards of same suit in vector, which extract from map
        VectorContainer& typeCards = iter->second;
        //store first element(Highest value) in card
        Card* card = typeCards.front();
        //delete/remove particular suit card of highest value
        typeCards.erase(typeCards.begin());
        if (typeCards.empty()) {
            cards.erase(iter);
        }
        return card;
    }
    
    return nullptr;
}

//calculates the score for existing cards 
int Bank::calculateScore()
{
    int totalScore = 0;

    for (const auto& pair : cards) {        
        int highestValue = 0;
        for (Card* card : pair.second) {
            highestValue = std::max(highestValue, card->getValue());
        }
        totalScore += highestValue;
    }

    return totalScore;
}

MapContainer& Bank::getCards()
{
	return cards;
}

//Card* Bank::getTopCardOfType(CardType type)
//{
//	auto iter = cards.find(type);
//	if (iter != cards.end() && !iter->second.empty()) {
//		return iter->second.back();
//	}
//
//	return nullptr;
//}

//displays the details of existing cards
void Bank::displayBankDetails() const {
    if (cards.empty()) {
        std::cout << " 0" << std::endl;
        return;
    }
    
    for (const auto& pair : cards) {
        std::cout << "\n  ";      

        for (Card* card : pair.second) {
            std::cout << card->str() << " ";
        }        
    }
    std::cout << std::endl;
}




