//Sagar Patel; 0364296
//Osama Esfar Sami; 0362386
#ifndef ComputerPlayer_hpp
#define ComputerPlayer_hpp


#include "Player.hpp"
#include <iostream>

class ComputerPlayer : public Player{

private:

    static int numberOfInstance;

public:

    ComputerPlayer(Piece i );
    ~ComputerPlayer();
    virtual void makeMove(Board&) = 0;

};

#endif /* ComputerPlayer_hpp */
