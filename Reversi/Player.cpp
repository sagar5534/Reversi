//
//  Player.cpp
//  Reversi
//
//  Created by Luna on 2018-11-11.
//  Copyright © 2018 Sagar. All rights reserved.
//

#include "Player.hpp"
#include <iostream>
using namespace std;

Player::Player( const string& selectedName, Piece color ){
    name = selectedName;
    piece = color;
    
}

Piece Player::getPiece() const {
    return piece;
}
