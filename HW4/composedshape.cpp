#include "composedshape.h"

namespace gtuComposedShape
{	
	/* explaining constructors :
  	----------------------------
	 * First, pushes container and small shape object into vector.
	 1st element is the container shape, 2nd is the first of small ones.
	 * Then sets the color for container printing to the file.
	 */
	composedshape::composedshape(const gtuShapes::rectangle& container,const gtuShapes::rectangle& small)
	{	
		_mainshape.push_back(gtuPolygon::polygon(container));
		_mainshape.push_back(gtuPolygon::polygon(small));
		_mainshape[0].setColor("red");	
	}
	composedshape::composedshape(const gtuShapes::rectangle& container,const gtuShapes::circle& small)
	{	
		_mainshape.push_back(gtuPolygon::polygon(container));
		_mainshape.push_back(gtuPolygon::polygon(small));
		_mainshape[0].setColor("red");	
	}
	composedshape::composedshape(const gtuShapes::rectangle& container,const gtuShapes::triangle& small)
	{	
		_mainshape.push_back(gtuPolygon::polygon(container));
		_mainshape.push_back(gtuPolygon::polygon(small));
		_mainshape[0].setColor("red");
	}
	composedshape::composedshape(const gtuShapes::triangle& container,const gtuShapes::rectangle& small)
	{	
		_mainshape.push_back(gtuPolygon::polygon(container));
		_mainshape.push_back(gtuPolygon::polygon(small));
		_mainshape[0].setColor("red");
	}
	composedshape::composedshape(const gtuShapes::triangle& container,const gtuShapes::circle& small)
	{	
		_mainshape.push_back(gtuPolygon::polygon(container));
		_mainshape.push_back(gtuPolygon::polygon(small));
		_mainshape[0].setColor("red");
	}
	composedshape::composedshape(const gtuShapes::triangle& container,const gtuShapes::triangle& small)
	{	
		_mainshape.push_back(gtuPolygon::polygon(container));
		_mainshape.push_back(gtuPolygon::polygon(small));
		_mainshape[0].setColor("red");
	}
	std::ostream& operator<<(std::ostream& outputStream,const composedshape& shape)
	{	
		outputStream << "<svg version=\"1.1\"" << std::endl
					<< "baseProfile=\"full\"" << std::endl
					<< "xmlns=\"http://www.w3.org/2000/svg\">" << std::endl;
		outputStream << shape[0];//Print the big shape
		for (int i = 1; i < shape.get_size_shape(); ++i)
			outputStream << shape[i];//Print the small shapes
		outputStream << "</svg>" << std::endl;

		return outputStream;
	}
	const gtuPolygon::polygon& composedshape::operator[](int index)const
	{	
		return _mainshape[index];	
	}
	gtuPolygon::polygon& composedshape::operator[](int index)
	{	
		return _mainshape[index];	
	}
	const composedshape& composedshape::operator+=(const gtuPolygon::polygon& p1)
	{
		_mainshape.push_back(p1);
		return *this;	
	}

