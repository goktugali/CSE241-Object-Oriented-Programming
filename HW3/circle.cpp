#include "circle.h"

double circle::current_area=0.0;
double circle::current_perimeter=0.0;
circle::circle(double radius_val,double cx_val,double cy_val)
{
	radius=radius_val;
	cx=cx_val;
	cy=cy_val;
	current_area+=PI*radius_val*radius_val;
	current_perimeter+=PI*2*radius_val;
}
circle::circle(double radius_val)
{
	radius=radius_val;
	current_area+=PI*radius_val*radius_val;
	current_perimeter+=PI*2*radius_val;
	cx=0.0;
	cy=0.0;
}
circle::circle(){
	radius=0;
	cx=0;
	cy=0;
}
bool circle::operator==(circle& circle)
{
	return (get_area() == circle.get_area());
}
bool circle::operator!=(circle& circle)
{
	return !(get_area() == circle.get_area());
}
const circle circle::operator+(const double plus)
{	
	radius+=plus;
	return circle(radius,cx,cy);
}
const circle circle::operator-(const double plus)
{	
	radius-=plus;
	return circle(radius,cx,cy);
}
const circle circle::operator++()
{
	cx++;
	cy++;
	return circle(radius,cx,cy);
}
const circle circle::operator++(int ignoreMe)
{	
	double tmpcx,tmpcy;
	tmpcx=cx;
	tmpcy=cy;
	cx++;
	cy++;
	return circle(radius,tmpcx,tmpcy);
}
ostream& operator<<(ostream& outputStream,const circle& circle)
{
	outputStream << "<circle cx=\"" << circle.get_cx() << "\" cy=\"" << circle.get_cy() << "\" r=\"" << circle.get_radius()
 				<< "\" stroke=\"black\" stroke-width=\"3\" fill=\"" 
				<< "green" << "\" />" << endl;
 	return outputStream;	
}
void circle::set_radius(double radius_val)
{
	radius = radius_val;
}
void circle::set_cx(double cx_val)
{
	cx=cx_val;
}
void circle::set_cy(double cy_val){
	cy=cy_val;
}