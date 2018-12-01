//Sagar Patel; 0364296
//Osama Esfar Sami; 0362386
#include "ComputerPlayer.hpp"
#include <iostream>

using namespace std;

#ifndef RandomPlayer_hpp
#define RandomPlayer_hpp

class RandomPlayer : public ComputerPlayer
{
public:
    RandomPlayer(Piece);
    ~RandomPlayer();
    void makeMove(Board&);

};
#endif
