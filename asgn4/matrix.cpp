#include <string>

#include <iostream>

#include "matrix.h"

using namespace std;

const int MAXSIZE = 6;
const int MINSIZE = 2;

// default constructor
Matrix_Class::Matrix_Class() {
  rowsize = MAXSIZE;
  colsize = MAXSIZE;
  // matrix instantiation
  matrix = new int * [rowsize];
  for (int i = 0; i < rowsize; i++) {
    matrix[i] = new int[colsize];
  }

}

// param constructor
Matrix_Class::Matrix_Class(const int r,
  const int c) {
  if (r > MINSIZE && r < MAXSIZE) {
    rowsize = r;
  } else {
    rowsize = MAXSIZE;
  }

  if (c > MINSIZE && r < MAXSIZE) {
    colsize = c;
  } else {
    colsize = MAXSIZE;
  }
  // matrix instantiation
  matrix = new int * [rowsize];
  for (int i = 0; i < rowsize; i++) {
    matrix[i] = new int[colsize];
  }

}

// destructor
Matrix_Class::~Matrix_Class() {
  // can call Clear() func
  Matrix_Class::Clear();
}

void Matrix_Class::Clear() {
  rowsize = 0;
  colsize = 0;
  for (int i = 0; i < rowsize; i++) {
    delete[] matrix[i];
  }
  delete[] matrix;
}

void Matrix_Class::Zero() {
  // sets all matrix values to zero
  for (int i = 0; i < rowsize; i++) {
    for (int j = 0; j < colsize; j++) {
      matrix[i][j] = 0;
    }
  }
}

void Matrix_Class::Print(string msg) const {
  // prints matrix size + contents to stdout
  cout << msg << endl;
  cout << "Rowsize: " << rowsize << " | Colsize: " << colsize << endl;
  for (int i = 0; i < rowsize; i++) {
    for (int j = 0; j < colsize; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}

void Matrix_Class::Input() {
  // input to matrix from stdin
  for (int i = 0; i < rowsize; i++) {
    cout << "Input " << colsize << " numbers for Row " << i + 1 << ": " << endl;
    for (int j = 0; j < colsize; j++) {
      cin >> matrix[i][j];
    }
  }
}

void Matrix_Class::Resize(const int r,
  const int c) {
  // clear + resize rowsize & colsize
  Matrix_Class::Clear();
  if (r > MAXSIZE || r < MINSIZE) {
    rowsize = MAXSIZE;
  } else {
    rowsize = r;
  }
  if (c > MAXSIZE || c < MINSIZE) {
    colsize = MAXSIZE;
  } else {
    colsize = c;
  }

  matrix = new int * [rowsize];
  for (int i = 0; i < rowsize; i++) {
    matrix[i] = new int[colsize];
  }
}

