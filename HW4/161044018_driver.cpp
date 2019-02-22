/* CSE 241 HW4 driver file.
 * # Author : Goktug Ali Akin
 * # Student Number : 161044018
 * This file contains all test functions for all implementations.
 * Some getter/setters are not tested since those are inlined.
 * Static member functions which are come from HW3 are not tested.
 * Static member functions and gtuShapes(rectangle,triangle,circle)
 operators are not used but implentation is availeble from HW3.
 * polygon.svg files saved as polygon1-6.svg and polygon+.svg(+ opr test).
 * polyline.svg files saved as polyline1-6.svg and polyline+.svg(+ opr test).
 * composedshape.svg files saved as compos1-6.svg with different shapes using
 shape arrays.
 * some constructor tested automatically when declaring arrays. Comment writed.
 */

#include <iostream>
#include <fstream>
#include "composedshape.h"
#include "polyline.h"
#include <vector>

using namespace gtuShapes;
using namespace gtuComposedShape;
using namespace gtuPolygon;
using namespace gtuPolyline;
using namespace std;

namespace
{	
	/** counter for occured errors, if >0 print color will be red, default is green **/
	int error=0;

	/****** ARRAYS THAT WILL BE USED IN TEST FUNCTIONS. ******/
	rectangle rect_arr[4] = {rectangle(95,120,0,0),rectangle(300,500,0,0),
							rectangle(200,300,0,0),rectangle(50,100,0,200)};

	circle circ_arr[4] = {circle(8.5),circle(10),
							circle(110),circle(45)};

	triangle tri_arr[5] = {triangle(160),triangle(20),
						triangle(40),triangle(60),triangle(400)};
	
	/* Constructors are tested in array elements automatically */
	composedshape comps_arr[6] = {composedshape(rect_arr[0],circ_arr[0]),
								composedshape(rect_arr[1],rect_arr[2]),
								composedshape(rect_arr[1],tri_arr[2]),
								composedshape(tri_arr[0],circ_arr[1]),
								composedshape(tri_arr[4],rect_arr[3]),
								composedshape(tri_arr[0],tri_arr[1])};

	/* Constructors are tested in array elements automatically */							
	polygon::Point2D point2d_arr[3] = {polygon::Point2D(10,10),polygon::Point2D(20,20),
									polygon::Point2D(10,10)};
	
	/*By this array, triangle,circle,and rectangle conversion constructors tested.*/
	polygon polly_arr[6] = {polygon(rect_arr[2]),polygon(circ_arr[2]),
							polygon(rect_arr[3]),polygon(tri_arr[0]),
							polygon(circ_arr[3]),polygon(circ_arr[3])};
							/* last two elements are same because of check opr. */
	
	/*By this array, triangle,circle,and rectangle conversion constructors 
	and conversion constructor from polygon tested.*/
	polyline polyline_arr[6] = {polyline(rect_arr[2]),polyline(circ_arr[2]),
							polyline(rect_arr[3]),polyline(tri_arr[0]),
							polyline(polly_arr[0]),polyline(polly_arr[0])};
							/* last two elements are same because of check opr. */

