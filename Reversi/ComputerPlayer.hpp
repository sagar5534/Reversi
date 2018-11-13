//
//  ComputerPlayer.hpp
//  Reversi
//
//  Created by Luna on 2018-11-11.
//  Copyright © 2018 Sagar. All rights reserved.
//

#ifndef ComputerPlayer_hpp
#define ComputerPlayer_hpp

#include <stdio.h>
#include "Player.hpp"

class ComputerPlayer : public Player{

private:
    string name;
    Piece piece;
    static int numberOfInstance;

public:
    ComputerPlayer(Piece);
    virtual ~ComputerPlayer();
    //Piece getPiece() const;
};

#endif /* ComputerPlayer_hpp */
