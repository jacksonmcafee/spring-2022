#include "bitvector.h"

const int WORDSIZE = 32;
const int DEFAULT_ARR = 256;

// default constructor
BitVector::BitVector() {
    size = DEFAULT_ARR/WORDSIZE;
    bvect = new int[size];
    // defaults bvect to 0s
    for(int i = 0; i < size; i++) {
      bvect[i] = 0;
      }
    bitlocations = 0;
}

// explicit constructor
BitVector::BitVector(size_t bv_size) {
    // checks if extra word needs to be allocated
    if(bv_size % WORDSIZE == 0) {
      size = bv_size / WORDSIZE;
    } else {
      size = (bv_size / WORDSIZE) + 1;
    }

    bvect = new int[size];
    // defaults bvect to 0s
    for(int i = 0; i < size; i++) {
      bvect[i] = 0;
      }
    bitlocations = 0;
}

// copy constructor
BitVector::BitVector(const BitVector &copy) {
    size = copy.size;
    bitlocations = copy.bitlocations;
    bvect = new int[size];
    for(int i = 0; i < size; i++) {
        bvect[i] = copy.bvect[i];
    }
}

// destructor
BitVector::~BitVector() {
    delete[] bvect;
}

BitVector & BitVector::operator =(const BitVector &a) {
    BitVector return_bvect;
    return_bvect.size = a.size;
    return_bvect.bitlocations = a.bitlocations;
    return_bvect.bvect = new int[size];
    for (int i = 0; i < size; i++) {
      return_bvect.bvect[i] = a.bvect[i];
    }

    return return_bvect;
}

int main() {

  return 0;
}
