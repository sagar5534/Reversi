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

Player::Player( const string& name, Piece piece ){
    this-> name = name;
    this-> piece = piece;
    
}
Player::~Player(){
    
}


Piece Player::getPiece() const {
    return piece;
}
