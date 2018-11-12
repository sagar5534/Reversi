//
//  ComputerPlayer.cpp
//  Reversi
//
//  Created by Luna on 2018-11-11.
//  Copyright © 2018 Sagar. All rights reserved.
//


#include <string>
#include <iostream>
#include "ComputerPlayer.hpp"

ComputerPlayer::ComputerPlayer(Piece i) : Player("Computer" + std::to_string(numberOfInstance), i){
    numberOfInstance++;
    
}



