
hw1 : myprinter_f.o 151044078_main.o 
	g++ -o exe 151044078_main.o myprinter_f.o

myprinter_f.o : myprinter_f.cpp
	g++ -c -std=c++11 myprinter_f.cpp

151044078_main.o : 151044078_main.cpp
	g++ -c -std=c++11 151044078_main.cpp

clean:
	rm *.o exe
	rm *.exe exe