	/******		 optimal fit functions 		*****/
	void composedshape::optimalFit(const gtuShapes::rectangle& container, const gtuShapes::rectangle& small)
	{			
		double container_width = container.get_width();
		double container_height = container.get_height();
		
		double small_width = small.get_width();
		double small_height = small.get_height();

		int numOfRects_width = static_cast<int>(container_width / small_width);
		int numOfRects_height = static_cast<int>(container_height / small_height);			
		double cx,cy;
		gtuShapes::rectangle tmp_rect(small_height,small_width,0,0);

		for (int i = 0; i < numOfRects_height; ++i)
		{	
			cx=0.0;
			for (int j = 0; j < numOfRects_width; ++j)
			{	
				tmp_rect.set_cx(cx);
				if(!(i==0 && j==0))
					*this += tmp_rect;/** I add myself a new shape object **/
						/** this += opr works by polygon(rectangle) constructor
							automatically converted (non-explicit) **/
				cx+=small_width;
			}
			cy+=small_height;
			tmp_rect.set_cy(cy);
		}		
	}
	void composedshape::optimalFit(const gtuShapes::rectangle& container, const gtuShapes::circle& small)
	{
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
		/* # Creating the svg file block ..**/
		double starting_cx,starting_cy;/** Starting Points for printing **/
		double cx,cy;
		starting_cx = static_cast<double>(c_width / (numOfCircles_width*2));
		starting_cy = static_cast<double>(c_height / (numOfCircles_height*2));

		numOfCircles_height = column_to_print;

		gtuShapes::circle tmp_circle(s_radius);
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
			}
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
	void composedshape::optimalFit(const gtuShapes::rectangle& container, const gtuShapes::triangle& small)
	{
		double container_width = container.get_width();
		double container_height = container.get_height();

		double tri_edge = small.get_tri_edge();
		double cr_height = sqrt(3)*tri_edge/2.0; 

		int numOfTriangles_width = static_cast<int>(container_width / tri_edge) + static_cast<int>((container_width - (tri_edge/2.0))/tri_edge);
		int numOfTriangles_height = static_cast<int>(container_height / cr_height);
		double cr1[2],cr2[2],up_corner[2],down_corner[2];/** Array variables control the corners of triangle **/
		
		gtuShapes::triangle tmp_tri(tri_edge);
		for (int i = 0; i < numOfTriangles_height; ++i)
		{	
			/** Restarting the corners **/
			cr1[0] = 0.0;
			cr1[1] = cr_height;
			cr2[0] = tri_edge/2.0;
			cr2[1] = cr_height - 1.73*tri_edge/2.0;
			up_corner[0] = tri_edge;
			up_corner[1] = cr_height;
			down_corner[0] = tri_edge / 2.0 + tri_edge;
			down_corner[1] = cr_height - 1.73*tri_edge/2.0;

			for (int j = 0; j < numOfTriangles_width; ++j)
			{	
				tmp_tri.set_cr1(cr1);
				tmp_tri.set_cr2(cr2);			
				/** Copy the cr2 to --> cr1 array. **/
				cr1[0] = cr2[0];
				cr1[1] = cr2[1];
				/** Normal and Reverse Triangles depens on this **/
				if(j%2==0){
					tmp_tri.set_cr3(up_corner);
					cr2[0]=up_corner[0];
					cr2[1]=up_corner[1];
					up_corner[0] += tri_edge;
					up_corner[1] = cr_height;
				}
				else{
					tmp_tri.set_cr3(down_corner);
					cr2[0]=down_corner[0];
					cr2[1]=down_corner[1];
					down_corner[0] += tri_edge;
					down_corner[1] = up_corner[1] - 1.73*tri_edge/2.0; 
				}
				if(!(i==0 && j==0))/** Avoid the first element pushing, since its already in vector from constructor **/
					*this += tmp_tri;			
			}
			cr_height+=1.73*tri_edge/2.0;/** Usage of height of rectangle **/
		}					
	}
	void composedshape::optimalFit(const gtuShapes::triangle& container, const gtuShapes::triangle& small)
	{
		float c_tri_edge = container.get_tri_edge();
		float s_tri_edge = small.get_tri_edge();
		double c_tri_height = (1.73*c_tri_edge)/2.0;
		double s_tri_height = (sqrt(3)*s_tri_edge)/2.0;
		/****
			# "similartiy theroem on triangles". 
		****/
		float c_new_height = c_tri_height;
		float c_new_width = ((c_tri_height - s_tri_height)*c_tri_edge) / (c_tri_height);/** New length of base of triangle **/
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

		cr2[0] = s_tri_edge / 2.0;
		cr2[1] = c_tri_height - s_tri_height;

		up_corner[0] = s_tri_edge;
		up_corner[1] = c_tri_height;

		down_corner[0] = s_tri_edge + s_tri_edge / 2.0;
		down_corner[1] = c_tri_height - s_tri_height;
		/** initalizing first small shape **/
		_mainshape[1][0].set_points(cr1[0],cr1[1]);
		_mainshape[1][1].set_points(cr2[0],cr2[1]);
		_mainshape[1][2].set_points(up_corner[0],up_corner[1]);
		/** Initial values of corners **/
		gtuShapes::triangle tmp_tri;
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
				cr1[0] = cr2[0];
				cr1[1] = cr2[1];
				/** Normal and Reverse Triangles depens on this **/
				if(j%2==0){
					tmp_tri.set_cr3(up_corner);/** update the object **/
					
					cr2[0]=up_corner[0];
					cr2[1]=up_corner[1];
					up_corner[0] += s_tri_edge;
					up_corner[1] = c_new_height;
				}
				else{
					tmp_tri.set_cr3(down_corner);/** update the object **/
					
					cr2[0]=down_corner[0];
					cr2[1]=down_corner[1];
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
	void composedshape::optimalFit(const gtuShapes::triangle& container, const gtuShapes::circle& small)
	{
		double c_tri_edge = container.get_tri_edge();
		double s_radius = small.get_radius();

		double tri_height = (sqrt(3)*c_tri_edge)/2.0; 
		int numOfCircles_height = static_cast<int>(tri_height / (sqrt(3)*s_radius));

		double starting_cx,starting_cy,cx,cy,old_cx;
		double max_width = c_tri_edge - sqrt(3)*s_radius;/** Maximum printig area per lines **/

		/** Starting points for printing **/
		starting_cx = sqrt(3)*s_radius;
		starting_cy = tri_height - 2*s_radius + s_radius;
		cx = starting_cx;
		cy = starting_cy;

		double angle = 0;
		for (int i = 0; i < 100; ++i)
		{	
			_mainshape[1][i].set_points(small.get_radius()*cos(angle)+cx,small.get_radius()*sin(angle)+cy);
			angle+=3.6*(3.14159/180);
		}
		
		/** Starting points for printing **/
		gtuShapes::circle tmp_circle;
		tmp_circle.set_radius(s_radius);
		tmp_circle.set_cy(cy);
		for (int i = 0; i < numOfCircles_height; ++i)
		{	
			old_cx = cx;
			tmp_circle.set_cy(cy);
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
		}
	}
	void composedshape::optimalFit(const gtuShapes::triangle& container, const gtuShapes::rectangle& small)
	{
		double c_tri_edge = container.get_tri_edge();
		double s_height = small.get_height();
		double s_width = small.get_width();

		double tri_height = (sqrt(3)*c_tri_edge)/2.0;
		double minus_height = s_height;	/** Reduction amount of triangles height per step **/
		double new_width = c_tri_edge;	/** Reduction amount of base of triangle per step **/

		int numOfRects_width = static_cast<int>((((tri_height - minus_height) * c_tri_edge) / tri_height) / s_width);
		int numOfRects_height = static_cast<int>(tri_height / s_height);

		/** Starting points for printing **/
		double starting_cx,starting_cy,cx,cy,old_cx;	
		starting_cx = (s_height*c_tri_edge/2.0) / tri_height;
		starting_cy = tri_height - s_height;
		cx = starting_cx;
		cy = starting_cy;
		_mainshape[1][0].set_points(cx,cy);
		_mainshape[1][1].set_points(cx+s_width,cy);
		_mainshape[1][2].set_points(cx+s_width,cy+s_height);
		_mainshape[1][3].set_points(cx,cy+s_height);

		gtuShapes::rectangle tmp_rect;
		tmp_rect.set_height(s_height);
		tmp_rect.set_width(s_width);
		for (int i = 0; i < numOfRects_height; ++i)
		{	
			tmp_rect.set_cy(cy);
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
		}		
	}
}
