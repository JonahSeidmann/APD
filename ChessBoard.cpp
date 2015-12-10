#include "ChessBoard.h"
#include <iostream>
#include "Piece.h"
#include "Pieces.h"
using namespace std;

// Default constructor places pieces, white (=1) on bottom and black (=-1) on top
ChessBoard::ChessBoard() {
    Rook wRook(1);
    Knight wKnight(1);
    Bishop wBishop(1);
    Queen wQueen(1);
    King wKing(1);
    Pawn wPawn(1);

    EmptySpace empty(0);

    Rook bRook(-1);
    Knight bKnight(-1);
    Bishop bBishop(-1);
    Queen bQueen(-1);
    King bKing(-1);
    Pawn bPawn(-1);

    Piece **board = new Piece[8][8];
    board[0][0] = &wRook;
    board[0][1] = &wKnight;
    board[0][2] = &wBishop;
    board[0][3] = &wQueen;
    board[0][4] = &wKing;
    board[0][5] = &wBishop;
    board[0][6] = &wKnight;
    board[0][7] = &wRook;
    for (int c = 0; c < columns; c++) {
	board[1][c] = &wPawn;
    }
    for (int r = 2; r < 6; r++) {
	for (int c = 0; c < 8; c++) {
	    board[r][c] = &empty;
	 }
    }
    for (int c = 0; c < 8; c++) {
	board[6][c] = &bPawn;
    }
    board[7][0] = &bRook;
    board[7][1] = &bKnight;
    board[7][2] = &bBishop;
    board[7][3] = &bQueen;
    board[7][4] = &bKing;
    board[7][5] = &bBishop;
    board[7][6] = &bKnight;
    board[7][7] = &bRook;
}

ChessBoard::~ChessBoard() {
    delete[] board;
}

void ChessBoard::printBoard() {
    cout << "   " << "a" << "   " << "b" << "   " << "c" << "   " << "d" << "   " << "e" << "   " << "f" << "   " << "g" << "   " << "h" << endl;;
    for (int r = 7; r >= 0; r--) {
	cout << (r+1);
	for (int c = 0; c < 8; c++) {
	    *board[r][c].printPiece();
	}
	cout << endl;
    }
}

void ChessBoard::newMove(char move[]) {
    cin >> move;
}

int ChessBoard::getLetterIndex(char c) {
    int i = c - '1';		// Char stored in order from 0 to 9 (values are 48 to 57), this subtracts the value for 0 to get a value from 0 to 9 and gives that value, -1 for offset
    return i;			
}

int ChessBoard::getNumberIndex(int i) {
    return (i - 1);
}

bool ChessBoard::checkMove(int x1, int y1, int x2, int y2, int team) {
    if (*board[x1][y1].getSide() == team) {					// Moving own piece
	if (*board[x2][y2].getSide() != team) {					// Not moving onto own piece
	    if (*board[x1][y1].isLegal(x1, y1, x2, y2, *board[x2][y2].getside())) {	// Can piece move there
		ChessBoard dummyBoard = board;					// Make dummy board to see if moving into check
		dummyBoard.makeMove(x1,y1,x2,y2);
		if (not dummyBoard.isCheck(-1*team)) {
		    if (*board[x1][y1].moveThroughPieces()) {			// Check if it can move through pieces (knight, pawn, king)
	    	    	return true;
		    }
		    else if (noPiecesBetween(x1,y1,x2,y2)) {			// Check if no piece in between
	    	    	return true;
		    }
		    else { 
	    	    	cout << "A piece is blocking that move" << endl;
	    	    return false;
		    }
    	    	}
    	    	else {
		    cout << "That move places you in check" << endl;
		    return false;
	        }
	    }
	    else {
		cout << "That piece cannot move there" << endl;
		return false;
	    }
	}
	else {
	    cout << "You are trying to capture your own piece" << endl;
	    return false;
    	}
    }
    else {
    cout << "You have nothing to move from there" << endl;
    return false;
    }
}

bool ChessBoard::noPiecesBetween(int x1, int y1, int x2, int y2) {
    int deltax, deltay;
    if ((x2 - x1) > 0) { deltax = 1; }
    else if ((x2 - x1) == 0) { deltax = 0; }
    else if ((x2 - x1) < 0) { deltax = -1; }
    if ((y2 - y1) > 0) { deltay = 1; }
    else if ((y2 - y1) == 0) { deltay = 0; }
    else if ((y2 - y1) < 0) { deltay = -1; }
    int x = x1 + deltax, y = y1 + deltay;
    while ((x != x2) && (y != y2)) {
	if (*board[x][y].getSide() != 0) {
	    return false;
	}
    x += deltax;
    y += deltay;
    }
    return true;
}


