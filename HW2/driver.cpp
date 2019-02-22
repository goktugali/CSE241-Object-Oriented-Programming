#include <iostream>
#include <fstream>
#include "composedshape.h"

using namespace std;

int main(){

	bool error=false;

	/** SETTER GETTER TESTS by loop **/
	rectangle r1(95,120),r2(90,120),r3(95,120),r4(350,550);
	rectangle rect_arr[4];
	rect_arr[0]=r1, rect_arr[1]=r2, rect_arr[2]=r3, rect_arr[3]=r4;
	for (int i = 0; i < 4; ++i)
	{
		rect_arr[i].set_cx(0);
		rect_arr[i].set_cy(0);
		if(rect_arr[i].get_cx()!=0 && rect_arr[i].get_cy()!=0)
			error=true;			
	}

	circle c1(8.5),c2(20),c3(30),c4(40);
	circle circle_arr[4];
	circle_arr[0]=c1, circle_arr[1]=c2, circle_arr[2]=c3, circle_arr[3]=c4;

	for (int j = 0; j < 4; ++j)
	{
		circle_arr[j].set_cx(0);
		circle_arr[j].set_cy(0);
		if(circle_arr[j].get_cx()!=0 && circle_arr[j].get_cy()!=0)
			error=true;			
	}
	/** SETTER GETTER TESTS by loop**/

	/** 
	  * Setter getter tests for triangle works automatically when
	  	writing data to the file. You can see the below
	  */

	/** initial values for container triangles **/
	triangle t1(20),t2(30),t3(40),t4(50),t5(160),t6(250);
	double cr1[2]={0,sqrt(3)*80};
	double cr2[2]={80,0};
	double cr3[2]={160,sqrt(3)*80};

	t5.set_cr1(cr1);
	t5.set_cr2(cr2);
	t5.set_cr3(cr3);

	double cr1_2[2]={0,sqrt(3)*125};
	double cr2_2[2]={125,0};
	double cr3_2[2]={250,sqrt(3)*125};

	t6.set_cr1(cr1_2);
	t6.set_cr2(cr2_2);
	t6.set_cr3(cr3_2);
	/** initial values for container triangles **/

	triangle triangle_arr[4];
	triangle_arr[0]=t1, triangle_arr[1]=t2, triangle_arr[2]=t3, triangle_arr[3]=t4;
	
	composedshape mainshape1(r1,c1),mainshape2(r2,c1),mainshape3(r1,t1),mainshape4(r4,r1);
	composedshape mainshape5(t6,c2),mainshape6(t6,r1),mainshape7(t5,t1);

	/** PRINTING THE FILE **/
	/*
	 * Automatically creating output files with different values.
	 * Values initialized up.	
	 */
	
	ofstream file;
	file.open("output1.svg");
	mainshape1.optimalFit(r1,c1);
	mainshape1.draw(file,r1,mainshape1.get_circle_vect());
	file.close();

	file.open("output2.svg");
	mainshape2.optimalFit(r2,c1);
	mainshape2.draw(file,r2,mainshape2.get_circle_vect());
	file.close();
	
	file.open("output3.svg");
	mainshape3.optimalFit(r1,t1);
	mainshape3.draw(file,r1,mainshape3.get_triangle_vect());
	file.close();
	
	file.open("output4.svg");
	mainshape4.optimalFit(r4,r1);
	mainshape4.draw(file,r4,mainshape4.get_rectangle_vect());
	file.close();
	
	file.open("output5.svg");
	mainshape5.optimalFit(t6,c2);
	mainshape5.draw(file,t6,mainshape5.get_circle_vect());
	file.close();
	
	file.open("output6.svg");
	mainshape6.optimalFit(t6,r1);
	mainshape6.draw(file,t6,mainshape6.get_rectangle_vect());
	file.close();
	
	file.open("output7.svg");
	mainshape7.optimalFit(t5,t1);
	mainshape7.draw(file,t5,mainshape7.get_triangle_vect());
	file.close();
	/** PRINTING THE FILE **/

	/** PRINT INFO MSG **/
	cout << "SVG files Generated output1.svg to output7.svg.." << endl;
	cout << "Generated formats" << endl << "- Circle inside rectangle(triangular)" << endl
		 << "- Circle inside rectangle(rectangular)" << endl
		 << "- Rectangle inside rectangle" << endl
		 << "- Triangle inside rectangle " << endl
		 << "- Rectangle inside triangle " << endl
		 << "- Triangle inside rectangle " << endl	
		 << "- Circle inside rectangle " << endl << endl
		 << "# " << error << " error generated" << endl;
	 /** PRINT INFO MSG **/

	return 0;
}