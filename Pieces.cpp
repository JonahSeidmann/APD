#include "Piece.h"
#include "Piece.cpp"
#include "Pieces.h"
#include <iostream>
#include <cmath>
using namespace std;

Rook::Rook(int s):Piece(s) {}

Rook::~Rook(){}

void Rook::printPiece() {
    if (side == 1) {
	cout << "  wR";
    }
    else if (side == -1) {
	cout << "  bR";
    }
    else {
	cout << "This piece does not have a side";
    }
}

bool Rook::isLegal (int x1, int y1, int x2, int y2, int s) {
    if ((x1 == x2) ^ (y1 == y2)) {
	return true;
    }
    else {
	return false;
    }
}

bool Rook::moveThroughPieces() {
    return false;
}

char Rook::getPiece() {
    return 'R';
}


Knight::Knight(int s):Piece(s) {}

Knight::~Knight(){}

void Knight::printPiece() {
    if (side == 1) {
	cout << "  wk";
    }
    else if (side == -1) {
	cout << "  bk";
    }
    else {
	cout << "This piece does not have a side";
    }
}

bool Knight::isLegal (int x1, int y1, int x2, int y2, int s) {
    if ((abs(x1 - x2) == 1) && (abs(y1 - y2) == 2)) {
	return true;
    }
    else if ((abs(x1 - x2) == 2) && (abs(y1 - y2) == 1)) {
	return true;
    }
    else {
	return false;
    }
}

bool Knight::moveThroughPieces() {
    return true;
}

char Knight::getPiece() {
    return 'k';
}


Bishop::Bishop(int s):Piece(s) {}

Bishop::~Bishop(){}

void Bishop::printPiece() {
    if (side == 1) {
	cout << "  wB";
    }
    else if (side == -1) {
	cout << "  bB";
    }
    else {
	cout << "This piece does not have a side";
    }
}

bool Bishop::isLegal (int x1, int y1, int x2, int y2, int s) {
    if (abs(x1 - x2) == abs(y1 - y2)) {
	return true;
    }
    else {
	return false;
    }
}

bool Bishop::moveThroughPieces() {
    return false;
}

char Bishop::getPiece() {
    return 'B';
}


Queen::Queen(int s):Piece(s) {}

Queen::~Queen(){}

void Queen::printPiece() {
    if (side == 1) {
	cout << "  wQ";
    }
    else if (side == -1) {
	cout << "  bQ";
    }
    else {
	cout << "This piece does not have a side";
    }
}

bool Queen::isLegal (int x1, int y1, int x2, int y2, int s) {
    if (abs(x1 - x2) == abs(y1 - y2)) {
	return true;
    }
    else if ((x1 == x2) ^ (y1 == y2)) {
	return true;
    }
    else {
	return false;
    }
}

bool Queen::moveThroughPieces() {
    return false;
}

char Queen::getPiece() {
    return 'Q';
}


King::King(int s):Piece(s) {}

King::~King(){}

void King::printPiece() {
    if (side == 1) {
	cout << "  wK";
    }
    else if (side == -1) {
	cout << "  bK";
    }
    else {
	cout << "This piece does not have a side";
    }
}

bool King::isLegal (int x1, int y1, int x2, int y2, int s) {
    if ((abs(x1 - x2) <= 1) && (abs(y1 - y2) <= 1)) {
	return true;
    }
    else {
	return false;
    }
}

bool King::moveThroughPieces() {
    return true;
}

char King::getPiece() {
    return 'K';
}


Pawn::Pawn(int s):Piece(s) {}

Pawn::~Pawn(){}

void Pawn::printPiece() {
    if (side == 1) {
	cout << "  wP";
    }
    else if (side == -1) {
	cout << "  bP";
    }
    else {
	cout << "This piece does not have a side";
    }
}

bool Pawn::isLegal (int x1, int y1, int x2, int y2, int s) {
    if ((x1 == x2) && (y2 == (y1 + side))) {
	return true;
    }
    else if ((abs(x1 - x2) == 1) && (y2 == y1 + side) && (s == side*-1)) {
	return true;
    }
    else if ((x1 == x2) && (y2 == (y1 + 2*side))) {
	return true;
    }
    else {
	return false;
    }
}

bool Pawn::moveThroughPieces() {
    return true;
}

char Pawn::getPiece() {
    return 'P';
}


EmptySpace::EmptySpace(int s):Piece(s) {}

EmptySpace::~EmptySpace(){}

void EmptySpace::printPiece() {
    cout << "  __";
}

char EmptySpace::getPiece() {
    return '_';
}
