//Sagar Patel; 0364296
//Osama Esfar Sami; 0362386
#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <string>
#include "Board.hpp"

using namespace std;

class Player {

    private:
        string name;
        Piece piece;

    public:
        Player( const string&, Piece);
        Piece getPiece() const;
        virtual void makeMove( Board& ) = 0;
        virtual ~Player();
        string getName();

};

#endif /* Player_hpp */
