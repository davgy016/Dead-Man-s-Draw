//#include "CardContainer.h"
//#include "CannonCard.h"
//#include <vector>
//#include "PlayArea.h"
//#include <algorithm>
//#include <memory>
#include "Game.h"
#include <iostream>

using namespace std;

int main()
{
    Game& game = Game::getInstance();
    game.initialiseGame();
    game.startGame();

   /* PlayArea p;
    Card* c = new CannonCard(3);
    cout<<c->getType();
    p.addCard(c);*/   
    
    return 0;
}


