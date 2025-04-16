#include "MapCard.h"
#include <iostream>
#include "Player.h"
#include "Game.h"

MapCard::MapCard(int value):
	Card(value, Map)
{
}

MapCard::~MapCard()
{
}

std::string MapCard::str() const
{
	return "Map(" + std::to_string(getValue()) + ")";
}

void MapCard::play(Game& game, Player& player)
{
	std::cout << "Draw 3 cards from discard pile. You must play one of the cards drawn into your play area. " << std::endl;
}
