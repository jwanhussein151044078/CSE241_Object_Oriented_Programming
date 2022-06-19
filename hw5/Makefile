exe : SHAPE.o RECTANGLE.o CIRCLE.o TRIANGLE.o COMPOSEDSHAPE.o global_functions.o POLYGON.o POLYGONVECT.o POLYGONDYN.o 151044078_main.o 
	g++ -o exe 151044078_main.o SHAPE.o RECTANGLE.o CIRCLE.o TRIANGLE.o COMPOSEDSHAPE.o global_functions.o POLYGON.o POLYGONVECT.o POLYGONDYN.o


RECTANGLE.o : RECTANGLE.cpp
	g++ -c -std=c++11 RECTANGLE.cpp

CIRCLE.o : CIRCLE.cpp
	g++ -c -std=c++11 CIRCLE.cpp

TRIANGLE.o : TRIANGLE.cpp
	g++ -c -std=c++11 TRIANGLE.cpp

COMPOSEDSHAPE.o : COMPOSEDSHAPE.cpp
	g++ -c -std=c++11 COMPOSEDSHAPE.cpp

POLYGON.o : POLYGON.cpp
	g++ -c -std=c++11 POLYGON.cpp

POLYGONVECT.o :POLYGONVECT.cpp
	g++ -c -std=c++11 POLYGONVECT.cpp

POLYGONDYN.o :POLYGONDYN.cpp
	g++ -c -std=c++11 POLYGONDYN.cpp

SHAPES.o : SHAPE.cpp
	g++ -c -std=c++11 SHAPE.cpp

global_functions.o : global_functions.cpp
	g++ -c -std=c++11 global_functions.cpp

151044078_main.o : 151044078_main.cpp
	g++ -c -std=c++11 151044078_main.cpp


clean:
	rm *.o exe
	