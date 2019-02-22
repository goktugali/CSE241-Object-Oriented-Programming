all:main
all:driver

driver: 161044018_driver.o triangle.o rectangle.o polygon.o polyline.o circle.o composedshape.o
	g++ -Wall 161044018_driver.o triangle.o rectangle.o polygon.o polyline.o circle.o composedshape.o -o 161044018_driver

main:	161044018_main.o triangle.o rectangle.o polygon.o polyline.o circle.o composedshape.o
	g++ -Wall 161044018_main.o triangle.o polygon.o polyline.o rectangle.o circle.o composedshape.o -o 161044018_main

161044018_main.o: 161044018_main.cpp
	g++ -Wall -c 161044018_main.cpp

161044018_driver.o: 161044018_driver.cpp
	g++ -Wall -c 161044018_driver.cpp

triangle.o: triangle.cpp
	g++ -c -Wall triangle.cpp

rectangle.o: rectangle.cpp
	g++ -c -Wall rectangle.cpp

circle.o: circle.cpp
	g++ -c -Wall circle.cpp

composedshape.o: composedshape.cpp
	g++ -c -Wall composedshape.cpp

polygon.o : polygon.cpp
	g++ -c -Wall polygon.cpp

polyline.o : polyline.cpp
	g++ -c -Wall polyline.cpp

clean:	
	rm -rf *o  
	
