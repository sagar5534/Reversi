//Sagar Patel; 0364296
//Osama Esfar Sami; 0362386

//Including necessary files
#include "Board.hpp"
#include "Game.hpp"
#include <iostream>

using namespace std;

//Default Constructor for Board
Board::Board(){
    //Resets the board pieces back to the deafult position
    reset();
    //Gives the first turn to Dark Piece/Player 1
    turn = Piece::DARK;
}

//Board Reset Function. Resets the Board back to the default position
void Board::reset(){
    //Loops throught entire board and makes each piece empty
    for (int i = 0; i < 64; i++) {
        Board::tiles[i] = Piece::EMPTY;
    }
    //Indivdiually makes the center pieces into White and Black
    Board::tiles[27] = Piece::WHITE;
    Board::tiles[28] = Piece::DARK;
    Board::tiles[35] = Piece::DARK;
    Board::tiles[36] = Piece::WHITE;

}

//Displays the Board onto the screen to see the current positions players have made
void Board::display(){

    std::cout << "----------------------------------" << '\n';

    //Prints labels for each column with correct spacing
    for (int i = 0; i < 8; i++) {
        std::cout << "   " << i+1;
    }

    //Prints each row and each tile. ToString method converts the Enum Piece into a specific String defined in Board.hpp
    std::cout << '\n';
    int count = 0;
    for (int i = 0; i < 8; i++) {
        std::cout << i+1;
        for (int x = count; x < count + 8; x++) {
            cout << " [" << ToString(tiles[x]) << ']';
        }
        cout << endl;
        count += 8;
    }

    std::cout << "----------------------------------" << '\n';

}

//Prints a list of Moves the currentPlayer can move
void Board::movesAvail(){
    cout << "Moves Available: [";
    //Iterates between array to print each move available which is stored in the availMoves array
    for (int i = 0; i < counter; i++){
        if (i == counter - 1){
        cout << availMoves[i];
        }else{
            cout << availMoves[i] << ", ";
        }
    }
    cout << "]" << endl;
}

