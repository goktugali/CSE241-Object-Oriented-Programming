import java.awt.Graphics;
import java.awt.*;
import javax.swing.*;
/**
* @author Goktug Akin
* @since 2019
* @version HW7
*/
public class Rectangle extends AbstractShape{

	private double _cx;
	private double _cy;
	private double _height;
	private double _width;

    /**
    * Default constructor.
    */
	public Rectangle()
    {
        _cx=0;
        _cy=0;
        _height=0;
        _width=0;
    }
    /**
    * Constructor that accepts height,width and coordinate values of top left corner.
    * @param height Height of rectangle.
    * @param width Width of rectangle.
    * @param cx x coordinate value of top left corner of rectangle.
    * @param cy y coordinate value of top left corner of rectangle.
    * @throws NumberFormatException If height/width value is illegal(less or equal than zero).
    */
    public Rectangle(double height, double width, double cx, double cy)throws NumberFormatException
    {   
        if(height<=0 || width<=0)
            throw new NumberFormatException("Illegal width/height value");
        _height=height;
        _width=width;
        _cx=cx;
        _cy=cy;
    }
    /**
    * Constructor that accepts height,width values of rectangle.
    * @param height Height of rectangle.
    * @param width Width of rectangle.
    * @throws NumberFormatException If height/width value is illegal(less or equal than zero).
    */
    public Rectangle(double height, double width)throws NumberFormatException
    {   
        if(height<=0 || width<=0)
            throw new NumberFormatException("Illegal width/height value");
        _height = height;
        _width = width;
        _cx=0.0;
        _cy=0.0;
    }
    /**
    * Retrieves the x coordinate value of top left corner of rectangle.
    * @return x coordinate of top left corner.
    */
    public double get_cx()
    {
        return _cx;
    }
    /**
    * Retrieves the y coordinate value of top left corner of rectangle.
    * @return y coordinate of top left corner.
    */
    public double get_cy()
    {
        return _cy;
    }
    /**
    * Retrieves the height value of rectangle.
    * @return Height of rectangle.
    */
    public double get_height()
    {
        return _height;
    }
    /**
    * Retrieves the width value of rectangle.
    * @return Width of rectangle.
    */
    public double get_width()
    {
        return _width;
    }
    /**
    * Sets the x coordinate of top left corner of rectangle.
    * @param cx coordinate value of top left corner.
    */
    public void set_cx(double cx)
    {
        _cx=cx;
    }
    /**
    * Sets the y coordinate of top left corner of rectangle.
    * @param cy coordinate value of top left corner.
    */
    public void set_cy(double cy)
    {
        _cy=cy;
    }
    /**
    * Sets the height of rectangle.
    * @param height Height of rectangle.
    * @throws NumberFormatException If height value is illegal(less or equal than zero).
    */
    public void set_height(double height)throws NumberFormatException
    {   
        if(height<=0)
            throw new NumberFormatException("Illegal height value");
        _height=height;
    }
    /**
    * Sets the width of rectangle.
    * @param width Width of rectangle.
    * @throws NumberFormatException If width value is illegal(less or equal than zero).
    */
    public void set_width(double width)throws NumberFormatException
    {   
        if(width<=0)
            throw new NumberFormatException("Illegal widtht value");
        _width=width;
    }
    /**
    * Retrieves the area of rectangle.
    * @return Area of rectangle.
    */
    @Override
    public double area()
    {
        return _height*_width;
    }
    /**
    * Retrieves the perimeter of rectangle.
    * @return Perimeter of rectangle.
    */
    @Override
    public double perimeter()
    {
        return 2*(_height+_width);
    }
    /**
    * Increment x and y coordinate value of top left corner of rectangle by 1.
    */
    @Override
    public void increment()
    {
        _cx++;
        _cy++;
    }
    /**
    * Decrement x and y coordinate value of top left corner of rectangle by 1.
    */
    @Override
    public void decrement()
    {
        _cx--;
        _cy--;
    }
    @Override
    public String toString()
    {
        return String.format("[Rectangle] - Height : %f , Width : %f , Area : %f , Perimeter : %f",_height,_width,area(),perimeter());
    }

    /**
    * Draws the rectangle with Graphics object.
    * @param g Graphics object.
    */
    @Override
    public void draw(Graphics g)
    {   
        int cx= (int)_cx;
        int cy= (int)_cy;
        g.fillRect(cx,cy,(int)_width,(int)_height);
        g.setColor(Color.black);
        g.drawRect(cx,cy,(int)_width,(int)_height); 
        /* 
         * ALGORITHM * 
         * fillRect fills the rectangle, draw paints the stroke (dis ceper).
        */  
    }

}