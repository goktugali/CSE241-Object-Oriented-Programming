import java.awt.Graphics;
import java.awt.*;
import javax.swing.*;
/**
* @author Goktug Akin
* @version HW8
* @since 2019
*/
public class Circle extends AbstractShape{

	private double _cx;
    private double _cy;
    private double _radius;

    /**
    * Default constructor.
    */
    public Circle()
    {
    	_radius=0;
		_cx=0;
		_cy=0;
    }
    /**
    * Constructor that accepts radius value of circle.
    * @param radius Radius of triangle.
    * @throws NumberFormatException If radius is less or equal than zero.
    */
    public Circle(double radius)throws NumberFormatException
    {   
        if(radius<=0)
            throw new NumberFormatException("Illegal radius value");
    	_radius=radius;
    	_cx=radius;
		_cy=radius;
    }
    /**
    * Constructor that accepts radius value and center coordinates of circle.
    * @param radius Radius of triangle.
    * @param cx x coordinate value of center of circle.
    * @param cy y coordinate value of center of circle.
    * @throws NumberFormatException If radius is less or equal than zero.
    */
    public Circle(double radius, double cx, double cy)throws NumberFormatException
    {   
        if(radius<=0)
            throw new NumberFormatException("Illegal radius value");
    	_radius=radius;
		_cx=cx;
		_cy=cy;

    }
    /**
    * Retrieves the radius of circle.
    * @return Radius of circle.
    */
    public double get_radius()
    {
    	return _radius;
    }
    /**
    * Retrieves the x coordinate value of center of circle.
    * @return x coordinate of center.
    */
    public double get_cx()
    {
    	return _cx;
    }
    /**
    * Retrieves the y coordinate value of center of circle.
    * @return y coordinate of center.
    */
    public double get_cy()
    {
    	return _cy;
    }
    /**
    * Sets the radius circle.
    * @param radius Radius value that will be setted.
    * @throws NumberFormatException If parameter radius is illegal (less or equal than 0).
    */
    public void set_radius(double radius)throws NumberFormatException
    {
        if(radius<=0)
            throw new NumberFormatException("Illegal radius value");
    	_radius = radius;
    }
    /**
    * Sets the x coordinate of center of circle.
    * @param cx x coordinate of center of circle.
    */
    public void set_cx(double cx)
    {
    	_cx=cx;
    }
    /**
    * Sets the y coordinate of center of circle.
    * @param cy y coordinate of center of circle.
    */
    public void set_cy(double cy)
    {
    	_cy=cy;
    }
    /**
    * Retrieves the area of triangle.
    * @return Area of circle.
    */
    public double area(){
		return _radius*_radius*3.14;
	}
    /**
    * Retrieves the perimeter of triangle.
    * @return Perimeter of circle.
    */
	public double perimeter(){
		return _radius*2*3.14;
	}

	@Override
    public String toString()
    {
        return String.format("[Circle] - Radius : %f , Area : %f , Perimeter : %f",_radius,area(),perimeter());
    }
    /**
    * Increments x and y coordinate of center of circle.
    */
    @Override
    public void increment()
    {
        _cx++;
        _cy++;
    }
    /**
    * Decrements x and y coordinate of center of circle.
    */
    @Override
    public void decrement()
    {
        _cx--;
        _cy--;
    }
    /**
    * Draw circle with graphics object.
    * @param g Graphics object.
    */
    @Override
    public void draw(Graphics g)
    {   
        int cx= (int)_cx;
        int cy= (int)_cy;
        g.fillOval(cx-(int)_radius,cy-(int)_radius,(int)_radius*2,(int)_radius*2);
        g.setColor(Color.black);
        g.drawOval(cx-(int)_radius,cy-(int)_radius,(int)_radius*2,(int)_radius*2);
        
    }
}