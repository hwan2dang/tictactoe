//https://www.youtube.com/watch?v=vQpgElG_Yfg&list=PLS-PUtTgdOpP_GPayGfPo4IShiq8Pybeg&ab_channel=KyoHeo

#include <iostream>
#include "tictactoe.hpp"
using namespace std;

string getPlayer(int inputNumber) {
    string playerName = " ";
    char answer = ' ';
    bool isValid = false; //bool positiveQuestion

    while(!isValid) {
        cout << "enter player" << inputNumber << "'s name: ";
        cin >> playerName;
        cout << "player" << inputNumber << "'s name is " << playerName << ". "
             << "is it correct? (y/n)" << endl;
        cin >> answer;

        if(answer == 'y') {
            isValid = true;
        } else {
            cout << "type your name again" << endl;
        }
    }
    return playerName;
}

int main() {
    string player1 = getPlayer(1); //ask name, "y"
    string player2 = getPlayer(2); //ask name

    TicTacToe myGame(player1, player2);
    myGame.run();

    return 0;
}