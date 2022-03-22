#ifndef SQUARE_H
#define SQUARE_H

#include "shape.h"

class Square: public Shape {
    private:
	double length;

    public:
	Square() {
	    length = 1.0;
            area = 1.0;
	    perimeter = 4.0; }
	Square(double l_temp) {
	if(l_temp >= 1.00) {
	    length = l_temp; }
	else {
	    length = 1.00; }
	    area = length * length;
	    perimeter = 4 * length; }

	double GetLength() {
	    return length; }
	void SetLength(double temp) {
	if(temp >= 1.00) {    
	    length = temp; }
	else {
	    length = 1.00; }	
	    area = length * length;
	    perimeter = 4 * length; }
	
	void PrintData();
};

#endif
