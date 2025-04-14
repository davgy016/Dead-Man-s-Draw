#include "KeyCard.h"

KeyCard::KeyCard(int value):
	Card(value, Chest)
{
}

KeyCard::~KeyCard()
{
}

std::string KeyCard::str() const
{
	return std::string();
}

void KeyCard::play(Game& game, Player& player)
{
}
