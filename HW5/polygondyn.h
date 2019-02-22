#ifndef POLYGONDYN_H_
#define POLYGONDYN_H_

#include "polygon.h"

namespace gtuShapes
{
class polygondyn : public polygon {
	public:
		polygondyn();
		polygondyn(shape* shptr)throw(invalidptr);
		polygondyn(std::vector<Point2D>& points)throw(invalidsize);
		polygondyn(const triangle& tri);
		polygondyn(const rectangle& rect);
		polygondyn(const circle& circ);
		~polygondyn();
		polygondyn(const polygondyn& copy);
		polygondyn& operator=(const polygondyn& other);
		virtual std::ostream& print(std::ostream& outputStream)const override;
		virtual const polygon::Point2D& operator[](int index)const throw(outofrange) override;
		virtual polygon::Point2D& operator[](int index)throw(outofrange) override;
		virtual double area()const override;
		virtual double perimeter()const override;
		virtual int getSize()const override{return _size;}
		virtual const shape& operator++()override;
	    virtual const shape& operator++(int ignore)throw(notavailable) override;
	    virtual const shape& operator--()override;
	    virtual const shape& operator--(int ignore)throw(notavailable) override;
	    friend std::ostream& operator<<(std::ostream& outputStream, const polygondyn& p1);
	private:
		polygon::Point2D* _points;
		int _size;

};
}
#endif