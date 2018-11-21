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

  return 0;
}

Piece Board::getWinner() const{

  return Piece::WHITE;
}

Piece Board::getPlayer() const{

  return Piece::WHITE;
}

int Board::numMoves() const{

  return 0;
}

Move Board::getMove(int move) const{

  return 0;
}
