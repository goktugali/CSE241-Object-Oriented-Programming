#ifndef CIRCLE_H_
#define CIRCLE_H_
#include <iostream>
#include <fstream>
#include <string>
#define PI 3

using namespace std;

class circle{

private:
	double radius;
	double cx;
	double cy;
	static double current_area;
	static double current_perimeter;
public:
	circle(double radius_val,double cx_val,double cy_val);/** Constructor for main container **/
	circle(double radius_val);/** Constructor for small shape **/
	circle();
	double get_radius() const{	return radius;}
	double get_cx() const{	return cx;}
	double get_cy() const{	return cy;}
	double get_area() const{ return PI*radius*radius;}
	double get_perimeter() const{	return 2*PI*radius;}
	static double get_current_area(){ return current_area;}
	static double get_current_perimeter(){ return current_perimeter;}

	void set_radius(double radius_val);
	void set_cx(double cx_val);
	void set_cy(double cy_val);
	/** overloaded operators **/
	friend ostream& operator<<(ostream& outputStream,const circle& circle);
	bool operator==(circle& circle);
	bool operator!=(circle& circle);
	const circle operator+(const double plus);
	const circle operator-(const double plus);
	const circle operator++();
	const circle operator++(int ignoreMe);
};

#endif