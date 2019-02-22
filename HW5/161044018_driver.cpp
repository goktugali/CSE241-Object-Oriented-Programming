/* 
	CSE 241 HW5 
	Author : Goktug Ali Akin
	Student ID : 161044018
	-----------------------
	* This file is driver(client) code. Not for user input.
	* Different types of composedshapes are printed to file.
	* Test functions and global functions which is in Homework
	  PDF, written in unnamed namespace.
	* Accessing gtushapes by shape class pointer is tested in this code.
	* Some info message printed to the terminal.
	* Exceptions are tested and printed screen by red text.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <vector>
#include "shape.h"
#include "gtuexceptions.h"
#include "rectangle.h"
#include "triangle.h"
#include "circle.h"
#include "polygon.h"
#include "polygondyn.h"
#include "polygonvect.h"
#include "composedshape.h"

using namespace gtuExceptions;
using namespace std;
using namespace gtuComposedShape;
using namespace gtuShapes;


namespace
{	
	void printAll(std::ofstream& file,const std::vector<shape*>& v) throw(invalidsize,invalidptr);
	void sortShapes(std::vector<shape*>& v) throw(invalidsize,invalidptr);
	void printPoly(std::ofstream& file,const std::vector<shape*>& v) throw(invalidsize,invalidptr);
	std::vector<shape*> convertAll(const std::vector<shape*>& v) throw(invalidsize,invalidptr);
	void print_composedshapes(const std::vector<shape*>& v) throw(invalidsize,invalidptr);
	
}

int main(){
	
	try{
		
	vector<shape*> complexshapes1;/* holds composedshapes by shape pointers */
	vector<shape*> composedshapes;/* complex shapes for testing */
	vector<shape *> converted_to_poly;

	rectangle arr_rect[4] = {rectangle(350,570),rectangle(30,50,90,90),rectangle(70,30,70,70),rectangle(80,120,150,150)};
	circle arr_circ[4] = {circle(30,50,60),circle(60,80,60),circle(90,200,200),circle(30,100,100)};
	triangle arr_tri[4] = {triangle(270),triangle(50),triangle(120),triangle(60)};
	composedshape compos_arr[6] = {composedshape(&arr_rect[0],&arr_rect[1]),composedshape(&arr_rect[0],&arr_tri[1]),
									composedshape(&arr_rect[0],&arr_circ[0]),composedshape(&arr_tri[0],&arr_rect[1]),
									composedshape(&arr_tri[0],&arr_circ[0]),composedshape(&arr_tri[0],&arr_tri[1])
								};/* we pushed shape pointer to composedshape ctor */

	polygondyn dyn_arr[4] = {polygondyn(arr_rect[3]),polygondyn(arr_tri[2]),polygondyn(arr_circ[3]),polygondyn(arr_circ[1])};
	
	for (int i = 0; i < 3; ++i)
		dyn_arr[i].setColor("blue");

	for (int i = 0; i < 6; ++i)
		composedshapes.push_back(&compos_arr[i]);
	print_composedshapes(composedshapes);
	cout << "--> Different types of composedshapes svg files created. Outputs saved as : " 
		<< " composedshape1.svg, composedshape2.svg ..." << endl<<endl;

	complexshapes1.push_back(&arr_rect[1]);
	complexshapes1.push_back(&arr_circ[2]);
	complexshapes1.push_back(&arr_tri[1]);
	ofstream file;
	/** fill vector with different type of shapes and test printpoly function to
		print just polygons **/
	file.open("just_polygons_test.svg");
	for (int i = 0; i < 3; ++i)	
		complexshapes1.push_back(&dyn_arr[i]);
	printPoly(file,complexshapes1);
	cout << "--> printPoly function executed. Output saved as : \"just_polygons_test.svg\" " << endl
		<< "For see the results, compare with \"allshapes(complex).svg\"" << endl << endl;

	file.open("allshapes(complex).svg");
	printAll(file,complexshapes1);
	cout << "--> printAll function executed. Output saved as : \"allshapes(complex).svg\" "
		<< "blue shapes are polygons, greens are normal shapes(rectangle,circle,triangle)" << endl<<endl;

	vector<shape*> vect;
	vect.push_back(&arr_rect[1]);
	vect.push_back(&arr_circ[2]);
	vect.push_back(&arr_tri[1]);
	converted_to_poly=convertAll(vect); 
	file.open("converted_to_polygons.svg");
	printAll(file,converted_to_poly);
	cout << "--> ConverAll function executed. Output saved as : \"converted_to_polygons.svg\"" << endl	
		<< "Triangle,Circle,Rectangle are converted. (polygons are not since they are already polygon)." << endl
		<< "For see the results, compare with \"allshapes(complex).svg\"" << endl << endl;

	std::vector<shape*> testArea;
	for (int i = 0; i < 4; ++i){
		testArea.push_back(&arr_rect[i]);
		testArea.push_back(&arr_tri[i]);
		testArea.push_back(&arr_circ[i]);
		testArea.push_back(&dyn_arr[i]);
	}
	cout << "--> Sort Shapes function executed. Shape areas printed below before sort process :" << endl;
	for (unsigned int i = 0; i < testArea.size(); ++i)
		cout << testArea[i]->area() << " ";
	sortShapes(testArea);
	cout << endl << "Areas sorted. Sorted areas printed below : " << endl;
	for (unsigned int i = 0; i < testArea.size(); ++i)
		cout << testArea[i]->area() << " ";
	cout << endl << endl;		
		
	cout << "--> Perimeter of theese Shapes printed. (access by shape pointer)" << endl;
	for (unsigned int i = 0; i < testArea.size(); ++i)
		cout << testArea[i]->perimeter() << " ";
	cout << endl << endl;
	}
	catch(exception& ex){
		cout << "Error occured : "<< ex.what() << endl;
	}

	cout << "------------------------------------------" << endl << endl;
	cout << "Testing some exceptions :" << endl;
	try{

		cout << "* Passing a negative value to rectangle constructor..." << endl;
		rectangle test(-50,-100);

	}catch(exception& ex){
		cout << "\033[1;31m# Error occured : \033[0m" << ex.what() << endl;
	}
	try{
		cout << "* Passing a invalid addres to composedshape constructor..." << endl;
		rectangle tmp;
		polygondyn p1(tmp);
		polygondyn p2(tmp);
		shape * ptr1=&p1;
		shape * ptr2=&p2;
		composedshape(ptr1,ptr2);

	}catch(exception& ex){
		cout << "\033[1;31m# Error occured : \033[0m" << ex.what() << endl;
	}
	try{
		cout << "* Passing a invalid size to vector. printAll function called..." << endl;
		std::vector<shape*> testv;
		ofstream testfileptr;
		printAll(testfileptr,testv);


	}catch(exception& ex){
		cout << "\033[1;31m# Error occured : \033[0m" << ex.what() << endl;
	}
	try{
		cout << "* Passing a invalid index to [] operator.(on polygondyn object)" << endl;
		rectangle tmp2;
		polygondyn test(tmp2);
		test[-1];

	}catch(exception& ex){
		cout << "\033[1;31m# Error occured : \033[0m" << ex.what() << endl;
	}

	return 0;
}

