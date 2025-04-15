#include "SwordCard.h"

SwordCard::SwordCard(int value):
	Card(value, Sword)
{
}

SwordCard::~SwordCard()
{
}

std::string SwordCard::str() const
{
	return "Sword(" + std::to_string(getValue()) + ")";
}

void SwordCard::play(Game& game, Player& player)
{
}
