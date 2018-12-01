//Sagar Patel; 0364296
//Osama Esfar Sami; 0362386
#include "Game.hpp"
#include <iostream>
#include "Board.hpp"
#include "Player.hpp"
#include "HumanPlayer.hpp"
#include "RandomPlayer.hpp"
#include "ComputerPlayer.hpp"

using namespace std;

//Default Constructor, resets the board. and sets both p1 and p2 to nullptrs
Game::Game(){
    board.reset();
    p1 = nullptr;
    p2 = nullptr;
    //Sets the currentPlayer to p1, for the next game
    currentPlayer = p1;
}

//Game Destructor that deletes both p1 and p2
Game::~Game(){
  delete p1;
  delete p2;
  delete currentPlayer;
}

//Allows the users to select the type of game and the players names if any human players are created
void Game::selectPlayers(){
    static int playertoplayer = 1;
    static int playertocomputer = 2;
    static int computertocomputer = 3;
    int choose;

    //Selects the Type of Game
    cout << "Select Type of Game:" << endl
    << "1 - Player VS Player" << endl
    << "2 - Player VS Computer" << endl
    << "3 - Computer VS Computer(Spectate)" << endl;
    bool correctInput = false;

    //Loop to ensure correct game is selected
    while( correctInput == false){
        cin >> choose;
        string name1, name2;
        if (choose == playertoplayer){
            //If two human players are selected then both are asked for names and creates the objects
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
            //One human player is asked for name and the computer is given a name itself. Then creates both objects
            correctInput = true;
            cout << "Enter Player name" << endl;
            cin >> name1;
            p1 = new HumanPlayer(name1, Piece::DARK);
            p2 = new RandomPlayer(Piece::WHITE);
            cout << "Computer Created" << endl;

        }else if(choose == computertocomputer) {
            //If both computers are selected then the objects are created
            correctInput = true;
            p1 = new RandomPlayer(Piece::DARK);
            p2 = new RandomPlayer(Piece::WHITE);
            cout << "Both Computers Created\n" << endl;

        }else{
            //If the error was incorrect then returns error and loops
            cout << "** Please enter a Correct Value **" << endl;
            correctInput = false;
        }
    }

  }

//Method is called once the game needs to change the current player to the next
Player* Game::nextPlayer() const{

    if (board.turn == p1->getPiece()){
        //If p1 was currentPlayer then make p2
        board.turn = p2->getPiece();
        return p2;
    }else{
        //If p2 was currentPlayer then make p1
        board.turn = p1->getPiece();
        return p1;
    }

}

//Play method
void Game::play(){

    cout << "\nStarting Game" << endl;
    isRunning = true;
    currentPlayer = p1;
    //Generates moves for the currentPlayer
    board.genMoves();
    //Loop keeps running untill the game hasnt ended
    while (isRunning == true) {
        cout << endl << endl;
        //Display Players Turn
        cout << "Player " << currentPlayer->getName() << "\'s Turn\n";
        //Displays the board
        board.display();
        //Displays the current available moves for the currentPlayer
        board.movesAvail();
        //Make Move
        currentPlayer->makeMove(board);

        //Move to the Next Round
        currentPlayer = nextPlayer();
        board.genMoves();
        //If the game does have a winner then stop the loop
        if (board.getWinner() != Piece::EMPTY) {
            isRunning = false;
            cout << endl;
            board.display();
        }
    }
}

//announceWinner will happen once the game ends. Prints the winner
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
