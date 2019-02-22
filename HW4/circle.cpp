#include "circle.h"

namespace gtuShapes
{
	double circle::current_area=0.0;
	double circle::current_perimeter=0.0;
	circle::circle(double radius_val,double cx_val,double cy_val)
	{	
		if(radius_val<=0)
		{
			std::cerr << "Invalid radius value passing. Program Terminated." << std::endl;
			exit(1);
		}
		if(cy_val<0 || cx_val<0)
		{
			std::cerr << "Invalid coordinate value passing. Program Terminated." << std::endl;
			exit(1);
		}
		radius=radius_val;
		cx=cx_val;
		cy=cy_val;
		current_area+=PI*radius_val*radius_val;
		current_perimeter+=PI*2*radius_val;
	}
	circle::circle(double radius_val)
	{	
		if(radius_val<=0)
		{
			std::cerr << "Invalid radius value passing. Program Terminated." << std::endl;
			exit(1);
		}
		radius=radius_val;
		current_area+=PI*radius_val*radius_val;
		current_perimeter+=PI*2*radius_val;
		cx=radius_val;
		cy=radius_val;
	}
	circle::circle(){
		radius=0;
		cx=0;
		cy=0;
	}
	void circle::input()
	{	
		double radius_val;
		std::cout << "Enter radius : ";
		std::cin >> radius_val;
		if(radius_val<=0.0)
		{
			std::cerr << "Invalid size passing. Program Terminated." << std::endl;
			exit(EXIT_FAILURE);
		}
		else
		{
			radius = radius_val;
			cx = radius;
			cy = radius;
		}
	}
	const bool circle::operator==(const circle& circle)const
	{
		return (get_area() == circle.get_area());
	}
	const bool circle::operator!=(const circle& circle)const
	{
		return !(get_area() == circle.get_area());
	}
	const circle circle::operator+(const double plus)const
	{	
		return circle(radius+plus,cx,cy);
	}
	const circle circle::operator-(const double plus)const
	{	
		return circle(radius-plus,cx,cy);
	}
	const circle circle::operator++()
	{
		cx++;
		cy++;
		return circle(radius,cx,cy);
	}
	const circle circle::operator++(int ignoreMe)
	{	
		double tmpcx,tmpcy;
		tmpcx=cx;
		tmpcy=cy;
		cx++;
		cy++;
		return circle(radius,tmpcx,tmpcy);
	}
	std::ostream& operator<<(std::ostream& outputStream,const circle& circle)
	{
		outputStream << "<circle cx=\"" << circle.get_cx() << "\" cy=\"" << circle.get_cy() << "\" r=\"" << circle.get_radius()
	 				<< "\" stroke=\"black\" stroke-width=\"3\" fill=\"" 
					<< "green" << "\" />" << std::endl;
	 	return outputStream;	
	}
	void circle::set_radius(double radius_val)
	{	
		if(radius_val<=0)
		{
			std::cerr << "Invalid radius value passing. Program Terminated." << std::endl;
			exit(1);
		}
		radius = radius_val;
	}
	void circle::set_cx(double cx_val)
	{	
		if(cx_val<0)
		{
			std::cerr << "Invalid coordinate value passing. Program Terminated." << std::endl;
			exit(1);
		}
		cx=cx_val;
	}
	void circle::set_cy(double cy_val){
		
		if(cy_val<0)
		{
			std::cerr << "Invalid coordinate value passing. Program Terminated." << std::endl;
			exit(1);
		}
		cy=cy_val;
	}
}