//Sagar Patel; 0364296
//Osama Esfar Sami; 0362386
#include <iostream>
#include "HumanPlayer.hpp"

using namespace std;

HumanPlayer::HumanPlayer(string name, Piece piece):Player(name,piece){

}

HumanPlayer::~HumanPlayer()
{

}
void HumanPlayer::makeMove(Board& board){
    bool correct = false;

    do {
        cout << "What is your next Move: "<<endl;

        Move place;
        cin >> place;

        if (board.isLegal(Player::getPiece(), place)){
            board.makeMove(Player::getPiece(), place);
            correct = true;
        }else{
            correct = false;
            cout << "** Incorrect Move. Please enter a correct Move **" << endl;
        }

    }while(correct == false);
}
