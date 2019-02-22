/**
* @author Goktug Akin
* @version HW7
* @since 2019
*/
public abstract class Polygon extends AbstractShape{

	public class Point2D{
		private double _x;
		private double _y;

		/**
		* Default constructor
		*/
		public Point2D()
		{
			_x = 0;
			_y = 0;
		}
		/**
		* Constructor that accepts x and y coordinates of Point2D.
		* @param x x coordinate of 2D point.
		* @param y y coordinate of 2D point.
		*/
		public Point2D(double x,double y)
		{
			_x=x;
			_y=y;
		}
		/**
		* Retrieves the x coordinate of 2D point.
		* @return x coordinate value of 2D point.
		*/
		public double get_x()
		{
			return _x;
		}
		/**
		* Retrieves the y coordinate of 2D point.
		* @return y coordinate value of 2D point.
		*/
		public double get_y()
		{
			return _y;
		}
		/**
		* Sets the points of 2D point.
		* @param x x coordinate of 2D point.
		* @param y y coordinate of 2D point.
		*/
		public void set_points(double x,double y)
		{
			_x=x;
			_y=y;
		} 

	}
}