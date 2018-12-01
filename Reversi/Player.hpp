//Sagar Patel; 0364296
//Osama Esfar Sami; 0362386
#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <string>
#include "Board.hpp"

using namespace std;
//Creating the class abstract class Player
class Player {
    //Initializing private variables
    private:
        string name;
        Piece piece;
    //declaring the methods for the abstract Player class
    public:
        //Constructor
        Player( const string&, Piece);
        //Method to get the Piece of the Player
        Piece getPiece() const;
        //The makeMove function for the Player to move
        virtual void makeMove( Board& ) = 0;
        //Destructor to destruct the constructor
        virtual ~Player();
        //gets the name of the player
        string getName();

};

#endif /* Player_hpp */
