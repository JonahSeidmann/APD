#include "Piece.h"
#ifndef ROOK_H
#define	ROOK_H
using namespace std;

class Rook: public Piece {
public:
    Rook(int s);
    virtual ~Rook();
    void printPiece();
    bool isLegal(int x1, int y1, int x2, int y2, int s);
    bool moveThroughPieces();
    char getPiece();
};

#endif	/* ROOK_H */


#ifndef KNIGHT_H
#define	KNIGHT_H
using namespace std;

class Knight: public Piece {
public:
    Knight(int s);
    virtual ~Knight();
    void printPiece();
    bool isLegal(int x1, int y1, int x2, int y2, int s);
    bool moveThroughPieces();
    char getPiece();
};


#endif	/* KNIGHT_H */

#ifndef BISHOP_H
#define	BISHOP_H
using namespace std;

class Bishop: public Piece {
public:
    Bishop(int s);
    virtual ~Bishop();
    void printPiece();
    bool isLegal(int x1, int y1, int x2, int y2, int s);
    bool moveThroughPieces();
    char getPiece();
};

#endif	/* BISHOP_H */


#ifndef QUEEN_H
#define	QUEEN_H
using namespace std;

class Queen: public Piece {
public:
    Queen(int s);
    virtual ~Queen();
    void printPiece();
    bool isLegal(int x1, int y1, int x2, int y2, int s);
    bool moveThroughPieces();
    char getPiece();
};

#endif	/* QUEEN_H */


#ifndef KING_H
#define	KING_H
using namespace std;

class King: public Piece {
public:
    King(int s);
    virtual ~King();
    void printPiece();
    bool isLegal(int x1, int y1, int x2, int y2, int s);
    bool moveThroughPieces();
    char getPiece();
};

#endif	/* KING_H */


#ifndef PAWN_H
#define	PAWN_H
using namespace std;

class Pawn: public Piece {
public:
    Pawn(int s);
    virtual ~Pawn();
    void printPiece();
    bool isLegal(int x1, int y1, int x2, int y2, int s);
    bool moveThroughPieces();
    char getPiece();
};

#endif	/* PAWN_H */


#ifndef EMPTYSPACE_H
#define	EMPTYSPACE_H
using namespace std;

class EmptySpace: public Piece {
public:
    EmptySpace(int s);
    virtual ~EmptySpace();
    void printPiece();
    char getPiece();
};

#endif	/* EMPTYSPACE_H */
