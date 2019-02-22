#ifndef SOURCE_H_
#define SOURCE_H_
#include <iostream>
#include <fstream>
using namespace std;

/** Input functions for shapes **/
inline void input_rectangle(double& height,double& width){
	cout << "Enter height :";
	cin >> height;
	cout << "Enter width : ";
	cin >> width;
}
inline void input_circle(double& radius){
	cout << "Enter radius : ";
	cin >> radius;
}
inline void input_triangle(double& tri_edge){
	cout << "Enter edge of triangle : ";
	cin >> tri_edge;
}
/** Print body of the svg file **/
inline void print_body(ofstream& file){
	file << "<svg version=\"1.1\"" << endl
		<< "baseProfile=\"full\"" << endl
		<< "xmlns=\"http://www.w3.org/2000/svg\">" << endl;

}
/** Print info msg to screen **/
inline void print_area_info(int numOfShapes,double container_area,double small_area){
	cout << endl << "I can fit at " << numOfShapes << " shapes into main container." << endl
		<< "The empty area(red) is : " << container_area - small_area << endl;
}
/** Swapping cornes for triangles **/
inline void swap_corners(double target_arr[],double source_arr[]){
	target_arr[0] = source_arr[0];
	target_arr[1] = source_arr[1];
}

#endif