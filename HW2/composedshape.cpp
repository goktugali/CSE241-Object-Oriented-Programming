#include "composedshape.h"

composedshape::composedshape(rectangle container_val,rectangle small_val){	
	container_rectangle=container_val;
	small_rectangle.push_back(small_val);
}
composedshape::composedshape(rectangle container_val,circle small_val){
	container_rectangle=container_val;
	small_circle.push_back(small_val);
}
composedshape::composedshape(rectangle container_val,triangle small_val){
	container_rectangle=container_val;
	small_triangle.push_back(small_val);
}
composedshape::composedshape(triangle container_val,triangle small_val){
	container_triangle=container_val;
	small_triangle.push_back(small_val);
}
composedshape::composedshape(triangle container_val,circle small_val){
	container_triangle=container_val;
	small_circle.push_back(small_val);
}
composedshape::composedshape(triangle container_val,rectangle small_val){
	container_triangle=container_val;
	small_rectangle.push_back(small_val);
}
void composedshape::optimalFit(rectangle container, rectangle small){

	int numOfRects_width = static_cast<int>(container.get_width() / small.get_width());
	int numOfRects_height = static_cast<int>(container.get_height() / small.get_height());

	double starting_cx = 0.0;
	double starting_cy = 0.0;
	double cx,cy;

	small_rectangle[0].set_cx(0);
	small_rectangle[0].set_cy(0);

	/** Filling the vector **/
	cy=starting_cy;
	small.set_cy(cy);
	for (int i = 0; i < numOfRects_height; ++i)
	{	
 		cx=starting_cx;
 		small.set_cx(cx);
	 	for (int j = 0; j < numOfRects_width; ++j)
	 	{	
	 		if(!(i==0 && j==0))/** Avoid the first element pushing, since its already in vector from constructor **/
	 			small_rectangle.push_back(small);
	 		cx+=small.get_width();
	 		small.set_cx(cx);		
	 	}
	 	cy+=small.get_height();
	 	small.set_cy(cy);
	}
	/** Filling the vector **/
}

void composedshape::optimalFit(rectangle container,triangle small){

	double triangle_height;
	triangle_height = (sqrt(3)*small.get_tri_edge())/2.0; 

	int numOfTriangles_width = static_cast<int>(container.get_width() / small.get_tri_edge()) + static_cast<int>((container.get_width()-small.get_tri_edge()/2.0)/small.get_tri_edge());
	int numOfTriangles_height = static_cast<int>(container.get_height() / triangle_height);

	double cr1[2],cr2[2],up_corner[2],down_corner[2];/** Array variables control the corners of triangle **/
	double tri_edge = small.get_tri_edge();
	double cr_height = sqrt(3)*tri_edge/2.0;

	/** 1st element of small shapes vector initializaton **/
	cr1[0] = 0.0;
	cr1[1] = cr_height;
	cr2[0] = tri_edge/2.0;
	cr2[1] = cr_height - sqrt(3)*tri_edge/2.0;
	up_corner[0] = tri_edge;
	up_corner[1] = cr_height;
	small_triangle[0].set_cr1(cr1);
	small_triangle[0].set_cr2(cr2);
	small_triangle[0].set_cr3(up_corner);

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
			small.set_cr1(cr1);
			small.set_cr2(cr2);
			swap_corners(cr1,cr2);/** Copy the cr2 to --> cr1 array. **/
			/** Normal and Reverse Triangles depens on this **/
			if(j%2==0){

				small.set_cr3(up_corner);
				swap_corners(cr2,up_corner);
				up_corner[0] += tri_edge;
				up_corner[1] = cr_height;
			}
			else{
				small.set_cr3(down_corner);
				swap_corners(cr2,down_corner);
				down_corner[0] += tri_edge;
				down_corner[1] = up_corner[1] - sqrt(3)*tri_edge/2.0; 
			}
			if(!(i==0 && j==0))/** Avoid the first element pushing, since its already in vector from constructor **/
				small_triangle.push_back(small);
			
		}
		cr_height+=sqrt(3)*tri_edge/2.0;/** Usage of height of rectangle **/
	}
}

