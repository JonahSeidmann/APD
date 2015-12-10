#ifndef CHESSBOARD_H
#define	CHESSBOARD_H
#include "Piece.h"
#include "Pieces.h"
using namespace std;

class ChessBoard {

public:
    ChessBoard();
    ~ChessBoard();
    void printBoard();
    void newMove(char move[]);
    int getLetterIndex(char c);
    int getNumberIndex(int i);
    bool checkMove(int x1, int y1, int x2, int y2, int team);
    bool noPiecesBetween(int x1, int y1, int x2, int y2);
    void makeMove(int x1, int y1, int x2, int y2);
    int endSide(int team);
    void changePiece(int x, int y, int team);
    bool isCheck(int team);
    int findKingx(int team);
    int findKingy(int team);
    bool isMate(int team);
    void takeTurn(int team);
    void endTurn(int team);

private:
    Piece board;
};

#endif	/* CHESSBOARD_H */
