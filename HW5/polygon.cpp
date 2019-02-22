#include "polygon.h"

namespace gtuShapes
{	
	polygon::polygon() : shape() {/* */}
	polygon::Point2D::Point2D(double x,double y) throw(invalidshapevalue)
	{	
		if (x<0 || y<0)
		{	
			throw invalidshapevalue();
		}
		_x = x;
		_y = y;
	}
	polygon::Point2D::Point2D()
	{
		_x=0;
		_y=0;
	}
	const bool polygon::Point2D::operator==(const Point2D& other)const
	{
		return (get_x()==other.get_x() && get_y()==other.get_y());
	}
	const bool polygon::Point2D::operator!=(const Point2D& other)const
	{
		return !(get_x()==other.get_x() && get_y()==other.get_y());
	}
	void polygon::Point2D::set_points(double x,double y)
	{	
		if (x<0 || y<0)
			throw invalidshapevalue();
		
		_x = x;
		_y = y;
	}

	std::ostream& operator<<(std::ostream& outputStream, const polygon* p1)
	{
		p1->print(outputStream);
		return outputStream;
	}
}