void composedshape::optimalFit(rectangle container, circle small){

	double c_width = container.get_width();
	double c_height = container.get_height();
	double s_radius = small.get_radius();
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

	/** Determining the which pattern style prints more circles **/

	/* # Creating the svg file block ..**/
	double starting_cx,starting_cy;/** Starting Points for printing **/
	double cx,cy;
	starting_cx = static_cast<double>(c_width / (numOfCircles_width*2));
	starting_cy = static_cast<double>(c_height / (numOfCircles_height*2));
	small_circle[0].set_cy(starting_cy);
	small_circle[0].set_cx(starting_cx);

	numOfCircles_height = column_to_print;

	/* RECTANGULAR PATTERN */
	if(pattern_type==1){
		
		cy=starting_cy;
		small.set_cy(cy);
		for (int i = 0; i < numOfCircles_height; ++i)
		{	
		 	cx=starting_cx;
		 	small.set_cx(cx);
		 	for (int j = 0; j < numOfCircles_width; ++j)
		 	{
		 		if(!(i==0 && j==0))/** Avoid the first element pushing, since its comes from constructor **/
 					small_circle.push_back(small);/** push object into vector **/
		 		cx+=2*s_radius;
		 		small.set_cx(cx);
		 	}
		 	cy+=2*s_radius;
		 	small.set_cy(cy);
		}	
	}
	/* RECTANGULAR PATTERN */
	/*                     */
	/* TRIANGULAR PATTERN */
	else if(pattern_type==0){
		cy=starting_cy;
		small.set_cy(cy);
		for (int i = 0; i < numOfCircles_height; ++i)
		{	
			if(i%2==0)
		 		cx=starting_cx;
		 	else	
	 			cx=starting_cx + s_radius;
	 		small.set_cx(cx);
		 	for (int j = 0; j < numOfCircles_width; ++j)
		 	{	
		 		if(!(i==0 && j==0))/** Avoid the first element pushing, since its comes from constructor **/
	 				small_circle.push_back(small);/** push object into vector **/
		 		cx+=2*s_radius;
		 		small.set_cx(cx);
		 		if(line==true && j==numOfCircles_width-2 && i%2!=0)
		 			break;
		 	}		 	
	 		cy+=s_radius*sqrt(3);
	 		small.set_cy(cy);
		}
	}
	/* TRIANGULAR PATTERN */
}

void composedshape::optimalFit(triangle container,rectangle small){

	double c_tri_edge = container.get_tri_edge();
	double s_height = small.get_height();

	double tri_height = (sqrt(3)*c_tri_edge)/2.0;
	double minus_height = s_height;	/** Reduction amount of triangles height per step **/
	double s_width = small.get_width();
	double new_width = c_tri_edge;	/** Reduction amount of base of triangle per step **/

	int numOfRects_width = static_cast<int>((((tri_height - minus_height) * c_tri_edge) / tri_height) / s_width);
	int numOfRects_height = static_cast<int>(tri_height / s_height);

	double starting_cx,starting_cy,cx,cy,old_cx;	/** Starting points for printing **/
	starting_cx = (s_height*c_tri_edge/2.0) / tri_height;
	starting_cy = tri_height - s_height;
	cx = starting_cx;
	cy = starting_cy;
	small_rectangle[0].set_cx(cx);
	small_rectangle[0].set_cy(cy);
	small.set_cy(cy);
	small.set_cx(cx);

	for (int i = 0; i < numOfRects_height; ++i)
	{	
		old_cx = cx;
		for (int j = 0; j < numOfRects_width; ++j)
		{	
			if(!(i==0 && j==0))/** Avoid the first element pushing, since its already in vector from constructor **/
				small_rectangle.push_back(small);	
			cx+=s_width;
			small.set_cx(cx);
		}

		minus_height += s_height;
		new_width = ((tri_height - minus_height) * c_tri_edge) / tri_height;
		numOfRects_width = static_cast<int>(new_width / s_width);

		cy -= s_height;
		cx = old_cx + starting_cx;
		small.set_cy(cy);
		small.set_cx(cx);
	}
}

