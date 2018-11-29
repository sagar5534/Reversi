#include "RandomPlayer.hpp"
#include "ComputerPlayer.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include <cstdlib>
#include <iostream>
using namespace std;

RandomPlayer::RandomPlayer(Piece i):ComputerPlayer(i){

}

RandomPlayer::~RandomPlayer(){

}

void RandomPlayer::makeMove(Board& board){

  bool correct = false;
  do {

      Move place;
      place = rand() % 64;

      if (board.isLegal(Player::getPiece(), place)){
          board.makeMove(Player::getPiece(), place);
          correct = true;
      }

  }while(correct == false);

}
