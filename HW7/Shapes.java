import java.awt.Graphics;
/**
* @author Goktug Akin
* @version HW7
* @since 2019
*/
public interface Shapes extends Comparable<Shapes>{

	/**
	* Retrieves the area of shape.
	* @return Area of shape.
	*/
	public double area();
	/**
	* Retrieves the perimeter of shape.
	* @return Perimeter of shape.
	*/
	public double perimeter();
	/**
	* Increments all of coordinates of shape.
	*/
	public void increment();
	/**
	* Decrements all of coordinates of shape.
	*/
	public void decrement();
	/**
	* Draws the shape with graphics object.
	* @param g Graphics object.
	*/
	public void draw(Graphics g);

}