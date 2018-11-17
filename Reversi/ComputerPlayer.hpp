//
//  ComputerPlayer.hpp
//  Reversi
//
//  Created by Luna on 2018-11-11.
//  Copyright © 2018 Sagar. All rights reserved.
//

#ifndef ComputerPlayer_hpp
#define ComputerPlayer_hpp


#include "Player.hpp"
#include <iostream>
 
class ComputerPlayer : public Player{

private:
   
    static int numberOfInstance;

public:
    
    ComputerPlayer(Piece i );
   virtual ~ComputerPlayer();
    
};

#endif /* ComputerPlayer_hpp */
