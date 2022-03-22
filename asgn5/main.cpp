/*

Jackson McAfee - COP3353
Asgn5 Shape Class & Inheritance

NOTES:
For future reference, including a specification that
triangles that users are attempting to create must EXIST
would be a good idea as Heron's Formula breaks down and spits out
numbers that aren't accurate when triangles that don't follow
a + b > c, etc. 

*/

#include "shape.h"
#include "rectangle.h"
#include "circle.h"
#include "square.h"
#include "triangle.h"

#include <iostream>

using namespace std;

int main() {

Shape normalShape;
Shape testShape(4.0, 6.0);

cout << "ShapeTest Start" << endl << " ============="  << endl;

// Test Get and Set, then PrintData For Shape testShape
cout << "Area: " << testShape.GetArea() << endl; 
cout << "Perimeter: " << testShape.GetPerimeter() << endl;
testShape.SetArea(4);
testShape.SetPerimeter(7.0);
testShape.PrintData();

cout << "ShapeTest End" << endl << " ============= " << endl << endl;

Rectangle normalRect;
Rectangle testRect(18.0, 24.0);

cout << "RectTest Start " << endl << " =============" << endl;

// Test Get and Set, the PrintData for Rect testRect
cout << "Length: " << testRect.GetLength() << endl;
cout << "Width: " << testRect.GetWidth() << endl;
testRect.SetLength(5.0);
testRect.SetWidth(9.0);
testRect.PrintData();

cout << "RectTest End" << endl << " ============= " << endl << endl;

Circle normalCircle;
Circle testCircle(2.0);

cout << "CircleTest Start " << endl << " ============= " << endl;

// Test Get and Set, the PrintData for Circle testCircle
cout << "Radius: " << testCircle.GetRadius() << endl;
testCircle.SetRadius(5.0);
testCircle.PrintData();

cout << "CircleTest End" << endl << " ============= " << endl << endl;

Square normalSquare;
Square testSquare(17.5);

cout << "SquareTest Start " << endl << " ============ " << endl;

cout << "Length: " << testSquare.GetLength() << endl;
testSquare.SetLength(6.0);
testSquare.PrintData();

cout << "SquareTest End" << endl << " ============= " << endl << endl;

Triangle normalTriangle;
Triangle testTriangle(4.8, 3.3, 5.9);

cout << "TriangleTest Start " << endl << " ============= " << endl;

cout << "Side1: " << testTriangle.GetSide1() << endl;
cout << "Side2: " << testTriangle.GetSide2() << endl;
cout << "Side3: " << testTriangle.GetSide3() << endl; 
testTriangle.SetSide1(5.0);
testTriangle.SetSide2(4.0);
testTriangle.SetSide3(5.0); 
testTriangle.PrintData();

cout << "TriangleTest End " << endl << " ============= " << endl << endl;
}