namespace
{	
	void sortShapes(std::vector<shape*>& v) throw(invalidsize,invalidptr) 
	{
		shape* temp;
		if(v.size()==0)
			throw invalidsize();

		for (unsigned int i = 0; i < v.size()-1; ++i)
		{	
			for (unsigned int j = 0; j < v.size()-i-1 ; ++j)
			{	
				if(*v[j]>v[j+1]){ /* boolean > operator tested there */
					
					temp=v[j];
					v[j]=v[j+1];
					v[j+1]=temp;
				}
			}
		}
	}
	void printAll(std::ofstream& file,const std::vector<shape*>& v) throw(invalidsize,invalidptr)
	{	
		if(v.size()==0)
			throw invalidsize();

		file << "<svg version=\"1.1\"" << std::endl
			<< "baseProfile=\"full\"" << std::endl
			<< "xmlns=\"http://www.w3.org/2000/svg\">" << std::endl
			<< "<rect width=\"650\" height=\"350\" fill=\"red\"/>" << std::endl;
		for (shape *p : v)	
			file << p;
		file << "</svg>" << std::endl;		
		file.close();
	}

	void printPoly(std::ofstream& file,const std::vector<shape*>& v) throw(invalidsize,invalidptr)
	{	
		if(v.size()==0)
			throw invalidsize();

		polygon* testptr;
		file << "<svg version=\"1.1\"" << std::endl
			<< "baseProfile=\"full\"" << std::endl
			<< "xmlns=\"http://www.w3.org/2000/svg\">" << std::endl
			<< "<rect width=\"650\" height=\"350\" fill=\"red\"/>" << std::endl;
		for (shape *p : v)
		{
			testptr = dynamic_cast<polygon*>(p);
			if(testptr!=nullptr)				
				file << p;	
		}
		file << "</svg>" << std::endl;
		file.close();
	}

	std::vector<shape*> convertAll(const std::vector<shape*>& v) throw(invalidsize,invalidptr)
	{	
		/* This function allocotes memory for your new vector.
			Be sure yo delete this memory for new vector */
		/* you can convert from rectanle,triangle,circle to polygon */
		if(v.size()==0)
			throw invalidsize();

		std::vector<shape*> polyshapes;
		rectangle * access_rect;
		triangle * access_tri;
		circle * access_circ;
		polygondyn * addr;/* polygon dyn pointer which will be pushed to vector */
		for(shape *p : v)
		{
			access_circ = dynamic_cast<circle*>(p);
			access_rect = dynamic_cast<rectangle*>(p);
			access_tri = dynamic_cast<triangle*>(p);
			if(access_circ!=nullptr){
				addr = new polygondyn(*access_circ);
				polyshapes.push_back(addr);
			}
			else if(access_tri!=nullptr){
				addr = new polygondyn(*access_tri);
				polyshapes.push_back(addr);
			}
			else if(access_rect!=nullptr){
				addr = new polygondyn(*access_rect);
				polyshapes.push_back(addr);		
			}
			else
				throw invalidptr();
		}

		return polyshapes;
	}

	void print_composedshapes(const std::vector<shape*>& v) throw(invalidsize,invalidptr)
	{
		if(v.size()==0)
			throw invalidsize();

		/* These function takes vector of shape pointers,
			and prints the composedshapes(pointed by shape pointer) 
			to files : compos1.svg, compos2.svg .... */

		composedshape* testptr;
		std::string filename;
		std::ofstream file;
		int i = 0;
		for (shape *p : v)
		{
			testptr = dynamic_cast<composedshape*>(p);
			if(testptr==nullptr)
				throw invalidptr();
			else if(testptr!=nullptr)
			{	
				filename = "composedshape" + std::to_string(i) + ".svg";		
				file.open(filename);
				file << p;
				file.close();
				++i;
			}
		}
		
	}
}
