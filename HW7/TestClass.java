import java.awt.Graphics;
import javax.swing.JFrame;
import javax.swing.JButton;
import javax.swing.JPanel;
import javax.swing.JDialog;
import java.awt.Color;
import javax.swing.SwingConstants;

/**
* <h1> TestClass </h1>
* This class contains static driver methods to test Shapes hierarchy. 
*/

public class TestClass extends JPanel{

	private Shapes shaperef;

	private TestClass(Shapes shp)
	{
		shaperef=shp;
	}

	@Override
	protected void paintComponent(Graphics g)
	{
		shaperef.draw(g);
	}

	/**
	* Prints the shapes contained in shapes array to Window (JDialog).
	* @param shapearr Shapes array that contains shapes.
	*/
	public static void drawAll(Shapes [] shapearr)
	{
		JFrame frame = new JFrame("Client (Driver)");
		frame.setBounds(100,100,450,300);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);

		int frame_pos = 150;
		for (int i=0;i<shapearr.length;++i) {
			JDialog dialog = new JDialog(frame,shapearr[i].getClass().getName());
			TestClass panel = new TestClass(shapearr[i]);

			dialog.add(panel);
			dialog.setBounds(frame_pos,frame_pos,450,300);
			dialog.setDefaultCloseOperation(JDialog.DISPOSE_ON_CLOSE);
			dialog.setVisible(true);
			frame_pos+=100;
		}
	}
	/**
	* Sorts the shapes given by Shapes Array respect to their areas. Passing Shapes Array will be modified after sorting process.
	* @param shapearr Shapes Array that will be sorted.
	*/
	public static void sortShapes(Shapes [] shapearr)
	{

		Shapes temp;
		if(shapearr.length==0)
			throw new NegativeArraySizeException();

		for (int i = 0; i < shapearr.length-1; ++i)
		{	
			for (int j = 0; j < shapearr.length-i-1 ; ++j)
			{	
				if(shapearr[j].compareTo(shapearr[j+1])==1){ /* boolean > operator tested there */
					
					temp=shapearr[j];
					shapearr[j]=shapearr[j+1];
					shapearr[j+1]=temp;
				}
			}
		}
	}
	/**
	* This method converts all shapes to <b>Polygon</b> (PolygonVect) given by Shapes Array.
	* <b>Rectangle</b>,<b>Triangle</b>,<b>Circle</b>,<b>Polygon</b> object is available for converting.
	* @param shapearr Shapes that will be converted to <b>Polygon</b>.
	* @return New PolygonVect array contains Shapes converted to PolygonVect objects.
	* @throws NegativeArraySizeException If param shapearr is empty.
	* @throws UnsupportedOperationException If shapearr contains invalid shape to convert (ComposedShape) 
	*/
	public static PolygonVect [] convertAll(Shapes [] shapearr)throws UnsupportedOperationException
	{
		if(shapearr.length==0)
			throw new NegativeArraySizeException();

		int valid_shape_ctr=0;

		PolygonVect [] polly_arr;

		for (int i=0;i<shapearr.length;++i) 
		{
			if(shapearr[i] instanceof Rectangle)
				valid_shape_ctr++;
			else if(shapearr[i] instanceof Triangle)
				valid_shape_ctr++;
			else if(shapearr[i] instanceof Circle)
				valid_shape_ctr++;
			else if(shapearr[i] instanceof Polygon)
				valid_shape_ctr++;

		}
		if(valid_shape_ctr>0)
			polly_arr = new PolygonVect[valid_shape_ctr];
		else
			throw new UnsupportedOperationException("No valid conversion.");

		for (int i=0;i<shapearr.length;++i) 
		{
			if(shapearr[i] instanceof Rectangle)
			{
				Rectangle rRef = (Rectangle)shapearr[i];
				polly_arr[i] = new PolygonVect(rRef);
			}
			else if(shapearr[i] instanceof Triangle)
			{
				Triangle tRef = (Triangle)shapearr[i];
				polly_arr[i] = new PolygonVect(tRef);
			}
			else if(shapearr[i] instanceof Circle)
			{
				Circle cRef = (Circle)shapearr[i];
				polly_arr[i] = new PolygonVect(cRef);
			}
			else if(shapearr[i] instanceof PolygonVect)
			{
				PolygonVect pvectRef = (PolygonVect)shapearr[i];
				polly_arr[i] = pvectRef;
			}
			else if(shapearr[i] instanceof PolygonDyn)
			{
				PolygonDyn pdynRef = (PolygonDyn)shapearr[i];
				polly_arr[i] = new PolygonVect(pdynRef);
			}
		}

		return polly_arr;
	}
}