//Make Moves function that accepts the Piece making the move and the number of tile.
void Board::makeMove(Piece piece, Move move){

        //All error checking is done in Player class. Any calls to this class means the move is already valid.

        //The tile in the Board is changed to the current specified in the method arguments
        tiles[move] = piece;
        //The Move number is saved in CurrentTile
        Move currentTile = move;
        //Gets the oppositePiece by checking what value piece is
        Piece oppositePiece = (piece == Piece::WHITE) ? Piece::DARK : Piece::WHITE;
        //A test tile is created for testing in the following functions
        int testTile = 0;

        //The methods following will check for any oppositePieces that need to be changed due to the current players move. The mothods will look in
        //all available directions and change if necessary

        //This loop checks for any oppositePiece that need to be changed in the UP direction
        //current piece must be past the 1st row
        if (currentTile > 7){
            //Tests the tile directly above the current position
            testTile = currentTile - 8;
            //While the next tile is oppositePiece and the test tile is not in the 1st row
            while (testTile > 7 && tiles[testTile] == oppositePiece) {
                //keeps moving to the next above tile
                testTile -= 8;
            }
            //If the tile ends on the same piece as the players
            if (tiles[testTile] == piece) {
                //Loops and makes all the pieces into the same as Piece
                while (testTile != move) {
                    tiles[testTile] = piece;
                    testTile+=8;
                }
            }
        }

        //Checks for any changes that need to be done UpRIGHT from the current position
        //Also checks if the current position isnt in the last two columns
        if ( (currentTile+1)%8 != 0 || (currentTile+1)%8 != 7 ){
            //Tests the tile directly below the current position
            testTile = currentTile - 7;
            //While the next tile is oppositePiece and the test tile is not in the 1st or 2nd row and not in the last coloumn
            while (testTile > 15 && ((testTile+1)%8 != 0) && tiles[testTile] == oppositePiece ) {
                //Keeps moving upright
                testTile -= 7;
            }
            //If the tile ends on the same piece as the players
            if (tiles[testTile] == piece) {
                //Loops and makes all the pieces into the same as Piece
                while (testTile != move) {
                    tiles[testTile] = piece;
                    testTile+=7;
                }
            }

        }

        //Checks for any changes that need to be done RIGHT from the current position
        //Makes sure current tile isnt in the last two columns
        if ( (currentTile+1)%8 != 0 && (currentTile+1)%8 != 7 ){
            //Tests the tile directly right from the current position
            testTile = currentTile + 1;
            while (testTile < 64 && tiles[testTile] == oppositePiece) {
                //Keeps moving right
                testTile += 1;
            }
            //If the tile ends on the same piece as the players
            if (tiles[testTile] == piece) {
                //Loops and makes all the pieces into the same as Piece
                while (testTile != move) {
                    tiles[testTile] = piece;
                    testTile-=1;
                }
            }
        }

        //Checks for any changes that need to be done downright from the current position
        //Makes sure current tile isnt in the last two columns
        if ( (currentTile+1)%8 != 0 || (currentTile+1)%8 != 7 ){
            //Tests the tile directly downright from the current position
            testTile = currentTile + 9;
            while (testTile < 56 && ((testTile+1)%8 != 0) && tiles[testTile] == oppositePiece ) {
                //Keeps moving right
                testTile += 9;
            }
            //If the tile ends on the same piece as the players
            if (tiles[testTile] == piece) {
                while (testTile != move) {
                    //Loops and makes all the pieces into the same as Piece
                    tiles[testTile] = piece;
                    testTile-=9;
                }
            }
        }

        //Checks for any changes that need to be done down from the current position
        //Makes sure current tile isnt in the last 2 rows
        if (currentTile < 48){
            //Tests the tile directly downright from the current position
            testTile = currentTile + 8;
            while (testTile < 64 && tiles[testTile] == oppositePiece) {
                //Keeps moving down
                testTile += 8;
            }
            //If the tile ends on the same piece as the players
            if (tiles[testTile] == piece) {
                //Loops and makes all the pieces into the same as Piece
                while (testTile != move) {
                    tiles[testTile] = piece;
                    testTile-=8;
                }
            }
        }

        //Checks for any changes that need to be done downleft from the current position
        //Makes sure current tile isnt in the first two columns
        if ((currentTile+1)%8 != 1 && (currentTile+1)%8 != 2){
            //Tests the tile directly downleft from the current position
            testTile = currentTile + 7;
            while (testTile < 56 && ((testTile+1)%8 != 1) && tiles[testTile] == oppositePiece ) {
                testTile += 7;
            }
            //If the tile ends on the same piece as the players
            if (tiles[testTile] == piece) {
                //Loops and makes all the pieces into the same as Piece
                while (testTile != move) {
                    tiles[testTile] = piece;
                    testTile-=7;
                }
            }
        }

        //Checks for any changes that need to be done left from the current position
        //Makes sure current tile isnt in the first two columns
        if ((currentTile+1)%8 != 1 && (currentTile+1)%8 != 2){
            //Tests the tile directly left from the current position
            testTile = currentTile - 1;
            while (testTile > 0 && tiles[testTile] == oppositePiece) {
                testTile -= 1;
            }
            //If the tile ends on the same piece as the players
            if (tiles[testTile] == piece) {
                //Loops and makes all the pieces into the same as Piece
                while (testTile != move) {
                    tiles[testTile] = piece;
                    testTile+=1;
                }
            }
        }

        //Checks for any changes that need to be done upleft from the current position
        //Makes sure current tile isnt in the first two columns
        if ((currentTile+1)%8 != 1 && (currentTile+1)%8 != 2){
            //Tests the tile directly left from the current position
            testTile = currentTile - 9;
            while (testTile > 7 && ((testTile+1)%8 != 1) && tiles[testTile] == oppositePiece ) {
                testTile -= 9;
            }
            //If the tile ends on the same piece as the players
            if (tiles[testTile] == piece) {
                //Loops and makes all the pieces into the same as Piece
                while (testTile != move) {
                    tiles[testTile] = piece;
                    testTile+=9;
                }
            }
        }

}

//Checks if the Piece can move to the selected move location
bool Board::isLegal(Piece piece, Move move) const {
    //checks if the move is out of the boards index
    if (move > 63 || move < 0){
        return false;
    }
    //Goes throught the availMoves array and checks the selected move is in in. Otherwise false is returned
    for (int i = 0; i < counter; i++) {
        if (availMoves[i] == move){
            return true;
        }
    }
    return false;
}

//Seaarches the board and returns the winner or returns Piece.EMPTY if no winners
Piece Board::getWinner() const{

    //Counters for the pieces on the board
    int darkNum = 0;
    int whiteNum = 0;

    //Loops throught the board and increases the counter for the Pieces found on the board.
    //If the Piece::EMPTY is found then returns it and ends the loop
    for (int i = 0; i < 64; ++i){
        if (tiles[i] == Piece::WHITE){
            whiteNum++;
        }else if (tiles[i] == Piece::DARK){
            darkNum++;
        }
        else{
            return Piece::EMPTY;
        }
    }
    //If no Piece::EMPTY was not found then we check which Piece was found and returns Piece with the most Pieces on the board
    if (darkNum > whiteNum) {
        return Piece::DARK;
    }else if (whiteNum > darkNum){
        return Piece::WHITE;
    }else{
        //Tie
        return Piece::EMPTY;
    }
}

//Gets the current players piece which is saved in Turn
Piece Board::getPlayer() const{
    return turn;
}

//Adds a move into the availMoves array but checks if it isnt repeated
void Board::addToMoves(int move){

    bool contains = false;
    for (int i = 0; i < counter; ++i){
        if (availMoves[i] == move){
            contains = true;
        }
    }
    if (contains == false){
        availMoves[counter] = move;
        counter++;
    }
}

