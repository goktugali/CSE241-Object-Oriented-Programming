#ifndef COMPOSEDSHAPE_H_
#define COMPOSEDSHAPE_H_
#include <iostream>
#include <vector>
#include "rectangle.h"
#include "triangle.h"
#include "circle.h"
#include "source.h"
#include <cmath>

using namespace std;

class composedshape{
/*
 * There are 6 members. Two of them will initialized when user enter input.
 * Other 4 members will be empty.
 * Has all of the posibilites of Container and small vector. 
 */
private:
	rectangle container_rectangle;
	vector<rectangle> small_rectangle;

	circle container_circle;
	vector<circle> small_circle;

	triangle container_triangle;
	vector<triangle> small_triangle;
public:
	/** Constructors for composed shape with different possiblities 
	  * There are 6 constructors because I cannot code the situation 
		where circle shape is main container.
	  * Since this possibilites are commented and not implemented.
	  * From the same reason, I dont implement the draw and optimalFit where circle is container.
	**/
	composedshape(rectangle container_val,rectangle small_val);
	composedshape(rectangle container_val,circle small_val);
	composedshape(rectangle container_val,triangle small_val);
	composedshape(triangle container_val,triangle small_val);
	composedshape(triangle container_val,circle small_val);
	composedshape(triangle container_val,rectangle small_val);
	//composedshape(circle container_val,rectangle small_val);
	//composedshape(circle container_val,circle small_val);
	//composedshape(circle container_val,triangle small_val);
	
	/** Functions that return vector of small shapes **/
	vector<rectangle> get_rectangle_vect();
	vector<triangle> get_triangle_vect();
	vector<circle> get_circle_vect();

	/** 6 posibilites of optimal fit methods, overloaded **/
	void optimalFit(rectangle container, rectangle small);
	void optimalFit(rectangle container, circle small);
	void optimalFit(rectangle container, triangle small);
	void optimalFit(triangle container, triangle small);
	void optimalFit(triangle container, rectangle small);
	void optimalFit(triangle container, circle small);
	/** 6 posibilites of draw methods, overloaded **/
	void draw(ofstream& file,rectangle container,vector<rectangle> small_rectangle);
	void draw(ofstream& file,rectangle container,vector<circle> small_circle);
	void draw(ofstream& file,rectangle container,vector<triangle> small_triangle);
	void draw(ofstream& file,triangle container,vector<rectangle> small_rectangle);
	void draw(ofstream& file,triangle container,vector<circle> small_circle);
	void draw(ofstream& file,triangle container,vector<triangle>small_triangle);
};

#endif	
