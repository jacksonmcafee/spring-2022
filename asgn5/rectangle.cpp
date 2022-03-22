#include "rectangle.h"
#include <iostream>

using namespace std;

void Rectangle::PrintData() {
    cout << "The measurements for this rectangle are as follows..." << endl;
    cout << "Area is: " << area << endl;
    cout << "Perimeter is: " << perimeter << endl;
    cout << "Length is: " << length << endl;
    cout << "Width is: " << width << endl;
}
