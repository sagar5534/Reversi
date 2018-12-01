//Sagar Patel; 0364296
//Osama Esfar Sami; 0362386
#ifndef Board_hpp
#define Board_hpp

#include <stdio.h>

//Enum for Types of Pieces
enum Piece {DARK, WHITE, EMPTY};
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
        int counter = 0;
    public:
        Board();
        void reset();
        void display();
        void makeMove(Piece, Move);
        bool isLegal(Piece, Move) const;
        Piece getWinner() const;
        Piece getPlayer() const;
        void genMoves();
        int numMoves() const;
        Move getMove(int) const;
        mutable Piece turn;
        void movesAvail();

};

#endif /* Board_hpp */
