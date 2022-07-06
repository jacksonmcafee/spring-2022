#include "bitvector.h"

int main() {

    BitVector myBitVector;
    myBitVector.Set(53);
    myBitVector.Flip(94);
    myBitVector.Set(122);
    myBitVector.Unset(122);

    myBitVector.Print();

    BitVector newBitVector(myBitVector);

    newBitVector.Print();

    BitVector altBitVector;

    altBitVector = myBitVector;

    altBitVector.Print();

    return 0;
}
