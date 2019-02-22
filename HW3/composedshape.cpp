#include "composedshape.h"

/** shapeElem constructors **/
composedshape::shapeElem::shapeElem(rectangle* small)
{
	shp_ptr=small;
	type=r;
}
composedshape::shapeElem::shapeElem(triangle* small)
{
	shp_ptr=small;
	type=t;
}
composedshape::shapeElem::shapeElem(circle* small)
{
	shp_ptr=small;
	type=c;
}
double composedshape::shapeElem::get_area()const
{
	if(type==r)
	{
		rectangle* rect = static_cast<rectangle*>(shp_ptr);
		return (*rect).get_area();
	}
	if(type==c)
	{
		circle* circ = static_cast<circle*>(shp_ptr);
		return (*circ).get_area();
	}
	if(type==t)
	{
		triangle* tri = static_cast<triangle*>(shp_ptr);
		return (*tri).get_area();
	}
	cerr << "Error occured!" << endl;
	return -1;
}
double composedshape::shapeElem::get_perimeter()const
{
	if(type==r)
	{
		rectangle* rect = static_cast<rectangle*>(shp_ptr);
		return (*rect).get_perimeter();
	}
	if(type==c)
	{
		circle* circ = static_cast<circle*>(shp_ptr);
		return (*circ).get_perimeter();
	}
	if(type==t)
	{
		triangle* tri = static_cast<triangle*>(shp_ptr);
		return (*tri).get_perimeter();
	}
	cerr << "Error occured!" << endl;
	return -1;
}
composedshape::composedshape(rectangle* container_val,rectangle* small_val)
{	
	shapeElem tmp(small_val);	/** pass pointer of small to void ptr which is in shapeElem class */
	small_shapes.push_back(tmp);
	big_shp_ptr=container_val; /** pass pointer to big_shp_ptr **/ 
	big_type=r;/** Every constructor I do same things ***/
}
composedshape::composedshape(rectangle* container_val,circle* small_val)
{
	shapeElem tmp(small_val);
	small_shapes.push_back(tmp);
	big_shp_ptr=container_val;
	big_type=r;
}
composedshape::composedshape(rectangle* container_val,triangle* small_val)
{
	shapeElem tmp(small_val);
	small_shapes.push_back(tmp);
	big_shp_ptr=container_val;
	big_type=r;
}
composedshape::composedshape(triangle* container_val,triangle* small_val)
{
	shapeElem tmp(small_val);
	small_shapes.push_back(tmp);
	big_shp_ptr=container_val;
	big_type=t;	
}
composedshape::composedshape(triangle* container_val,circle* small_val){
	shapeElem tmp(small_val);
	small_shapes.push_back(tmp);
	big_shp_ptr=container_val;
	big_type=t;	
}
composedshape::composedshape(triangle* container_val,rectangle* small_val){
	shapeElem tmp(small_val);
	small_shapes.push_back(tmp);
	big_shp_ptr=container_val;
	big_type=t;
}
const composedshape::shapeElem composedshape::operator[](int index)const
{
	return small_shapes[index];
}
ostream& operator<<(ostream& outputStream,const composedshape& mainshape)
{	
	outputStream << "<svg version=\"1.1\"" << endl
				<< "baseProfile=\"full\"" << endl
				<< "xmlns=\"http://www.w3.org/2000/svg\">" << endl;
	if(mainshape.big_type==0)
	{
		rectangle* container = static_cast<rectangle*>(mainshape.big_shp_ptr);
		outputStream << (*container);
	}
	else if(mainshape.big_type==1)
	{
		triangle* container = static_cast<triangle*>(mainshape.big_shp_ptr);
		outputStream << (*container);
	}
	else{
		cerr << "circle overload has not been implemented!!!"<< endl;
		return outputStream;
	}
	
	for (unsigned int i = 0; i < mainshape.small_shapes.size(); ++i)
		outputStream << mainshape[i];
	
	outputStream << "</svg>" << endl;
	return outputStream;
}

