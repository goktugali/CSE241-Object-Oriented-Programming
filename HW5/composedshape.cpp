#include "composedshape.h"

namespace gtuComposedShape
{	
composedshape::composedshape(const shape* container,const shape* small)throw(invalidptr)
{	
	const rectangle* c_rectptr = dynamic_cast<const rectangle*>(container);
	const triangle* c_triptr = dynamic_cast<const triangle*>(container);

	const triangle* s_triptr = dynamic_cast<const triangle*>(small);
	const rectangle* s_rectptr = dynamic_cast<const rectangle*>(small);
	const circle* s_circptr = dynamic_cast<const circle*>(small);

	if(c_rectptr != nullptr && s_rectptr!=nullptr){
		rectangle * pass = new rectangle(*c_rectptr);
		_mainshape.push_back(pass);
		rectangle* pass1 = new rectangle(*s_rectptr);
		_mainshape.push_back(pass1);
	}
	else if(c_rectptr != nullptr && s_triptr!=nullptr){
		rectangle * pass = new rectangle(*c_rectptr);
		_mainshape.push_back(pass);
		triangle* pass1 = new triangle(*s_triptr);
		_mainshape.push_back(pass1);
	}
	else if(c_rectptr != nullptr && s_circptr!=nullptr){
		rectangle * pass = new rectangle(*c_rectptr);
		_mainshape.push_back(pass);
		circle* pass1 = new circle(*s_circptr);
		_mainshape.push_back(pass1);
	}
	else if(c_triptr != nullptr && s_triptr!=nullptr){
		triangle * pass = new triangle(*c_triptr);
		_mainshape.push_back(pass);
		triangle* pass1 = new triangle(*s_triptr);
		_mainshape.push_back(pass1);
	}
	else if(c_triptr != nullptr && s_rectptr!=nullptr){
		triangle * pass = new triangle(*c_triptr);
		_mainshape.push_back(pass);
		rectangle* pass1 = new rectangle(*s_rectptr);
		_mainshape.push_back(pass1);
	}
	else if(c_triptr != nullptr && s_circptr!=nullptr){
		triangle * pass = new triangle(*c_triptr);
		_mainshape.push_back(pass);
		circle* pass1 = new circle(*s_circptr);
		_mainshape.push_back(pass1);
	}
	else{
		throw invalidptr();
	}

	optimalFit(); /* by this call when a composedshape object created, it fits automatically */
					/* please comment this call if you want run it explicilty */
}
composedshape::~composedshape()
{	
	for (unsigned int i = 0; i < _mainshape.size(); ++i)
		delete _mainshape[i];
	_mainshape.clear();
		
}
composedshape& composedshape::operator=(const composedshape& other)
{
	if (this==&other)
		return *this;
	else
	{
		for (unsigned int i = 0; i < _mainshape.size(); ++i)
			delete _mainshape[i];
		
		rectangle * assingrect;
		rectangle * passrect;
		triangle * assingtri;
		triangle * passtri;
		circle * assingcirc;
		circle * passcirc;

		for (unsigned int i = 0; i < other._mainshape.size(); ++i)
		{	
			assingcirc = dynamic_cast<circle*>(other._mainshape[i]);
			assingrect = dynamic_cast<rectangle*>(other._mainshape[i]);
			assingtri = dynamic_cast<triangle*>(other._mainshape[i]);
			if(assingcirc!=nullptr)
			{	
				passrect = new rectangle;
				*passrect = *assingrect;
				_mainshape.push_back(passrect);
			}
			else if(assingcirc!=nullptr)
			{	
				passcirc= new circle;
				*passcirc = *assingcirc;
				_mainshape.push_back(passcirc);
			}
			else if(assingtri!=nullptr)
			{	
				passtri = new triangle;
				*passtri = *assingtri;
				_mainshape.push_back(passtri);
			}
		
				
		}
	return *this;
	}
}
composedshape::composedshape(const composedshape& copy)
{	
	rectangle * assingrect;
	rectangle * passrect;
	triangle * assingtri;
	triangle * passtri;
	circle * assingcirc;
	circle * passcirc;
	for (unsigned int i = 0; i < copy._mainshape.size(); ++i)
	{
		assingcirc = dynamic_cast<circle*>(copy._mainshape[i]);
		assingrect = dynamic_cast<rectangle*>(copy._mainshape[i]);
		assingtri = dynamic_cast<triangle*>(copy._mainshape[i]);
		if(assingcirc!=nullptr)
		{	
			passrect = new rectangle;
			*passrect = *assingrect;
			_mainshape.push_back(passrect);
		}
		else if(assingcirc!=nullptr)
		{	
			passcirc= new circle;
			*passcirc = *assingcirc;
			_mainshape.push_back(passcirc);
		}
		else if(assingtri!=nullptr)
		{	
			passtri = new triangle;
			*passtri = *assingtri;
			_mainshape.push_back(passtri);
		}
	}
}
std::ostream& composedshape::print(std::ostream& outputStream)const
{
	outputStream << "<svg version=\"1.1\"" << std::endl
				<< "baseProfile=\"full\"" << std::endl
				<< "xmlns=\"http://www.w3.org/2000/svg\">" << std::endl;
	outputStream << _mainshape[0];//Print the big shape
	for (int i = 1; i < get_size_shape(); ++i)
		outputStream << _mainshape[i];//Print the small shapes
	outputStream << "</svg>" << std::endl;

	return outputStream;
}
std::ostream& operator<<(std::ostream& outputStream,const composedshape& shape){	
	return shape.print(outputStream);
}
double composedshape::area()const
{
	return _mainshape[0]->area();
}
double composedshape::perimeter()const
{
	return _mainshape[0]->perimeter();
}

const shape& composedshape::operator++()
{
	for (unsigned int i = 0; i < _mainshape.size(); ++i)
		++_mainshape[i];
	return *this;
}

const shape& composedshape::operator++(int ignore)throw(notavailable)
{
 	throw notavailable();
}

const shape& composedshape::operator--()
{
	for (unsigned int i = 0; i < _mainshape.size(); ++i)
		--_mainshape[i];
	return *this;
}
const shape& composedshape::operator--(int ignore)throw(notavailable)
{
 	throw notavailable();
}
const shape* composedshape::operator[](int index)const throw (outofrange){	
	if(index<0)
		throw outofrange();
	return (_mainshape[index]);	
}

shape* composedshape::operator[](int index)throw (outofrange){	
	if(index<0)
		throw outofrange();
	return (_mainshape[index]);	
}

const composedshape& composedshape::operator+=(shape* shptr){

	if(dynamic_cast<rectangle*>(shptr) == nullptr && dynamic_cast<triangle*>(shptr) == nullptr && dynamic_cast<circle*>(shptr) == nullptr)
		throw invalidptr();

	_mainshape.push_back(shptr);
	return *this;	
}
void composedshape::optimalFit()
{	

/* dyanmic_cast tests which of theese pointer are not null.
	pointers that are not equal null pointer shows that shapes type */ 
rectangle* c_rectptr = dynamic_cast<rectangle*>(_mainshape[0]);
triangle* c_triptr = dynamic_cast<triangle*>(_mainshape[0]);
/*circle* c_circptr = dynamic_cast<circle*>(_mainshape[0]);*/ /* dont used since not implemented */
rectangle* s_rectptr = dynamic_cast<rectangle*>(_mainshape[1]);
triangle* s_triptr = dynamic_cast<triangle*>(_mainshape[1]);
circle* s_circptr = dynamic_cast<circle*>(_mainshape[1]);

/* control theese if statements by pointers */
	if(c_rectptr!=nullptr) 
	{	
		c_rectptr->setColor("red");
		c_rectptr->set_cx(0);
		c_rectptr->set_cy(0);

		if(s_rectptr!=nullptr)
		{	
			s_rectptr->setColor("green");
			s_rectptr->set_cx(0);
			s_rectptr->set_cy(0);

			double container_width = c_rectptr->get_width();
			double container_height = c_rectptr->get_height();
			
			double small_width = s_rectptr->get_width();
			double small_height = s_rectptr->get_height();

			if(container_width<small_width || container_height<small_height)
				return;

			int numOfRects_width = static_cast<int>(container_width / small_width);
			int numOfRects_height = static_cast<int>(container_height / small_height);			
			double cx,cy;
			rectangle tmp_rect(small_height,small_width,0,0);
			tmp_rect.setColor("green");/* set inner shapes color */
			rectangle* new_rect;

			for (int i = 0; i < numOfRects_height; ++i)
			{	
				cx=0.0;
				for (int j = 0; j < numOfRects_width; ++j)
				{	
					tmp_rect.set_cx(cx);
					if(!(i==0 && j==0)){
						new_rect = new rectangle; /* alloce for new shape */
						*new_rect = tmp_rect;
						*this += new_rect;/** add pointer to shape vector **/
							
					}
					cx+=small_width;
				}
				cy+=small_height;
				tmp_rect.set_cy(cy);
			}
		}
		else if(s_circptr!=nullptr)
		{	
			s_circptr->setColor("green");
			
			double c_width = c_rectptr->get_width();
			double c_height = c_rectptr->get_height();
			double s_radius = s_circptr->get_radius();

			int numOfCircles_width = static_cast<int>(c_width / (s_radius*2));
			int numOfCircles_height = static_cast<int>(c_height / (s_radius*2));

			if(2*s_radius>c_width || 2*s_radius>c_height)
				return;

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
					if(current_lenght + 1.732*s_radius <= c_height){
						column_to_print++;
						totalCircles_triangular += numOfCircles_width;
					}
				}
				else{
					if(current_lenght + s_radius*1.732 <= c_height){
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
					current_lenght+=s_radius*1.732;
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
			s_circptr->set_cx(starting_cx);
			s_circptr->set_cy(starting_cy);

			numOfCircles_height = column_to_print;

			circle tmp_circle(s_radius);
			tmp_circle.setColor("green");
			circle* new_circ;
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
				 		if(!(i==0 && j==0)){/** Avoid the first element pushing, since its comes from constructor **/
		 					new_circ = new circle;/* alloca for new shape pointer */
		 					*new_circ=tmp_circle;
		 					*this += new_circ;/** push pointer into vector **/
				 		}
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
				 		if(!(i==0 && j==0)){/** Avoid the first element pushing, since its comes from constructor **/
			 				new_circ=new circle;
			 				*new_circ=tmp_circle;
			 				*this += new_circ;/** push object into vector **/
				 		}
				 		cx+=2*s_radius;
				 		if(line==true && j==numOfCircles_width-2 && i%2!=0)
				 			break;
				 	}		 	
			 		cy+=s_radius*1.732;
			 		tmp_circle.set_cy(cy);
				}
			}

		}
		else if (s_triptr!=nullptr)
		{	
			s_triptr->setColor("green");

			long double container_width = c_rectptr->get_width();
			long double container_height = c_rectptr->get_height();

			long double tri_edge = s_triptr->get_tri_edge();
			long double cr_height = 1.732*tri_edge/2.0; 

			int numOfTriangles_width = static_cast<int>(container_width / tri_edge) + static_cast<int>((container_width - (tri_edge/2.0))/tri_edge);
			int numOfTriangles_height = static_cast<int>(container_height / cr_height);
			long double cr1[2],cr2[2],up_corner[2],down_corner[2];/** Array variables control the corners of triangle **/
			
			triangle tmp_tri(tri_edge);
			
			tmp_tri.setColor("green");
			triangle* new_tri;
			for (int i = 0; i < numOfTriangles_height; ++i)
			{	
				/** Restarting the corners **/
				cr1[0] = 0.0;
				cr1[1] = cr_height;
				cr2[0] = tri_edge/2.0;
				cr2[1] = cr_height - 1.732*tri_edge/2.0;
				up_corner[0] = tri_edge;
				up_corner[1] = cr_height;
				down_corner[0] = tri_edge / 2.0 + tri_edge;
				down_corner[1] = cr_height - 1.732*tri_edge/2.0;

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
						down_corner[1] = up_corner[1] - 1.732*tri_edge/2.0; 
					}
					if(!(i==0 && j==0)){/** Avoid the first element pushing, since its already in vector from constructor **/
						new_tri = new triangle;
						*new_tri=tmp_tri;
						*this += new_tri;
					}			
				}
				cr_height+=1.732*tri_edge/2.0;/** Usage of height of rectangle **/
			}	
		}
	}
	else if(c_triptr!=nullptr)
	{	
		c_triptr->setColor("red");
		if(s_triptr!=nullptr)
		{	
			s_triptr->setColor("green");

			long double c_tri_edge = c_triptr->get_tri_edge();
			long double s_tri_edge = s_triptr->get_tri_edge();
			long double c_tri_height = (1.732*c_tri_edge)/2.0;
			long double s_tri_height = (1.732*s_tri_edge)/2.0;
			/****
				# "similartiy theroem on triangles". 
			****/
			long double c_new_height = c_tri_height;
			long double c_new_width = ((c_tri_height - s_tri_height)*c_tri_edge) / (c_tri_height);/** New length of base of triangle **/
			long double minus_width = c_tri_edge - c_new_width;
			long double minus_height = 0;/** Reduicton amount of triangle height per step **/
			long double add_width = 0;/** Increasing amount of triangle width(small shape) per step(inside loop) **/
			
			/** Two types of triangles **/
			int reverse_triangles = static_cast<int>(c_new_width / s_tri_edge);	
			int normal_triangles = static_cast<int>(c_tri_edge / s_tri_edge);
			/** Two types of triangles **/
			int numOfTriangles_width =  reverse_triangles + normal_triangles; /** Total triangles per line **/
			int numOfTriangles_height = static_cast<int>(c_tri_edge / s_tri_edge);
			/**************************************************************************************************/
			long double cr1[2],cr2[2],up_corner[2],down_corner[2]; /** Arrays that store the corners of triangles **/
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
			s_triptr->set_cr1(cr1);
			s_triptr->set_cr2(cr2);
			s_triptr->set_cr3(up_corner);
			/** Initial values of corners **/
			triangle tmp_tri;
			triangle* new_tri;
			tmp_tri.setColor("green");/* set inner shapes color */
			
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
						down_corner[1] = up_corner[1] - 1.732*s_tri_edge/2.0; 
					}
					/** Normal and Reverse Triangles depens on this **/
					if(!(i==0 && j==0)){/** Avoid the first element pushing, since its already in vector from constructor **/
						new_tri = new triangle;/* allocate for shape pointer */
						*new_tri = tmp_tri;
						*this += new_tri;/** Push updated pointer to vector **/		
					}
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
		else if(s_rectptr!=nullptr)
		{	
			s_rectptr->setColor("green");

			double c_tri_edge = c_triptr->get_tri_edge();
			double s_height = s_rectptr->get_height();
			double s_width = s_rectptr->get_width();

			double tri_height = (1.732*c_tri_edge)/2.0;
			double minus_height = s_height;	/** Reduction amount of triangles height per step **/
			double new_width = c_tri_edge;	/** Reduction amount of base of triangle per step **/

			int numOfRects_width = static_cast<int>((((tri_height - minus_height) * c_tri_edge) / tri_height) / s_width);
			int numOfRects_height = static_cast<int>(tri_height / s_height);
			if(numOfRects_height < 0 || numOfRects_width < 0)
				return;

			/** Starting points for printing **/
			double starting_cx,starting_cy,cx,cy,old_cx;	
			starting_cx = (s_height*c_tri_edge/2.0) / tri_height;
			starting_cy = tri_height - s_height;
			cx = starting_cx;
			cy = starting_cy;
			s_rectptr->set_cx(cx);
			s_rectptr->set_cy(cy);
		
			rectangle tmp_rect;
			rectangle* new_rect;/* shape pointer to push vector */
			tmp_rect.setColor("green");/* set inner shapes color */
			tmp_rect.set_height(s_height);
			tmp_rect.set_width(s_width);
			for (int i = 0; i < numOfRects_height; ++i)
			{	
				tmp_rect.set_cy(cy);
				old_cx = cx;
				for (int j = 0; j < numOfRects_width; ++j)
				{			
					tmp_rect.set_cx(cx);
					if(!(i==0 && j==0)){/** Avoid the first element pushing, since its already in vector from constructor **/
						new_rect = new rectangle;
						*new_rect = tmp_rect;
						*this += new_rect;/* push allocated pointer to vector */
					}		
					cx+=s_width;		
				}

				minus_height += s_height;
				new_width = ((tri_height - minus_height) * c_tri_edge) / tri_height;
				numOfRects_width = static_cast<int>(new_width / s_width);

				cy -= s_height;
				cx = old_cx + starting_cx;		
			}	
		}
		else if (s_circptr!=nullptr)
		{	
			s_circptr->setColor("green");

			double c_tri_edge = c_triptr->get_tri_edge();
			double s_radius = s_circptr->get_radius();

			double tri_height = (1.732*c_tri_edge)/2.0;
			
			int numOfCircles_height = static_cast<int>(tri_height / (1.732*s_radius));
			if(numOfCircles_height == 0)
				return;

			double starting_cx,starting_cy,cx,cy,old_cx;
			double max_width = c_tri_edge - 1.732*s_radius;/** Maximum printig area per lines **/

			/** Starting points for printing **/
			starting_cx = 1.732*s_radius;
			starting_cy = tri_height - 2*s_radius + s_radius;
			cx = starting_cx;
			cy = starting_cy;
			s_circptr->set_cx(cx);
			s_circptr->set_cy(cy);
			/** Starting points for printing **/
			circle tmp_circle;
			circle * new_circ;/* shape pointer to push vector */
			tmp_circle.set_radius(s_radius);
			tmp_circle.set_cy(cy);
			tmp_circle.setColor("green");/* set inner shapes color */
			for (int i = 0; i < numOfCircles_height; ++i)
			{	
				old_cx = cx;
				tmp_circle.set_cy(cy);
				for (int j = 0; cx <= max_width; ++j)
				{		
					tmp_circle.set_cx(cx);
					if(!(i==0 && j==0)){/** Avoid the first element pushing, since its already in vector from constructor **/
						new_circ = new circle;/* alloce for shape pointer */
						*new_circ=tmp_circle;
						*this += new_circ;/** push pointer into vector **/
					}
					cx+=2*s_radius;	
				}
				/** numerical updates **/	
				cy -= 1.732*s_radius;
				max_width -= s_radius;
				cx = old_cx +  s_radius;		
			}
		}
	}

	else {

		throw notavailable();
	}
	
}

}
