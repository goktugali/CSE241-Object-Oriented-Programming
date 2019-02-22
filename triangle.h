#ifndef TRIANGLE_H_
#define TRIANGLE_H_
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class triangle{

private:
	double tri_edge;
	double cr1[2];
	double cr2[2];
	double cr3[2];
public:
	triangle(double tri_edge_val,double cr1_val[],double cr2_val[],double cr3_val[]);/** Constructor for main contanier **/
	triangle(double tri_edge_val);/** Constructor for small shape **/
	triangle();

	double* get_cr1();/* These are returns the corners of triangles. Since this is not const **/
	double* get_cr2();
	double* get_cr3();
	double get_tri_edge()const;
	void set_cr1(double cr1_val[]);
	void set_cr2(double cr2_val[]);
	void set_cr3(double cr3_val[]);
	void set_tri_edge(double edge);
	/* 
	 * Draw member functions has a color paramter to define the printing color 
	 * Changes in composedShape's draw member function
	 */
	void draw(ofstream& file,string color);

};

#endif