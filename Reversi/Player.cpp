//Sagar Patel; 0364296
//Osama Esfar Sami; 0362386
//including the header file and implementing the Player class here
#include "Player.hpp"
#include <iostream>
#include <string>
using namespace std;
//Argumented Constructor to take in name and Piece of the Player
Player::Player( const string& name, Piece piece ){
    this->name = name;
    this->piece = piece;
}
//Destructor to destruct the The object Player once it is finished in the main
Player::~Player(){

}
//gets the Piece of the Player and return it back
Piece Player::getPiece() const {
    return piece;
}
//returns the name of the PLayer
string Player::getName() {
    return name;
}
