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
    currentPlayer = p1;
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
            cout << "Both Computers Created\n" << endl;

        }else{
            cout << "** Please enter a Correct Value **" << endl;
            correctInput = false;
        }
    }

  }

//In progress
Player* Game::nextPlayer() const{

    if (board.turn == p1->getPiece()){
        //turn=p1
        board.turn = p2->getPiece();
        return p2;
    }else{
        //turn=p2
        board.turn = p1->getPiece();
        return p1;
    }

}

void Game::play(){

    cout << "\nStarting Game" << endl;
    isRunning = true;
    currentPlayer = p1;

    while (isRunning == true) {
        board.display();
        //Display Players Turn
        int player = (currentPlayer->getPiece() == Piece::DARK) ? 1:2;
        cout << "Player " << player << "\'s Turn\n";

        //Make Move
        currentPlayer->makeMove(board);

        //Next Round
        currentPlayer = nextPlayer();
        //isRunning = false;
    }

    announceWinner();

}

void Game::announceWinner(){

    Piece winner = board.getWinner();
    cout << endl;
    if (winner == Piece::DARK){
        cout << "** Player 1 has WON **" << endl;
    }
    else if(winner == Piece::WHITE){
        cout << "** Player 2 has WON **" << endl;
    }else{
        cout << "** Game is a TIE **" << endl;
    }

}