ostream& operator<<(ostream& outputStream,const composedshape::shapeElem& small_shapes)
{
	if(small_shapes.type==0)
	{
		rectangle* shape = static_cast<rectangle*>(small_shapes.shp_ptr);
		outputStream << (*shape);
	}
	else if(small_shapes.type==1)
	{
		triangle* shape = static_cast<triangle*>(small_shapes.shp_ptr);
		outputStream << (*shape);
	}
	else if(small_shapes.type==2)
	{
		circle* shape = static_cast<circle*>(small_shapes.shp_ptr);
		outputStream << (*shape);
	}

	return outputStream;
}
const composedshape composedshape::operator+=(const rectangle& shape)
{
	rectangle* rect_ptr = new rectangle(shape.get_height(),shape.get_width(),shape.get_cx(),shape.get_cy());
	/** Allocate a memory location for shape which is coming from optimal fit **/
	/** pass this adress to shapeElem classes void ptr **/
	/** same thing for all overloads **/
	shapeElem tmp(rect_ptr);
	small_shapes.push_back(tmp);
	return *this; /** Return myself **/
}
const composedshape composedshape::operator+=(triangle& shape)
{
	triangle* tri_ptr = new triangle(shape.get_tri_edge(),shape.get_cr1(),shape.get_cr2(),shape.get_cr3());
	shapeElem tmp(tri_ptr);
	small_shapes.push_back(tmp);
	return *this;	
}
const composedshape composedshape::operator+=(const circle& shape)
{
	circle* circ_ptr = new circle(shape.get_radius(),shape.get_cx(),shape.get_cy());
	shapeElem tmp(circ_ptr);
	small_shapes.push_back(tmp);
	return *this;	
}
void composedshape::optimalFit()
{	
	if(big_type==0)
	{
		if(small_shapes[0].type==r)
		{	
			/** cast coming pointer from shapeElem to rectangle class to acces it **/
			/** same algorithm used all in posibilites **/
			rectangle* acces_small = static_cast<rectangle*>(small_shapes[0].shp_ptr);
			rectangle* acces_container = static_cast<rectangle*>(big_shp_ptr);
			(*acces_small).set_cx(0);
			(*acces_small).set_cy(0);

			int numOfRects_width = static_cast<int>((*acces_container).get_width() / (*acces_small).get_width());
			int numOfRects_height = static_cast<int>((*acces_container).get_height() / (*acces_small).get_height());

			double small_width = (*acces_small).get_width();
			double small_height = (*acces_small).get_height();
			double cx,cy;

			rectangle tmp_rect;
			tmp_rect.set_height(small_height);
			tmp_rect.set_width(small_width);
			for (int i = 0; i < numOfRects_height; ++i)
			{	
				cx=0.0;
				for (int j = 0; j < numOfRects_width; ++j)
				{	
					tmp_rect.set_cx(cx);
					if(!(i==0 && j==0))
						*this += tmp_rect;/** I add myself a new shape object **/
					cx+=small_width;
				}
				cy+=small_height;
				tmp_rect.set_cy(cy);
			}
		}

		else if(small_shapes[0].type==c)
		{	
			circle* acces_small = static_cast<circle*>(small_shapes[0].shp_ptr);
			rectangle* acces_container = static_cast<rectangle*>(big_shp_ptr);

			double c_width = (*acces_container).get_width();
			double c_height = (*acces_container).get_height();
			double s_radius = (*acces_small).get_radius();
			int numOfCircles_width = static_cast<int>(c_width / (s_radius*2));
			int numOfCircles_height = static_cast<int>(c_height / (s_radius*2));

			int totalCircles_rectangular = numOfCircles_height*numOfCircles_width;
			bool line = false;/** controlling the situation that number of circles like this per lines n + n-1 + n ... **/
			bool enter = true;/** first check of entering the loop **/

			double current_lenght = 0.0; /** Current usage of height of rectangle**/
			int totalCircles_triangular = 0;
			int i = 0;
			int pattern_type = 1; /** 1 means rectangular, 0 means triangular **/
			int column_to_print = 0;/** Column number to print for triangular pattern **/

			if(2*s_radius > c_height)
				enter = false;

			/** Determining the which pattern style prints more circles **/
			while(current_lenght<=c_height && enter)
			{
				if(i%2==0){
					if(current_lenght + sqrt(3)*s_radius <= c_height){
						column_to_print++;
						totalCircles_triangular += numOfCircles_width;
					}
				}
				else{
					if(current_lenght + s_radius*sqrt(3) <= c_height){
						column_to_print++;
						if(c_width - ((numOfCircles_width-1)*2*s_radius+s_radius) >= 2*s_radius)
							totalCircles_triangular += numOfCircles_width;
						else{
							totalCircles_triangular += numOfCircles_width-1;
							line=true;
						}				
					}		
				}	
				if(i==0)
					current_lenght+=2*s_radius;
				else
					current_lenght+=s_radius*sqrt(3);
				++i;
			}
			/** Determining the which pattern style prints more circles **/

			if(totalCircles_triangular>totalCircles_rectangular)
				pattern_type = 0;
			/* # Creating the svg file block ..**/
			double starting_cx,starting_cy;/** Starting Points for printing **/
			double cx,cy;
			starting_cx = static_cast<double>(c_width / (numOfCircles_width*2));
			starting_cy = static_cast<double>(c_height / (numOfCircles_height*2));
			(*acces_small).set_cy(starting_cy);
			(*acces_small).set_cx(starting_cx);

			numOfCircles_height = column_to_print;

			circle tmp_circle;
			tmp_circle.set_radius(s_radius);
			/* RECTANGULAR PATTERN */
			if(pattern_type==1){
				cy=starting_cy;
				tmp_circle.set_cy(cy);
				for (int i = 0; i < numOfCircles_height; ++i)
				{	
				 	cx=starting_cx;
				 	tmp_circle.set_cy(cy);
				 	for (int j = 0; j < numOfCircles_width; ++j)
				 	{	
				 		tmp_circle.set_cx(cx);
				 		if(!(i==0 && j==0))/** Avoid the first element pushing, since its comes from constructor **/
		 					*this += tmp_circle;/** push object into vector **/
				 		cx+=2*s_radius;
				 	}
				 	cy+=2*s_radius;
				}	tmp_circle.set_cy(cy);
			}
			/* RECTANGULAR PATTERN */
			/*                     */
			/* TRIANGULAR PATTERN */
			else if(pattern_type==0){
				cy=starting_cy;
				tmp_circle.set_cy(cy);
				for (int i = 0; i < numOfCircles_height; ++i)
				{	
					if(i%2==0)
				 		cx=starting_cx;
				 	else	
			 			cx=starting_cx + s_radius;
				 	for (int j = 0; j < numOfCircles_width; ++j)
				 	{	
				 		tmp_circle.set_cx(cx);
				 		if(!(i==0 && j==0))/** Avoid the first element pushing, since its comes from constructor **/
			 				*this += tmp_circle;/** push object into vector **/
				 		cx+=2*s_radius;
				 		if(line==true && j==numOfCircles_width-2 && i%2!=0)
				 			break;
				 	}		 	
			 		cy+=s_radius*sqrt(3);
			 		tmp_circle.set_cy(cy);
				}
			}
			/* TRIANGULAR PATTERN */

		}

		else if(small_shapes[0].type==t)
		{
			triangle* acces_small = static_cast<triangle*>(small_shapes[0].shp_ptr);
			rectangle* acces_container = static_cast<rectangle*>(big_shp_ptr);

			double triangle_height;
			triangle_height = (sqrt(3)*(*acces_small).get_tri_edge())/2.0; 

			int numOfTriangles_width = static_cast<int>((*acces_container).get_width() / (*acces_small).get_tri_edge()) + static_cast<int>(((*acces_container).get_width()-(*acces_small).get_tri_edge()/2.0)/(*acces_small).get_tri_edge());
			int numOfTriangles_height = static_cast<int>((*acces_container).get_height() / triangle_height);

			double cr1[2],cr2[2],up_corner[2],down_corner[2];/** Array variables control the corners of triangle **/
			double tri_edge = (*acces_small).get_tri_edge();
			double cr_height = sqrt(3)*tri_edge/2.0;

			/** 1st element of small shapes vector initializaton **/
			cr1[0] = 0.0;
			cr1[1] = cr_height;
			cr2[0] = tri_edge/2.0;
			cr2[1] = cr_height - sqrt(3)*tri_edge/2.0;
			up_corner[0] = tri_edge;
			up_corner[1] = cr_height;
			(*acces_small).set_cr1(cr1);
			(*acces_small).set_cr2(cr2);
			(*acces_small).set_cr3(up_corner);

			triangle tmp_tri;
			for (int i = 0; i < numOfTriangles_height; ++i)
			{	
				/** Restarting the corners **/
				cr1[0] = 0.0;
				cr1[1] = cr_height;
				cr2[0] = tri_edge/2.0;
				cr2[1] = cr_height - sqrt(3)*tri_edge/2.0;
				up_corner[0] = tri_edge;
				up_corner[1] = cr_height;
				down_corner[0] = tri_edge / 2.0 + tri_edge;
				down_corner[1] = cr_height - sqrt(3)*tri_edge/2.0;

				for (int j = 0; j < numOfTriangles_width; ++j)
				{	
					tmp_tri.set_cr1(cr1);
					tmp_tri.set_cr2(cr2);			
					swap_corners(cr1,cr2);/** Copy the cr2 to --> cr1 array. **/
					/** Normal and Reverse Triangles depens on this **/
					if(j%2==0){
						tmp_tri.set_cr3(up_corner);
						swap_corners(cr2,up_corner);
						up_corner[0] += tri_edge;
						up_corner[1] = cr_height;
					}
					else{
						tmp_tri.set_cr3(down_corner);
						swap_corners(cr2,down_corner);
						down_corner[0] += tri_edge;
						down_corner[1] = up_corner[1] - sqrt(3)*tri_edge/2.0; 
					}
					if(!(i==0 && j==0))/** Avoid the first element pushing, since its already in vector from constructor **/
						*this += tmp_tri;			
				}
				cr_height+=sqrt(3)*tri_edge/2.0;/** Usage of height of rectangle **/
			}
							
		}
	}

	if(big_type==1)
	{
		if(small_shapes[0].type==r)
		{	
			rectangle* acces_small = static_cast<rectangle*>(small_shapes[0].shp_ptr);
			triangle* acces_container = static_cast<triangle*>(big_shp_ptr);

			double c_tri_edge = (*acces_container).get_tri_edge();
			double s_height = (*acces_small).get_height();

			double tri_height = (sqrt(3)*c_tri_edge)/2.0;
			double minus_height = s_height;	/** Reduction amount of triangles height per step **/
			double s_width = (*acces_small).get_width();
			double new_width = c_tri_edge;	/** Reduction amount of base of triangle per step **/

			int numOfRects_width = static_cast<int>((((tri_height - minus_height) * c_tri_edge) / tri_height) / s_width);
			int numOfRects_height = static_cast<int>(tri_height / s_height);

			double starting_cx,starting_cy,cx,cy,old_cx;	/** Starting points for printing **/
			starting_cx = (s_height*c_tri_edge/2.0) / tri_height;
			starting_cy = tri_height - s_height;
			cx = starting_cx;
			cy = starting_cy;
			(*acces_small).set_cx(cx);
			(*acces_small).set_cy(cy);
	
			rectangle tmp_rect;
			tmp_rect.set_height(s_height);
			tmp_rect.set_width(s_width);
			tmp_rect.set_cy(cy);
			for (int i = 0; i < numOfRects_height; ++i)
			{	
				old_cx = cx;
				for (int j = 0; j < numOfRects_width; ++j)
				{			
					tmp_rect.set_cx(cx);
					if(!(i==0 && j==0))/** Avoid the first element pushing, since its already in vector from constructor **/
						*this += tmp_rect;	
					cx+=s_width;		
				}

				minus_height += s_height;
				new_width = ((tri_height - minus_height) * c_tri_edge) / tri_height;
				numOfRects_width = static_cast<int>(new_width / s_width);

				cy -= s_height;
				cx = old_cx + starting_cx;
				tmp_rect.set_cy(cy);
			}
		}
		else if(small_shapes[0].type==c)
		{	
			circle* acces_small = static_cast<circle*>(small_shapes[0].shp_ptr);
			triangle* acces_container = static_cast<triangle*>(big_shp_ptr);

			double c_tri_edge = (*acces_container).get_tri_edge();
			double s_radius = (*acces_small).get_radius();

			double tri_height;
			tri_height = (sqrt(3)*c_tri_edge)/2.0; 
			int numOfCircles_height = static_cast<int>(tri_height / (sqrt(3)*s_radius));

			double starting_cx,starting_cy,cx,cy,old_cx;
			double max_width = c_tri_edge - sqrt(3)*s_radius;/** Maximum printig area per lines **/

			/** Starting points for printing **/
			starting_cx = sqrt(3)*s_radius;
			starting_cy = tri_height - 2*s_radius + s_radius;
			cx = starting_cx;
			cy = starting_cy;
			(*acces_small).set_cx(cx);
			(*acces_small).set_cy(cy);
			/** Starting points for printing **/
			circle tmp_circle;
			tmp_circle.set_radius(s_radius);
			tmp_circle.set_cy(cy);
			for (int i = 0; i < numOfCircles_height; ++i)
			{	
				old_cx = cx;
				for (int j = 0; cx <= max_width; ++j)
				{		
					tmp_circle.set_cx(cx);
					if(!(i==0 && j==0))/** Avoid the first element pushing, since its already in vector from constructor **/
						*this += tmp_circle;/** push updated object into small shape vector **/
					cx+=2*s_radius;	
				}
				/** numerical updates **/	
				cy -= sqrt(3)*s_radius;
				max_width -= s_radius;
				cx = old_cx +  s_radius;
				tmp_circle.set_cy(cy);
			}
		}
		else if(small_shapes[0].type==t)
		{	
			triangle* acces_small = static_cast<triangle*>(small_shapes[0].shp_ptr);
			triangle* acces_container = static_cast<triangle*>(big_shp_ptr);

			float c_tri_edge = static_cast<float>((*acces_container).get_tri_edge());
			float s_tri_edge = static_cast<float>((*acces_small).get_tri_edge());
			double c_tri_height = (sqrt(3)*c_tri_edge)/2.0;
			double s_tri_height = (sqrt(3)*s_tri_edge)/2.0;
			/****
				# "similartiy theroem on triangles". 
			****/
			float c_new_height = c_tri_height;
			float c_new_width;
			c_new_width = ((c_tri_height - s_tri_height)*c_tri_edge) / (c_tri_height);/** New length of base of triangle **/
			double minus_width = c_tri_edge - c_new_width;
			double minus_height = 0;/** Reduicton amount of triangle height per step **/
			double add_width = 0;/** Increasing amount of triangle width(small shape) per step(inside loop) **/
			
			/** Two types of triangles **/
			int reverse_triangles = static_cast<int>(c_new_width / s_tri_edge);	
			int normal_triangles = static_cast<int>(c_tri_edge / s_tri_edge);
			/** Two types of triangles **/
			int numOfTriangles_width =  reverse_triangles + normal_triangles; /** Total triangles per line **/
			int numOfTriangles_height = static_cast<int>(c_tri_edge / s_tri_edge);
			/**************************************************************************************************/
			double cr1[2],cr2[2],up_corner[2],down_corner[2]; /** Arrays that store the corners of triangles **/

			/** Initial values of corners and first element of vector **/
			cr1[0] = 0;
			cr1[1] = c_tri_height;
			(*acces_small).set_cr1(cr1);

			cr2[0] = s_tri_edge / 2.0;
			cr2[1] = c_tri_height - s_tri_height;
			(*acces_small).set_cr2(cr2);

			up_corner[0] = s_tri_edge;
			up_corner[1] = c_tri_height;
			(*acces_small).set_cr3(up_corner);

			down_corner[0] = s_tri_edge + s_tri_edge / 2.0;
			down_corner[1] = c_tri_height - s_tri_height;
			/** Initial values of corners **/
			triangle tmp_tri;
			for (int i = 0; i < numOfTriangles_height; ++i)
			{	
				/** Restarting the corners **/
				cr1[0] = add_width;
				cr1[1] = c_tri_height - minus_height;
				cr2[0] = s_tri_edge/2.0 + add_width;
				cr2[1] = c_tri_height - s_tri_height - minus_height;

				up_corner[0] = s_tri_edge + add_width;
				up_corner[1] = c_tri_height - minus_height;

				down_corner[0] = s_tri_edge / 2.0 + s_tri_edge + add_width;
				down_corner[1] = c_tri_height - minus_height- s_tri_height;
			
				for (int j = 0; j < numOfTriangles_width; ++j)
				{				
					tmp_tri.set_cr1(cr1);/** update the object **/
					tmp_tri.set_cr2(cr2);
					swap_corners(cr1,cr2);
					/** Normal and Reverse Triangles depens on this **/
					if(j%2==0){
						tmp_tri.set_cr3(up_corner);/** update the object **/
						swap_corners(cr2,up_corner);
						up_corner[0] += s_tri_edge;
						up_corner[1] = c_new_height;
					}
					else{
						tmp_tri.set_cr3(down_corner);/** update the object **/
						swap_corners(cr2,down_corner);
						down_corner[0] += s_tri_edge;
						down_corner[1] = up_corner[1] - sqrt(3)*s_tri_edge/2.0; 
					}
					/** Normal and Reverse Triangles depens on this **/
					if(!(i==0 && j==0))/** Avoid the first element pushing, since its already in vector from constructor **/
						*this += tmp_tri;/** Push updated object to vector **/		
				}
				
				/** numerical updates **/
				c_new_height -= s_tri_height;
				c_new_width -=minus_width;
				normal_triangles = reverse_triangles;
				reverse_triangles = static_cast<int>(c_new_width / s_tri_edge);
				numOfTriangles_width = normal_triangles + reverse_triangles;

				minus_height+=s_tri_height;
				add_width+=s_tri_edge / 2.0;
			}
		}
	}
}