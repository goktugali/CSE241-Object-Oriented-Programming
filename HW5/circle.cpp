#include "circle.h"
#define PI 3.14
namespace gtuShapes
{	
	double circle::_current_area=0.0;
	double circle::_current_perimeter=0.0;

	circle::circle() : shape()
	{
		_radius=0;
		_cx=0;
		_cy=0;
	}

	circle::circle(double radius)throw(invalidshapevalue) : shape()
	{
		if(radius<=0)
			throw invalidshapevalue();
		
		_radius=radius;
		_current_area+=PI*radius*radius;
		_current_perimeter+=PI*2*radius;
		_cx=radius;
		_cy=radius;
	}
	circle::circle(double radius, double cx, double cy)throw(invalidshapevalue) : shape()
	{
		if(radius<=0)
			throw invalidshapevalue();

		if(cy<0 || cx<0)
			throw invalidshapevalue();
		
		_radius=radius;
		_cx=cx;
		_cy=cy;
		_current_area+=PI*radius*radius;
		_current_perimeter+=PI*2*radius;
	}

	void circle::set_radius(double radius)throw(invalidshapevalue) {
		if(radius<=0)
			throw invalidshapevalue();
	
		_radius = radius;
	}

	void circle::set_cx(double cx)throw(invalidshapevalue) {
		if(cx<0)
			throw invalidshapevalue();
		
		_cx=cx;
	}

	void circle::set_cy(double cy)throw(invalidshapevalue) {
		if(cy<0)
			throw invalidshapevalue();
		
		_cy=cy;
	}
	
	std::ostream& circle::print(std::ostream& outputStream)const{
		return outputStream << *this;
	}
	std::ostream& operator<<(std::ostream& outputStream,const circle& circle)
	{
		outputStream << "<circle cx=\"" << circle.get_cx() << "\" cy=\"" << circle.get_cy() << "\" r=\"" << circle.get_radius()
	 				<< "\" stroke=\"black\" stroke-width=\"3\" fill=\"" 
					<< circle.getColor() << "\" />" << std::endl;
	 	return outputStream;	
	}
	const circle circle::operator+(const double plus)const
	{	
		return circle(_radius+plus,_cx,_cy);
	}
	const circle circle::operator-(const double minus)const
	{	
		return circle(_radius-minus,_cx,_cy);
	}
	const shape& circle::operator++() {
		_cx++;
		_cy++;
		return *this;
	}

	const shape& circle::operator++(int ignore)throw(notavailable) {

		throw notavailable();
	}
	const shape& circle::operator--() {
		_cx--;
		_cy--;
		return *this;
	}
	const shape& circle::operator--(int ignore)throw(notavailable) {

		throw notavailable();
	}
	double circle::area() const {
		return _radius*_radius*PI;
	}

	double circle::perimeter() const {
		return _radius*2*PI;
	}
}