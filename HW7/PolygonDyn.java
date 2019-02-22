import java.util.ArrayList;
import java.awt.*;
/**
* @author Goktug Akin
* @since 2019
* @version HW7
*/
public class PolygonDyn extends Polygon{

	private Point2D [] _points;
	private int _size;

	/**
	* Constructor that accpets 2D points by ArrayList.
	* @param points 2D points with contained by ArrayList.
	* @throws NegativeArraySizeException If parameter points has illegal size (less or equal than zero)
	*/
	public PolygonDyn(ArrayList<Point2D> points)throws NegativeArraySizeException
	{
		if(points.size()<=0)
			throw new NegativeArraySizeException("Invalid size passing PolygonDyn(ArrayList<Point2D> ..) constructor");
		_points = new Point2D[points.size()];
		for (int i=0;i<points.size();++i)
			_points[i]=(points.get(i));
		_size = points.size();		
	}
	/**
	* Conversion constructor converts from <b>Rectangle</b>
	* @param rect Rectangle object that will be converted to Polygon.
	*/
	public PolygonDyn(Rectangle rect)
	{	
		_points = new Point2D[4];
		Point2D temp=new Point2D(rect.get_cx(),rect.get_cy());
		_points[0]=(temp);
		Point2D temp2=new Point2D(rect.get_cx()+rect.get_width(),rect.get_cy());
		_points[1]=(temp2);
		Point2D temp3=new Point2D(rect.get_cx()+rect.get_width(),rect.get_cy()+rect.get_height());
		_points[2]=(temp3);
		Point2D temp4=new Point2D(rect.get_cx(),rect.get_cy()+rect.get_height());
		_points[3]=(temp4);
		_size = 4;
	}
	/**
	* Conversion constructor converts from <b>Triangle</b>
	* @param tri Triangle object that will be converted to Polygon.
	*/
	public PolygonDyn(Triangle tri)
	{	
		_points = new Point2D[3];
		Point2D temp=new Point2D(tri.get_cr1()[0],tri.get_cr1()[1]);
		_points[0]=(temp);
		Point2D temp2=new Point2D(tri.get_cr2()[0],tri.get_cr2()[1]);
		_points[1]=(temp2);
		Point2D temp3=new Point2D(tri.get_cr3()[0],tri.get_cr3()[1]);
		_points[2]=(temp3);
		_size = 3;
	}
	/**
	* Conversion constructor converts from <b>Circle</b>
	* @param circ Circle object that will be converted to Polygon.
	*/
	public PolygonDyn(Circle circ)
	{
		Point2D temp = new Point2D();
		double angle = 0;
		_points = new Point2D[100];
		for (int i = 0; i < 100; ++i)
		{
			temp=new Point2D(circ.get_radius()*Math.cos(angle)+circ.get_cx(),circ.get_radius()*Math.sin(angle)+circ.get_cy());
			angle+=3.6*(3.14159/180);//For 100 equal intervals angle changes
			_points[i]=(temp);
		}
		_size = 100;
	}

	/**
	* Conversion constructor converts from <b>PolygonVect</b>
	* @param pvect PolygonVect object which will be converted to PolygonDyn.
	* @throws NegativeArraySizeException If param pvect has illegal number of points (less or equal than zero).
	*/
	public PolygonDyn(PolygonVect pvect)throws NegativeArraySizeException
	{
		if(pvect.size()<=0)
			throw new NegativeArraySizeException("Invalid size passed to PolygonVect(PolygonDyn pdyn) constructor.");
		else
		{	_points = new Point2D[pvect.size()];
			for (int i=0;i<pvect.size();++i)
				_points[i]=(pvect.getPoint(i));
		}
	}

	/**
	* Retrieves the number of the points.
	* @return Number of Point2D objects. 
	*/
	public int size()
	{
		return _size;
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
			return _points[index];
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
		for (int i = 0,j=0; i < this.size() ; ++i,++j){
			if(i==this.size()-1)
				j=-1;
			temp+=((_points[i].get_x()*_points[j+1].get_y()) - (_points[i].get_y()*_points[j+1].get_x()));	
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
		for (int i = 0,j=0; i < this.size();++i,++j)
		{
			if(i==this.size()-1)
				j=-1;
			temp+= Math.sqrt((Math.pow(_points[i].get_x() - _points[j+1].get_x(),2)) + (Math.pow(_points[i].get_y() - _points[j+1].get_y(),2)));
			
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

		int [] x_points = new int[this.size()];
		int [] y_points = new int[this.size()];

		for (int i=0;i<this.size();++i) 
			x_points[i]=(int)_points[i].get_x();
		for (int i=0;i<this.size();++i) 
			y_points[i]=(int)_points[i].get_y();
		
		g.fillPolygon(x_points,y_points,this.size());
		g.setColor(Color.black);
        for (int i=0; i<this.size(); ++i)
            x_points[i]--;
        for(int j=0; j<this.size(); ++j)
            y_points[j]--;
        g.drawPolygon(x_points,y_points,this.size()); 
	}
	/**
	* Increments all of the coordinates of polygon.
	*/
	@Override
	public void increment()
	{
		double x,y;
		for (int i=0;i<this.size();++i) {
			x=_points[i].get_x();
			x--;
			y=_points[i].get_y();
			y--;
			_points[i].set_points(x,y);		
		}
	}
	/**
	* Decrements all of the coordinates of polygon.
	*/
	@Override
	public void decrement()
	{
		double x,y;
		for (int i=0;i<this.size();++i) {
			x=_points[i].get_x();
			x++;
			y=_points[i].get_y();
			y++;
			_points[i].set_points(x,y);		
		}
	}

	@Override
	public String toString()
	{
		return String.format("PolygonDyn with %d points", _size);
	}
}