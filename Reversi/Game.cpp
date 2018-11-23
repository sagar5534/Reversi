//
//  Game.cpp
//  Reversi
//
//  Created by Luna on 2018-11-11.
//  Copyright © 2018 Sagar. All rights reserved.
//

#include "Game.hpp"
#include <iostream>
#include "Board.hpp"
#include "Player.hpp"
#include "HumanPlayer.hpp"
#include "RandomPlayer.hpp"
using namespace std;

Game::Game(){
  board.reset();
  p1 = nullptr;
  p2 = nullptr;
}

Game::~Game(){
  delete p1;
  delete p2;
}
void Game::selectPlayers(){
    int playertoplayer = 1;
    int playertocomputer = 2;
    int computertocomputer = 3;
    int choose;

    cout << "Select Type of Game:" << endl
    << "1 - Player VS Player" << endl
    << "2 - Player VS Computer" << endl
    << "3 - Computer VS Computer(Spectate)" << endl;

    cin >> choose;
    //TODO Error CHECKER

    if (choose == playertocomputer){
        string name;
        cout << "Enter the player's name";
        cin>> name;
      p1 = new HumanPlayer(name, Piece::DARK);
      p2 = new RandomPlayer(Piece::WHITE);
  }
}

//In progress
//Player Game::nextPlayer() const {

//}

void Game::play(){

}

void announceWinner(){

}
