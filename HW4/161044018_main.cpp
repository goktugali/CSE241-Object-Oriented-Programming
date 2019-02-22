/**** HW4 main.cpp CSE 241 2018.
	* Code for interacting the user for input
	and output to .svg file..
	* Author : Goktug Ali Akin
	* Student Number : 161044018
 ----------------------------------
 	usable namespaces:
	* gtuShapes (rectangle,triangle,circle)
	* gtuComposedShape (main-big shape)
  	* polygon and polyline
*****/
#include <iostream>
#include <fstream>
#include "composedshape.h"

using namespace gtuShapes;
using namespace gtuComposedShape;

int main(){

	char c_shp,s_shp;/** Container and small shape char var. **/
	std::ofstream file;
	file.open("output_main.svg");
	
	std::cout << "Enter container shape (R,C,T): ";
	std::cin >> c_shp;

	if(c_shp=='R' || c_shp=='r'){
	
		rectangle container; /** Decleration of container shape **/
		container.input();

		std::cout << "Enter smaller shape (R,C,T): ";
		std::cin >> s_shp;

		if(s_shp=='R' || s_shp=='r'){		/** CASE : RECTANGLE,RECTANGLE **/
			rectangle small;
			small.input();

			composedshape mainshape(container,small);	/** Decleration of composed shape **/
			mainshape.optimalFit(container,small);
			file << mainshape;	/** print main shape to file **/ /** overloaded **/		
			std::cout << "-> Empty area is(red) : " 
				<< container.get_area() - small.get_area()*(mainshape.get_size_shape()-1)
				<< std::endl;
		}

		else if(s_shp=='C' || s_shp=='c'){	/** CASE : RECTANGLE,CIRCLE **/
			circle small;
			small.input();
	
			composedshape mainshape(container,small);
			mainshape.optimalFit(container,small);
			file << mainshape;
			std::cout << "-> Empty area is(red) : " 
				<< container.get_area() - small.get_area()*(mainshape.get_size_shape()-1)
				<< std::endl;
		}

		else if(s_shp=='T' || s_shp=='t'){	/** CASE : RECTANGLE,TRIANGLE **/
			triangle small;
			small.input();

			composedshape mainshape(container,small);
			mainshape.optimalFit(container,small);
			file << mainshape;
			std::cout << "-> Empty area is(red) : " 
				<< container.get_area() - small.get_area()*(mainshape.get_size_shape()-1)
				<< std::endl;	
		}
		else{
			std::cerr << "Wrong choice! Exiting.." << std::endl;
			return -1;
		}
	}
	else if(c_shp=='T' || c_shp=='t'){	
		
		triangle container;
		container.input();

		std::cout << "Enter smaller shape (R,C,T): ";
		std::cin >> s_shp;

		if(s_shp=='R' || s_shp=='r'){	/** CASE : TRIANGlE,RECTANGLE **/
			rectangle small;
			small.input();

			composedshape mainshape(container,small);
			mainshape.optimalFit(container,small);
			file << mainshape;
			std::cout << "-> Empty area is(red) : " 
				<< container.get_area() - small.get_area()*(mainshape.get_size_shape()-1)
				<< std::endl;
		}

		else if(s_shp=='C' || s_shp=='c'){	/** CASE : TRIANGlE,CIRCLE **/
			circle small;
			small.input();
			
			composedshape mainshape(container,small);
			mainshape.optimalFit(container,small);
			file << mainshape;
			std::cout << "-> Empty area is(red) : " 
				<< container.get_area() - small.get_area()*(mainshape.get_size_shape()-1)
				<< std::endl;
		}

		else if(s_shp=='T' || s_shp=='t'){	/** CASE : TRIANGlE,TRIANGLE **/
			triangle small;
			small.input();

			composedshape mainshape(container,small);
			mainshape.optimalFit(container,small);
			file << mainshape;	
			std::cout << "-> Empty area is(red) : " 
				<< container.get_area() - small.get_area()*(mainshape.get_size_shape()-1)
				<< std::endl;	
		}

		else{
			std::cerr << "Wrong choice! Exiting.." << std::endl;
			return -1;
		}
	}
	else if(c_shp=='C' || c_shp=='c'){
		std::cerr << "This function cannot work now. Exiting.." << std::endl;
		/** I cannot code this part **/
		return -1;
	}
	else{
		std::cerr << "Wrong choice! Exiting.." << std::endl;
		return -1;
	}

	std::cout << "-> Output saved as : output_main.svg" << std::endl;
	return 0;
}