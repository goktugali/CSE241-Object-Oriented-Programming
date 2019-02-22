#include "polygon.h"

namespace gtuPolygon
{	
	polygon::polygon(const Point2D& point)
	{
		_coefficients = new Point2D[1];
		_coefficients[0] = point;
		_color = "green";//Default color.
	}
	polygon::polygon(const std::vector<Point2D> points)
	{	
		if (points.size()==0)
		{
			std::cerr << "Invalid vector passing. Program Terminated.." << std::endl ;
			exit(1);
		}
		_coefficients = new Point2D[points.size()];
		_size = points.size();
		_color = "green";//Default color.
		for (int i = 0; i < _size; ++i)
			_coefficients[i] = points[i];	
	}
	polygon::polygon(int size)
	{	
		if (size <= 0)
		{
			std::cerr << "Invalid size passing. Program Terminated." << std::endl ;
			exit(1);
		}
		_coefficients = new Point2D[size];
		_size=size;
		_color = "green";//Default color.
	}
	polygon::polygon(const gtuShapes::rectangle& rect)
	{	
		_coefficients = new Point2D[4];
		_size=4;
		_color = "green";//Default color.
		_coefficients[0].set_points(rect.get_cx(),rect.get_cy());
		_coefficients[1].set_points(rect.get_cx()+rect.get_width(),rect.get_cy());
		_coefficients[2].set_points(rect.get_cx()+rect.get_width(),rect.get_cy()+rect.get_height());
		_coefficients[3].set_points(rect.get_cx(),rect.get_cy()+rect.get_height());
	}
	polygon::polygon(const gtuShapes::triangle& tri)
	{
		_coefficients = new Point2D[3];
		_size=3;
		_color = "green";//Default color.
		_coefficients[0].set_points(tri.get_cr1()[0],tri.get_cr1()[1]);
		_coefficients[1].set_points(tri.get_cr2()[0],tri.get_cr2()[1]);
		_coefficients[2].set_points(tri.get_cr3()[0],tri.get_cr3()[1]);		
	}
	polygon::polygon(const gtuShapes::circle& circ)
	{	 
		_coefficients = new Point2D[100];//100 equal intervals
		_size=100;
		_color = "green";//Default color.
		double angle = 0;
		for (int i = 0; i < _size; ++i)
		{
			_coefficients[i].set_points(circ.get_radius()*cos(angle)+circ.get_cx(),circ.get_radius()*sin(angle)+circ.get_cy());
			angle+=3.6*(3.14159/180);//For 100 equal intervals angle changes
		}		
	}
	void polygon::setColor(std::string color)
	{	
		_color = color;
	}
	polygon& polygon::operator=(const polygon& other)
	{
		if (this==&other)
		{
			return *this;
		}
		
		else
		{
			_size = other.getSize();
			_color = other.getColor();
			delete [] _coefficients;
			_coefficients = new Point2D[_size];
			for (int i = 0; i < _size; ++i)		
				(*this)[i] = other[i];
			return *this;		
		}
	}
	
	polygon::polygon(const polygon& copy)
	{
		_coefficients = new Point2D[copy.getSize()];
		_size = copy.getSize();
		_color = copy.getColor();
		for (int i = 0; i < _size; ++i)
			(*this)[i] = copy[i];	
	}
	polygon::~polygon()
	{	
		delete [] _coefficients;
	}
	polygon::Point2D::Point2D(double x,double y)
	{	
		if (x<0 || y<0)
		{	
			std::cerr << "Invalid points passing. Program Terminated.." << std::endl;
			exit(1);
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
		{	
			std::cerr << "Invalid points passing. Program Terminated.." << std::endl;
			exit(1);
		}
		_x = x;
		_y = y;
	}

	const polygon polygon::operator+(const polygon& other)const
	{
		polygon tmp(_size + other.getSize());
		int i;
		for (i = 0; i < _size; ++i)
			tmp[i] = (*this)[i];
	
		for (int j = 0; j < other.getSize(); ++j,++i)	
			tmp[i] = other[j];
		return tmp;	
	}
	const bool polygon::operator==(const polygon& other)const
	{
		if(getSize()!=other.getSize())
			return false;
		else
		{	bool check = true;
			for (int i = 0; i < getSize(); ++i)
				if((*this)[i]!=other[i])
					check = false;
			return check;
		}
	}
	const bool polygon::operator!=(const polygon& other)const
	{
		if(getSize()!=other.getSize())
			return true;
		else
		{	bool check = false;
			for (int i = 0; i < getSize(); ++i)
				if((*this)[i]!=other[i])
					check = true;
			return check;
		}
	}
	const polygon::Point2D& polygon::operator[](int index)const
	{	
		if (index<0)
		{
			std::cerr << "Invalid index passing. Program Terminated.." << std::endl;
			exit(1);
		}
		return _coefficients[index];
	}
	polygon::Point2D& polygon::operator[](int index)
	{	
		if (index<0)
		{
			std::cerr << "Invalid index passing. Program Terminated.." << std::endl;
			exit(1);
		}
		return _coefficients[index];
	}
	std::ostream& operator<<(std::ostream& outputStream, const polygon& p1)
	{
		outputStream << "<polygon points=\"";
		for (int i = 0; i < p1.getSize(); ++i)
			outputStream << p1[i].get_x() << "," << p1[i].get_y() << " " ;

		outputStream << "\" stroke=\"black\" stroke-width=\"2\" fill=\"" 
					<< p1.getColor() << "\" />" << std::endl;
		return outputStream;
	}
}