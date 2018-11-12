//
//  Game.cpp
//  Reversi
//
//  Created by Luna on 2018-11-11.
//  Copyright © 2018 Sagar. All rights reserved.
//

#include "Game.hpp"
#include <iostream>
using namespace std;

Game::Game(){
  board.reset();
  p1 = nullptr;
  p2 = nullptr;
}
~Game(){
  delete p1;
  delete p2;
}

void Game::selectPlayers(){
  int playertoplayer = 1;
  int playertocomputer = 2;
  int choose;
  cin >> choose;
  if (choose = playertocomputer){
    string name;
    cout << "Enter the players name";
    cin>> name;

  }
}
