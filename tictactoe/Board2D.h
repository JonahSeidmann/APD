#ifndef BOARD_H
#define	BOARD_H

class Board2D {
public:
    Board2D(int numOfRows, int numOfCols);
    Board2D(Board2D& orig);
    virtual ~Board2D();
    void setValueAtIndex(int row, int col, int val);
    int getValueAtIndex(int row, int col);
    virtual void printToScreen();   
    int getNumOfRows();
    int getNumOfCols();
private:
    int numOfRows, numOfCols;
    int** arr;   
    int** createArray();

};

#endif	/* BOARD_H */