	/** TEST FUNCTIONS **/
	void print_composedshape();
	void print_polygon();
	void test_polygon_operators();
	void test_polygon_constructors();
	void test_point2d();
	void test_polyline();
	void test_polyline_operators();
	/** TEST FUNCTIONS **/
	void print_bodyof_svg(ofstream& file){/* just draws the body of the file **/
		file << "<svg version=\"1.1\"" << endl
			<< "baseProfile=\"full\"" << endl
			<< "xmlns=\"http://www.w3.org/2000/svg\">" << endl
			<< "<rect width=\"650\" height=\"350\" fill=\"red\"/>" << endl;
			/** background rectangle can be changed there **/
	}  

}
int main(){

	print_polygon();
	test_point2d();
	test_polygon_constructors();
	test_polygon_operators();
	test_polyline();
	test_polyline_operators();

	/** ComposedShape OptimalFit and Output to svg file 
	 * outputs saved as : compos1.svg to compos6.svg */
	comps_arr[0].optimalFit(rect_arr[0],circ_arr[0]);
	comps_arr[1].optimalFit(rect_arr[1],rect_arr[2]);
	comps_arr[2].optimalFit(rect_arr[1],tri_arr[2]);
	comps_arr[3].optimalFit(tri_arr[0],circ_arr[1]);
	comps_arr[4].optimalFit(tri_arr[4],rect_arr[3]);
	comps_arr[5].optimalFit(tri_arr[0],tri_arr[1]);
	print_composedshape();

	if(error>0)/* print error msg to screen adding them colors **/
		cerr << endl << "-> "<<error <<"\033[1;31m error\033[0m" << " generated" << endl;
	else
		cout << endl << "-> "<<error <<"\033[1;32m error\033[0m" << " generated" << endl;		
	return 0;
}
namespace
{
	void print_composedshape(){
		cout << "# ComposedShape outputs saved as compos1-6.svg (<< operator tested)." << endl;

		ofstream file;
		file.open("compos1.svg");
		file << comps_arr[0];
		file.close();
		file.open("compos2.svg");
		file << comps_arr[1];
		file.close();
		file.open("compos3.svg");
		file << comps_arr[2];
		file.close();
		file.open("compos4.svg");
		file << comps_arr[3];
		file.close();
		file.open("compos5.svg");
		file << comps_arr[4];
		file.close();
		file.open("compos6.svg");
		file << comps_arr[5];
		file.close();
		cout << "------------------------------------------" << endl;		
	}
	void print_polygon(){
		cout << "# Polygon outputs saved as polygon1-5.svg (<< operator tested). " << endl;

		ofstream file;
		file.open("polygon1.svg");
		print_bodyof_svg(file);
		file << polly_arr[0];
		file << "</svg>" << endl;
		file.close();

		file.open("polygon2.svg");
		print_bodyof_svg(file);
		file << polly_arr[1];
		file << "</svg>" << endl;
		file.close();

		file.open("polygon3.svg");
		print_bodyof_svg(file);
		file << polly_arr[2];
		file << "</svg>" << endl;
		file.close();

		file.open("polygon4.svg");
		print_bodyof_svg(file);
		file << polly_arr[3];
		file << "</svg>" << endl;
		file.close();

		file.open("polygon5.svg");
		print_bodyof_svg(file);
		file << polly_arr[4];
		file << "</svg>" << endl;
		file.close();

		cout << "------------------------------------------" << endl;
	}
	void test_polygon_operators(){

		cout << "# Operators for polygon class tested. If error occurs,"
			<< endl << "error message will print below with this format (** error msg)" << endl;
		if(polly_arr[4]!=polly_arr[5]){
			cerr << "** operator error occured for : != " << endl;
			++error;
		}
		if(polly_arr[4]==polly_arr[3]){
			cerr << "** operator error occured for : == " << endl;
			++error;
		}

		cout << "+ operator for polygon class tested. Output saved as : polygon+.svg" << endl;
		polygon plus(polly_arr[0]+polly_arr[2]);
		ofstream file;
		file.open("polygon+.svg");
		print_bodyof_svg(file);
		file << plus;
		file << "</svg>" << endl;
		file.close();
		cout << "------------------------------------------" << endl;
	}
	void test_polygon_constructors(){

		cout << "# Constructor for Polygon which takes Point2D vector tested."
			<< endl << "Output saved as : ex_vect.svg" << endl;
		vector<polygon::Point2D> points;
		/* example rectangle pushed (200x500)*/
		points.push_back(polygon::Point2D(30,40));
		points.push_back(polygon::Point2D(530,40));
		points.push_back(polygon::Point2D(530,240));
		points.push_back(polygon::Point2D(30,240));
		polygon ex_vect(points);
		/* lets test by print it */
		ofstream file;
		file.open("vect_test.svg");
		print_bodyof_svg(file);
		file << ex_vect;
		file << "</svg>" << endl;
		file.close();

		cout << "# Constructor for Polygon whick takes Point2D object tested."
			<< endl << "If there is an error, error msg will print the screen "
			<< endl << "by this format : (** error msg)" << endl;

		polygon test(point2d_arr[0]);
		if (test[0] != point2d_arr[0]){/* overloaded != operator uesed */
			cerr << "** ERROR constructor polygon(Point2D&) does not work properly." << endl;
			++error;
		}
		/*
		 * Conversion constructors from rectangle,circle,triagnle .. (gtuShapes)
		 was not implemented since theese are tested polygon_arr decleration **/
		cout << "------------------------------------------" << endl;
	}

