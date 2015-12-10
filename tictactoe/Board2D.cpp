#include "Board2D.h"
#include <iostream>
using namespace std;

Board2D::Board2D(int numOfRows, int numOfCols) { //constructor
    this->numOfCols = numOfCols;
    this->numOfRows = numOfRows;
    arr = createArray();
}

Board2D::Board2D(Board2D& orig) { //copy constructor    
    arr = createArray();
    for (int row = 0; row < numOfRows; row++)
        for (int col = 0; col < numOfCols; col++)
            setValueAtIndex(row, col, orig.getValueAtIndex(row, col));

}

Board2D::~Board2D() { //destructor
    delete[] arr;
}

//set method for elements in our array

void Board2D::setValueAtIndex(int row, int col, int val) {
    arr[row][col] = val;
}

//get method for elements in our array

int Board2D::getValueAtIndex(int row, int col) {
    return arr[row][col];
}

void Board2D::printToScreen() {
    for (int row = 0; row < numOfRows; row++) {
        for (int col = 0; col < numOfCols; col++) {
            int temp = getValueAtIndex(row, col);
            cout << " " << (temp == -99 ? '-' : (char) temp) << " ";
        }
        cout << endl;
    }
}

int** Board2D::createArray() {
    int** tArr = new int*[numOfRows];
    for (int row = 0; row < 3; row++) {
        tArr[row] = new int[numOfCols];
        for (int col = 0; col < 3; col++)
            // default value set to 99 so that we know if an index is empty if 
            // it's set to -99. 
            tArr[row][col] = -99;
    }
    return tArr;
}

int Board2D::getNumOfRows() {
    return numOfRows;
}

int Board2D::getNumOfCols() {
    return numOfCols;
}
