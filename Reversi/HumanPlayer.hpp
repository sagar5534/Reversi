//Sagar Patel; 0364296
//Osama Esfar Sami; 0362386
#ifndef HumanPlayer_hpp
#define HumanPlayer_hpp

#include "Player.hpp"
#include <iostream>

class HumanPlayer : public Player
{
    

public:
    HumanPlayer(string,Piece);
    virtual ~HumanPlayer();
    virtual void makeMove(Board&);
  
    
};
#endif