//Generates Moves that are possible by the current Player
void Board::genMoves(){

    counter = 0;

    //Processes entire Board
    for (int currentTile = 0; currentTile < 64; currentTile++) {
        //the current tile on the board belongs to the current player
        if (tiles[currentTile] == turn){
            //Creates an oppositePiece by checking the players piece
            Piece oppositePiece = (tiles[currentTile] == Piece::WHITE) ? Piece::DARK : Piece::WHITE;
            int testTile = 0;
            //Exceed2 is a bool that makes sure that the following while loops exceed2 loops which ensures that X0X is valid to become XXX but XX is not valid
            bool exceed2 = false;

            //The following next loops are used to test every direction from the currentTile and checks to see if the current player can make any possible moves in that location
            //In each direction loop it checks if the selected position is even a tile that can make that move. For ex if the tile is in the last two columns then the user cannot have any possible right moves
            //Once the direction finds a possible move it sends it to the addToMoves function that checks and adds it into the array
            //Comments that avoided for each loop. Simlar to the first loop.

            exceed2 = false;
            //Moves the tesTile right above the currentTile
            testTile = currentTile - 8;
            //While the testTile is in a location where the possibly of a good move is true
            while (testTile > 7 && tiles[testTile] == oppositePiece) {
                //Keeps moving the testtile above
                testTile -= 8;
                exceed2 = true;
            }
            //Once an Empty tile is found, that tile is the location the user can move to. The location is then added to the array
            if (exceed2 == true && testTile > 0 && tiles[testTile] == Piece::EMPTY){
                Board::addToMoves(testTile);
            }

            //UPRIGHT
            exceed2 = false;
            if ( (currentTile+1)%8 != 0 || (currentTile+1)%8 != 7 ){
                testTile = currentTile - 7;
                while (testTile > 15 && ((testTile+1)%8 != 0) && tiles[testTile] == oppositePiece ) {
                    testTile -= 7;
                    exceed2 = true;
                }
                //MAY NOT WORK IF WORKED ONLY ONCE IE 30
                if (exceed2 == true && tiles[testTile] == Piece::EMPTY){
                    addToMoves(testTile);
                }
            }

            //RIGHT
            exceed2 = false;
            if ( (currentTile+1)%8 != 0 && (currentTile+1)%8 != 7 ){
                testTile = currentTile + 1;
                while (testTile < 64 && tiles[testTile] == oppositePiece) {
                    testTile += 1;
                    exceed2 = true;
                }
                if (exceed2 == true && tiles[testTile] == Piece::EMPTY){
                    addToMoves(testTile);
                }
            }

            //DOWNRIGHT
            exceed2 = false;
            if ( (currentTile+1)%8 != 0 || (currentTile+1)%8 != 7 ){
                testTile = currentTile + 9;
                while (testTile < 56 && ((testTile+1)%8 != 0) && tiles[testTile] == oppositePiece ) {
                    testTile += 9;
                    exceed2 = true;
                }
                //MAY NOT WORK IF WORKED ONLY ONCE IE 30
                if (exceed2 == true && tiles[testTile] == Piece::EMPTY){
                    addToMoves(testTile);
                }
            }

            //DOWN
            if (currentTile < 48){
                exceed2 = false;
                testTile = currentTile + 8;
                while (testTile < 64 && tiles[testTile] == oppositePiece) {
                    testTile += 8;
                    exceed2 = true;
                }
                if (exceed2 == true && tiles[testTile] == Piece::EMPTY){
                    addToMoves(testTile);
                }
            }

            //DOWNLEFT
            exceed2 = false;
            if ((currentTile+1)%8 != 1 && (currentTile+1)%8 != 2){
                testTile = currentTile + 7;
                while (testTile < 56 && ((testTile+1)%8 != 1) && tiles[testTile] == oppositePiece ) {
                    testTile += 7;
                    exceed2 = true;
                }
                if (exceed2 == true && tiles[testTile] == Piece::EMPTY){
                    addToMoves(testTile);
                }
            }

            //LEFT
            exceed2 = false;
            if ((currentTile+1)%8 != 1 && (currentTile+1)%8 != 2){
                testTile = currentTile - 1;
                while (testTile > 0 && tiles[testTile] == oppositePiece) {
                    testTile -= 1;
                    exceed2 = true;
                }
                if (exceed2 == true && tiles[testTile] == Piece::EMPTY){
                    addToMoves(testTile);
                }
            }

            //UPLEFT
            exceed2 = false;
            if ((currentTile+1)%8 != 1 && (currentTile+1)%8 != 2){
                testTile = currentTile - 9;
                while (testTile > 7 && ((testTile+1)%8 != 1) && tiles[testTile] == oppositePiece ) {
                    testTile -= 9;
                    exceed2 = true;
                }
                if (exceed2 == true && tiles[testTile] == Piece::EMPTY){
                    addToMoves(testTile);
                }
            }

        }
        //Moves to next piece in the board
    }

}

//Retuns the numbers of Moves the current player can make by reading the counter that increases everytime an availMove is found
int Board::numMoves() const{
    return counter;
}

//Retuns the move from the argument given
Move Board::getMove(int move) const{
    Move temp = move;
    return temp;
}
