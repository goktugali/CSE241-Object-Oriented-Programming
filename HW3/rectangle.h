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
	static double current_area;
	static double current_perimeter;
public:
	rectangle(double height_val,double width_val,double cx_val,double cy_val);/** Consturctor for main container **/
	rectangle(double height_val,double width_val);/** constructor for small shape **/
	rectangle();
	double get_cx() const{	return cx;}
	double get_cy() const{	return cy;}
	double get_height() const{	return height;}
	double get_width() const{	return width;}
	double get_area() const{	return height*width;}
	double get_perimeter() const{	return 2*(height+width);}
	static double get_current_area(){	return current_area;}
	static double get_current_perimeter(){	return current_perimeter;}
	void set_cx(double cx_val);
	void set_cy(double cy_val);
	void set_height(double height_val);
	void set_width(double width_val);
	/** overloaded operators **/
	friend ostream& operator<<(ostream& outputStream,const rectangle& rect);
	bool operator==(const rectangle& rect);
	bool operator!=(const rectangle& rect);
	const rectangle operator+(const double plus);
	const rectangle operator-(const double minus);
	const rectangle operator++();
	const rectangle operator++(int ignoreMe);
};
#endif