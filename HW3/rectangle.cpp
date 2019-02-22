#include "rectangle.h"

double rectangle::current_area=0.0;
double rectangle::current_perimeter=0.0;

rectangle::rectangle(double height_val,double width_val,double cx_val,double cy_val){
	height=height_val;
	width=width_val;
	cx=cx_val;
	cy=cy_val;
	current_area+=height_val*width_val;
	current_perimeter+=2*(height+width);
}
rectangle::rectangle(double height_val,double width_val){
	height = height_val;
	width = width_val;
	cx=0.0;
	cy=0.0;
	current_area+=height_val*width_val;
	current_perimeter+=2*(height+width);
}
rectangle::rectangle(){
	height=0;
	width=0;
	cx=0;
	cy=0;
}
ostream& operator<<(ostream& outputStream,const rectangle& rect)
{
	outputStream << "<rect width=\""<< rect.get_width() << "\" height=\""<< rect.get_height() << "\""<<" x=\""
		<< rect.get_cx() << "\" y=\""<< rect.get_cy() << "\" stroke=\"black\" stroke-width=\"3\" fill=\"" 
		<< "green" << "\" />" << endl;
	return outputStream;
}
bool rectangle::operator==(const rectangle& rect)
{	
	return (get_area()==rect.get_area());
}
bool rectangle::operator!=(const rectangle& rect)
{
	return !(get_area()==rect.get_area());
}
const rectangle rectangle::operator+(const double plus)
{	
	height+=plus;
	width+=plus;
	return rectangle(height,width,cx,cy);
}
const rectangle rectangle::operator-(const double minus)
{	
	height-=minus;
	width-=minus;
	return rectangle(height,width,cx,cy);
}
const rectangle rectangle::operator++()
{
	cx++;
	cy++;
	return rectangle(height,width,cx,cy);
}
const rectangle rectangle::operator++(int ignoreMe)
{
	double tmpcx = cx;
	double tmpcy = cy;
	cx++,
	cy++;
	return rectangle(height,width,tmpcx,tmpcy);
}
void rectangle::set_cx(double cx_val)
{
	cx=cx_val;
}
void rectangle::set_cy(double cy_val)
{
	cy=cy_val;
}
void rectangle::set_height(double height_val)
{
	height=height_val;
}
void rectangle::set_width(double width_val)
{
	width = width_val;
}