/* 
 * File:   TictactoeBoard.cpp
 * Author: mustafa
 * 
 * Created on 13 November 2015, 13:56
 */

#include "TictactoeBoard.h"
#include "Board2D.h"
#include <iostream>
using namespace std;

TictactoeBoard::TictactoeBoard() : Board2D(3, 3) {
}

TictactoeBoard::TictactoeBoard(TictactoeBoard& orig) : Board2D(3, 3) {
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            setValueAtIndex(row, col, orig.getValueAtIndex(row, col));
}

TictactoeBoard::~TictactoeBoard() {
}

void TictactoeBoard::printToScreen() {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            int temp = getValueAtIndex(row, col);
            cout << " " << (temp == -99 ? '-' : temp == 1 ? 'X' : 'O') << " ";
        }
        cout << endl;
    }
}

bool TictactoeBoard::play(bool player, int row, int col) {
    if (checkIfValidMove(row, col)) {
        setValueAtIndex(row, col, player);
        return true;
    } else
        return false;
}

bool TictactoeBoard::checkIfValidMove(int row, int col) {
    if (row <= 2 && col <= 2)
        return getValueAtIndex(row, col) == -99;
    return false;
}

bool TictactoeBoard::checkIfPlayerWon(bool player, int row, int col) {
    if (getValueAtIndex(row, 0) == player && getValueAtIndex(row, 1) == player && getValueAtIndex(row, 2) == player)
        return true;
    else if (getValueAtIndex(0, col) == player && getValueAtIndex(1, col) == player && getValueAtIndex(2, col) == player)
        return true;
    else if ((getValueAtIndex(1, 1) == player) && !((row == 2 && col!= 2) || (row != 2 && col == 2)))
        if (getValueAtIndex(0, 0) == player && getValueAtIndex(2, 2) == player)
            return true;
        else if (getValueAtIndex(0, 2) == player && getValueAtIndex(2, 0) == player)
            return true;
        else
            return false;
    else
        return false;
}


