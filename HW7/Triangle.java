import java.awt.Graphics;
import java.awt.*;
import javax.swing.*;

/**
* @author Goktug Akin
* @since 2019
* @version HW7
*/
public class Triangle extends AbstractShape{

	private double[] _cr1;
    private double[] _cr2;
    private double[] _cr3;
    private double _tri_edge;

    /**
    * Default constructor.
    */
    public Triangle()
    {   
        _cr1 = new double[2];
        _cr2 = new double[2];
        _cr3 = new double[2];

    	_tri_edge=0;
		_cr1[0]=0;
		_cr1[1]=0;

		_cr2[0]=0;
		_cr2[1]=0;

		_cr3[0]=0;
		_cr3[1]=0;
    }
    /**
    * Constructor that accepts edge of triangle and three corners.
    * @param tri_edge Edge value of triangle.
    * @param cr1 Corner1 of triangle (x,y).
    * @param cr2 Corner2 of triangle (x,y).
    * @param cr3 Corner3 of triangle (x,y).
    * @throws NumberFormatException If triangle edge is less or equal than zero.
    */
    public Triangle(double tri_edge,double[] cr1,double[] cr2,double[] cr3)throws NumberFormatException
    {
        if(tri_edge<=0)
            throw new NumberFormatException("Illegal triangle edge value");

        _cr1 = new double[2];
        _cr2 = new double[2];
        _cr3 = new double[2];

    	_tri_edge = tri_edge;
		_cr1[0] = cr1[0];
		_cr1[1] = cr1[1];

		_cr2[0] = cr2[0];
		_cr2[1] = cr2[1];

		_cr3[0] = cr3[0];
		_cr3[1] = cr3[1];
    }
    /**
    * Constructor that accepts edge of triangle and two corners.
    * @param tri_edge Edge value of triangle.
    * @param cr1 Corner1 of triangle (x,y).
    * @param cr2 Corner2 of triangle (x,y).
    * @throws NumberFormatException If triangle edge is less or equal than zero.
    */
    public Triangle(double tri_edge,double[] cr1,double[] cr2)throws NumberFormatException
    {   
        if(tri_edge<=0)
            throw new NumberFormatException("Illegal triangle edge value");

        _cr1 = new double[2];
        _cr2 = new double[2];
        _cr3 = new double[2];

    	_tri_edge = tri_edge;
		_cr1[0] = cr1[0];
		_cr1[1] = cr1[1];

		_cr2[0] = cr2[0];
		_cr2[1] = cr2[1];
    }
    /**
    * Constructor that accepts edge of triangle.
    * @param tri_edge Edge value of triangle.
    * @throws NumberFormatException If triangle edge is less or equal than zero.
    */
    public Triangle(double tri_edge)throws NumberFormatException
    {   
        if(tri_edge<=0)
            throw new NumberFormatException("Illegal triangle edge value");

        _cr1 = new double[2];
        _cr2 = new double[2];
        _cr3 = new double[2];
        
    	_tri_edge=tri_edge;
		double tri_height = 1.732*tri_edge/2.0;
		_cr1[0]=0;
		_cr1[1]=tri_height;

		_cr2[0]=tri_edge/2.0;
		_cr2[1]=0;

		_cr3[0]=tri_edge;
		_cr3[1]=tri_height;
    }
    /**
    * Retrieves the edge of triangle.
    * @return Edge of an triangle.
    */
    double get_tri_edge()
    {
        return _tri_edge;
    }
    /**
    * Retrieves the corner1 of triangle.
    * @return Corner1 of triangle.
    */
    double[] get_cr1()
    {
        return _cr1;
    }
    /**
    * Retrieves the corner2 of triangle.
    * @return Corner2 of triangle.
    */
    double[] get_cr2()
    {
        return _cr2;
    }
    /**
    * Retrieves the corner3 of triangle.
    * @return Corner3 of triangle.
    */
    double[] get_cr3()
    {
        return _cr3;
    }
    /**
    * Sets the corner1.
    * @param cr1 Corner1 as a array (x,y).
    */
    public void set_cr1(double[] cr1)
    {
    	_cr1[0]=cr1[0];
		_cr1[1]=cr1[1];

    }
    /**
    * Sets the corner2.
    * @param cr2 Corner2 as a array (x,y).
    */
    public void set_cr2(double[] cr2)
    {
    	_cr2[0]=cr2[0];
		_cr2[1]=cr2[1];
    }
   /**
    * Sets the corner3.
    * @param cr3 Corner3 as a array (x,y).
    */
    public void set_cr3(double[] cr3)
    {
    	_cr3[0]=cr3[0];
		_cr3[1]=cr3[1];
    }
   /**
    * Sets the edge of triangle.
    * @param tri_edge Edge of a triangle.
    * @throws NumberFormatException If triangle edge is less or equal than zero.
    */
    public void set_tri_edge(double tri_edge)throws NumberFormatException
    {   
        if(tri_edge<=0)
            throw new NumberFormatException("Illegal triangle edge value");
    	_tri_edge = tri_edge;
    }

    /**
    * Retrieves the area of triangle.
    * @return Area of triangle.
    */
    @Override
    public double area()
    {
    	return (_tri_edge*_tri_edge*1.732)/4.0;
    }
    /**
    * Retrieves the perimeter of triangle.
    * @return Perimeter of triangle.
    */
    @Override
    public double perimeter()
    {
    	return 3*_tri_edge;
    }
    /**
    * Increment all coordinate of corner values by 1.
    */
    @Override
    public void increment()
    {
        _cr1[0]++;
        _cr1[0]++;
        _cr2[0]++;
        _cr2[0]++;
        _cr3[0]++;
        _cr3[0]++;
        _cr1[1]++;
        _cr1[1]++;
        _cr2[1]++;
        _cr2[1]++;
        _cr3[1]++;
        _cr3[1]++;
    }
    /**
    * Decrement all coordinate of corner values by 1.
    */
    @Override
    public void decrement()
    {
        _cr1[0]--;
        _cr1[0]--;
        _cr2[0]--;
        _cr2[0]--;
        _cr3[0]--;
        _cr3[0]--;
        _cr1[1]--;
        _cr1[1]--;
        _cr2[1]--;
        _cr2[1]--;
        _cr3[1]--;
        _cr3[1]--;
    }

    @Override
    public String toString()
    {
        return String.format("[Triangle] - Edge : %f ,Area : %f , Perimeter : %f",_tri_edge,area(),perimeter());
    }
    /**
    * Draw triangle with Graphics object.
    * @param g Graphics object.
    */
    @Override
    public void draw(Graphics g)
    {
        int [] x_points = new int []{(int)_cr1[0],(int)_cr2[0],(int)_cr3[0]};
        int [] y_points = new int []{(int)_cr1[1],(int)_cr2[1],(int)_cr3[1]};
        g.fillPolygon(x_points,y_points,3);
        g.setColor(Color.black);
        g.drawPolygon(x_points,y_points,3); 
    }
}