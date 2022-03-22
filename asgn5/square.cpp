#include "square.h"
#include <iostream> 

using namespace std;

void Square::PrintData() {
    cout << "The measurements for this square are as follows... " << endl;
    cout << "Area is: " << area << endl;
    cout << "Perimeter is: " << perimeter << endl;
    cout << "Length is: " << length << endl; 
}
