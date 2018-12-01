//Sagar Patel; 0364296
//Osama Esfar Sami; 0362386

#ifndef Board_hpp
#define Board_hpp

#include <stdio.h>

//Enum for Types of Pieces
enum Piece {DARK, WHITE, EMPTY};
//Function that returns a char of the types of Pieces. Used with the Board.display
inline const char* ToString(Piece v)
{
    switch (v)
    {
        //Retuns O, X or nothing for Empty
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

//Creates the move and nummmove for the game movements
typedef int Move;
const Move nullMove = -1;

//Board Class
class Board{

    private:
        //Creates an Array full of Pieces
        Piece tiles [64];
        //method that is used by genMoves() kept private
        void addToMoves(int);
        //Array of all the available moves. 120 is the max theoretically move.
        Move availMoves [120];
        //Counter of the number of availMoves found
        int counter = 0;
    public:
        //Default Constructor for Board
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
        //Piece Turn saves the current players piece
        mutable Piece turn;
        //Method the print the availMoves by the currentPlayer
        void movesAvail();

};

#endif /* Board_hpp */
