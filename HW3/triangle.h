#ifndef TRIANGLE_H_
#define TRIANGLE_H_
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

class triangle{

private:
	double tri_edge;
	double cr1[2];
	double cr2[2];
	double cr3[2];
	static double current_area;
	static double current_perimeter;
public:
	triangle(double tri_edge_val,double cr1_val[],double cr2_val[],double cr3_val[]);/** Constructor for main contanier **/
	triangle(double tri_edge_val,double cr1_val[],double cr2_val[]);
	triangle(double tri_edge_val);/** Constructor for small shape **/
	triangle();

	double* get_cr1();/* These are returns the corners of triangles. Since this is not const **/
	double* get_cr2();
	double* get_cr3();
	double get_tri_edge()const{	return tri_edge;}
	double get_area()const{	return (tri_edge*tri_edge*sqrt(3))/4.0;}
	double get_perimeter()const{ return 3*tri_edge;	}
	static double get_current_area(){ return current_area;}
	static double get_current_perimeter(){	return current_perimeter;}
	void set_cr1(double cr1_val[]);
	void set_cr2(double cr2_val[]);
	void set_cr3(double cr3_val[]);
	void set_tri_edge(double edge);
	/** overloaded operators **/
	friend ostream& operator<<(ostream& outputStream,triangle& tri);
	bool operator==(triangle& tri);
	bool operator!=(triangle& tri);
	const triangle operator+(const double plus);
	const triangle operator-(const double plus);
	const triangle operator++();
	const triangle operator++(int ignoreMe);

};

#endif