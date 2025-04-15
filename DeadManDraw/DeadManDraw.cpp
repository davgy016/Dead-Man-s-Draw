//#include "CardContainer.h"
//#include "CannonCard.h"
//#include <vector>
//#include "PlayArea.h"
//#include <algorithm>
//#include <memory>
#include "Game.h"
#include <iostream>
#include "KeyCard.h"
#ifndef GAME_TITLE_H
#define GAME_TITLE_H
#define GAME_TITLE \
"______                  _   ___  ___              _     \n" \
"|  _  \\                | |  |  \\/  |             ( )    \n" \
"| | | | ___   __ _   __| |  | .  . |  __ _  _ __ |/ ___ \n" \
"| | | |/ _ \\ / _` | / _` |  | |\\/| | / _` || '_ \\  / __|\n" \
"| |/ /|  __/| (_| || (_| |  | |  | || (_| || | | | \\__ \\ \n" \
"______ \\___| \\__,_| \\__,_|  \\_|  |_/ \\__,_||_| |_| |___/\n" \
"|  _  \\                         _      _\n" \
"| | | | _ __  __ _ __      __ _| |_  _| |_\n" \
"| | | || '__|/ _` |\\ \\ /\\ / /|_   _||_   _|\n" \
"| |/ / | |  | (_| | \\ V  V /   |_|    |_|\n" \
"|___/  |_|   \\__,_|  \\_/\\_/\n"



#endif //GAME_TITLE_H

using namespace std;

int main()
{
    std::cout << GAME_TITLE << std::endl;
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


