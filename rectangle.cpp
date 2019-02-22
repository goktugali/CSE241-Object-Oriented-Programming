#include "rectangle.h"

rectangle::rectangle(double height_val,double width_val,double cx_val,double cy_val){
	height=height_val;
	width=width_val;
	cx=cx_val;
	cy=cy_val;
}
rectangle::rectangle(double height_val,double width_val){
	height = height_val;
	width = width_val;
}
rectangle::rectangle(){
	height=0;
	width=0;
	cx=0;
	cy=0;
}
double rectangle::get_cx() const{
	return cx;
}
double rectangle::get_cy() const{
	return cy;
}
double rectangle::get_height() const{
	return height;
}
double rectangle::get_width() const{
	return width;
}
void rectangle::set_cx(double cx_val){
	cx=cx_val;
}
void rectangle::set_cy(double cy_val){
	cy=cy_val;
}
void rectangle::set_height(double height_val){
	height=height_val;
}
void rectangle::set_width(double width_val){
	width = width_val;
}
void rectangle::draw(std::ofstream& file,string color){

	file << "<rect width=\""<< width << "\" height=\""<< height << "\""<<" x=\""<< cx 
		<< "\" y=\""<< cy << "\" fill=\""<< color << "\" stroke=\"black\" />" << endl;
}