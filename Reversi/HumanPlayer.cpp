#include <iostream>
#include "HumanPlayer.hpp"

using namespace std;

HumanPlayer::~HumanPlayer()
{
   
}
void HumanPlayer::makeMove(Board& board){
    cout << "Where do you want to move your Piece"<<endl;
    Move place;
    cin >> place;
   // board.makeMove(Player.getPiece(), place);
  
    
}