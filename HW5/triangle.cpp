#include "triangle.h"

namespace gtuShapes
{	
	long double triangle::_current_area=0.0;
	long double triangle::_current_perimeter=0.0;

	triangle::triangle() : shape()
	{
		_tri_edge=0;
		_cr1[0]=0;
		_cr1[1]=0;

		_cr2[0]=0;
		_cr2[1]=0;

		_cr3[0]=0;
		_cr3[1]=0;
	}

	triangle::triangle(long double tri_edge, const long double cr1[2], const long double cr2[2], const long double cr3[2]) throw(invalidshapevalue) : shape() 
	{
		if(tri_edge<=0)
			throw invalidshapevalue();
		
		if(cr1[0]<0 || cr1[1]<0)
			throw invalidshapevalue();
		
		if(cr2[0]<0 || cr2[1]<0)
			throw invalidshapevalue();
		
		if(cr3[0]<0 || cr3[1]<0)
			throw invalidshapevalue();
		
		_tri_edge = tri_edge;
		_cr1[0] = cr1[0];
		_cr1[1] = cr1[1];

		_cr2[0] = cr2[0];
		_cr2[1] = cr2[1];

		_cr3[0] = cr3[0];
		_cr3[1] = cr3[1];
		_current_area+=(tri_edge*tri_edge*1.732)/4.0;
		_current_perimeter+=3*tri_edge;
	}

	triangle::triangle(long double tri_edge, const long double cr1[2], const long double cr2[2]) throw(invalidshapevalue): shape() 
	{
		if(tri_edge<=0)
			throw invalidshapevalue();
		
		if(cr1[0]<0 || cr1[1]<0)
			throw invalidshapevalue();;
		
		if(cr2[0]<0 || cr2[1]<0)		
			throw invalidshapevalue();
		
		_tri_edge = tri_edge;
		_cr1[0] = cr1[0];
		_cr1[1] = cr1[1];

		_cr2[0] = cr2[0];
		_cr2[1] = cr2[1];
		_current_area+=(tri_edge*tri_edge*1.732)/4.0;
		_current_perimeter+=3*tri_edge;
	}

	triangle::triangle(long double tri_edge)throw(invalidshapevalue) : shape()
	{
		if(tri_edge<=0)
			throw invalidshapevalue();

		_tri_edge=tri_edge;
		double tri_height = 1.732*tri_edge/2.0;
		_cr1[0]=0;
		_cr1[1]=tri_height;

		_cr2[0]=tri_edge/2.0;
		_cr2[1]=0;

		_cr3[0]=tri_edge;
		_cr3[1]=tri_height;
		_current_area+=(tri_edge*tri_edge*1.732)/4.0;
		_current_perimeter+=3*tri_edge;
	}

	void triangle::set_cr1(long double cr1[2])throw(invalidshapevalue) {
		if(cr1[0]<0 || cr1[1]<0)
			throw invalidshapevalue();

		_cr1[0]=cr1[0];
		_cr1[1]=cr1[1];
	}

	void triangle::set_cr2(long double cr2[2])throw(invalidshapevalue) {
		if(cr2[0]<0 || cr2[1]<0)
			throw invalidshapevalue();

		_cr2[0]=cr2[0];
		_cr2[1]=cr2[1];
	}

	void triangle::set_cr3(long double cr3[2]) throw(invalidshapevalue){
		if(cr3[0]<0 || cr3[1]<0)
			throw invalidshapevalue();
		
		_cr3[0]=cr3[0];
		_cr3[1]=cr3[1];
	}

	void triangle::set_tri_edge(long double tri_edge) throw(invalidshapevalue){
		if(tri_edge<=0)
			throw invalidshapevalue();
		
		_tri_edge = tri_edge;
	}
	std::ostream& triangle::print(std::ostream& outputStream)const{

		return outputStream << *this;
	}
	std::ostream& operator<<(std::ostream& outputStream,const triangle& tri)
	{
		outputStream << "<polygon points=\"" << tri.get_cr1()[0] << "," << tri.get_cr1()[1] << " " << tri.get_cr2()[0] << ","
					<<  tri.get_cr2()[1] << " " << tri.get_cr3()[0] << "," << tri.get_cr3()[1] 
					<< "\" stroke=\"black\" stroke-width=\"3\" fill=\"" 
					<< tri.getColor() << "\" />" << std::endl;
		return outputStream;
	}
	const triangle triangle::operator+(double plus)const
	{	
		return triangle(_tri_edge+plus,_cr1,_cr2,_cr3);
	}
	const triangle triangle::operator-(double minus)const
	{	
		return triangle(_tri_edge-minus,_cr1,_cr2,_cr3);
	}
	const shape& triangle::operator++() {
		_cr1[0]++;
		_cr1[1]++;
		_cr2[0]++;
		_cr2[1]++;
		_cr3[0]++;
		_cr3[1]++;
		return *this;
	}
	
	const shape& triangle::operator++(int ignore) {
		throw notavailable();
	}

	const shape& triangle::operator--() {
		_cr1[0]--;
		_cr1[1]--;
		_cr2[0]--;
		_cr2[1]--;
		_cr3[0]--;
		_cr3[1]--;
		return *this;
	}
	const shape& triangle::operator--(int ignore) {
		throw notavailable();
	}
	double triangle::area() const {
		return (_tri_edge*_tri_edge*1.732)/4.0;
	}

	double triangle::perimeter() const {
		return 3*_tri_edge;
	}
}
