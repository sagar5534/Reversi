


#include <string>
#include <iostream>
#include "ComputerPlayer.hpp"

using namespace std;

int ComputerPlayer::numberOfInstance = 65;

ComputerPlayer::ComputerPlayer(Piece i):Player("Computer"+to_string(numberOfInstance),i)
{

    numberOfInstance++;
}
