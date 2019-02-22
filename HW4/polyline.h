#ifndef POLYLINE_H_
#define POLYLINE_H_
#include "polygon.h"
#include <iostream>

using namespace gtuPolygon;/** this class use polygon class for all work **/

namespace gtuPolyline
{
	class polyline
	{
	public:	
		/** Conversion Constructors **/
		polyline(const gtuShapes::rectangle& rect);
		polyline(const gtuShapes::triangle& tri);
		polyline(const gtuShapes::circle& circ);
		polyline(const polygon::Point2D& point);
		/** Conversion from polygon **/
		polyline(const polygon& poly);
		polyline(int size);
		
		polygon get_plyline()const{return _plyline;}//Returns the polygon object inside
		int getSize()const{return _plyline.getSize();}

		/** operator overloads **/
		const bool operator==(const polyline& other)const;
		const bool operator!=(const polyline& other)const;
		const polyline operator+(const polyline& other)const;
		const polygon::Point2D& operator[](int index)const;
		polygon::Point2D& operator[](int index);
		friend std::ostream& operator<<(std::ostream& outputStream, const polyline& p1);
		
	private:
		polygon _plyline;
		
	};
}
#endif