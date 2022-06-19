


exe : Rectangle.o Circle.o Triangle.o ComposedShape.o function.o 151044078_main.o 
	g++ -o exe 151044078_main.o Rectangle.o Circle.o Triangle.o ComposedShape.o function.o

ComposedShape.o : ComposedShape.cpp
	g++ -c -std=c++0x ComposedShape.cpp

Rectangle.o : Rectangle.cpp
	g++ -c -std=c++0x Rectangle.cpp

Circle.o : Circle.cpp
	g++ -c -std=c++0x Circle.cpp

Triangle.o :
	g++ -c -std=c++0x Triangle.cpp

function.o :
	g++ -c -std=c++0x function.cpp

151044078_main.o : 151044078_main.cpp
	g++ -c -std=c++0x 151044078_main.cpp

clean:
	rm *.o exe
	