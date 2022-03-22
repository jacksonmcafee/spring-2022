#include "triangle.h"
#include <iostream>

using namespace std;

void Triangle::PrintData() {
    cout << "The measurements for this triangle are as follows... " << endl;
    cout << "Area is: " << area << endl;
    cout << "Perimeter is: " << perimeter << endl;
    cout << "Side 1 is: " << side1 << endl;
    cout << "Side 2 is: " << side2 << endl;
    cout << "Side 3 is: " << side3 << endl;
}
