//Sagar Patel; 0364296
//Osama Esfar Sami; 0362386
#include <iostream>
#include "HumanPlayer.hpp"

using namespace std;
//Argumented Constructor for the Human Player
HumanPlayer::HumanPlayer(string name, Piece piece):Player(name,piece){

}
//Destructor to destruct the Human Player object
HumanPlayer::~HumanPlayer()
{

}
//makeMove Function to make the Human Player move on the Board
void HumanPlayer::makeMove(Board& board){
  //boolean to check if its correct
  bool correct = false;

    do {
        cout << "What is your next Move: "<<endl;

        Move place;
        cin >> place;
        //checks if the Move is legal and makes it if it is true 
        if (board.isLegal(Player::getPiece(), place)){
            board.makeMove(Player::getPiece(), place);
            correct = true;
        }else{
            correct = false;
            cout << "** Incorrect Move. Please enter a correct Move **" << endl;
        }

    }while(correct == false);
}
