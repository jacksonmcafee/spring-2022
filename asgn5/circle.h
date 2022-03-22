#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

const double pi = 3.1415926;

class Circle: public Shape {
    private:
	double radius;
    public:
	Circle() {
	    radius = 1.0;
            area = pi;
	    perimeter = 2 * pi; }
	Circle(double r_temp) {
	    if(r_temp >= 1.00) {
		radius = r_temp; }
	    else {
		radius = 1.00; }
            area = (pi * radius * radius);
	    perimeter = (pi * radius * 2); }

	double GetRadius() {
	    return radius; }
	void SetRadius(double temp) {
	    if(temp >= 1.00) {
		radius = temp; }
	    else {
		radius = 1.00; }
            area = (pi * radius * radius);
	    perimeter = (pi * radius * 2); }

	void PrintData();
};

#endif
