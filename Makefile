all:main
all:driver

driver: driver.o triangle.o rectangle.o circle.o composedshape.o
	g++ -Wall driver.o triangle.o rectangle.o circle.o composedshape.o -o 161044018_driver

main:	161044018_main.o triangle.o rectangle.o circle.o composedshape.o
	g++ -Wall 161044018_main.o triangle.o rectangle.o circle.o composedshape.o -o 161044018_main

161044018_main.o: 161044018_main.cpp
	g++ -Wall -c 161044018_main.cpp

driver.o: driver.cpp
	g++ -Wall -c driver.cpp

triangle.o: triangle.cpp
	g++ -c -Wall triangle.cpp

rectangle.o: rectangle.cpp
	g++ -c -Wall rectangle.cpp

circle.o: circle.cpp
	g++ -c -Wall circle.cpp

composedshape.o: composedshape.cpp
	g++ -c -Wall composedshape.cpp

clean:	rm -rf *o shape
	
