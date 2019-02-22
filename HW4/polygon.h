#ifndef POLYGON_H_
#define POLYGON_H_

#include "circle.h"
#include "triangle.h"
#include "rectangle.h"

#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>//Included just for determining the printing color

namespace gtuPolygon
{	
	class polygon{
	public:
		class Point2D{/* this class represent 2d point */
		public:
			/** Constructors **/
			Point2D(double x,double y);
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
		/** Constructors **/
		polygon(const Point2D& point);
		polygon(const std::vector<Point2D> points);
		polygon(int size);

		/** Conversion Constructors **/
		polygon(const gtuShapes::rectangle& rect);
		polygon(const gtuShapes::triangle& tri);
		polygon(const gtuShapes::circle& circ);

		/** Big three **/
		polygon(const polygon& copy);
		~polygon();
		polygon& operator=(const polygon& other);

		/** Operator overloads **/
		const bool operator==(const polygon& other)const;
		const polygon operator+(const polygon& other)const;
		const bool operator!=(const polygon& other)const;
		const Point2D& operator[](int index)const;
		Point2D& operator[](int index);
		friend std::ostream& operator<<(std::ostream& outputStream, const polygon& p1);

		/* getter methods */
		int getSize()const{return _size;}
		std::string getColor()const{return _color;}
		void setColor(std::string color);//Color setter
	private:
		Point2D* _coefficients;/** Coordinates **/
		std::string _color;/** printing color **/
		int _size;/** Num of coordinates **/
	};
}
#endif
