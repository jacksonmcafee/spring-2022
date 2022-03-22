#ifndef SHAPE_H
#define SHAPE_H

class Shape {
    protected:
	double area;
	double perimeter;

    public:
	Shape();
	Shape(double a_temp, double p_temp);
	
	double GetArea();
	double GetPerimeter();
	void SetArea(double temp);	
	void SetPerimeter(double temp);

	virtual void PrintData();
};

#endif
