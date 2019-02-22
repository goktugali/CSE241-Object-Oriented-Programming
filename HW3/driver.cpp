#include <iostream>
#include <fstream>
#include "composedshape.h"

using namespace std;

void test_rectangle_inside_rectangle(double container_height,double container_width,double small_height,double small_width)
{
	rectangle r1(container_height,container_width);
	rectangle r2(small_height,small_width);
	composedshape mainshape(&r1,&r2);
	mainshape.optimalFit();
	ofstream file;
	file.open("output_r_r.svg");
	file << mainshape;
	file.close(); 
}
void test_circle_inside_rectangle(double container_height,double container_width,double small_radius)
{
	rectangle r1(container_height,container_width);
	circle c2(small_radius);
	composedshape mainshape(&r1,&c2);
	mainshape.optimalFit();
	ofstream file;
	file.open("output_c_r.svg");
	file << mainshape;
	file.close(); 
}
void test_triangle_inside_rectangle(double container_height,double container_width,double small_tri_edge)
{
	rectangle r1(container_height,container_width);
	triangle t2(small_tri_edge);
	composedshape mainshape(&r1,&t2);
	mainshape.optimalFit();
	ofstream file;
	file.open("output_t_r.svg");
	file << mainshape;
	file.close(); 
}

void test_circle_inside_triangle(double container_tri_edge,double small_radius)
{	
	double c_tri_height = sqrt(3)*container_tri_edge/2.0;
	double cr1[2]={0,c_tri_height};
	double cr2[2]={container_tri_edge/2.0,0};
	double cr3[2]={container_tri_edge,c_tri_height};

	triangle t1(container_tri_edge,cr1,cr2,cr3);
	circle c2(small_radius);
	composedshape mainshape(&t1,&c2);
	mainshape.optimalFit();
	ofstream file;
	file.open("output_c_t.svg");
	file << mainshape;
	file.close();
}

void test_triangle_inside_triangle(double container_tri_edge,double small_tri_edge)
{	
	double c_tri_height = sqrt(3)*container_tri_edge/2.0;
	double cr1[2]={0,c_tri_height};
	double cr2[2]={container_tri_edge/2.0,0};
	double cr3[2]={container_tri_edge,c_tri_height};

	triangle t1(container_tri_edge,cr1,cr2,cr3);
	triangle t2(small_tri_edge);
	composedshape mainshape(&t1,&t2);
	mainshape.optimalFit();
	ofstream file;
	file.open("output_t_t.svg");
	file << mainshape;
	file.close();
}

void test_rectangle_inside_triangle(double container_tri_edge,double small_height,double small_width)
{	
	double c_tri_height = sqrt(3)*container_tri_edge/2.0;
	double cr1[2]={0,c_tri_height};
	double cr2[2]={container_tri_edge/2.0,0};
	double cr3[2]={container_tri_edge,c_tri_height};

	triangle t1(container_tri_edge,cr1,cr2,cr3);
	rectangle r2(small_height,small_width);
	composedshape mainshape(&t1,&r2);
	mainshape.optimalFit();
	ofstream file;
	file.open("output_r_t.svg");
	file << mainshape;
	file.close();
}

