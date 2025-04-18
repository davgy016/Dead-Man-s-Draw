#include "Deck.h"
#include "CannonCard.h"
#include "KeyCard.h"
#include "ChestCard.h"
#include "SwordCard.h"
#include "HookCard.h"
#include "OracleCard.h"
#include "MapCard.h"
#include "MermaidCard.h"
#include "KrakenCard.h"
#include <iostream>
#include <algorithm>
#include <random>
#include "CardFactory.h"

Deck::Deck() :
	CardContainer<VectorContainer>()
{
}

Deck::~Deck()
{
	for (Card* c : cards) {
		delete c;
	}
	cards.clear();
	std::cout << "Deck Destroyed" << std::endl;
}

void Deck::initialise()
{
	VectorContainer allCards = CardFactory::createAllCards();
	cards.insert(cards.end(), allCards.begin(), allCards.end());

	shuffleDeck();
}

void Deck::shuffleDeck()
{
	VectorContainer shuffleDeck{ cards.begin(), cards.end() };
	std::shuffle(shuffleDeck.begin(), shuffleDeck.end(), std::mt19937{ std::random_device{}() });
	std::copy(shuffleDeck.begin(), shuffleDeck.end(), cards.begin());

}

Card* Deck::peekCard() const
{
	if (cards.empty()) {
		std::cout<<"Deck is empty"<<std::endl;
		return nullptr;
	}
	return cards.back();
}

Card* Deck::removeCard() 
{
	if (cards.empty()) {
		std::cout << "Deck is empty" << std::endl;
		return nullptr;
	}
	Card* topCard = cards.back();
	cards.pop_back();
	return topCard;
}
