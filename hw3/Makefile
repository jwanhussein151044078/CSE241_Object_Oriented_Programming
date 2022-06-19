
exe : SHAPES.o ComposedShape.o function.o 151044078_main.o 
	g++ -o exe 151044078_main.o SHAPES.o ComposedShape.o function.o

SHAPES.o : SHAPES.cpp
	g++ -c -std=c++11 SHAPES.cpp

ComposedShape.o : ComposedShape.cpp
	g++ -c -std=c++11 ComposedShape.cpp

function.o : function.cpp
	g++ -c -std=c++11 function.cpp

151044078_main.o : 151044078_main.cpp
	g++ -c -std=c++11 151044078_main.cpp

clean:
	rm *.o exe
	