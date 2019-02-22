#ifndef POLYGONVECT_H_
#define POLYGONVECT_H_
#include "polygon.h"

namespace gtuShapes
{
class polygonvect : public polygon{

	public:
		polygonvect(std::vector<Point2D> points)throw(invalidsize);
		polygonvect(shape * shptr)throw(invalidptr);
		polygonvect(const triangle& tri);
		polygonvect(const rectangle& rect);
		polygonvect(const circle& circ);
		virtual std::ostream& print(std::ostream& outputStream)const override;
		virtual const Point2D& operator[](int index)const throw(outofrange) override ;
		virtual Point2D& operator[](int index)throw(outofrange) override;
		virtual double area()const override;
		virtual double perimeter()const override;
		virtual const shape& operator++()override;
       	virtual const shape& operator++(int ignore)throw(notavailable) override;
       	virtual const shape& operator--()override;
       	virtual const shape& operator--(int ignore)throw(notavailable) override;
        virtual int getSize()const override{return _points.size();}
        friend std::ostream& operator<<(std::ostream& outputStream, const polygonvect& p1);
	private:
		std::vector<polygon::Point2D> _points;

};
}
#endif