//
//  Board.cpp
//  Reversi
//
//  Created by Luna on 2018-11-11.
//  Copyright © 2018 Sagar. All rights reserved.
//

#include "Board.hpp"
#include <iostream>
using namespace std;

Board::Board(){
    reset();
}

void Board::reset(){

    Piece tiles [64];
    for (int i = 0; i < 64; i++) {
        tiles[i] = Piece::EMPTY;
    }

}

void Board::display(){

    std::cout << "--------------------" << '\n';



    std::cout << "--------------------" << '\n';

}

void Board::makeMove(Piece piece, Move move){

}

bool Board::isLegal(Piece piece, Move move) const {

    if (move > 63 || move < 0){
        return false;
    }
    for (int i = 0; i < counter; i++) {
        if (availMoves[i] == move){
            return true;
        }
    }
    return false;
}

Piece Board::getWinner() const{

    int darkNum = 0;
    int whiteNum = 0;

    for (int i = 0; i < 64; ++i){
        if (tiles[i] == Piece::WHITE){
            whiteNum++;
        }else if (tiles[i] == Piece::DARK){
            darkNum++;
        }
        else{
            return Piece::EMPTY;
        }
    }

    if (darkNum > whiteNum) {
        return Piece::DARK;
    }else if (whiteNum > darkNum){
        return Piece::WHITE;
    }else{
        //Tie
        return Piece::EMPTY;
    }
}

Piece Board::getPlayer() const{

    return Piece::WHITE;
}

void Board::addToMoves(int move){

    bool contains = false;
    for (int i = 0; i < counter; ++i){
        if (availMoves[i] == move){
            contains = true;
        }
    }
    if (contains == false){
        availMoves[counter] = move;
        counter++;
    }
}

void Board::genMoves(){

    counter = 0;

    //Process entire Board
    for (int currentTile = 0; currentTile < 64; currentTile++) {
        //Tile is not Empty
        if(tiles[currentTile] != Piece::EMPTY){

            //Test marker
            Piece oppositePiece = (tiles[currentTile] == Piece::WHITE) ? Piece::DARK : Piece::WHITE;
            int testTile = 0;
            bool exceed2 = false;

            //UP
            exceed2 = false;
            testTile = currentTile - 8;
            while (testTile > 7 && tiles[testTile] == oppositePiece) {
                testTile -= 8;
                exceed2 = true;
            }
            if (exceed2 == true && testTile > 0 && tiles[testTile] == Piece::EMPTY){
                Board::addToMoves(testTile);
            }

            //UPRIGHT
            exceed2 = false;
            if ( (currentTile+1)%8 != 0 || (currentTile+1)%8 != 7 ){
                testTile = currentTile - 7;
                while (testTile > 15 && ((testTile+1)%8 != 0) && tiles[testTile] == oppositePiece ) {
                    testTile -= 7;
                    exceed2 = true;
                }
                //MAY NOT WORK IF WORKED ONLY ONCE IE 30
                if (exceed2 == true && tiles[testTile] == Piece::EMPTY){
                    addToMoves(testTile);
                }
            }

            //RIGHT
            exceed2 = false;
            if ( (currentTile+1)%8 != 0 && (currentTile+1)%8 != 7 ){
                testTile = currentTile + 1;
                while (testTile < 64 && tiles[testTile] == oppositePiece) {
                    testTile += 1;
                    exceed2 = true;
                }
                if (exceed2 == true && tiles[testTile] == Piece::EMPTY){
                    addToMoves(testTile);
                }
            }

            //DOWNRIGHT
            exceed2 = false;
            if ( (currentTile+1)%8 != 0 || (currentTile+1)%8 != 7 ){
                testTile = currentTile + 9;
                while (testTile < 56 && ((testTile+1)%8 != 0) && tiles[testTile] == oppositePiece ) {
                    testTile += 9;
                    exceed2 = true;
                }
                //MAY NOT WORK IF WORKED ONLY ONCE IE 30
                if (exceed2 == true && tiles[testTile] == Piece::EMPTY){
                    addToMoves(testTile);
                }
            }

            //DOWN
            if (currentTile < 48){
                exceed2 = false;
                testTile = currentTile + 8;
                while (testTile < 64 && tiles[testTile] == oppositePiece) {
                    testTile += 8;
                    exceed2 = true;
                }
                if (exceed2 == true && tiles[testTile] == Piece::EMPTY){
                    addToMoves(testTile);
                }
            }

            //DOWNLEFT
            exceed2 = false;
            if ((currentTile+1)%8 != 1 && (currentTile+1)%8 != 2){
                testTile = currentTile + 7;
                while (testTile < 56 && ((testTile+1)%8 != 1) && tiles[testTile] == oppositePiece ) {
                    testTile += 7;
                    exceed2 = true;
                }
                //MAY NOT WORK IF WORKED ONLY ONCE IE 30
                if (exceed2 == true && tiles[testTile] == Piece::EMPTY){
                    addToMoves(testTile);
                }
            }

            //LEFT
            exceed2 = false;
            if ((currentTile+1)%8 != 1 && (currentTile+1)%8 != 2){
                testTile = currentTile - 1;
                while (testTile > 0 && tiles[testTile] == oppositePiece) {
                    testTile -= 1;
                    exceed2 = true;
                }
                if (exceed2 == true && tiles[testTile] == Piece::EMPTY){
                    addToMoves(testTile);
                }
            }

            //UPLEFT
            exceed2 = false;
            if ((currentTile+1)%8 != 1 && (currentTile+1)%8 != 2){
                testTile = currentTile - 9;
                while (testTile > 7 && ((testTile+1)%8 != 1) && tiles[testTile] == oppositePiece ) {
                    testTile -= 9;
                    exceed2 = true;
                }
                //MAY NOT WORK IF WORKED ONLY ONCE IE 30
                if (exceed2 == true && tiles[testTile] == Piece::EMPTY){
                    addToMoves(testTile);
                }
            }

        }
        //Moves to next piece
    }

    cout << "Moves Available: [";
    for (int i = 0; i < counter; i++){
        if (i == counter - 1){
            cout << availMoves[i];
        }else{
            cout << availMoves[i] << ", ";
        }
    }
    cout << "]" << endl;

}

int Board::numMoves() const{
    return counter;
}

Move Board::getMove(int move) const{
    Move temp = move;
    return temp;
}
