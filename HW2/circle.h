#ifndef CIRCLE_H_
#define CIRCLE_H_
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class circle{

private:
	double radius;
	double cx;
	double cy;
public:
	circle(double radius_val,double cx_val,double cy_val);/** Constructor for main container **/
	circle(double radius_val);/** Constructor for small shape **/
	circle();
	double get_radius() const;
	double get_cx() const;
	double get_cy() const;
	void set_radius(double radius_val);
	void set_cx(double cx_val);
	void set_cy(double cy_val);
	/* 
	 * Draw member functions has a color parameter to define the printing color 
	 * Changes in composedShape's draw member function
	 */
	void draw(ofstream& file,string color);

};

#endif