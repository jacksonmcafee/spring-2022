#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle: public Shape {
    private:
	double length;
	double width;

    public: 
	Rectangle() {
	    length = 1.0;
	    width = 1.0;
	    perimeter = 4.0;
	}
	Rectangle(double l_temp, double w_temp) {
	    if(l_temp >= 1.00) {
        	length = l_temp; }
	    else {
		length = 1.00; }
	    if(w_temp >= 1.00) {
		width = w_temp; }
	    else {
		width = 1.00; } 
	    area = length * width;
	    perimeter = (length * 2) + (width * 2);
	}

	double GetLength() {
	    return length; }
	double GetWidth() {
	    return width; }
	void SetLength(double temp) {
	    if(temp >= 1.00) {
                length = temp; }
            else {
                length = 1.00; } 
            area = length * width;
            perimeter = (length * 2) + (width * 2); }
	void SetWidth(double temp) {
	    if(temp >= 1.00) {
                width = temp; }
            else {
                width = 1.00; }
            area = length * width;
            perimeter = (length * 2) + (width * 2); }

	void PrintData();
};

#endif
