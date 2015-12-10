#include "Piece.h"
#include "Piece.cpp"
#include "Pieces.h"
#include <iostream>
using namespace std;

Rook::Rook():Piece(int s) {}

Rook::~Rook(){}

void printPiece() {
    if (side == 1) {
	cout << "  wR";
    }
    else if (side == -1) {
	cout << "  bR";
    else {
	cout << "This piece does not have a side";
    }
}

bool isLegal (int x, int y, int s) {
    else if (x == 0 ^^ y == 0) {
	return true;
    }
    else {
	return false;
    }
}

bool moveThroughPieces() {
    return false;
}

char getPiece() {
    return 'R';
}


Knight::Knight():Piece(int s) {}

Knight::~Knight(){}

void printPiece() {
    if (side == 1) {
	cout << "  wk";
    }
    else if (side == -1) {
	cout << "  bk";
    else {
	cout << "This piece does not have a side";
    }
}

bool isLegal (int x, int y, int s) {
    else if (abs(x) == 1 && abs(y) == 2) {
	return true;
    }
    else if (abs(x) == 2 && abs(y) == 1) {
	return true;
    }
    else {
	return false;
    }
}

bool moveThroughPieces() {
    return true;
}

char getPiece() {
    return 'k';
}


Bishop::Bishop():Piece(int s) {}

Bishop::~Bishop(){}

void printPiece() {
    if (side == 1) {
	cout << "  wB";
    }
    else if (side == -1) {
	cout << "  bB";
    else {
	cout << "This piece does not have a side";
    }
}

bool isLegal (int x, int y, int s) {
    else if (abs(x) == abs(y)) {
	return true;
    }
    else {
	return false;
    }
}

bool moveThroughPieces() {
    return false;
}

char getPiece() {
    return 'B';
}


Queen::Queen():Piece(int s) {}

Queen::~Queen(){}

void printPiece() {
    if (side == 1) {
	cout << "  wQ";
    }
    else if (side == -1) {
	cout << "  bQ";
    else {
	cout << "This piece does not have a side";
    }
}

bool isLegal (int x, int y, int s) {
    else if (abs(x) == abs(y)) {
	return true;
    }
    else if (x == 0 ^^ y == 0) {
	return true;
    }
    else {
	return false;
    }
}

bool moveThroughPieces() {
    return false;
}

char getPiece() {
    return 'Q';
}


King::King():Piece(int s) {}

King::~King(){}

void printPiece() {
    if (side == 1) {
	cout << "  wK";
    }
    else if (side == -1) {
	cout << "  bK";
    else {
	cout << "This piece does not have a side";
    }
}

bool isLegal (int x, int y, int s) {
    else if (abs(x) <= 1 && abs(y) <= 1) {
	return true;
    }
    else {
	return false;
    }
}

bool moveThroughPieces() {
    return true;
}

char getPiece() {
    return 'K';
}


Pawn::Pawn():Piece(int s) {}

Pawn::~Pawn(){}

void printPiece() {
    if (side == 1) {
	cout << "  wP";
    }
    else if (side == -1) {
	cout << "  bP";
    else {
	cout << "This piece does not have a side";
    }
}

bool isLegal (int x, int y, int s) {
    else if (x == 0 && y == side) {
	return true;
    }
    else if (abs(x) == 1 && y == 0 && s == side*-1) {
	return true;
    }
    else {
	return false;
    }
}

bool moveThroughPieces() {
    return true;
}

char getPiece() {
    return 'P';
}


EmptySpace::EmptySpace():Piece(int s) {}

EmptySpace::~EmptySpace(){}

void printPiece() {
	cout << "  __";
}

bool isLegal (int x, int y, int s) {
	return false;
}

bool moveThroughPieces() {
    return true;
}

char getPiece() {
    return '_';
}
