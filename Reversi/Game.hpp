//Sagar Patel; 0364296
//Osama Esfar Sami; 0362386
#ifndef Game_hpp
#define Game_hpp
//includes the the header files for Board and Player for implementation
#include <stdio.h>
#include "Board.hpp"
#include "Player.hpp"

class Game{
private:
    //Initializing the private objects and the variables
    Board board;
    Player *p1, *p2, *currentPlayer;
    bool isRunning;
public:
    //Deafault Constructor to initialize the Game 
    Game();
    //Destructor
    ~Game();
    //method to selects the players 
    void selectPlayers();
    //method to check whose turn it is
    Player* nextPlayer() const;
    //method to play the Game
    void play();
    //method to announce the Winner
    void announceWinner();
};
#endif /* Game_hpp */
