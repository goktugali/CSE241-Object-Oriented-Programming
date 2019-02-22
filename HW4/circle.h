#ifndef CIRCLE_H_
#define CIRCLE_H_
#include <iostream>
#include <cstdlib>
#include <fstream>
#define PI 3

namespace gtuShapes
{
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
		void input();
		double get_radius() const{	return radius;}
		double get_cx() const{	return cx;}
		double get_cy() const{	return cy;}
		double get_area() const{ return PI*radius*radius;}
		double get_perimeter() const{	return 2*PI*radius;}
		static double get_current_area(){ return current_area;}/* not used, come from hw3 */
		static double get_current_perimeter(){ return current_perimeter;}

		void set_radius(double radius_val);
		void set_cx(double cx_val);
		void set_cy(double cy_val);
		/** overloaded operators **/
		friend std::ostream& operator<<(std::ostream& outputStream,const circle& circle);
		const bool operator==(const circle& circle)const;
		const bool operator!=(const circle& circle)const;
		const circle operator+(const double plus)const;
		const circle operator-(const double plus)const;
		const circle operator++();
		const circle operator++(int ignoreMe);
	};
}
#endif