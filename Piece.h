#ifndef PIECE_H
#define	PIECE_H
using namespace std;

class Piece {
public:
    Piece();
    Piece(int s);
    virtual ~Piece();
    int getSide();
    virtual void printPiece() = 0;
protected:
    int side;
};

#endif	/* PIECE_H */
