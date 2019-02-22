import java.util.ArrayList;
import java.awt.Graphics;
import java.awt.*;
/**
* @author Goktug Akin
* @since 2019
* @version HW7
*/
public class PolygonVect extends Polygon{

	private ArrayList<Point2D> _points; 

	/**
	* Constructor that accpets 2D points by ArrayList.
	* @param points 2D points with contained by ArrayList.
	* @throws NegativeArraySizeException If parameter points has illegal size (less or equal than zero).
	*/
	public PolygonVect(ArrayList<Point2D> points)throws NegativeArraySizeException
	{
		if(points.size()<=0)
			throw new NegativeArraySizeException("Invalid size passing PolygonVect(ArrayList<Point2D> ..) constructor");
		_points = new ArrayList<Point2D>();
		for (int i=0;i<points.size();++i)
			_points.add(points.get(i));
		
	}
	/**
	* Conversion constructor converts from <b>Rectangle</b>
	* @param rect Rectangle object that will be converted to Polygon.
	*/
	public PolygonVect(Rectangle rect)
	{	
		_points = new ArrayList<Point2D>();
		Point2D temp=new Point2D(rect.get_cx(),rect.get_cy());
		_points.add(temp);
		Point2D temp2=new Point2D(rect.get_cx()+rect.get_width(),rect.get_cy());
		_points.add(temp2);
		Point2D temp3=new Point2D(rect.get_cx()+rect.get_width(),rect.get_cy()+rect.get_height());
		_points.add(temp3);
		Point2D temp4=new Point2D(rect.get_cx(),rect.get_cy()+rect.get_height());
		_points.add(temp4);
	}
	/**
	* Conversion constructor converts from <b>Triangle</b>
	* @param tri Triangle object that will be converted to Polygon.
	*/
	public PolygonVect(Triangle tri)
	{	
		_points = new ArrayList<Point2D>();
		Point2D temp=new Point2D(tri.get_cr1()[0],tri.get_cr1()[1]);
		_points.add(temp);
		Point2D temp2=new Point2D(tri.get_cr2()[0],tri.get_cr2()[1]);
		_points.add(temp2);
		Point2D temp3=new Point2D(tri.get_cr3()[0],tri.get_cr3()[1]);
		_points.add(temp3);
	}
	/**
	* Conversion constructor converts from <b>Circle</b>
	* @param circ Circle object that will be converted to Polygon.
	*/
	public PolygonVect(Circle circ)
	{	
		_points = new ArrayList<Point2D>();
		Point2D temp = new Point2D();
		double angle = 0;
		for (int i = 0; i < 100; ++i)
		{
			temp=new Point2D(circ.get_radius()*Math.cos(angle)+circ.get_cx(),circ.get_radius()*Math.sin(angle)+circ.get_cy());
			angle+=3.6*(3.14159/180);//For 100 equal intervals angle changes
			_points.add(temp);
		}
	}
	/**
	* Conversion constructor converts from <b>PolygonDyn</b>
	* @param pdyn PolygonDyn object that will be converted to Polygon.
	* @throws NegativeArraySizeException If param pdyn has illegal number of points (less or equal than zero).
	*/
	public PolygonVect(PolygonDyn pdyn)throws NegativeArraySizeException
	{
		if(pdyn.size()<=0)
			throw new NegativeArraySizeException("Invalid size passed to PolygonVect(PolygonDyn pdyn) constructor.");
		else
		{	
			_points = new ArrayList<Point2D>();
			for (int i=0;i<this.size();++i)
				_points.remove(i);
			for (int i=0;i<pdyn.size();++i)
				_points.add(pdyn.getPoint(i));
		}
	}
	/**
	* Retrieves the number of the points.
	* @return Number of Point2D objects. 
	*/
	public int size()
	{
		return _points.size();
	}
	/**
	* Retrieves the point with in the given index.
	* @param index index value for 2D point
	* @return Point2D object with given index.
	* @throws NegativeArraySizeException If index is illegal (less than zero).
	*/
	public Point2D getPoint(int index)throws NegativeArraySizeException
	{	
		if(index<0)
			throw new NegativeArraySizeException("Invalid index passed to getPoint(int index) for PolygonVect.");
		else
			return _points.get(index);
	}
	/**
	* Retrieves the area of the polygon.
	* @return Area of the polygon.
	*/
	@Override
	public double area()
	{
		// Calculating area for coordinate geometry
		// Source : https://www.mathopenref.com/coordpolygonarea.html
		double temp = 0;
		for (int i = 0,j=0; i < _points.size() ; ++i,++j){
			if(i==_points.size()-1)
				j=-1;
			temp+=((_points.get(i).get_x()*_points.get(j+1).get_y()) - (_points.get(i).get_y()*_points.get(j+1).get_x()));	
		}
		if(temp<0)
			temp=temp*-1;
		
		return temp / 2;
	}
	/**
	* Retrieves the perimeter of the polygon.
	* @return Perimeter of the polygon.
	*/
	@Override
	public double perimeter()
	{	
		// Calculating perimeter for coordinate geometry
		// Source : https://www.mathopenref.com/coordpolygonarea.html
		double temp = 0;
		for (int i = 0,j=0; i < _points.size();++i,++j)
		{
			if(i==_points.size()-1)
				j=-1;
			temp+= Math.sqrt((Math.pow(_points.get(i).get_x() - _points.get(j+1).get_x(),2)) + (Math.pow(_points.get(i).get_y() - _points.get(j+1).get_y(),2)));
			
		}
	 	return temp;
	}

	/**
	* Draw polygon with graphics object.
	* @param g Graphics object.
	*/
	@Override
	public void draw(Graphics g)
	{

		int [] x_points = new int[_points.size()];
		int [] y_points = new int[_points.size()];

		for (int i=0;i<_points.size();++i) 
			x_points[i]=(int)_points.get(i).get_x();
		for (int i=0;i<_points.size();++i) 
			y_points[i]=(int)_points.get(i).get_y();
		
		g.fillPolygon(x_points,y_points,_points.size());
		g.setColor(Color.black);
        for (int i=0; i<_points.size(); ++i)
            x_points[i]--;
        for(int j=0; j<_points.size(); ++j)
            y_points[j]--;
        g.drawPolygon(x_points,y_points,_points.size()); 
	}
	/**
	* Increments all of the coordinates of polygon.
	*/
	@Override
	public void increment()
	{
		double x,y;
		for (int i=0;i<_points.size();++i) {
			x=_points.get(i).get_x();
			x--;
			y=_points.get(i).get_y();
			y--;
			_points.get(i).set_points(x,y);		
		}
	}
	/**
	* Decrements all of the coordinates of polygon.
	*/
	@Override
	public void decrement()
	{
		double x,y;
		for (int i=0;i<_points.size();++i) {
			x=_points.get(i).get_x();
			x++;
			y=_points.get(i).get_y();
			y++;
			_points.get(i).set_points(x,y);		
		}
	}

	@Override
	public String toString()
	{
		return String.format("PolygonVect with %d points", _points.size());
	}

}