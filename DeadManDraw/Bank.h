#ifndef BANK_H
#define BANK_H
#include "CardContainer.h"
#include "Player.h"

/*
* This is the class where each player stores its cards
* Inherits from CardContainer with specific container type
*/

class Bank : public CardContainer<MapContainer>
{
public:
	Bank();
	~Bank();
	//add card into the bank
	void addCard(Card* card) override;

	//Card* removeCard(int index) override;

	//removes the specific type of card from bank. e.g when sword plays its ability
	Card* removeCardByType(CardType type) override;

	//calculate point values(highest values of suit) of the cards in bank
	int calculateScore();

	//get cards from bank
	MapContainer& getCards() override;

	//Card* getTopCardOfType(CardType type);

	//display details of the cards from bank
	void displayBankDetails() const;

	//sort cards by value for specific type
	void sortCardsByValue(CardType type);

};


#endif // BANK_H