#include "circle.h"

circle::circle(double radius_val,double cx_val,double cy_val){
	radius=radius_val;
	cx=cx_val;
	cy=cy_val;
}
circle::circle(double radius_val){
	radius=radius_val;
}
circle::circle(){
	radius=0;
	cx=0;
	cy=0;
}

double circle::get_radius() const{
	return radius;
}
double circle::get_cx() const{
	return cx;
}
double circle::get_cy() const{
	return cy;
}
void circle::set_radius(double radius_val){
	radius = radius_val;
}
void circle::set_cx(double cx_val){
	cx=cx_val;
}
void circle::set_cy(double cy_val){
	cy=cy_val;
}
void circle::draw(ofstream& file,string color){
	
	file << "<circle cx=\"" << cx << "\" cy=\"" << cy << "\" r=\"" << radius
 		 << "\" fill=\""<< color << "\" stroke=\"black\" />" << endl;	
}
