//
//  Board.hpp
//  Reversi
//
//  Created by Luna on 2018-11-11.
//  Copyright © 2018 Sagar. All rights reserved.
//

#ifndef Board_hpp
#define Board_hpp

#include <stdio.h>

//Enum for Types of Pieces
enum Piece {WHITE, DARK, EMPTY};
inline const char* ToString(Piece v)
{
    switch (v)
    {
        case Piece::WHITE:
            return "O";
        case Piece::DARK:
            return "X";
        case Piece::EMPTY:
            return " ";
        default:
            return "ERROR";
    }
}

typedef int Move;
const Move nullMove = -1;

class Board{

    private:
        //May be Move tiles
        Piece tiles [64];
        
        void addToMoves(int);
        Move availMoves [140];
    public:
        Board();
        int counter = 0;
        void reset();
        void display();
        void makeMove(Piece, Move);
        bool isLegal(Piece, Move) const;
        Piece getWinner() const;
        Piece getPlayer() const;
        void genMoves();
        int numMoves() const;
        Move getMove(int) const;
};

#endif /* Board_hpp */
