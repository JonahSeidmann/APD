/* 
 * File:   TictactoeBoard.h
 * Author: mustafa
 *
 * Created on 13 November 2015, 13:56
 */

#ifndef TICTACTOEBOARD_H
#define	TICTACTOEBOARD_H
#include "Board2D.h"

class TictactoeBoard : public Board2D {
public:
    TictactoeBoard();
    TictactoeBoard(TictactoeBoard& orig);
    virtual ~TictactoeBoard();
    void printToScreen();
    bool checkIfValidMove(int row, int col);
    bool play(bool player, int row, int col);
    bool checkIfPlayerWon(bool player, int row, int col);
private:

};

#endif	/* TICTACTOEBOARD_H */

