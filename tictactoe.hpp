// How to display board?
    // what is display? cout
    // board <- what is board? int board[3][3]
// How to reserve(save) board
    // cin
// Where to save/handle players
    // class
// Take turn <- bool true = 1 player // false = 0 player
// How do we know that we have a winner
    // [0 0][0 1][0 2]
    // [1 0][1 1][1 2]
    // [2 0][2 1][2 2]
// What if the user tries to put a mark that is already occupied
// std::string
// std::vector
// std::cout

#ifndef tictactoe_hpp
#define tictactoe_hpp
#include <iostream>
#include <vector>
//1. How to write re-usable code
//      what is essential
        //how to group them
        
class TicTacToe {
private:
    bool isAvailableNumber(int inputSpotNumber);
    bool isAvailableMarker(int inputNumber);
    bool isWinner();
    void displayBoard();
    void swapMarkerAndPlayer();
    void spotMarker(int inputNumber);

    char currentMarker;
    std::string currentPlayer;
    int spotNumber;
    std::string player1Name;
    std::string player2Name;
    int row;
    int col;
    char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

public:
    TicTacToe(std::string player1, std::string player2);
    void run();
};

#include "tictactoe.cpp"
#endif