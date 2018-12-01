//Sagar Patel; 0364296
//Osama Esfar Sami; 0362386
#include <iostream>
using namespace std;
#include "Player.hpp"
#include "Board.hpp"
#include "ComputerPlayer.hpp"
#include "Game.hpp"
#include "HumanPlayer.hpp"
#include "RandomPlayer.hpp"

int main() {
    //Enters the game, creates game object
    cout << "Welcome to Reversi\n";
    Game game;
    //Selects the payers, runs the game and then announces winner
    game.selectPlayers();
    game.play();
    game.announceWinner();

}
