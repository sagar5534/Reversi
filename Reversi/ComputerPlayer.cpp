//Sagar Patel; 0364296
//Osama Esfar Sami; 0362386
#include <string>
#include <iostream>
#include "ComputerPlayer.hpp"

using namespace std;
//Initializing the static variable 
int ComputerPlayer::numberOfInstance = 1;

//Argumented Constructor to write take the Piece and print the name of the Players
ComputerPlayer::ComputerPlayer(Piece i):Player("Computer"+to_string(numberOfInstance),i)
{
    numberOfInstance++;
}
//Destructor to destruct the object of the Computer Player
ComputerPlayer::~ComputerPlayer(){

}
