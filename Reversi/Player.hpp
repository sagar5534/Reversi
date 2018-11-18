//
//  Player.hpp
//  Reversi
//
//  Created by Luna on 2018-11-11.
//  Copyright © 2018 Sagar. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <string>
#include "Board.hpp"

using namespace std;

class Player {
    public:
        Player( const string&, Piece);
        Piece getPiece() const;
        virtual void makeMove( Board& ) = 0;
        virtual ~Player();

    protected:
        string name;
        Piece piece;
};

#endif /* Player_hpp */
