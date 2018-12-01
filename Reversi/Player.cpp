//Sagar Patel; 0364296
//Osama Esfar Sami; 0362386
#include "Player.hpp"
#include <iostream>
#include <string>
using namespace std;

Player::Player( const string& name, Piece piece ){
    this->name = name;
    this->piece = piece;
}

Player::~Player(){

}

Piece Player::getPiece() const {
    return piece;
}

string Player::getName() {
    return name;
}
