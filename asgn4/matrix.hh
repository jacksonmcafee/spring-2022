#ifndef MATRIX_H
#define MATRIX_H

#include <string>

using namespace std;

class Matrix_Class {
  public:
    Matrix_Class(); // default constructor
  Matrix_Class(const int r,
    const int c = 6); // constructor
  ~Matrix_Class(); // destructor
  void Clear(); // delete matrix
  void Zero(); // set all matrix values to zero
  void Print(string msg) const; // print matrix to stdout
  void Input(); // input to matrix from stdin
  void Resize(const int r,
    const int c); // clear + resize row + col

  int Getrowsize() {
    return rowsize;
  }
  int Getcolsize() {
    return colsize;
  }

  Matrix_Class & operator = (const Matrix_Class & m) {
    // copy private values
    rowsize = m.rowsize;
    colsize = m.colsize;

    // copy matrix data
    for (int i = 0; i < rowsize; i++) {
      for (int j = 0; j < colsize; j++) {
        matrix[i][j] = m.matrix[i][j];
      }
    }
    return *this;
  }
/*
  Matrix_Class & operator * (Matrix_Class & m1) {
    // storage object to return
    int temp = 0;
    bool canMultiply;
    // if r = m1.c, true
    // if r != m1.c, false
    if (rowsize == m1.colsize) {
      canMultiply = true;
    } else {
      cout << "Invalid matrix sizes. Ending program." << endl;
      exit(0);
    }

    if (canMultiply) {
      for (int i = 0; i < rowsize; i++) {
        for (int j = 0; j < m1.colsize; j++) {
          temp = 0;
          for (int k = 0; k < m1.rowsize; k++) {
            temp += matrix[i][k] * m1.matrix[k][j];
          }
          // deal with temp here
        }
      }
    }

    return "something here";
  }
*/

  private:
  int * * matrix;
  int rowsize;
  int colsize;
};

#endif