void test_operators_rectangle()
{
	cout << "##### OPERATOR TESTER FOR RECTANGLE CLASS ####### " << endl;
	cout << ".......... (+) opreator in test ............." << endl;
	
	rectangle r1(200,300);
	cout << "# height : " << r1.get_height() << " width : " << r1.get_width() << endl;
	double plus = 50;
	r1 + 50;
	cout << "# Value \"" << plus << "\" has been added to the rectangle." << endl;
	cout << "# New rectangle height : " << r1.get_height() << " width : " << r1.get_width() << endl;
	cout << "......... (+) operator test finisihed......." << endl << endl;

	cout << "......... (-) operator in test ..............." << endl;
	
	rectangle r2(150,300);
	cout << "# height : " << r2.get_height() << " width : " << r2.get_width() << endl;
	double minus = 50;
	r2-50;
	cout << "# Value \"" << minus << "\" has been deducted to the rectangle." << endl;
	cout << "# New rectangle height : " << r2.get_height() << " width : " << r2.get_width() << endl;
	cout << ".......... (-) operator test finisihed......." << endl << endl;

	cout << "......... (== and !=) operator in test ..............." << endl;
	rectangle rt1(50,100),rt2(50,100),rt3(100,100);
	if(rt1==rt2)
		cout << "# r1 area :" << rt1.get_area() << " r2 area : " << rt2.get_area() << " is equal." << endl;
	if(rt1!=rt3)
		cout << "# r1 area :" << rt1.get_area() << " r3 area : " << rt3.get_area() << " is not equal" << endl;
	if(rt1==rt3)
		cout << "******Error occured******" << endl;
	if(rt1!=rt2)
		cout << "******Error occured" << endl;
	cout << ".......... (== and !=) operator test finisihed......." << endl << endl;

	cout << "# (<<)operator tested. Output saved as : \"rectangle_<<.svg\"." << endl;

	cout << "##### OPERATOR TESTER FOR RECTANGLE CLASS ####### " << endl << endl << endl;

	ofstream file;
	file.open("rectangle_<<_.svg");
	file << "<svg version=\"1.1\"" << endl
		<< "baseProfile=\"full\"" << endl
		<< "xmlns=\"http://www.w3.org/2000/svg\">" << endl;
	file << r1;
	file << "</svg>" << endl;
	file.close();
}
void test_operators_circle()
{
	cout << "##### OPERATOR TESTER FOR CIRCLE CLASS ####### " << endl;
	cout << ".......... (+) opreator in test ............." << endl;
	
	circle c1(100);
	cout << "# radius : " << c1.get_radius() << endl;
	double plus = 50;
	c1 + 50;
	cout << "# Value \"" << plus << "\" has been added to the circle." << endl;
	cout << "# New circle radius : " << c1.get_radius() << endl;
	cout << "......... (+) operator test finisihed......." << endl << endl;
	cout << "......... (-) operator in test ..............." << endl;

	circle c2(250);
	cout << "# radius : " << c2.get_radius() << endl;
	double minus = 50;
	c2-50;
	cout << "Value \"" << minus << "\" has been deducted to the circle." << endl;
	cout << "New circle radius : " << c2.get_radius() << endl;
	cout << ".......... (-) operator test finisihed......." << endl << endl;

	cout << "......... (== and !=) operator in test ..............." << endl;
	circle cc1(100),cc2(100),cc3(200);
	if(cc1==cc2)
		cout << "# c1 area :" << cc1.get_area() << " c2 area : " << cc2.get_area() << " is equal." << endl;
	if(cc1!=cc3)
		cout << "# c1 area :" << cc1.get_area() << " c3 area : " << cc3.get_area() << " is not equal" << endl;
	if(cc1==cc3)
		cout << "******Error occured******" << endl;
	if(cc1!=cc2)
		cout << "******Error occured" << endl;
	cout << ".......... (== and !=) operator test finisihed......." << endl << endl;

	cout << "# (<<)operator tested. Output saved as : \"circle_<<.svg\"." << endl;
	cout << "##### OPERATOR TESTER FOR CIRCLE CLASS ####### " << endl << endl << endl;

	ofstream file;
	c1.set_cx(c1.get_radius());/** for print the middle of the picture **/
	c1.set_cy(c1.get_radius());

	file.open("circle_<<_.svg");
	file << "<svg version=\"1.1\"" << endl
		<< "baseProfile=\"full\"" << endl
		<< "xmlns=\"http://www.w3.org/2000/svg\">" << endl;
	file << c1;
	file << "</svg>" << endl;
	file.close();
}
void test_operator_triangle()
{
	cout << "##### OPERATOR TESTER FOR TRIANGLE CLASS ####### " << endl;
	cout << ".......... (+) opreator in test ............." << endl;
	
	triangle t1(100);
	cout << "# edge : " << t1.get_tri_edge() << endl;
	double plus = 50;
	t1 + 50;
	cout << "# Value \"" << plus << "\" has been added to the triangle." << endl;
	cout << "# New triangle edge : " << t1.get_tri_edge() << endl;
	cout << "......... (+) operator test finisihed......." << endl << endl;
	cout << "......... (-) operator in test ..............." << endl;

	triangle t2(250);
	cout << "# edge : " << t2.get_tri_edge() << endl;
	double minus = 50;
	t2-50;
	cout << "Value \"" << minus << "\" has been deducted to the triangle." << endl;
	cout << "New triangle edge : " << t2.get_tri_edge() << endl;
	cout << ".......... (-) operator test finisihed......." << endl << endl;

	cout << "......... (== and !=) operator in test ..............." << endl;
	triangle tt1(100),tt2(100),tt3(200);
	if(tt1==tt2)
		cout << "# c1 area :" << tt1.get_area() << " c2 area : " << tt2.get_area() << " is equal." << endl;
	if(tt1!=tt3)
		cout << "# c1 area :" << tt1.get_area() << " c3 area : " << tt3.get_area() << " is not equal" << endl;
	if(tt1==tt3)
		cout << "******Error occured******" << endl;
	if(tt1!=tt2)
		cout << "******Error occured" << endl;
	cout << ".......... (== and !=) operator test finisihed......." << endl << endl;

	cout << "# (<<)operator tested. Output saved as : \"triangle_<<.svg\"." << endl;
	cout << "##### OPERATOR TESTER FOR TRIANGLE CLASS ####### " << endl;

	/** just for giving values for corners, ignore it **/
	double tri_height = sqrt(3)*t1.get_tri_edge()/2.0;
	double cr1[2]={0.0,tri_height};
	double cr2[2]={t1.get_tri_edge()/2.0,tri_height-sqrt(3)*t1.get_tri_edge()/2.0};
	double cr3[2]={t1.get_tri_edge(),tri_height};
	t1.set_cr1(cr1);
	t1.set_cr2(cr2);
	t1.set_cr3(cr3);
	/** just for giving values for corners, ignore it **/
	ofstream file;
	file.open("triangle_<<_.svg");
	file << "<svg version=\"1.1\"" << endl
		<< "baseProfile=\"full\"" << endl
		<< "xmlns=\"http://www.w3.org/2000/svg\">" << endl;
	file << t1;
	file << "</svg>" << endl;
	file.close();	
}
void test_static_methods()
{	
	cout << "Static members tests : " << endl;
	rectangle r1(50,10);/**area = 500 perimeter=120 **/
	rectangle r2(40,10);/**area = 400 perimeter=100 **/
	rectangle r3(30,10);/**area = 300 petimeter=80 **/
	
	if(rectangle::get_current_area()==r1.get_area()+r2.get_area()+r3.get_area())
		cout << "> rectangle area confirmed " << endl;
	if(rectangle::get_current_perimeter()==r1.get_perimeter()+r2.get_perimeter()+r3.get_perimeter())
		cout << "> rectangle perimeter confirmed" << endl << endl;

	circle c1(10);/** area 300 perimeter=60 **/
	circle c2(20);/** area 1200 perimeter=120 **/
	circle c3(30);/** area 2700 perimeter=180 **/

	if(circle::get_current_area()==c1.get_area()+c2.get_area()+c3.get_area())
		cout << "> circle area confirmed" << endl;
	if(circle::get_current_perimeter()==c1.get_perimeter()+c2.get_perimeter()+c3.get_perimeter())
		cout << "> circle perimeter confirmed" << endl << endl;

	triangle t1(20);
	triangle t2(40);
	triangle t3(60);
	
	cout << t1.get_area()+t2.get_area()+t3.get_area() << endl;
	cout << triangle::get_current_area() << endl;
	/** If error occurs please look at this results, it may be error about numbers fraction part.. x,x.... **/
	if(triangle::get_current_area()==t1.get_area()+t2.get_area()+t3.get_area()) 
		cout << "> triangle area confirmed" <<endl;
	if(triangle::get_current_perimeter()==t1.get_perimeter()+t2.get_perimeter()+t3.get_perimeter())
		cout << "> trianlge perimeter confirmed" << endl << endl;
	
}
int main(){

	/** TESTING THE DRAWING **/
	test_static_methods();
	/* svg files are created, you can change the values */
	/* Left side parameter is container shape */
	test_rectangle_inside_rectangle(300,500,95,140);
	test_circle_inside_rectangle(85,120,8.5);
	test_triangle_inside_rectangle(300,500,80);
	test_circle_inside_triangle(160,35);
	test_rectangle_inside_triangle(300,40,60);
	test_triangle_inside_triangle(160,30);
	/** TESTING THE DRAWING **/

	/** TESTING OPERATORS FOR CLASSES **/
	/* results printed on the terminal */
	test_operators_rectangle();
	test_operators_circle();
	test_operator_triangle();
	/** TESTING OPERATORS FOR CLASSES **/
	
	return 0;
}