	void test_point2d(){
		
		cout << "# Operators for Polygon::Point2D class tested. If error occurs,"
			<< endl << "error msg will print below with this format (** error msg)" << endl;

		if(point2d_arr[0]==point2d_arr[1]){
			cerr << "** operator error occured for : ==" << endl;
			++error;
		}
		if(point2d_arr[0]!=point2d_arr[2]){
			cerr << "** operator error occured for : !=" << endl;
			++error;	
		}

		polygon::Point2D test;
		test.set_points(5,5);
		if(test.get_x()!= 5 || test.get_y()!= 5){
			cerr << "** Error occured : Setter for Point2D class." << endl;
			++error;
		}

		cout << "------------------------------------------" << endl;	
	}
	void test_polyline(){
		cout << "# Class polyline tested(operators,prints). If any error occurs," 
			<< endl << "error msg will print below with this format (** error msg)" << endl;

		cout << "# Operator << tested. Output saved as polyline1-6.svg" << endl;
		
		ofstream file;
		file.open("polyline1.svg");
		print_bodyof_svg(file);
		file << polyline_arr[0];
		file << "</svg>" << endl;
		file.close();

		file.open("polyline2.svg");
		print_bodyof_svg(file);
		file << polyline_arr[1];
		file << "</svg>" << endl;
		file.close();

		file.open("polyline3.svg");
		print_bodyof_svg(file);
		file << polyline_arr[2];
		file << "</svg>" << endl;
		file.close();

		file.open("polyline4.svg");
		print_bodyof_svg(file);
		file << polyline_arr[3];
		file << "</svg>" << endl;
		file.close();

		file.open("polyline5.svg");
		print_bodyof_svg(file);
		file << polyline_arr[4];
		file << "</svg>" << endl;
		file.close();

		cout << "------------------------------------------" << endl;

		cout << "Constructor for polyline, polyline(size) and getter method tested. If any"
			<< endl << "error occurs, error msg will print below with this format (** error msg)" << endl;

		polyline tmp(5);
		if(tmp.get_plyline().getSize()!=5 || tmp.getSize()!=5){
			cerr << "** Error occured for polyline getters or constructor(int size)." << endl;
			++error;	
		}
		cout << "------------------------------------------" << endl;
	
	}	
	void test_polyline_operators(){
		cout << "# Operators for polyline class tested. If error occurs,"
			<< endl << "error message will print below with this format (** error msg)" << endl;
		if(polyline_arr[4]!=polyline_arr[5]){
			cerr << "** operator error occured for : != " << endl;
			++error;
		}
		if(polyline_arr[4]==polyline_arr[3]){
			cerr << "** operator error occured for : == " << endl;
			++error;
		}

		cout << "+ operator for polyline class tested. Output saved as : polyline+.svg" << endl;
		polyline plus(polyline_arr[0]+polyline_arr[2]);
		ofstream file;
		file.open("polyline+.svg");
		print_bodyof_svg(file);
		file << plus;
		file << "</svg>" << endl;
		file.close();
		cout << "------------------------------------------" << endl;
	}
}
