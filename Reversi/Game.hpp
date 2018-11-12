//
//  Game.hpp
//  Reversi
//
//  Created by Luna on 2018-11-11.
//  Copyright © 2018 Sagar. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include "Board.hpp"
#include "Player.hpp"

class Game{
private:
    Board board;
    Player *p1,*p2;
public:
    Game();
    ~Game();
    //void selectPlayers();
    //Player* nextPlayer() const;
    //void play();
    //void announceWinner();
    
};
#endif /* Game_hpp */