void ChessBoard::makeMove(int x1, int y1, int x2, int y2) {
    board[x2][y2] = board[x1][y1];
    board[x1][y1] = &empty;
    if ((*board[x2][y2].getPiece() == 'P') && (x2 == endSide(*board[x2][y2].getSide()))) {
	changePiece(x2,y2,*board[x2][y2].getSide());
    }
}

int ChessBoard::endSide(int team) {
    if (team == 1) {
	return 7;
    }
    else if (team == -1) {
	return 0;
    }
}

void ChessBoard::changePiece(int x, int y, int team) {
    char p;
    cout << "A pawn has reached the end! What would you like it to become?" << endl;
    cin >> p;
    if (team == 1) {
	if (p == 'R') {
	    board[x][y] = &wRook;
	}
	else if (p == 'k') {
	    board[x][y] = &wKnight;
	}
	else if (p == 'B') {
	    board[x][y] = &wBishop;
	}
	else if (p == 'Q') {
	    board[x][y] = &wQueen;
	}
	else if (p == 'P') {
	    board[x][y] = &wPawn;
	}
	else {
	    cout << "That is not a valid piece" << endl;
	    changePiece(x, y, team);
	}
    }
    else if (team == -1) {
	if (p == 'R') {
	    board[x][y] = &bRook;
	}
	else if (p == 'k') {
	    board[x][y] = &bKnight;
	}
	else if (p == 'B') {
	    board[x][y] = &bBishop;
	}
	else if (p == 'Q') {
	    board[x][y] = &bQueen;
	}
	else if (p == 'P') {
	    board[x][y] = &bPawn;
	}
	else {
	    cout << "That is not a valid piece" << endl;
	    changePiece(x, y, team);
	}
    }
}

bool ChessBoard::isCheck(int team) {
    int kingx = findKingx(team);
    int kingy = findKingy(team);
    for (int r = 0; r < 8; r++){
	for (int c = 0; c < 8; c++) {
	    if (checkMove (r, c, kingx, kingy, -1*team)) {
		return true;
	    }
	}
    }
    return false;
}

int ChessBoard::findKingx(int team) {
    for (int r = 0; r < 8; r++){
	for (int c = 0; c < 8; c++) {
	   if ((*board[r][c].getPiece() == 'K') && (*board[r][c].getSide() == team)) {
		return c;
	   }
	}
    }
    cout << "No king found" << endl;
    return 0;
}

int ChessBoard::findKingy(int team) {
    for (int r = 0; r < 8; r++){
	for (int c = 0; c < 8; c++) {
	   if ((*board[r][c].getPiece() == 'K') && (*board[r][c].getSide() == team)) {
		return r;
	   }
	}
    }
    cout << "No king found" << endl;
    return 0;
}
		
bool ChessBoard::isMate(int team) {
    ChessBoard dummyBoard();
    for (int x1 = 0; x1 < 8; x1++) {
	for (int y1 = 0; y1 < 8; y1++) {
	    for (int x2 = 0; x2 < 8; x2++) {
		for (int y2 = 0; y2 < 8; y2++) {
		    if (checkMove(x1,y1,x2,y2,team)) {
			dummyBoard.setBoard(board);
			dummyBoard.makeMove(x1,y1,x2,y2);
			if (not dummyBoard.isCheck(team)) {
			    return false;
			}
		    }
    		}
	    }
	}
    }
    return true;
}

void ChessBoard::takeTurn(int team) {
    if (team == 1) {
	cout << "White team turn. Input move" << endl;
    }
    else if (team == -1) {
	cout << "Black team turn. Input move" << endl;
    }
    char move[8];
    newMove(move);
    int x1 = getLetterIndex(move[0]);
    int x2 = getLetterIndex(move[6]);
    int y1 = getNumberIndex(move[1]);
    int y2 = getNumberIndex(move[7]);
    if (checkMove(x1,y1,x2,y2,team)) {
	makeMove(x1,y1,x2,y2);
	endTurn(team);
    }
    else { takeTurn(team); }
}

void ChessBoard::endTurn(int team) {
    printBoard();
    int stop = 0;
    if (isCheck(team*-1)) {
	if (isMate(team*-1)) {
	    if (team == 1) {
		cout << "Checkmate! White team wins!" << endl;
		stop = 1;
	    }
	    else if (team == -1) {
		cout << "Checkmate! Black team wins!" << endl;
		stop = 1;
	    }
	}
	else {
	    cout << "Check" << endl;
	}
    }
    if (stop == 0) {
    takeTurn(team*-1);
    }
}
























