#include "ChestCard.h"
#include <iostream>

ChestCard::ChestCard(int value):
	Card(value, Chest)
{
}

ChestCard::~ChestCard()
{
}

std::string ChestCard::str() const
{
	return "Chest(" + std::to_string(getValue()) + ")";
}

void ChestCard::play(Game& game, Player& player)
{
	std::cout << "Chest ability: No immediate effect. If banked with a Key card, draw bonus cards from the Discard pile." << std::endl;
}

void ChestCard::willAddToBank(Game& game, Player& player)
{
}
