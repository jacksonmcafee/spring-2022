#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"
#include <cmath>

using namespace std;


class Triangle: public Shape {
    private: 
	double side1;
	double side2;
	double side3;

    public:
	Triangle() {
	    side1 = 1.0;
	    side2 = 1.0; 
	    side3 = 1.0;
            int s = (side1 + side2 + side3)/2;
            area = sqrt(abs(s * (s - side1) * (s - side2) * (s - side3)));
	    perimeter = side1 + side2 + side3; }
	Triangle(double h_temp, double b_temp, double l_temp) {
	    if(h_temp >= 1.00) {
            	side1 = h_temp; }
	    else {
		side1 = 1.00; }
    	    if(b_temp >= 1.00) {
                side2 = b_temp; }
	    else {
		side2 = 1.00; }
	    if(l_temp >= 1.00) {
	        side3 = l_temp; }
	    else {
		side3 = 1.00; }
	    int s = (side1 + side2 + side3)/2;
            area = sqrt(abs(s * (s - side1) * (s - side2) * (s - side3)));
            perimeter = side1 + side2 + side3;
	}

	double GetSide1() {
	    return side1; }
	double GetSide2() {
	    return side2; }
	double GetSide3() {
	    return side3; }
	void SetSide1(double temp) {
	    if(temp >= 1.00) {
		side1 = temp; }
	    else {
		side1 = 1.00; }
            int s = (side1 + side2 + side3)/2;      
            area = sqrt(abs(s * (s - side1) * (s - side2) * (s - side3)));
            perimeter = side1 + side2 + side3;
	}
	void SetSide2(double temp) {
	    if(temp >= 1.00) {
		side2 = temp; }
	    else {
		side2 = 1.00; }
            int s = (side1 + side2 + side3)/2;
            area = sqrt(abs(s * (s - side1) * (s - side2) * (s - side3)));
            perimeter = side1 + side2 + side3;
	}
	void SetSide3(double temp) {
	    if(temp >= 1.00) {
		side3 = temp; }
	    else {
		side3 = 1.00; }
            int s = (side1 + side2 + side3)/2;
            area = sqrt(abs(s * (s - side1) * (s - side2) * (s - side3)));
            perimeter = side1 + side2 + side3;
	}

	void PrintData();
};

#endif
