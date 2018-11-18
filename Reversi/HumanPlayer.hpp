
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