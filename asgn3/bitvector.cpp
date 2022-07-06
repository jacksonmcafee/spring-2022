#include "bitvector.h"
#include <cmath>

const uint WORDSIZE = 32;
const uint DEFAULT_ARR = 256;

// set index bit
void BitVector::Set(const size_t index) {
  int current_word;
  if(index > size * WORDSIZE || index < 0) {
    // ERROR: out of range
    std::cout << "Invalid index, out of range." << std::endl;
    return;
  }
  else {
    // find correct word then bitlocation
    current_word = floor(index / WORDSIZE);
    bitlocations = 32 - (index % WORDSIZE);
  }

  // bit setting time
  bvect[current_word] |= 1UL << bitlocations;
}

// set all bits
void BitVector::Set() {
    for (int i = 0; i < size; i++) {
      bvect[i] = 1;
    }
}

// unset index bit
void BitVector::Unset(const size_t index) {
  int current_word;
  if(index > size * WORDSIZE || index < 0) {
    // ERROR: out of range
    std::cout << "Invalid index, out of range." << std::endl;
    return;
  }
  else {
    // find correct word then bitlocation
    current_word = floor(index / WORDSIZE);
    bitlocations = 32 - (index % WORDSIZE);
  }

  // bit-unsetting time
  bvect[current_word] &= ~(1UL << bitlocations);
}

// unset all bits
void BitVector::Unset() {
  for (int i = 0; i < size; i++) {
    bvect[i] = 0;
  }
}

// flip index bit
void BitVector::Flip(const size_t index) {
  int current_word;
  if(index > size * WORDSIZE || index < 0) {
    // ERROR: out of range
    std::cout << "Invalid index, out of range." << std::endl;
    return;
  }
  else {
    // find correct word then bitlocation
    current_word = floor(index / WORDSIZE);
    bitlocations = 32 - (index % WORDSIZE);
  }

  // bit-flipping time
  bvect[current_word] ^= 1UL << bitlocations;
}

// flip all bits
void BitVector::Flip() {
  for(int i = 0; i < size; i++) {
    bvect[i] = ~bvect[i];
  }
}

bool BitVector::Test(size_t index) const {
  int current_word;
  int l_bitlocations;
  if(index > size * WORDSIZE || index < 0) {
    // ERROR: out of range
    std::cout << "Invalid index, out of range." << std::endl;
    return false;
  }
  else {
    // find correct word then bitlocation
    current_word = floor(index / WORDSIZE);
    l_bitlocations = 32 - (index % WORDSIZE);
  }

  bool bit = (bvect[current_word] >> l_bitlocations) & 1U;
  return bit;
}

void BitVector::Print() {
  for (int i = 0; i < size; i++) {
    std::cout << bvect[i] << " ";
  }
  std::cout << std::endl;
}

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
    if (this == &a) return *this; // prevents self assignment

    size = a.size;
    bitlocations = a.bitlocations;
    bvect = new int[size];
    for (int i = 0; i < size; i++) {
      bvect[i] = a.bvect[i];
    }

    return *this;
}

size_t BitVector::Size() const {
    return size;
}

int main() {

  // write test suite

  return 0;
}
