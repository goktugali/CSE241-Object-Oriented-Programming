#ifndef POLYGON_H_
#define POLYGON_H_

#include "circle.h"
#include "triangle.h"
#include "rectangle.h"
#include "shape.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>//Included just for determining the printing color

namespace gtuShapes
{	
	class polygon : public shape{
	public:
		polygon();
		virtual ~polygon()=default;
		class Point2D{/* this class represent 2d point */
		public:
			/** Constructors **/
			Point2D(double x,double y)throw(invalidshapevalue);
			Point2D();

			/** Operator Overloads **/
			const bool operator==(const Point2D& other)const;
			const bool operator!=(const Point2D& other)const;

			/** getter methods **/
			double get_x()const { return _x;}
			double get_y()const { return _y;}
			void set_points(double x,double y);
		private:
			double _x;
			double _y;
		};

		/** Operator overloads **/
		virtual const Point2D& operator[](int index)const=0;
		virtual Point2D& operator[](int index)=0;
		virtual int getSize()const=0;

	};
	std::ostream& operator<<(std::ostream& outputStream, const polygon* p1);
}
#endif
