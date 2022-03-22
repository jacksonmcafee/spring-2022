#include <cstdlib>
#include <iostream>
#include <vector>
#include <cmath>
#include "bitvector.h"

const int WORDSIZE = 32;
const int DEFAULT_ARR = 256;

using namespace std;

// BitVector constructors
BitVector::BitVector() {
    size = (DEFAULT_ARR/WORDSIZE);
    // creates bitvec
    bvect = new int[size];
    for(int i = 0; i < size; i++) {
	bvect[i] = 0;
	}
}

BitVector::BitVector(size_t bv_size) {
    // remainder logic, testing for +1 to size (# of words)
    bool no_remainder = false;
    if (bv_size % WORDSIZE == 0) {
        no_remainder = true;
    }
    
    if (no_remainder == true) {
        size = (bv_size/WORDSIZE);
    }
    else {
        size = (bv_size/WORDSIZE) + 1;
    }
    
    // creates bitvec
    bvect = new int[size];
    for(int i = 0; i < (size); i++) {
	bvect[i] = 0;
	}
}

BitVector::BitVector( const BitVector &obj) {
    size = obj.size;
    bitlocations = obj.bitlocations;
    bvect = new int[size];
    for(int i = 0; i < size; i++) {
	bvect[i] = obj.bvect[i];
	}
}

BitVector::~BitVector() {
    delete[] bvect;
}

void BitVector::Set() {
    // sets all bit values to 1
    // 255(11111111)
    for(int i = 0; i < size; i++) {
	bvect[i] = 255;
	}
}

void BitVector::Set(const size_t index) {
    // locating bit
    int word_index = round(floor(index/size));
    bitlocations = 31 - (index % 32);
    int temp = bvect[word_index];
    // creating bitmask
    // 1(00000001)
    int bitmask = 1;

    if(index < 0 || index > size*word_index) {
        return; }
    

    bitmask = bitmask << bitlocations;
    // logical OR and setting the bit
    temp = temp | bitmask;
    bvect[word_index] = temp;

}

void BitVector::Unset() {
    // sets all bit values to 0
    // 0(00000000)
    for(int i = 0; i < size; i++) {
	bvect[i] = 0;
	}
}

void BitVector::Unset(const size_t index) {
    // locating bit
    int word_index = round(floor(index/size));
    bitlocations = 31 - (index % 32);
    // creating bitmask of 0
    int temp1 = bvect[word_index];
    int temp2 = bvect[word_index];
    int bitmask1 = 0;
    
    if(index < 0 || index > size*word_index) {
        return; }

    // shifting bit to first pos
    temp1 = temp1 >> bitlocations;
    // logical AND with 0 bitmask,
    temp1 = temp1 ^ bitmask1;
    if(temp1 == 1) {
	temp2 &= ~(1UL << bitlocations);
	bvect[word_index] = temp2;
	}
}

void BitVector::Flip() {
    // flips every bit
    for(int i = 0; i < size; i++) {
    	int temp = ~bvect[i];
    	bvect[i] = temp;
	}
}

void BitVector::Flip(const size_t index) {
    int word_index = round(floor(index/size));
    bitlocations = 31 - (index % 32);
    int temp = bvect[word_index];
    // creating bitmask
    int bitmask = 1;

    if(index < 0 || index > size*word_index) {
	return; }    

    bitmask = bitmask << bitlocations;
    // apply bitmask
    temp = temp ^ bitmask;
    bvect[word_index] = temp;
    
}

bool BitVector::Test (size_t index) const {
    int word_index = round(floor(index/size));
    int bitloc = 31 - (index % 32);
    int bittemp = bvect[word_index];
    int bitmask = 1;
    // shifts bit in question to first position
    bittemp = bittemp >> bitloc;
    // prints bit
    bittemp = bittemp & bitmask;
    cout << bittemp << endl;
    return true;    
}

void BitVector::Print() {
    // uses cout to display 
    for(int j = 0; j < size; j++) {
        int k = bvect[j];
	for (int i = 31; i >= 0; i--) {
        k = k >> i;
        if (k & 1)
            cout << "1";
        else
            cout << "0";
    	}
        cout << endl;
    }
}

size_t BitVector::Size() const {
    return size;
}

int main() {
    // main func here
    return 0;
}
