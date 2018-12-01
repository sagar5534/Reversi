//Sagar Patel; 0364296
//Osama Esfar Sami; 0362386
#include "ComputerPlayer.hpp"
#include <iostream>

using namespace std;

#ifndef RandomPlayer_hpp
#define RandomPlayer_hpp
//Creating the Random Player from inheriting it from Computer Player
class RandomPlayer : public ComputerPlayer
{
public:
    //Argumented Constructor
    RandomPlayer(Piece);
    //Destructor
    ~RandomPlayer();
    //makeMove fucntion to make the Random Player to Move
    void makeMove(Board&);

};
#endif
