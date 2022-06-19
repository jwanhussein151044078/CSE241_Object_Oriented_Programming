exe : LinkedList.o PriorityQueue.o Arraylist.o vector.o List.o Queue.o Collection.o Iterator.o 151044078_main.o 
	g++ -o  exe 151044078_main.o Iterator.o Collection.o List.o Queue.o PriorityQueue.o vector.o Arraylist.o LinkedList.o

LinkedList.o : LinkedList.cpp
	g++ -c -std=c++11 LinkedList.cpp

PriorityQueue.o : PriorityQueue.cpp
	g++ -c -std=c++11 PriorityQueue.cpp

Arraylist.o : Arraylist.cpp
	g++ -c -std=c++11 Arraylist.cpp

vector.o : vector.cpp
	g++ -c -std=c++11 vector.cpp

List.o : List.cpp
	g++ -c -std=c++11 List.cpp

Queue.o : Queue.cpp
	g++ -c -std=c++11 Queue.cpp

Iterator.o : Iterator.cpp
	g++ -c -std=c++11 Iterator.cpp

Collection.o : Collection.cpp
	g++ -c -std=c++11 Collection.cpp

151044078_main.o : 151044078_main.cpp
	g++ -c -std=c++11 151044078_main.cpp


clean:
	rm *o