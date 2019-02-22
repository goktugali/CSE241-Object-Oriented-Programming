#ifndef TRIANGLE_H_
#define TRIANGLE_H_
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

namespace gtuShapes
{
	class triangle{

	private:
		double tri_edge;
		double cr1[2];
		double cr2[2];
		double cr3[2];
		static double current_area;
		static double current_perimeter;
	public:
		triangle(double tri_edge_val,const double cr1_val[],const double cr2_val[],const double cr3_val[]);/** Constructor for main contanier **/
		triangle(double tri_edge_val,const double cr1_val[],const double cr2_val[]);
		triangle(double tri_edge_val);
		triangle();

		const double* get_cr1()const;
		const double* get_cr2()const;
		const double* get_cr3()const;
		double get_tri_edge()const{	return tri_edge;}
		double get_area()const{	return (tri_edge*tri_edge*sqrt(3))/4.0;}
		double get_perimeter()const{ return 3*tri_edge;	}
		static double get_current_area(){ return current_area;}
		static double get_current_perimeter(){	return current_perimeter;}

		void input();
		void set_cr1(double cr1_val[]);
		void set_cr2(double cr2_val[]);
		void set_cr3(double cr3_val[]);
		void set_tri_edge(double edge);

		/** overloaded operators **/
		friend std::ostream& operator<<(std::ostream& outputStream,const triangle& tri);
		const bool operator==(const triangle& tri)const;
		const bool operator!=(const triangle& tri)const;
		const triangle operator+(double plus)const;
		const triangle operator-(double plus)const;
		const triangle operator++();
		const triangle operator++(int ignoreMe);
	};
}
#endif