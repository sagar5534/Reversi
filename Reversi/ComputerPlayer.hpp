//Sagar Patel; 0364296
//Osama Esfar Sami; 0362386
#ifndef ComputerPlayer_hpp
#define ComputerPlayer_hpp

//including the header file and implementing the Computer Player class here
#include "Player.hpp"
#include <iostream>

class ComputerPlayer : public Player{

private:
    //static int 
    static int numberOfInstance;

public:
    //Argumented Constructor 
    ComputerPlayer(Piece i );
    //Destructor
    ~ComputerPlayer();
    //Mamkemove method for Computer
    virtual void makeMove(Board&) = 0;

};

#endif /* ComputerPlayer_hpp */
