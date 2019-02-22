#include "rectangle.h"

namespace gtuShapes
{
	double rectangle::_current_area=0.0;
	double rectangle::_current_perimeter=0.0;
	rectangle::rectangle() : shape(),_height(0),_width(0),_cx(0),_cy(0) 
	{
		/** Intentionally empty **/
	}

	rectangle::rectangle(double height, double width, double cx, double cy)throw (invalidshapevalue) : shape()
	{	
		if(height<=0 || width<=0)	
			throw invalidshapevalue();
		
		if(cx<0 || cy<0)		
			throw invalidshapevalue();
		
		_height=height;
		_width=width;
		_cx=cx;
		_cy=cy;
		_current_area+=height*width;
		_current_perimeter+=2*(height+width);
	}

	rectangle::rectangle(double height, double width)throw (invalidshapevalue) : shape()
	{
		if(height<=0 || width<=0)		
			throw invalidshapevalue();
		
		_height = height;
		_width = width;
		_cx=0.0;
		_cy=0.0;
		_current_area+=height*width;
		_current_perimeter+=2*(height+width);
	}

	void rectangle::set_cx(double cx)throw (invalidshapevalue) {
		if(cx<0)		
			throw invalidshapevalue();
		
		_cx=cx;
	}

	void rectangle::set_cy(double cy)throw (invalidshapevalue) {
		if(cy<0)	
			throw invalidshapevalue();
		
		_cy=cy;
	}

	void rectangle::set_height(double height)throw (invalidshapevalue) {
		if(height<=0)	
			throw invalidshapevalue();
		
		_height=height;
	}

	void rectangle::set_width(double width)throw (invalidshapevalue) {
		if(width<=0)		
			throw invalidshapevalue();

		_width=width;
	}
	const rectangle rectangle::operator+(double plus)const
	{	
		return rectangle(_height+plus,_width+plus,_cx,_cy);
	}
	const rectangle rectangle::operator-(double minus)const
	{	
		return rectangle(_height-minus,_width-minus,_cx,_cy);
	}
	const shape& rectangle::operator++() {
		_cx++;
		_cy++;
		return *this;
	}
	const shape& rectangle::operator++(int ignore)throw (notavailable) {
		throw notavailable();
	}
	const shape& rectangle::operator--() {
		_cx++;
		_cy++;
		return *this;
	}
	const shape& rectangle::operator--(int ignore)throw (notavailable) {
		throw notavailable();
	}
	double rectangle::area() const {
		return _height*_width;
	}

	double rectangle::perimeter() const {
		return 2*(_height+_width);
	}
	std::ostream& operator<<(std::ostream& outputStream,const rectangle& rect)
	{
		outputStream << "<rect width=\""<< rect.get_width() << "\" height=\""<< rect.get_height() << "\""<<" x=\""
			<< rect.get_cx() << "\" y=\""<< rect.get_cy() << "\" stroke=\"black\" stroke-width=\"3\" fill=\"" 
			<< rect.getColor() << "\" />" << std::endl;
		return outputStream;
	}
	std::ostream& rectangle::print(std::ostream& outputStream)const {
		return outputStream << *this;
	}

}
