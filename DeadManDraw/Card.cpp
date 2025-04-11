#include "Card.h"


Card::Card(int value):
	_pointValue(value)
{
}

Card::~Card()
{
}

int Card::getValue() const
{
	return _pointValue;
}

const CardType& Card::getType() const
{
	
}