void composedshape::optimalFit(triangle container, circle small){

	double c_tri_edge = container.get_tri_edge();
	double s_radius = small.get_radius();

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
	small_circle[0].set_cx(cx);
	small_circle[0].set_cy(cy);
	/** Starting points for printing **/
	small.set_cy(cy);
	small.set_cx(cx);
	for (int i = 0; i < numOfCircles_height; ++i)
	{	
		old_cx = cx;
		for (int j = 0; cx <= max_width; ++j)
		{	
			if(!(i==0 && j==0))/** Avoid the first element pushing, since its already in vector from constructor **/
				small_circle.push_back(small);/** push updated object into small shape vector **/
			cx+=2*s_radius;
			small.set_cx(cx);
		}
		/** numerical updates **/	
		cy -= sqrt(3)*s_radius;
		max_width -= s_radius;
		cx = old_cx +  s_radius;
		/** Update the object **/
		small.set_cy(cy);
		small.set_cx(cx);
	}

}
void composedshape::optimalFit(triangle container, triangle small){

	float c_tri_edge = static_cast<float>(container.get_tri_edge());
	float s_tri_edge = static_cast<float>(small.get_tri_edge());
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
	small.set_cr1(cr1);
	small_triangle[0].set_cr1(cr1);

	cr2[0] = s_tri_edge / 2.0;
	cr2[1] = c_tri_height - s_tri_height;
	small.set_cr2(cr2);
	small_triangle[0].set_cr2(cr2);

	up_corner[0] = s_tri_edge;
	up_corner[1] = c_tri_height;
	small.set_cr3(up_corner);
	small_triangle[0].set_cr3(up_corner);

	down_corner[0] = s_tri_edge + s_tri_edge / 2.0;
	down_corner[1] = c_tri_height - s_tri_height;
	/** Initial values of corners **/
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
			small.set_cr1(cr1);/** update the object **/
			small.set_cr2(cr2);
			swap_corners(cr1,cr2);
			/** Normal and Reverse Triangles depens on this **/
			if(j%2==0){
				small.set_cr3(up_corner);/** update the object **/
				swap_corners(cr2,up_corner);
				up_corner[0] += s_tri_edge;
				up_corner[1] = c_new_height;
			}
			else{
				small.set_cr3(down_corner);/** update the object **/
				swap_corners(cr2,down_corner);
				down_corner[0] += s_tri_edge;
				down_corner[1] = up_corner[1] - sqrt(3)*s_tri_edge/2.0; 
			}
			/** Normal and Reverse Triangles depens on this **/
			if(!(i==0 && j==0))/** Avoid the first element pushing, since its already in vector from constructor **/
				small_triangle.push_back(small);/** Push updated object to vector **/		
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

void composedshape::draw(ofstream& file,triangle container,vector<rectangle> small_rectangle){

	int numOfSmallShapes = small_rectangle.size();
	print_body(file);

	container.draw(file,"red");
	for (int i = 0; i < numOfSmallShapes; ++i)
		small_rectangle[i].draw(file,"green");
	file << "</svg>" << endl;
}
void composedshape::draw(ofstream& file,triangle container,vector<circle> small_circle){

	int numOfSmallShapes = small_circle.size();
	print_body(file);

	container.draw(file,"red");
	for (int i = 0; i < numOfSmallShapes; ++i)
		small_circle[i].draw(file,"green");
	file << "</svg>" << endl;
}

void composedshape::draw(ofstream& file, triangle container,vector<triangle> small_triangle){
	int numOfSmallShapes = small_triangle.size();
	print_body(file);

	container.draw(file,"red");
	for (int i = 0; i < numOfSmallShapes; ++i)
		small_triangle[i].draw(file,"green");
	file << "</svg>" << endl;

}
void composedshape::draw(ofstream& file,rectangle container, vector<rectangle> small_rectangle){

	int numOfSmallShapes = small_rectangle.size();
	print_body(file);

	container.draw(file,"red");
	for (int i = 0; i < numOfSmallShapes; ++i)
		small_rectangle[i].draw(file,"green");
	file << "</svg>" << endl;
}

void composedshape::draw(ofstream& file,rectangle container,vector<circle> small_circle){
	int numOfSmallShapes = small_circle.size();
	print_body(file);

	container.draw(file,"red");
	for (int i = 0; i < numOfSmallShapes; ++i)
		small_circle[i].draw(file,"green");
	file << "</svg>" << endl;
}
void composedshape::draw(ofstream& file,rectangle container,vector<triangle> small_triangle){

	int numOfSmallShapes = small_triangle.size();
	print_body(file);

	container.draw(file,"red");
	for (int i = 0; i < numOfSmallShapes; ++i)
		small_triangle[i].draw(file,"green");
	file << "</svg>" << endl;
}
vector<rectangle> composedshape::get_rectangle_vect(){
	return small_rectangle;
}
vector<triangle> composedshape::get_triangle_vect(){
	return small_triangle;
}
vector<circle> composedshape::get_circle_vect(){
	return small_circle;
}