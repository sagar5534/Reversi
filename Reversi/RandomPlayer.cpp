//Sagar Patel; 0364296
//Osama Esfar Sami; 0362386
//including the header file and implementing the Random Player class here 
#include "RandomPlayer.hpp"
#include "ComputerPlayer.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include <cstdlib>
#include <iostream>
using namespace std;
//Argumeneted Constructor  
RandomPlayer::RandomPlayer(Piece i):ComputerPlayer(i){

}
//Destructor to destruct the the Computer player object
RandomPlayer::~RandomPlayer(){

}
//makeMove function to make the Computer Player move 
void RandomPlayer::makeMove(Board& board){

    if (board.numMoves() != 0) {
        //boolean to check if the Move is correct
        bool correct = false;
        do {

          Move place;
          place = rand() % 64;
          //method to check if the Move is legal and makes the Move 
          if (board.isLegal(Player::getPiece(), place)){
              //makes the random player move
              board.makeMove(Player::getPiece(), place);
              correct = true;
              cout << "Computer moved: " << place;
          }
        }while(correct == false);
    }else{
        cout << "Skipped " << getName() << endl;
    }

}
