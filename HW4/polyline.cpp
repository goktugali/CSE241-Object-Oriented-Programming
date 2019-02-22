#include "polyline.h"
namespace gtuPolyline
{	
	using namespace gtuPolygon;

	polyline::polyline(const polygon& poly):_plyline(poly)
	{
		/** Intentionally empty **/
	}
	polyline::polyline(const gtuShapes::rectangle& rect):_plyline(rect)
	{
		/** Intentionally empty **/
	}
	polyline::polyline(const gtuShapes::triangle& tri):_plyline(tri)
	{
		/** Intentionally empty **/
	}
	polyline::polyline(const gtuShapes::circle& circ):_plyline(circ)
	{
		/** Intentionally empty **/
	}
	polyline::polyline(const polygon::Point2D& point):_plyline(point)
	{
		/** Intentionally empty **/	
	}
	polyline::polyline(int size):_plyline(size)
	{
		/** Intentionally empty **/	
	}
	const bool polyline::operator==(const polyline& other)const
	{
		return (_plyline==other.get_plyline());
	}
	const bool polyline::operator!=(const polyline& other)const
	{
		return !(_plyline==other.get_plyline());
	}
	const polyline polyline::operator+(const polyline& other)const
	{	
		return polyline(_plyline + other.get_plyline());
	}
	const polygon::Point2D& polyline::operator[](int index)const
	{
		return _plyline[index];
	}
	polygon::Point2D& polyline::operator[](int index)
	{
		return _plyline[index];
	}
	std::ostream& operator<<(std::ostream& outputStream, const polyline& p1)
	{
		outputStream << "<polyline points=\"";
		for (int i = 0; i < p1.get_plyline().getSize(); ++i)
			outputStream << p1.get_plyline()[i].get_x() << "," << p1.get_plyline()[i].get_y() << " " ;
		outputStream << "\" stroke=\"black\" stroke-width=\"2\" fill=\"" 
					<< p1.get_plyline().getColor() << "\" />" << std::endl;
					
		return outputStream;
	}
}