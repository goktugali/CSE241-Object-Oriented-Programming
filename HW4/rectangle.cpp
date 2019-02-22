#include "rectangle.h"

namespace gtuShapes
{
	double rectangle::current_area=0.0;
	double rectangle::current_perimeter=0.0;

	rectangle::rectangle(double height_val,double width_val,double cx_val,double cy_val)
	{	
		if(height_val<=0 || width_val<=0)
		{
			std::cerr << "Invalid height/width passing. Program terminated." << std::endl;
			exit(1);
		}
		if(cx_val<0 || cy_val<0)
		{
			std::cerr << "Invalid coordinate value passing. Program terminated." << std::endl;
			exit(1);
		}
		height=height_val;
		width=width_val;
		cx=cx_val;
		cy=cy_val;
		current_area+=height_val*width_val;
		current_perimeter+=2*(height+width);
	}
	rectangle::rectangle(double height_val,double width_val)
	{	
		if(height_val<=0 || width_val<=0)
		{
			std::cerr << "Invalid height/width passing. Program terminated." << std::endl;
			exit(1);
		}
		height = height_val;
		width = width_val;
		cx=0.0;
		cy=0.0;
		current_area+=height_val*width_val;
		current_perimeter+=2*(height+width);
	}
	rectangle::rectangle()
	{
		height=0;
		width=0;
		cx=0;
		cy=0;
	}
	void rectangle::input()
	{	
		double height_val,width_val;

		std::cout << "Enter height : ";
		std::cin >> height_val;
		if(height_val<=0)
		{
			std::cerr << "Invalid size passing. Program terminated" << std::endl;
			exit(1);
		}
		std::cout << "Enter width : ";
		std::cin >> width_val;
		if(width_val<=0)
		{
			std::cerr << "Invalid size passing. Program terminated" << std::endl;
			exit(1);
		}
		height = height_val;
		width = width_val;
		cx=0.0;
		cy=0.0; 
	}
	std::ostream& operator<<(std::ostream& outputStream,const rectangle& rect)
	{
		outputStream << "<rect width=\""<< rect.get_width() << "\" height=\""<< rect.get_height() << "\""<<" x=\""
			<< rect.get_cx() << "\" y=\""<< rect.get_cy() << "\" stroke=\"black\" stroke-width=\"3\" fill=\"" 
			<< "green" << "\" />" << std::endl;
		return outputStream;
	}
	const bool rectangle::operator==(const rectangle& rect)const
	{	
		return (get_area()==rect.get_area());
	}
	const bool rectangle::operator!=(const rectangle& rect)const
	{
		return !(get_area()==rect.get_area());
	}
	const rectangle rectangle::operator+(double plus)const
	{	
		return rectangle(height+plus,width+plus,cx,cy);
	}
	const rectangle rectangle::operator-(double minus)const
	{	
		return rectangle(height-minus,width-minus,cx,cy);
	}
	const rectangle rectangle::operator++()
	{
		cx++;
		cy++;
		return rectangle(height,width,cx,cy);
	}
	const rectangle rectangle::operator++(int ignoreMe)
	{
		double tmpcx = cx;
		double tmpcy = cy;
		cx++,
		cy++;
		return rectangle(height,width,tmpcx,tmpcy);
	}
	void rectangle::set_cx(double cx_val)
	{	
		if(cx_val<0)
		{
			std::cerr << "Invalid coordinate value passing. Program terminated." << std::endl;
			exit(1);
		}
		cx=cx_val;
	}
	void rectangle::set_cy(double cy_val)
	{	
		if(cy_val<0)
		{
			std::cerr << "Invalid coordinate value passing. Program terminated." << std::endl;
			exit(1);
		}
		cy=cy_val;
	}
	void rectangle::set_height(double height_val)
	{	
		if(height_val<=0)
		{
			std::cerr << "Invalid height value passing. Program terminated." << std::endl;
			exit(1);
		}
		height=height_val;
	}
	void rectangle::set_width(double width_val)
	{	
		if(width_val<=0)
		{
			std::cerr << "Invalid width value passing. Program terminated." << std::endl;
			exit(1);
		}
		width = width_val;
	}
}