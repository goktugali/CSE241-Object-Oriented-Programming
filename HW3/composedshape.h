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
enum shapes{r=0,t=1,c=2};
class composedshape{
public:
	/** Constructors for composed shape with different possiblities 
	  * There are 6 constructors because I cannot code the situation 
		where circle shape is main container.
	**/
	composedshape(rectangle* container_val,rectangle* small_val);
	composedshape(rectangle* container_val,circle* small_val);
	composedshape(rectangle* container_val,triangle* small_val);

	composedshape(triangle* container_val,triangle* small_val);
	composedshape(triangle* container_val,circle* small_val);
	composedshape(triangle* container_val,rectangle* small_val);
	class shapeElem{
	public:
		friend ostream& operator<<(ostream& outputStream,const shapeElem& small_shapes);
		friend class composedshape;
		shapeElem(rectangle* small);
		shapeElem(triangle* small);
		shapeElem(circle* small);
		shapeElem(){cerr << "Invalid type!!" << endl;}
		double get_area()const;
		double get_perimeter()const;
	private:
		void *shp_ptr;
		shapes type;

	};
	void optimalFit();

	/** overloaded operators **/
	friend ostream& operator<<(ostream& outputStream,const composedshape& mainshape);
	const composedshape operator+=(const rectangle& shape);
	const composedshape operator+=(const circle& shape);
	const composedshape operator+=(triangle& shape);
	const shapeElem operator[](int index)const;

private:
	void* big_shp_ptr;/** ptr to hold big shp. same logic with shapeElem's **/
	shapes big_type;/** enum type for defining the shp typ. **/
	vector<shapeElem> small_shapes;	
};

#endif	
