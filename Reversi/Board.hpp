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

enum class Piece : char {
    WHITE = 'O', DARK = 'X', EMPTY = '.'
};

typedef int Move;
const Move nullMove = -1;

class Board{

    private:
        //May be Move tiles
        Piece tiles [64];
    public:
        Board();
        void reset();
        void display();
        void makeMove(Piece, Move);
        bool isLegal(Piece, Move) const;
        Piece getWinner() const;
        Piece getPlayer() const;
        void getMoves();
        int numMoves() const;
        Move getMove(int) const;

};


#endif /* Board_hpp */
