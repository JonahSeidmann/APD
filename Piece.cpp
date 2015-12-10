#include "Piece.h"
using namespace std;

// Constructors
Piece::Piece() {
    side = 0;
}

Piece::Piece(int s) {  // White = 1, Black = -1, No piece = 0
    side = s;
}
Piece::~Piece() {}

int Piece::getSide() {
    return side;
}

	
