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
#include "ComputerPlayer.hpp"

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
    static int playertoplayer = 1;
    static int playertocomputer = 2;
    static int computertocomputer = 3;
    int choose;

    cout << "Select Type of Game:" << endl
    << "1 - Player VS Player" << endl
    << "2 - Player VS Computer" << endl
    << "3 - Computer VS Computer(Spectate)" << endl;

    bool correctInput = false;
    while( correctInput == false){
        cin >> choose;
        string name1, name2;
        if (choose == playertoplayer){

            correctInput = true;
            cout << "Enter Player 1's name" << endl;
            cin >> name1;
            cout << "Enter Player 2's name" << endl;
            cin >> name2;
            p1 = new HumanPlayer(name1, Piece::DARK);
            p2 = new HumanPlayer(name2, Piece::WHITE);
            cout << "Both Players Created" << endl;

        }
        else if(choose == playertocomputer){

            correctInput = true;
            cout << "Enter Player name";
            cin >> name1;
            p1 = new HumanPlayer(name1, Piece::DARK);
            p2 = new RandomPlayer(Piece::WHITE);
            cout << "Computer Created" << endl;

        }else if(choose == computertocomputer) {

            correctInput = true;
            p1 = new RandomPlayer(Piece::DARK);
            p2 = new RandomPlayer(Piece::WHITE);
            cout << "Both Computers Created" << endl;

        }else{
            cout << "** Please enter a Correct Value **" << endl;
            correctInput = false;
        }
    }

  }

//In progress
Player* Game::nextPlayer() const {

    return p1;
}

void Game::play(){

    isRunning = true;

    while (isRunning == true) {
        //Play Game
        board.display();
        

        isRunning = false;
    }

    cout << "END" << endl;

}

void Game::announceWinner(){

    Piece winner = board.getWinner();

    if (winner == Piece::DARK){
        cout << "** Player 1 has WON **" << endl;
    }
    else if(winner == Piece::WHITE){
        cout << "** Player 2 has WON **" << endl;
    }else{

    }

}
