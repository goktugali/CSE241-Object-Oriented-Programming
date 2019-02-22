#include "polygonvect.h"
#include <cmath>

namespace gtuShapes
{	
	polygonvect::polygonvect(std::vector<Point2D> points)throw(invalidsize) : polygon() 
	{	
		if(points.size()==0)
			throw invalidsize();
		for (unsigned int i = 0; i < points.size(); ++i)
			_points.push_back(points[i]);
		this->setColor("green");	
	}
	polygonvect::polygonvect(shape * shptr)throw(invalidptr) : polygon() 
	{
		/* This constructor takes shape pointer, determine its type and converts 
		I know I am duplicating the code but, I cant use delegating constructor
		(to prevent duplicate) inside body of the constructor */

		rectangle * isRectangle = dynamic_cast<rectangle*>(shptr);
		triangle * isTriangle = dynamic_cast<triangle*>(shptr);
		circle * isCircle = dynamic_cast<circle*>(shptr);

		if(isRectangle!=nullptr)
		{
			polygon::Point2D temp;
			temp.set_points(isRectangle->get_cx(),isRectangle->get_cy());
			_points.push_back(temp);
			temp.set_points(isRectangle->get_cx()+isRectangle->get_width(),isRectangle->get_cy());
			_points.push_back(temp);
			temp.set_points(isRectangle->get_cx()+isRectangle->get_width(),isRectangle->get_cy()+isRectangle->get_height());
			_points.push_back(temp);
			temp.set_points(isRectangle->get_cx(),isRectangle->get_cy()+isRectangle->get_height());
			_points.push_back(temp);
		}
		else if(isTriangle!=nullptr)
		{
			polygon::Point2D temp;
			temp.set_points(isTriangle->get_cr1()[0],isTriangle->get_cr1()[1]);
			_points.push_back(temp);
			temp.set_points(isTriangle->get_cr2()[0],isTriangle->get_cr2()[1]);
			_points.push_back(temp);
			temp.set_points(isTriangle->get_cr3()[0],isTriangle->get_cr3()[1]);
			_points.push_back(temp);
		}
		else if(isCircle!=nullptr)
		{
			polygon::Point2D temp;
			double angle = 0;
			for (int i = 0; i < 100; ++i)
			{
				temp.set_points(isCircle->get_radius()*cos(angle)+isCircle->get_cx(),isCircle->get_radius()*sin(angle)+isCircle->get_cy());
				angle+=3.6*(3.14159/180);//For 100 equal intervals angle changes
				_points.push_back(temp);
			}
		}
		else
			throw invalidptr();
	}
	polygonvect::polygonvect(const triangle& tri) : polygon()
	{	
		polygon::Point2D temp;
		temp.set_points(tri.get_cr1()[0],tri.get_cr1()[1]);
		_points.push_back(temp);
		temp.set_points(tri.get_cr2()[0],tri.get_cr2()[1]);
		_points.push_back(temp);
		temp.set_points(tri.get_cr3()[0],tri.get_cr3()[1]);
		_points.push_back(temp);
	}
	polygonvect::polygonvect(const rectangle& rect) : polygon()
	{	
		polygon::Point2D temp;
		temp.set_points(rect.get_cx(),rect.get_cy());
		_points.push_back(temp);
		temp.set_points(rect.get_cx()+rect.get_width(),rect.get_cy());
		_points.push_back(temp);
		temp.set_points(rect.get_cx()+rect.get_width(),rect.get_cy()+rect.get_height());
		_points.push_back(temp);
		temp.set_points(rect.get_cx(),rect.get_cy()+rect.get_height());
		_points.push_back(temp);

	}
	polygonvect::polygonvect(const circle& circ) : polygon()
	{	
		polygon::Point2D temp;
		double angle = 0;
		for (int i = 0; i < 100; ++i)
		{
			temp.set_points(circ.get_radius()*cos(angle)+circ.get_cx(),circ.get_radius()*sin(angle)+circ.get_cy());
			angle+=3.6*(3.14159/180);//For 100 equal intervals angle changes
			_points.push_back(temp);
		}

	}
	const polygon::Point2D& polygonvect::operator[](int index)const throw(outofrange)
	{	
		if (index<0)
		{
			throw outofrange();
		}
		return _points[index];
	}
	polygon::Point2D& polygonvect::operator[](int index) throw (outofrange)
	{
		if (index<0)
		{
			throw outofrange();
		}
		return _points[index];
	}
	
	double polygonvect::area()const
	{	
		// Calculating area for coordinate geometry
		// Source : https://www.mathopenref.com/coordpolygonarea.html
		double temp = 0;
		for (unsigned int i = 0,j=0; i < _points.size() ; ++i,++j){
			if(i==_points.size()-1)
				j=-1;
			temp+=((_points[i].get_x()*_points[j+1].get_y()) - (_points[i].get_y()*_points[j+1].get_x()));	
		}
		if(temp<0)
			temp=temp*-1;
		
		return temp / 2;
	}
	double polygonvect::perimeter()const
	{	
		// Calculating perimeter for coordinate geometry
		// Source : https://www.mathopenref.com/coordpolygonarea.html
		double temp = 0;
		for (unsigned int i = 0,j=0; i < _points.size();++i,++j)
		{
			if(i==_points.size()-1)
				j=-1;
			temp+= sqrt((pow(_points[i].get_x() - _points[j+1].get_x(),2)) + (pow(_points[i].get_y() - _points[j+1].get_y(),2)));
			
		}
	 	return temp;
	 }
	const shape& polygonvect::operator++()
	{
		double tmpx;
		double tmpy;
		for (unsigned int i = 0; i < _points.size(); ++i)
		{
			tmpx = _points[i].get_x() + 1;
			tmpy = _points[i].get_y() + 1 ;
			_points[i].set_points(tmpx,tmpy);
		}
		return *this;
	}
	
    const shape& polygonvect::operator++(int ignore) throw(notavailable)
    {
    	throw notavailable();
    }
	const shape& polygonvect::operator--()
	{
		double tmpx;
		double tmpy;
		for (unsigned int i = 0; i < _points.size(); ++i)
		{
			tmpx = _points[i].get_x() - 1;
			tmpy = _points[i].get_y() - 1 ;
			_points[i].set_points(tmpx,tmpy);
		}
		return *this;
	}
	 const shape& polygonvect::operator--(int ignore) throw(notavailable)
    {
    	throw notavailable();
    }
    std::ostream& polygonvect::print(std::ostream& outputStream)const
    {
    	return outputStream << *this;
    }
    std::ostream& operator<<(std::ostream& outputStream, const polygonvect& p1)
    {
		outputStream << "<polygon points=\"";
		for (unsigned int i = 0; i < p1._points.size(); ++i)
			outputStream << p1._points[i].get_x() << "," << p1._points[i].get_y() << " " ;

		outputStream << "\" stroke=\"black\" stroke-width=\"2\" fill=\"" 
					<< p1.getColor() << "\" />" << std::endl;
		return outputStream;
    }
}