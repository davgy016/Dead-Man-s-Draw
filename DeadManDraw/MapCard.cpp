#include "MapCard.h"
#include <iostream>
#include "Player.h"
#include "Game.h"

MapCard::MapCard(int value) :
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

	DiscardPile* discardPile = game.getDiscardPile();

	int numCards = std::min(3, static_cast<int>(discardPile->size()));
	VectorContainer drawnCards = discardPile->drawCards(numCards);

	if (drawnCards.empty()) {
		std::cout << "No cards in Discard Pile to draw" << std::endl;
		return;
	}
	//display drawn cards from discard pile	
	for (int i = 0; i < drawnCards.size(); ++i) {
		std::cout << "  " << i + 1 << "  " << drawnCards[i]->str() << std::endl;
	}

	int choice = 0;
	bool validInput = false;
	while (!validInput) {
		std::cout << "Choose a suit to discard 1-" << drawnCards.size() <<": ";
		std::cin >> choice;

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Please enter a number." << std::endl;
		}
		else if (choice<1 || choice > drawnCards.size()) {
			std::cout << "Invalid choice. Enter number between 1 and " << drawnCards.size() << std::endl;
		}
		else {
			validInput = true;

		}
	}
	Card* chosenCard = drawnCards[choice - 1];	
	drawnCards.erase(drawnCards.begin() + (choice - 1));
	discardPile->addCards(drawnCards);

	std::cout <<"Selected " << chosenCard->str()<<" - ";

	player.playCard(chosenCard, game);

}









