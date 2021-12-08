#include "tictactoe.hpp"

TicTacToe::TicTacToe(std::string player1, std::string player2) {
    player1Name = player1;
    player2Name = player2;
}

void TicTacToe::run() {
    std::cout << "---Welcome come to Paul's checker Game---" << std::endl;
    std::cout << "Each player takes to put their mark!" << std::endl;
    std::cout << "player1 has [O], player2 has [X]" << std::endl;
    std::cout << player1Name << " will take the first turn!" << std::endl;
    displayBoard();

    currentPlayer = player1Name;
    currentMarker = 'O';
    bool isValid1 = true;
    bool isValid2 = true;
    int count = 0;

    while(isValid1) {
        while(isValid2) {
            std::cout << currentPlayer << "'s turn! pick a spot bettwen 1 ~ 9" << std::endl;
            std::cin >> spotNumber;
            if(isAvailableNumber(spotNumber) || isAvailableMarker(spotNumber) || std::cin.fail()) {
                std::cout << "That spot is invalid" << std::endl;
                std::cin.clear();
                std::cin.ignore();
            } else {
                isValid2 = false;
            }
        }

        isValid2 = true;
        count++;
        spotMarker(spotNumber);
        displayBoard(); //result spotMarker

        if(isWinner()) {
            std::cout << "sameThree: " << currentMarker << " , "
                      << currentMarker << " , "
                      << currentMarker << std::endl;
            std::cout << currentPlayer << " have a winner!" << std::endl;
            isValid1 = false;
        } else if(count == 9) {
            std::cout << "That is a tie game!" << std::endl;
            isValid1 = false;
        }
        swapMarkerAndPlayer();
    }
}

void TicTacToe::swapMarkerAndPlayer() {
    if(currentMarker == 'O') {
        currentMarker = 'X';
    } else {
        currentMarker = 'O';
    }

    if(currentPlayer == player1Name) {
        currentPlayer = player2Name;
    } else {
        currentPlayer = player1Name;
    }
}

bool TicTacToe::isAvailableNumber(int inputSpotNumber) {
    if(inputSpotNumber > 0 && inputSpotNumber < 10) {
        return false;
    }
    return true;
}

bool TicTacToe::isAvailableMarker(int inputNumber) {
    row = spotNumber / 3;
    col = 0;
    if(inputNumber % 3 == 0) {
        row = row - 1;
        col = 2;
    } else {
        col = (inputNumber % 3) - 1;
    }

    if(board[row][col] == 'X' || board[row][col] == 'O') {
        return true;
    }
    return false;
}

void TicTacToe::spotMarker(int inputNumber) {
    row = spotNumber / 3;
    col = 0;
    if(inputNumber % 3 == 0) {
        row = row - 1;
        col = 2;
    } else {
        col = (inputNumber % 3) - 1;
    }
    board[row][col] = currentMarker;
}

void TicTacToe::displayBoard() {
    std::cout << " " << board[0][0]  << " | " << board[0][1] << " | " << board[0][2] << std::endl;
    std::cout << "-----------" << std::endl;
    std::cout << " " << board[1][0]  << " | " << board[1][1] << " | " << board[1][2] << std::endl;
    std::cout << "-----------" << std::endl;
    std::cout << " " << board[2][0]  << " | " << board[2][1] << " | " << board[2][2] << std::endl;
}

bool TicTacToe::isWinner() {
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return true;
        }
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return true;
        }
    }
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return true;
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return true;
    }
    return false;
}