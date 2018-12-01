//
//  main.cpp
//  Reversi
//
//  Created by Luna on 2018-11-11.
//  Copyright © 2018 Sagar. All rights reserved.
//

#include <iostream>
using namespace std;
#include "Player.hpp"
#include "Board.hpp"
#include "ComputerPlayer.hpp"
#include "Game.hpp"
#include "HumanPlayer.hpp"
#include "RandomPlayer.hpp"

int main() {

    cout << "Welcome to Reversi\n";
    Game game;

    game.selectPlayers();
    game.play();

}
