#include "polygondyn.h"
#include <cmath>

namespace gtuShapes
{	
	polygondyn::polygondyn(shape* shptr)throw(invalidptr) : polygon() 
	{	
		/* This constructor takes shape pointer, determine its type and converts 
			I know I am duplicating the code but, I cant use delegating constructor
			(to prevent duplicate) inside body of the constructor */

		rectangle * isRectangle = dynamic_cast<rectangle*>(shptr);
		triangle * isTriangle = dynamic_cast<triangle*>(shptr);
		circle * isCircle = dynamic_cast<circle*>(shptr);

		if(isRectangle!=nullptr)
		{
			_points = new Point2D[4];
			_size=4;
			_points[0].set_points(isRectangle->get_cx(),isRectangle->get_cy());
			_points[1].set_points(isRectangle->get_cx()+isRectangle->get_width(),isRectangle->get_cy());
			_points[2].set_points(isRectangle->get_cx()+isRectangle->get_width(),isRectangle->get_cy()+isRectangle->get_height());
			_points[3].set_points(isRectangle->get_cx(),isRectangle->get_cy()+isRectangle->get_height());
		}
		else if(isTriangle!=nullptr)
		{
			_points = new Point2D[3];
			_size=3;
			_points[0].set_points(isTriangle->get_cr1()[0],isTriangle->get_cr1()[1]);
			_points[1].set_points(isTriangle->get_cr2()[0],isTriangle->get_cr2()[1]);
			_points[2].set_points(isTriangle->get_cr3()[0],isTriangle->get_cr3()[1]);
		}
		else if(isCircle!=nullptr)
		{
			_points = new Point2D[100];//100 equal intervals
			_size=100;
			double angle = 0;
			for (int i = 0; i < _size; ++i)
			{
				_points[i].set_points(isCircle->get_radius()*cos(angle)+isCircle->get_cx(),isCircle->get_radius()*sin(angle)+isCircle->get_cy());
				angle+=3.6*(3.14159/180);//For 100 equal intervals angle changes
			}
		}
		else 
			throw invalidptr();
	}
	polygondyn::polygondyn(std::vector<Point2D>& points)throw(invalidsize) : polygon() 
	{
		if (points.size()==0)
			throw invalidsize();
		
		_points = new Point2D[points.size()];
		_size = points.size();
		for (int i = 0; i < _size; ++i)
			_points[i] = points[i];
	}
	polygondyn::polygondyn(const rectangle& rect) : polygon()
	{
		_points = new Point2D[4];
		_size=4;
		_points[0].set_points(rect.get_cx(),rect.get_cy());
		_points[1].set_points(rect.get_cx()+rect.get_width(),rect.get_cy());
		_points[2].set_points(rect.get_cx()+rect.get_width(),rect.get_cy()+rect.get_height());
		_points[3].set_points(rect.get_cx(),rect.get_cy()+rect.get_height());
	}
	polygondyn::polygondyn(const triangle& tri) : polygon()
	{
		_points = new Point2D[3];
		_size=3;
		_points[0].set_points(tri.get_cr1()[0],tri.get_cr1()[1]);
		_points[1].set_points(tri.get_cr2()[0],tri.get_cr2()[1]);
		_points[2].set_points(tri.get_cr3()[0],tri.get_cr3()[1]);
	}
	polygondyn::polygondyn(const circle& circ) : polygon()
	{	
		_points = new Point2D[100];//100 equal intervals
		_size=100;

		double angle = 0;
		for (int i = 0; i < _size; ++i)
		{	
			_points[i].set_points(circ.get_radius()*cos(angle)+circ.get_cx(),circ.get_radius()*sin(angle)+circ.get_cy());
			angle+=3.6*(3.14159/180);//For 100 equal intervals angle changes
		}
	}
	polygondyn& polygondyn::operator=(const polygondyn& other)
	{
		if (this==&other)
			return *this;
		else
		{
			_size = other.getSize();
			this->setColor(other.getColor());
			delete [] _points;
			_points = new Point2D[_size];
			for (int i = 0; i < _size; ++i)		
				(*this)[i] = other[i];
			return *this;		
		}
	}
	polygondyn::polygondyn(const polygondyn& copy)
	{
		_points = new Point2D[copy.getSize()];
		_size = copy.getSize();
		this->setColor(copy.getColor());
		for (int i = 0; i < _size; ++i)
			(*this)[i] = copy[i];
	}
	polygondyn::~polygondyn()
	{	
		delete [] _points;
	}
	std::ostream& operator<<(std::ostream& outputStream, const polygondyn& p1)
	{
		outputStream << "<polygon points=\"";
		for (int i = 0; i < p1._size; ++i)
			outputStream << p1._points[i].get_x() << "," << p1._points[i].get_y() << " " ;

		outputStream << "\" stroke=\"black\" stroke-width=\"2\" fill=\"" 
					<< p1.getColor() << "\" />" << std::endl;

		return outputStream;
	}
	std::ostream& polygondyn::print(std::ostream& outputStream)const
	{
		return outputStream << *this;
	} 
	const polygon::Point2D& polygondyn::operator[](int index)const throw(outofrange)
	{
		if (index<0)
		{
			throw outofrange();
		}
		return _points[index];
	}
	polygon::Point2D& polygondyn::operator[](int index) throw(outofrange)
	{
		if (index<0)
		{
			throw outofrange();
		}
		return _points[index];
	}
	double polygondyn::area()const 
	{
		double temp = 0;
		for (int i = 0,j=0; i < _size ; ++i,++j)
		{
			if(i==_size-1)
				j=-1;
			temp+=((_points[i].get_x()*_points[j+1].get_y()) - (_points[i].get_y()*_points[j+1].get_x()));
		}	
		if(temp<0)
			temp=temp*-1;
		return temp / 2;
	}
	double polygondyn::perimeter()const 
	{
		double temp = 0;
		for (int i = 0,j=0; i < _size;++i,++j)
		{
			if(i==_size-1)
				j=-1;
			temp+= sqrt((pow(_points[i].get_x() - _points[j+1].get_x(),2)) + (pow(_points[i].get_y() - _points[j+1].get_y(),2)));
		}	
	 	return temp;
	}
	const shape& polygondyn::operator++()
	{	
		double tmpx;
		double tmpy;
		for (int i = 0; i < _size; ++i)
		{
			tmpx = _points[i].get_x() + 1;
			tmpy = _points[i].get_y() + 1 ;
			_points[i].set_points(tmpx,tmpy);
		}
		return *this;	
	}
	
	const shape& polygondyn::operator++(int ignore) throw(notavailable)
	{
		throw notavailable();
	}
	const shape& polygondyn::operator--()
	{	
		double tmpx;
		double tmpy;
		for (int i = 0; i < _size; ++i)
		{
			tmpx = _points[i].get_x() - 1;
			tmpy = _points[i].get_y() - 1 ;
			_points[i].set_points(tmpx,tmpy);
		}
		return *this;	
	}
	const shape& polygondyn::operator--(int ignore) throw(notavailable)
	{
		throw notavailable();
	}

}