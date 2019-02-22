#include "triangle.h"

double triangle::current_area=0.0;
double triangle::current_perimeter=0.0;

triangle::triangle(double tri_edge_val,double cr1_val[],double cr2_val[],double cr3_val[])
{
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
triangle::triangle(double tri_edge_val,double cr1_val[],double cr2_val[])
{
	tri_edge = tri_edge_val;
	cr1[0] = cr1_val[0];
	cr1[1] = cr1_val[1];

	cr2[0] = cr2_val[0];
	cr2[1] = cr2_val[1];
	current_area+=(tri_edge_val*tri_edge_val*sqrt(3))/4.0;
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

triangle::triangle(double tri_edge_val)
{
	tri_edge=tri_edge_val;
	current_area+=(tri_edge_val*tri_edge_val*sqrt(3))/4.0;
	current_perimeter+=3*tri_edge;
}
bool triangle::operator==(triangle& tri)
{
	return (get_area() == tri.get_area());
}
bool triangle::operator!=(triangle& tri)
{
	return !(get_area() == tri.get_area());
}
const triangle triangle::operator+(const double plus)
{	
	tri_edge+=plus;
	return triangle(tri_edge,cr1,cr2,cr3);
}
const triangle triangle::operator-(const double plus)
{	
	tri_edge-=plus;
	return triangle(tri_edge,cr1,cr2,cr3);
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
ostream& operator<<(ostream& outputStream,triangle& tri)
{
	outputStream << "<polygon points=\"" << tri.get_cr1()[0] << "," << tri.get_cr1()[1] << " " << tri.get_cr2()[0] << ","
				<<  tri.get_cr2()[1] << " " << tri.get_cr3()[0] << "," << tri.get_cr3()[1] 
				<< "\" stroke=\"black\" stroke-width=\"3\" fill=\"" 
				<< "green" << "\" />" << endl;
	return outputStream;
}
double* triangle::get_cr1()
{
	return cr1;
}
double* triangle::get_cr2()
{
	return cr2;
}
double* triangle::get_cr3()
{
	return cr3;
}
void triangle::set_cr1(double cr1_val[]){
	cr1[0]=cr1_val[0];
	cr1[1]=cr1_val[1];
}
void triangle::set_cr2(double cr2_val[]){
	cr2[0]=cr2_val[0];
	cr2[1]=cr2_val[1];
}
void triangle::set_cr3(double cr3_val[]){
	cr3[0]=cr3_val[0];
	cr3[1]=cr3_val[1];
}
void triangle::set_tri_edge(double edge){
	tri_edge = edge;
}