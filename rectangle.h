#ifndef RECTANGLE_H_
#define RECTANGLE_H
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class rectangle{

private:
	double height;
	double width;
	double cx;
	double cy;
public:
	rectangle(double height_val,double width_val,double cx_val,double cy_val);/** Consturctor for main container **/
	rectangle(double height_val,double width_val);/** constructor for small shape **/
	rectangle();
	double get_cx() const;
	double get_cy() const;
	double get_height() const;
	double get_width() const;
	void set_cx(double cx_val);
	void set_cy(double cy_val);
	void set_height(double height_val);
	void set_width(double width_val);
	/* 
	 * Draw member functions has a color parameter to define the printing color 
	 * Changes in composedShape's draw member function
	 */
	void draw(std::ofstream& file,string color);
};

#endif