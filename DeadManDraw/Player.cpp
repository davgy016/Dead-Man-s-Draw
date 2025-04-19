#include "Player.h"
#include "Bank.h"
#include "PlayArea.h"
#include "Game.h"
#include <iostream>

using namespace std;

Player::Player() :
	_busted(false)
{
	_playArea = new PlayArea();
	_bank = new Bank();
	initialise();
}

Player::~Player()
{
	delete _playArea;
	delete _bank;
	cout << "Player destroyed" << endl;
}

void Player::initialise()
{
	std::string names[] = { "Sam", "Billy", "Jen", "Bob", "Sally", "Joe", "Sue", "Sasha", "Tina", "Marge" };
	_name = names[rand() % 10];
}

const std::string& Player::getName() const
{
	return  _name;
}

PlayArea* Player::getPlayArea() const
{
	return _playArea;
}

Bank* Player::getBank() const
{
	return _bank;
}

bool Player::hasBusted() const
{
	return _busted;
}
void Player::setBusted(bool busted)
{
	_busted = busted;
}

// plays the card into the play area 
// returns true if this causes the player to bust,  
// otherwise the card's ability is performed and this function returns false 
bool Player::playCard(Card* card, Game& game)
{	
	if (_playArea->isBust(card)) {
		_busted = true;
		std::cout << "Bust! You lost all cards" << std::endl;
		_playArea->moveAllCardsTo(game.getDiscardPile()->getCards());
		game.getDiscardPile()->addCard(card);
		return true;
	}
	else {
		_playArea->addCard(card);
		card->play(game, *this);
		if (_busted) {
			return true;
		}
		return false;
	}

}

//when player stops drawing card, game calls this method to bank cards from playArea
//it checks if it has chest-key combination,if so adds bonus cards to the bank from discadPile
//otherwise it just add the cards into the bank
void Player::bankCards(Game& game)
{
	VectorContainer cards = _playArea->getCards();
	
	for (Card* card : cards) {
		card->willAddToBank(game, *this);
	}

	for (Card* card : cards) {
		_bank->addCard(card);
	}

	_playArea->getCards().clear();

	_busted = false;
}

//allows player select the card from bank e.g. play Hook, Sword, Cannon
CardType Player::selectCardTypeFromBank(Game& game, Player* targetPlayer)
{
	Bank* bank = targetPlayer->getBank();
	MapContainer& bankCards = targetPlayer->getBank()->getCards();

	std::vector<CardType> availableSuits;
	int index = 1;

	//if each suit has cards, then gets card type with highest value and stores in new vector of availableSuits. Then display available suits for user to choose
	//Note: in bank cards is always sorted by highest to lowest	
	for (auto& pair : bankCards) {
		if (!pair.second.empty()) {
			CardType ct = pair.first;
			availableSuits.push_back(ct);
			std::cout <<"   " << index << "  " << pair.second.front()->str() << std::endl;
			index++;
		}
	}	

	//user select suit to discard
	int choice = 0;
	bool validInput = false;
	while (!validInput) {
		if (availableSuits.size() > 0) {

		std::cout << "Choose a suit to discard 1-" << availableSuits.size()<<": ";
		std::cin >> choice;
		}

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Please enter a number." << std::endl;
		}
		else if (choice<1 || choice > availableSuits.size()) {
			std::cout << "Invalid choice. Enter number between 1 and " << availableSuits.size() << std::endl;
		}
		else {
			validInput = true;			
		}
	}

	return availableSuits[choice - 1];
}

//display play area cards
void Player::printPlayerArea() const
{
	std::cout << "Play Area:" << std::endl;

	VectorContainer& cards = _playArea->getCards();
	if (cards.empty()) {
		std::cout << "Empty" << std::endl;
		return;
	}
	for (Card* card : cards) {
		std::cout << "  " << card->str() << std::endl;
	}
}

//display bank cards
void Player::printBank() const
{
	std::cout << "Bank:";
	_bank->displayBankDetails();
}

//display player score
int Player::getScore() const
{
	int sumScore = _bank->calculateScore();
	return sumScore;
}


