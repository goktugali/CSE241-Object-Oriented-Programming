all:driver

driver: 161044018_driver.o shape.o polygondyn.o polygonvect.o triangle.o rectangle.o polygon.o circle.o composedshape.o shape.o
	g++ -Wall 161044018_driver.o shape.o polygondyn.o polygonvect.o triangle.o rectangle.o polygon.o circle.o composedshape.o -o 161044018_driver

161044018_driver.o: 161044018_driver.cpp
	g++ -Wall -c 161044018_driver.cpp -std=c++11

shape.o : shape.cpp
	g++ -c -Wall shape.cpp -std=c++11

triangle.o: triangle.cpp
	g++ -c -Wall triangle.cpp -std=c++11

rectangle.o: rectangle.cpp
	g++ -c -Wall rectangle.cpp -std=c++11

circle.o: circle.cpp
	g++ -c -Wall circle.cpp -std=c++11

composedshape.o: composedshape.cpp
	g++ -c -Wall composedshape.cpp -std=c++11

polygon.o : polygon.cpp
	g++ -c -Wall polygon.cpp -std=c++11

polygondyn.o : polygondyn.cpp
	g++ -c -Wall polygondyn.cpp -std=c++11

polygonvect.o : polygonvect.cpp
	g++ -c -Wall polygonvect.cpp -std=c++11

clean:	
	rm -rf *o
cleansvg:
	rm -rf *svg  
