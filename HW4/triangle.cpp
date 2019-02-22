#include "triangle.h"

namespace gtuShapes
{
	double triangle::current_area=0.0;
	double triangle::current_perimeter=0.0;

	triangle::triangle(double tri_edge_val,const double cr1_val[],const double cr2_val[],const double cr3_val[])
	{	
		if(tri_edge_val<=0)
		{
			std::cerr << "Invalid edge value passing. Program Terminated." << std::endl;
			exit(1);
		}
		if(cr1_val[0]<0 || cr1_val[1]<0)
		{
			std::cerr << "Invalid coordinate value passing. Program Terminated." << std::endl;
			exit(1);
		}
		if(cr2_val[0]<0 || cr2_val[1]<0)
		{
			std::cerr << "Invalid coordinate value passing. Program Terminated." << std::endl;
			exit(1);
		}

		if(cr3_val[0]<0 || cr3_val[1]<0)
		{
			std::cerr << "Invalid coordinate value passing. Program Terminated." << std::endl;
			exit(1);
		}

		tri_edge = tri_edge_val;
		cr1[0] = cr1_val[0];
		cr1[1] = cr1_val[1];

		cr2[0] = cr2_val[0];
		cr2[1] = cr2_val[1];

		cr3[0] = cr3_val[0];
		cr3[1] = cr3_val[1];
		current_area+=(tri_edge_val*tri_edge_val*1.732)/4.0;
		current_perimeter+=3*tri_edge;
	}
	triangle::triangle(double tri_edge_val,const double cr1_val[],const double cr2_val[])
	{	
		if(tri_edge_val<=0)
		{
			std::cerr << "Invalid edge value passing. Program Terminated." << std::endl;
			exit(1);
		}
		if(cr1_val[0]<0 || cr1_val[1]<0)
		{
			std::cerr << "Invalid coordinate value passing. Program Terminated." << std::endl;
			exit(1);
		}
		if(cr2_val[0]<0 || cr2_val[1]<0)
		{
			std::cerr << "Invalid coordinate value passing. Program Terminated." << std::endl;
			exit(1);
		}
		tri_edge = tri_edge_val;
		cr1[0] = cr1_val[0];
		cr1[1] = cr1_val[1];

		cr2[0] = cr2_val[0];
		cr2[1] = cr2_val[1];
		current_area+=(tri_edge_val*tri_edge_val*1.732)/4.0;
		current_perimeter+=3*tri_edge;
	}

	triangle::triangle(double tri_edge_val)
	{	
		if(tri_edge_val<=0)
		{
			std::cerr << "Invalid edge value passing. Program Terminated." << std::endl;
			exit(1);
		}

		tri_edge=tri_edge_val;
		double tri_height = 1.732*tri_edge/2.0;
		cr1[0]=0;
		cr1[1]=tri_height;

		cr2[0]=tri_edge/2.0;
		cr2[1]=0;

		cr3[0]=tri_edge;
		cr3[1]=tri_height;
		current_area+=(tri_edge_val*tri_edge_val*1.732)/4.0;
		current_perimeter+=3*tri_edge;
	}

	triangle::triangle()
	{
		tri_edge=0;
		cr1[0]=0;
		cr1[1]=0;

		cr2[0]=0;
		cr2[1]=0;

		cr3[0]=0;
		cr3[1]=0;
	}


	const double* triangle::get_cr1()const
	{
		return cr1;
	}
	const double* triangle::get_cr2()const
	{
		return cr2;
	}
	const double* triangle::get_cr3()const
	{
		return cr3;
	}
	void triangle::set_cr1(double cr1_val[]){
		if(cr1_val[0]<0 || cr1_val[1]<0)
		{
			std::cerr << "Invalid coordinate value passing. Program Terminated." << std::endl;
			exit(1);
		}
		cr1[0]=cr1_val[0];
		cr1[1]=cr1_val[1];
	}
	void triangle::set_cr2(double cr2_val[]){
		if(cr2_val[0]<0 || cr2_val[1]<0)
		{
			std::cerr << "Invalid coordinate value passing. Program Terminated." << std::endl;
			exit(1);
		}
		cr2[0]=cr2_val[0];
		cr2[1]=cr2_val[1];
	}
	void triangle::set_cr3(double cr3_val[]){
		if(cr3_val[0]<0 || cr3_val[1]<0)
		{
			std::cerr << "Invalid coordinate value passing. Program Terminated." << std::endl;
			exit(1);
		}
		cr3[0]=cr3_val[0];
		cr3[1]=cr3_val[1];
	}
	void triangle::set_tri_edge(double edge){
		if(edge<=0)
		{
			std::cerr << "Invalid edge value passing. Program Terminated." << std::endl;
			exit(1);
		}
		tri_edge = edge;
	}
	void triangle::input()
	{	
		double tri_edge_val;
		std::cout << "Enter edge of triangle : ";
		std::cin >> tri_edge_val;
		if(tri_edge_val<=0)
		{
			std::cerr << "Invalid size passing. Program Terminated." << std::endl;
			exit(1);
		}
		else
		{	tri_edge=tri_edge_val;
			double tri_height = 1.732*tri_edge/2.0;
			cr1[0]=0;
			cr1[1]=tri_height;

			cr2[0]=tri_edge/2.0;
			cr2[1]=0;

			cr3[0]=tri_edge;
			cr3[1]=tri_height;
		}
	}
	const bool triangle::operator==(const triangle& tri)const
	{
		return (get_area() == tri.get_area());
	}
	const bool triangle::operator!=(const triangle& tri)const
	{
		return !(get_area() == tri.get_area());
	}
	const triangle triangle::operator+(double plus)const
	{	
		return triangle(tri_edge+plus,cr1,cr2,cr3);
	}
	const triangle triangle::operator-(double plus)const
	{	
		return triangle(tri_edge-plus,cr1,cr2,cr3);
	}
	const triangle triangle::operator++()
	{
		cr1[0]++;
		cr1[1]++;
		cr2[0]++;
		cr2[1]++;
		cr3[0]++;
		cr3[1]++;
		return triangle(tri_edge,cr1,cr2,cr3);
	}
	const triangle triangle::operator++(int ignoreMe)
	{	
		double tmp_cr1[2],tmp_cr2[2],tmp_cr3[2];
		tmp_cr1[0]=cr1[0];
		tmp_cr1[1]=cr1[1];
		cr1[0]++;
		cr1[1]++;
		tmp_cr2[0]=cr2[0];
		tmp_cr2[1]=cr2[1];
		cr2[0]++;
		cr2[1]++;
		tmp_cr3[0]=cr3[0];
		tmp_cr3[1]=cr3[1];
		cr3[0]++;
		cr3[1]++;
		return triangle(tri_edge,tmp_cr1,tmp_cr2,tmp_cr3);
	}
	std::ostream& operator<<(std::ostream& outputStream,const triangle& tri)
	{
		outputStream << "<polygon points=\"" << tri.get_cr1()[0] << "," << tri.get_cr1()[1] << " " << tri.get_cr2()[0] << ","
					<<  tri.get_cr2()[1] << " " << tri.get_cr3()[0] << "," << tri.get_cr3()[1] 
					<< "\" stroke=\"black\" stroke-width=\"3\" fill=\"" 
					<< "green" << "\" />" << std::endl;
		return outputStream;
	}
}
