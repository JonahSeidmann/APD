#include <iostream>
#include "Board2D.h"
#include "TictactoeBoard.h"
using namespace std;

bool playerTurn = 1;

void changeTurn() {
    playerTurn = !playerTurn;
}

void clearConsole() {
    cout << "\x1B[2J\x1B[H";
}

void printState(TictactoeBoard& b) {
    clearConsole();
    b.printToScreen();
}

int main(int argc, char** argv) {
    int row, col;
    TictactoeBoard b;
    b.printToScreen();
    int turnNumber = 1;
    while (turnNumber < 10) {
        cout << (playerTurn ? 'X' : 'O') << " turn!" << endl;
        cout << "row (0-2):";
        cin>>row;
        cout << "row (0-2):";
        cin>>col;
        if (b.play(playerTurn, row, col)) {
            printState(b);
            if (turnNumber >= 5) {
                if (b.checkIfPlayerWon(playerTurn, row, col)) {
                    cout << (playerTurn ? 'X' : 'O') << " won!" << endl;
                    break;
                } else if (turnNumber == 9) {
                    printState(b);
                    cout << "Draw game!" << endl;
                } else;
            }
            changeTurn();
            turnNumber++;
        } else
            cout << "Invalid move" << endl;
    }
    return 0;
}

