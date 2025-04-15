//#include "CardContainer.h"
//#include "CannonCard.h"
//#include <vector>
//#include "PlayArea.h"
//#include <algorithm>
//#include <memory>
#include "Game.h"
#include <iostream>
#include "KeyCard.h"

using namespace std;

int main()
{
    Game& game = Game::getInstance();
    game.initialiseGame();
    game.startGame();
    Card* card = new KeyCard(4);
    game.getCurrentPlayer()->playCard(card, game);

   /* PlayArea p;
    Card* c = new CannonCard(3);
    cout<<c->getType();
    p.addCard(c);*/   
    
    return 0;
}


