//Sagar Patel; 0364296
//Osama Esfar Sami; 0362386
#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include "Board.hpp"
#include "Player.hpp"

class Game{
private:
    Board board;
    Player *p1, *p2, *currentPlayer;
    bool isRunning;
public:
    Game();
    ~Game();
    void selectPlayers();
    Player* nextPlayer() const;
    void play();
    void announceWinner();
};
#endif /* Game_hpp */
