/** HW2 main.cpp
  * Goktug Ali Akin
  * 161044018
  */
#include <iostream>
#include "source.h"
#include "composedshape.h"
#include <fstream>

#define PI 3
using namespace std;

int main(){

	char c_shp,s_shp;/** Container and small shape char var. **/
	ofstream file;
	file.open("output.svg");
	
	cout << "Enter container shape (R,C,T): ";
	cin >> c_shp;
	if(c_shp=='R' || c_shp=='r'){
		double c_height,c_width;
		input_rectangle(c_height,c_width);
		rectangle container(c_height,c_width,0.0,0.0); /** Decleration of container shape **/

		cout << "Enter smaller shape (R,C,T): ";
		cin >> s_shp;
		if(s_shp=='R' || s_shp=='r'){		/** CASE : RECTANGLE,RECTANGLE **/
			double s_height,s_width;
			input_rectangle(s_height,s_width);
			rectangle small(s_height,s_width);

			composedshape mainshape(container,small);	/** Decleration of composed shape **/
			mainshape.optimalFit(container,small);	/** Optimalfit process **/
			mainshape.draw(file,container,mainshape.get_rectangle_vect());	/** Draw to the svg file **/
			double small_areas = mainshape.get_rectangle_vect().size()*mainshape.get_rectangle_vect()[0].get_height()*mainshape.get_rectangle_vect()[0].get_width();
			print_area_info(mainshape.get_rectangle_vect().size(),c_height*c_width,small_areas); /** Print info msg **/
		}

		else if(s_shp=='C' || s_shp=='c'){	/** CASE : RECTANGLE,CIRCLE **/
			double s_radius;
			input_circle(s_radius);
			circle small(s_radius);
	
			composedshape mainshape(container,small);
			mainshape.optimalFit(container,small);
			mainshape.draw(file,container,mainshape.get_circle_vect());
			double small_areas = mainshape.get_circle_vect().size()*pow(mainshape.get_circle_vect()[0].get_radius(),2);
			print_area_info(mainshape.get_circle_vect().size(),c_height*c_width,small_areas);
		}

		else if(s_shp=='T' || s_shp=='t'){	/** CASE : RECTANGLE,TRIANGLE **/
			double s_tri_edge;
			input_triangle(s_tri_edge);
			triangle small(s_tri_edge);

			composedshape mainshape(container,small);
			mainshape.optimalFit(container,small);
			mainshape.draw(file,container,mainshape.get_triangle_vect());
			double small_areas = mainshape.get_triangle_vect().size()*((pow(mainshape.get_triangle_vect()[0].get_tri_edge(),2)*sqrt(3))/4.0);
			print_area_info(mainshape.get_triangle_vect().size(),c_height*c_width,small_areas);
			
		}

		else{
			cerr << "Wrong choice! Exiting.." << endl;
			return -1;
		}

	}

	else if(c_shp=='T' || c_shp=='t'){	
		double c_tri_edge;
		double c_tri_height;
		input_triangle(c_tri_edge);
		c_tri_height = sqrt(3)*c_tri_edge/2.0;

		double cr1[2]={0,c_tri_height};
		double cr2[2]={c_tri_edge/2.0,0};
		double cr3[2]={c_tri_edge,c_tri_height};

		triangle container(c_tri_edge,cr1,cr2,cr3);
		cout << "Enter smaller shape (R,C,T): ";
		cin >> s_shp;

		if(s_shp=='R' || s_shp=='r'){	/** CASE : TRIANGlE,RECTANGLE **/
			double s_height,s_width;
			input_rectangle(s_height,s_width);
			rectangle small(s_height,s_width);

			composedshape mainshape(container,small);
			mainshape.optimalFit(container,small);
			mainshape.draw(file,container,mainshape.get_rectangle_vect());
			double small_areas = mainshape.get_rectangle_vect().size()*mainshape.get_rectangle_vect()[0].get_height()*mainshape.get_rectangle_vect()[0].get_width();
			print_area_info(mainshape.get_rectangle_vect().size(),(pow(c_tri_edge,2)*sqrt(3))/4.0,small_areas);
		}

		else if(s_shp=='C' || s_shp=='c'){	/** CASE : TRIANGlE,CIRCLE **/
			double s_radius;
			input_circle(s_radius);
			circle small(s_radius);
			
			composedshape mainshape(container,small);
			mainshape.optimalFit(container,small);
			mainshape.draw(file,container,mainshape.get_circle_vect());
			double small_areas = mainshape.get_circle_vect().size()*pow(mainshape.get_circle_vect()[0].get_radius(),2);
			print_area_info(mainshape.get_circle_vect().size(),(pow(c_tri_edge,2)*sqrt(3))/4.0,small_areas);
		}

		else if(s_shp=='T' || s_shp=='t'){	/** CASE : TRIANGlE,TRIANGLE **/
			double s_tri_edge;
			input_triangle(s_tri_edge);
			triangle small(s_tri_edge);

			composedshape mainshape(container,small);
			mainshape.optimalFit(container,small);
			mainshape.draw(file,container,mainshape.get_triangle_vect());
			double small_areas = mainshape.get_triangle_vect().size()*((pow(mainshape.get_triangle_vect()[0].get_tri_edge(),2)*sqrt(3))/4.0);
			print_area_info(mainshape.get_triangle_vect().size(),(pow(c_tri_edge,2)*sqrt(3))/4.0,small_areas);		
		}

		else{
			cerr << "Wrong choice! Exiting.." << endl;
			return -1;
		}
	}
	else if(c_shp=='C' || c_shp=='c'){
		cerr << "This function cannot work now. Exiting.." << endl;
		/** I cannot code this part **/
		return -1;
	}
	else{
		cerr << "Wrong choice! Exiting.." << endl;
		return -1;
	}

	return 0;
}
