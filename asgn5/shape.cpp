#include <iostream>
#include "shape.h"

using namespace std;

Shape::Shape(){
    area = 1.0;
    perimeter = 1.0; }
Shape::Shape(double a_temp, double p_temp) {
    if(a_temp >= 1.00) {
	area = a_temp; }
    else {
	area = 1.00; }
    if(p_temp >= 1.00) {
	perimeter = p_temp; }
    else {
	perimeter = 1.00; }
}

double Shape::GetArea() {
    return area; }
double Shape::GetPerimeter() {
    return perimeter; }
void Shape::SetArea(double temp) {
    if(temp >= 1.00) {
	area = temp; }
    else {
	area = 1.00; } 
}
void Shape::SetPerimeter(double temp) {
    if(temp >= 1.00) {
	perimeter = temp; }
    else {
	perimeter = 1.00; }
}

void Shape::PrintData() {
    cout << "Measurements for this shape are as follows... " << endl;
    cout << "Area is: " << area << endl;
    cout << "Perimeter is: " << perimeter << endl;
}
