import java.util.ArrayList;
/*
* 	CSE 241 HW7
*	Goktug Ali Akin
*	161044018
*
*/
public class DriverApp {

	public static void main(String[] args) {
		System.out.printf("This is a driver(client) program tests some classes and their methods\n");
		System.out.printf("Test info messages will print the screen, If any error occurs, errors will be printed too.\n\n");
		System.out.println("# ComposedShape tested in MainApp by GUI, so not tested here.");
		System.out.println("# Conversion constructors from Rectangle,Triangle,Circle tested for PolygonDyn and PolygonVect class.");
		System.out.println("---------------------------------------------------------------");

		Shapes shape_arr [] = new Shapes[9];

		Rectangle rect1 = new Rectangle(150,200);
		Triangle tri1 = new Triangle(100);
		Circle circ1 = new Circle(100);
		PolygonVect polyvect1 = new PolygonVect(rect1);
		PolygonVect polyvect2 = new PolygonVect(tri1);
		PolygonVect polyvect3 = new PolygonVect(circ1);
		PolygonDyn polydyn1 = new PolygonDyn(rect1);
		PolygonDyn polydyn2 = new PolygonDyn(tri1);
		PolygonDyn polydyn3 = new PolygonDyn(circ1);

		shape_arr[0]=rect1;
		shape_arr[1]=tri1;
		shape_arr[2]=circ1;
		shape_arr[3]=polyvect1;
		shape_arr[4]=polyvect2;
		shape_arr[5]=polyvect3;
		shape_arr[6]=polydyn1;
		shape_arr[7]=polydyn2;
		shape_arr[8]=polydyn3;

		PolygonVect [] converted_to_poly = new PolygonVect[9];
		converted_to_poly = TestClass.convertAll(shape_arr);
		System.out.println("# [convertAll] Method tested with shape_arr. All shapes converted to PolygonVect.");
		System.out.println("Lets print the areas with array returned from convertAll method.");
		System.out.println("We expect, areas below must be the same with the areas printed before sortShapes method call.");
		System.out.println("Please check the areas between them to correctnes of conversion.");
		System.out.printf("--> ");
		for (int i=0;i<shape_arr.length;++i)
			System.out.printf("%.2f ",converted_to_poly[i].area());
		System.out.printf("\n------------------------------------------------------------\n");
			
		TestClass.drawAll(shape_arr);
		
		System.out.println("Areas of shapes printed below before [sortShapes method] call. area() methods tested");
		System.out.printf("for different shapes.\n");
		System.out.printf("--> ");
		for (int i=0;i<shape_arr.length; ++i) 
			System.out.printf("%.2f ",shape_arr[i].area());
		System.out.printf("\n\n# [sortShapes] Method tested. Ater sorting areas : \n");

		TestClass.sortShapes(shape_arr); 
		for (int i=0;i<shape_arr.length; ++i) 
			System.out.printf("%.2f ",shape_arr[i].area());
		System.out.printf("\n ------------------------------------------------------------\n");
		System.out.println("# Some exceptions will be tested below, error messages printed with -> specifier.");
		System.out.println("Other exceptions, tested in GUI, such as invalid inputs for Shapes.");
		System.out.println("Passing negative value to Rectangle constructor : ");
		try{
			Rectangle ex_rect = new Rectangle(-50,100);
		}
		catch(Exception ex){
			System.out.printf("-> ");
			System.out.println(ex.getMessage());
		}
		
		System.out.println("Passing empty ArrayList to PolygonVect : ");
		try{

			ArrayList<Polygon.Point2D> abc = new ArrayList<Polygon.Point2D>();
			PolygonVect ex_vect = new PolygonVect(abc);
		}
		catch(Exception ex){
			System.out.printf("-> ");
			System.out.println(ex.getMessage());
		}
		System.out.println("Passing invalid(negative) index for getPoint() method for PolygonDyn : ");
		try{

			polydyn1.getPoint(-1);

		}
		catch(Exception ex){
			System.out.printf("->");
			System.out.println(ex.getMessage());

		}
		System.out.printf("------------------------------------------------------------\n");
		System.out.println("# [drawAll] Method tested with different shapes, output windows generated.");
	}
}