#include "triangle.h"

triangle::triangle(double tri_edge_val,double cr1_val[],double cr2_val[],double cr3_val[]){
	tri_edge = tri_edge_val;
	cr1[0] = cr1_val[0];
	cr1[1] = cr1_val[1];

	cr2[0] = cr2_val[0];
	cr2[1] = cr2_val[1];

	cr3[0] = cr3_val[0];
	cr3[1] = cr3_val[1];
}
triangle::triangle(){
	tri_edge=0;
	cr1[0]=0;
	cr1[1]=0;

	cr2[0]=0;
	cr2[1]=0;

	cr3[0]=0;
	cr3[1]=0;
}

triangle::triangle(double tri_edge_val){
	tri_edge=tri_edge_val;
}

double* triangle::get_cr1(){
	return cr1;
}
double* triangle::get_cr2(){
	return cr2;
}
double* triangle::get_cr3(){
	return cr3;
}
double triangle::get_tri_edge() const{
	return tri_edge;
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
void triangle::draw(ofstream& file,string color){
	file << "<polygon points=\"" << cr1[0] << "," << cr1[1] << " " << cr2[0] << ","
		<<  cr2[1] << " " << cr3[0] << "," << cr3[1] << "\" fill=\"" 
		<< color << "\" stroke=\"black\" />" << endl;
}