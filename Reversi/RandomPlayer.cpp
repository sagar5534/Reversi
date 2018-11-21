#include "RandomPlayer.hpp"
#include "ComputerPlayer.hpp"
#include "Player.hpp"
#include <cstdlib>
#include <iostream>
using namespace std;

RandomPlayer::RandomPlayer(Piece i):ComputerPlayer(i){

}
RandomPlayer::~RandomPlayer(){

}
void RandomPlayer::makeMove(Board& board){
   Move place;

   bool legal = false;

   while(legal == false){

       place = srand()%64 +1;
       if(board.isLegal(Player::getPiece(),place) == true){
           legal = true;
           board.makeMove(Player::getPiece(),place);
       }

   }


}
