//Sagar Patel; 0364296
//Osama Esfar Sami; 0362386
#ifndef HumanPlayer_hpp
#define HumanPlayer_hpp
//including the header file and implementing the Player class here
#include "Player.hpp"
#include <iostream>
//Creating the HumanPlayer inherited from the abstract class Player
class HumanPlayer : public Player
{
    

public:
    //Argumented Constructor
    HumanPlayer(string,Piece);
    //Destructor
    virtual ~HumanPlayer();
    //makemove fucntion for the Human PLAYER
    virtual void makeMove(Board&);
  
    
};
#endif