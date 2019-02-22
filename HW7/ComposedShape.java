import java.awt.Graphics;
import java.awt.*;
/**
* @author Goktug Akin
* @version HW7
* @since 2019
*/
public class ComposedShape extends AbstractShape{

	private Shapes[] _mainshape;
	private int _totalShapes;

	/**
	* Constructor that accepts two shapes, one is Container, other one is Small shape.
	* This shapes can be <b>Rectangle</b>,<b>Triangle</b> for Container, <b>Rectangle</b>,<b>Triangle</b>,<b>Circle</b> for Small shape.
	* @param container Container shape for ComposedShape.
	* @param small Small shape for ComposedShape.
	* @throws UnsupportedOperationException If container is not instance of <b>Rectangle</b>,<b>Triangle</b>.
	* @throws UnsupportedOperationException If small is not instanceof of <b>Rectangle</b>,<b>Triangle</b>,<b>Circle</b>.
	*/
	public ComposedShape(Shapes container, Shapes small)throws UnsupportedOperationException
	{	
		if(!(container instanceof Rectangle) && !(container instanceof Triangle))
			throw new UnsupportedOperationException("Container shape is not valid shape for ComposedShape, passed class name : " + container.getClass().getName());
		if(!(small instanceof Rectangle) && !(small instanceof Triangle) && !(small instanceof Circle) )
			throw new UnsupportedOperationException("Small shape is not valid shape for ComposedShape, passed class name : " + container.getClass().getName());

		_mainshape = new Shapes[2];
		_mainshape[0]=container;
		_mainshape[1]=small;
	}
	/**
	* Retrieves the number of shapes.
	* @return Number of shapes.
	*/
	public int getSize()
	{

		return _totalShapes;
	}
	/**
	* This method fits small shape in big shape. In this version, user of this class must call this method 
	* <i>explicitly</i> to fitting process.
	*/
	public void optimalFit()
	{

		if(_mainshape[0] instanceof Rectangle)
		{	
			Rectangle big_rect_ref = (Rectangle)_mainshape[0];
			big_rect_ref.set_cx(0);
			big_rect_ref.set_cy(0);

			if(_mainshape[1] instanceof Rectangle)
			{
				Rectangle small_rect_ref = (Rectangle)_mainshape[1];
				small_rect_ref.set_cx(0);
				small_rect_ref.set_cy(0);

				double container_width = big_rect_ref.get_width();
				double container_height = big_rect_ref.get_height();
				
				double small_width = small_rect_ref.get_width();
				double small_height = small_rect_ref.get_height();

				int numOfRects_width = (int)(container_width / small_width);
				int numOfRects_height = (int)(container_height / small_height);

				_totalShapes=numOfRects_width*numOfRects_height + 1;
				_mainshape = new Shapes[_totalShapes];
				_mainshape[0] = big_rect_ref;
				if(_totalShapes>1)
					_mainshape[1] = small_rect_ref;
				else
					return;

				double cx=0,cy=0;
				Rectangle tmp_rect = new Rectangle(small_height,small_width,0,0);
				Rectangle new_rect = new Rectangle();

				int k = 2;
				for (int i = 0; i < numOfRects_height; ++i)
				{	
					cx=0.0;
					for (int j = 0; j < numOfRects_width; ++j)
					{	
						tmp_rect.set_cx(cx);
						if(!(i==0 && j==0)){
							new_rect = new Rectangle(tmp_rect.get_height(),tmp_rect.get_width(),tmp_rect.get_cx(),tmp_rect.get_cy());
							_mainshape[k]=new_rect;
							++k;			
						}
						cx+=small_width;
					}
					cy+=small_height;
					tmp_rect.set_cy(cy);
				}

			}

			else if(_mainshape[1] instanceof Circle)
			{	

				Circle small_circle_ref = (Circle)_mainshape[1];
			
				double c_width = big_rect_ref.get_width();
				double c_height = big_rect_ref.get_height();

				double s_radius = small_circle_ref.get_radius();

				int numOfCircles_width = (int)(c_width / (s_radius*2));
				int numOfCircles_height = (int)(c_height / (s_radius*2));
				int totalCircles_rectangular=numOfCircles_height*numOfCircles_width;

				
				int totalCircles_triangular=0;
				int column_to_print = 0;
				double current_lenght = 0.0;
				boolean line = false;/** controlling the situation that number of circles like this per lines n + n-1 + n ... **/
				boolean enter = true;/** first check of entering the loop **/

				int g = 0;
				while(current_lenght<=c_height && enter)
				{
					if(g%2==0){
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
					if(g==0)
						current_lenght+=2*s_radius;
					else
						current_lenght+=s_radius*1.732;
					++g;
				}

				 totalCircles_rectangular = numOfCircles_height*numOfCircles_width;
				_totalShapes=totalCircles_rectangular+1;

				_mainshape = new Shapes[_totalShapes];
				
				_mainshape[0] = big_rect_ref;
				if(_totalShapes>1)
					_mainshape[1] = small_circle_ref;
				else
					return;
				
				/* # Creating the svg file block ..**/
				double starting_cx,starting_cy;/** Starting Points for printing **/
				double cx,cy;
				starting_cx = (double)(c_width / (numOfCircles_width*2));
				starting_cy = (double)(c_height / (numOfCircles_height*2));

				small_circle_ref.set_cx(starting_cx);
				small_circle_ref.set_cy(starting_cy);

				Circle tmp_circle = new Circle(s_radius);
				Circle new_circ = new Circle();
				int k =1;
				cy=starting_cy;
				tmp_circle.set_cy(cy);
				for (int i = 0; i < numOfCircles_height; ++i)
				{	
				 	cx=starting_cx;
				 	tmp_circle.set_cy(cy);
				 	for (int j = 0; j < numOfCircles_width; ++j)
				 	{	
				 		tmp_circle.set_cx(cx);
	 					new_circ = new Circle(tmp_circle.get_radius(),tmp_circle.get_cx(),tmp_circle.get_cy());
	 					_mainshape[k]=new_circ;
	 					++k;
				 		cx+=2*s_radius;
				 	}
				 	cy+=2*s_radius;
				}
				
			}

			else if(_mainshape[1] instanceof Triangle)
			{	

				Triangle small_tri_ref = (Triangle)_mainshape[1];

				double container_width = big_rect_ref.get_width();
				double container_height = big_rect_ref.get_height();

				double tri_edge = small_tri_ref.get_tri_edge();
				double cr_height = 1.732*tri_edge/2.0; 

				int numOfTriangles_width = (int)(container_width / tri_edge) + (int)((container_width - (tri_edge/2.0))/tri_edge);
				int numOfTriangles_height = (int)(container_height / cr_height);

				_totalShapes = numOfTriangles_width*numOfTriangles_height+1;
				_mainshape = new Shapes[_totalShapes];

				_mainshape[0] = big_rect_ref;
				if(_totalShapes>1)
					_mainshape[1] = small_tri_ref;
				else
					return;

				double [] cr1 = new double[]{0.0,0.0};
				double [] cr2 = new double[]{0.0,0.0};
				double [] up_corner = new double[]{0.0,0.0};
				double [] down_corner = new double[]{0.0,0.0};/** Array variables control the corners of triangle **/
				
				Triangle tmp_tri = new Triangle(tri_edge);
				Triangle new_tri = new Triangle();
				int k = 2;
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
							new_tri = new Triangle(tmp_tri.get_tri_edge(),tmp_tri.get_cr1(),tmp_tri.get_cr2(),tmp_tri.get_cr3());
							_mainshape[k]=new_tri;
							++k;
						}			
					}
					cr_height+=1.732*tri_edge/2.0;
				}

			}
		}

		else if(_mainshape[0] instanceof Triangle)
		{	
			Triangle big_tri_ref = (Triangle)_mainshape[0];

			if(_mainshape[1] instanceof Rectangle)
			{	
				Rectangle small_rect_ref = (Rectangle)_mainshape[1];

				double c_tri_edge = big_tri_ref.get_tri_edge();
				double s_height = small_rect_ref.get_height();
				double s_width = small_rect_ref.get_width();

				double tri_height = (1.732*c_tri_edge)/2.0;
				double minus_height = s_height;	/** Reduction amount of triangles height per step **/
				double new_width = c_tri_edge;	/** Reduction amount of base of triangle per step **/

				int numOfRects_width = (int)((((tri_height - minus_height) * c_tri_edge) / tri_height) / s_width);
				int numOfRects_height = (int)(tri_height / s_height);

				/** Starting points for printing **/
				double starting_cx,starting_cy,cx,cy,old_cx;	
				starting_cx = (s_height*c_tri_edge/2.0) / tri_height;
				starting_cy = tri_height - s_height;
				cx = starting_cx;
				cy = starting_cy;

				int shpctr=1;
				for (int it = 0; it < numOfRects_height; ++it)
				{	
					old_cx = cx;
					for (int jt = 0; jt < numOfRects_width; ++jt)
					{					
						cx+=s_width;
						++shpctr;		
					}
					minus_height += s_height;
					new_width = ((tri_height - minus_height) * c_tri_edge) / tri_height;
					numOfRects_width = (int)(new_width / s_width);
					cy -= s_height;
					cx = old_cx + starting_cx;		
				}


				_totalShapes=shpctr;
				_mainshape = new Shapes[_totalShapes];
				_mainshape[0]=big_tri_ref;
				if(_totalShapes>1)
					_mainshape[1]=small_rect_ref;
				else
					return;
				
				minus_height=s_height;
				numOfRects_width = (int)((((tri_height - minus_height) * c_tri_edge) / tri_height) / s_width);
				numOfRects_height = (int)(tri_height / s_height);
				starting_cx = (s_height*c_tri_edge/2.0) / tri_height;
				starting_cy = tri_height - s_height;
				cx = starting_cx;
				cy = starting_cy;

				small_rect_ref.set_cx(cx);
				small_rect_ref.set_cy(cy);
			
				Rectangle tmp_rect = new Rectangle(small_rect_ref.get_height(),small_rect_ref.get_width());
				Rectangle new_rect = new Rectangle();

				int k=2;
				for (int i = 0; i < numOfRects_height; ++i)
				{	
					tmp_rect.set_cy(cy);
					old_cx = cx;
					for (int j = 0; j < numOfRects_width; ++j)
					{			
						tmp_rect.set_cx(cx);
						if(!(i==0 && j==0)){/** Avoid the first element pushing, since its already in vector from constructor **/
							new_rect = new Rectangle(tmp_rect.get_height(),tmp_rect.get_width(),tmp_rect.get_cx(),tmp_rect.get_cy());
							_mainshape[k]=new_rect;
							++k;
						}		
						cx+=s_width;		
					}

					minus_height += s_height;
					new_width = ((tri_height - minus_height) * c_tri_edge) / tri_height;
					numOfRects_width = (int)(new_width / s_width);

					cy -= s_height;
					cx = old_cx + starting_cx;		
				}
			}

			else if(_mainshape[1] instanceof Triangle)
			{

				Triangle small_tri_ref = (Triangle)_mainshape[1];

				double c_tri_edge = big_tri_ref.get_tri_edge();
				double s_tri_edge = small_tri_ref.get_tri_edge();
				double c_tri_height = (1.732*c_tri_edge)/2.0;
				double s_tri_height = (1.732*s_tri_edge)/2.0;
				/****
					# "similartiy theroem on triangles". 
				****/
				double c_new_height = c_tri_height;
				double c_new_width = ((c_tri_height - s_tri_height)*c_tri_edge) / (c_tri_height);/** New length of base of triangle **/
				double minus_width = c_tri_edge - c_new_width;
				double minus_height = 0;/** Reduicton amount of triangle height per step **/
				double add_width = 0;/** Increasing amount of triangle width(small shape) per step(inside loop) **/
				
				/** Two types of triangles **/
				int reverse_triangles = (int)(c_new_width / s_tri_edge);	
				int normal_triangles = (int)(c_tri_edge / s_tri_edge);
				/** Two types of triangles **/
				int numOfTriangles_width =  reverse_triangles + normal_triangles; /** Total triangles per line **/
				int numOfTriangles_height = (int)(c_tri_edge / s_tri_edge);
				/**************************************************************************************************/
				double [] cr1 = new double[]{0.0,0.0};
				double [] cr2 = new double[]{0.0,0.0};
				double [] up_corner = new double[]{0.0,0.0};
				double [] down_corner = new double[]{0.0,0.0};/** Array variables control the corners of triangle **/

				cr1[0] = 0;
				cr1[1] = c_tri_height;

				cr2[0] = s_tri_edge / 2.0;
				cr2[1] = c_tri_height - s_tri_height;

				up_corner[0] = s_tri_edge;
				up_corner[1] = c_tri_height;

				down_corner[0] = s_tri_edge + s_tri_edge / 2.0;
				down_corner[1] = c_tri_height - s_tri_height;
				/** initalizing first small shape **/
				small_tri_ref.set_cr1(cr1);
				small_tri_ref.set_cr2(cr2);
				small_tri_ref.set_cr3(up_corner);
				/** Initial values of corners **/
				Triangle tmp_tri = new Triangle(small_tri_ref.get_tri_edge(),small_tri_ref.get_cr1(),small_tri_ref.get_cr2(),small_tri_ref.get_cr3());
				Triangle new_tri = new Triangle();

				int shpctr=1;
				for (int i = 0; i < numOfTriangles_height; ++i)
				{		
					for (int j = 0; j < numOfTriangles_width; ++j)		
						shpctr++;

					c_new_height -= s_tri_height;
					c_new_width -=minus_width;
					normal_triangles = reverse_triangles;
					reverse_triangles = (int)(c_new_width / s_tri_edge);
					numOfTriangles_width = normal_triangles + reverse_triangles;

					minus_height+=s_tri_height;
					add_width+=s_tri_edge / 2.0;
				}

				_totalShapes=shpctr;
				_mainshape = new Shapes[_totalShapes];
				_mainshape[0] = big_tri_ref;
				if(_totalShapes>1)
					_mainshape[1] = small_tri_ref;
				else
					return;

				c_new_height = c_tri_height;
				c_new_width = ((c_tri_height - s_tri_height)*c_tri_edge) / (c_tri_height);/** New length of base of triangle **/
				minus_height = 0;/** Reduicton amount of triangle height per step **/
				add_width = 0;/** Increasing amount of triangle width(small shape) per step(inside loop) **/
							
				reverse_triangles = (int)(c_new_width / s_tri_edge);	
				normal_triangles = (int)(c_tri_edge / s_tri_edge);
				numOfTriangles_width =  reverse_triangles + normal_triangles; /** Total triangles per line **/
				
				int k = 2;
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
							new_tri = new Triangle(tmp_tri.get_tri_edge(),tmp_tri.get_cr1(),tmp_tri.get_cr2(),tmp_tri.get_cr3());/* allocate for shape pointer */
							_mainshape[k]=new_tri;
							++k;	
						}
					}
					
					/** numerical updates **/
					c_new_height -= s_tri_height;
					c_new_width -=minus_width;
					normal_triangles = reverse_triangles;
					reverse_triangles = (int)(c_new_width / s_tri_edge);
					numOfTriangles_width = normal_triangles + reverse_triangles;

					minus_height+=s_tri_height;
					add_width+=s_tri_edge / 2.0;
				}
			}
			else if(_mainshape[1] instanceof Circle)
			{
				Circle small_circle_ref = (Circle)_mainshape[1];

				double c_tri_edge = big_tri_ref.get_tri_edge();
				double s_radius = small_circle_ref.get_radius();
				double tri_height = (1.732*c_tri_edge)/2.0;
				
				int numOfCircles_height = (int)(tri_height / (1.732*s_radius));

				double starting_cx,starting_cy,cx,cy,old_cx;
				double max_width = c_tri_edge - 1.732*s_radius;/** Maximum printig area per lines **/

				/** Starting points for printing **/
				starting_cx = 1.732*s_radius;
				starting_cy = tri_height - 2*s_radius + s_radius;
				cx = starting_cx;
				cy = starting_cy;
				small_circle_ref.set_cx(cx);
				small_circle_ref.set_cy(cy);
				/** Starting points for printing **/
				Circle tmp_circle = new Circle(small_circle_ref.get_radius(),cx,cy);
				Circle new_circ = new Circle();/* shape pointer to push vector */

				int shpctr = 1;
				for (int i = 0; i < numOfCircles_height; ++i)
				{	
					old_cx = cx;
					for (int j = 0; cx <= max_width; ++j)
					{		

						cx+=2*s_radius;	
						shpctr++;
					}
					
					cy -= 1.732*s_radius;
					max_width -= s_radius;
					cx = old_cx +  s_radius;		
				}
				_totalShapes=shpctr;
				_mainshape = new Shapes[_totalShapes];
				_mainshape[0] = big_tri_ref;
				if(_totalShapes>1)
					_mainshape[1] = small_circle_ref;
				else
					return;

				starting_cx = 1.732*s_radius;
				starting_cy = tri_height - 2*s_radius + s_radius;
				cx = starting_cx;
				cy = starting_cy;
				max_width = c_tri_edge - 1.732*s_radius;	

				int k = 2;
				for (int i = 0; i < numOfCircles_height; ++i)
				{	
					old_cx = cx;
					tmp_circle.set_cy(cy);
					for (int j = 0; cx <= max_width; ++j)
					{		
						tmp_circle.set_cx(cx);
						if(!(i==0 && j==0)){/** Avoid the first element pushing, since its already in vector from constructor **/
							new_circ = new Circle(tmp_circle.get_radius(),tmp_circle.get_cx(),tmp_circle.get_cy());/* alloce for shape pointer */
							_mainshape[k] = new_circ;
							++k;
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
	}

	/**
	* Draws the ComposedShape with graphics object.
	* @param g Graphics object.
	*/
	@Override
	public void draw(Graphics g)
	{
		for(int i = 0; i<_totalShapes; i++)
		{	
			if(i==0)
				g.setColor(Color.red);
			else
				g.setColor(Color.green);
			_mainshape[i].draw(g);		
		}
	}

	/**
	* Increments all of the coordinates by 1 of big(container) shape.
	*/
	@Override
	public void increment()
	{

		for(int i = 0; i<_totalShapes; i++)
			_mainshape[i].increment();
	}
	/**
	* Decrements all of the coordinates of by 1 big(container) shape.
	*/
	@Override
	public void decrement()
	{

		for(int i = 0; i<_totalShapes; i++)
			_mainshape[i].decrement();
	}
	/**
	* Retrieves the area of ComposedShape.
	* @return Area of ComposedShape.
	*/
	@Override
	public double area()
	{
		return _mainshape[0].area();
	}
	/**
	* Retrieves the perimeter of ComposedShape.
	* @return Perimeter of ComposedShape.
	*/
	@Override
	public double perimeter()
	{
		return _mainshape[0].perimeter();
	}

}