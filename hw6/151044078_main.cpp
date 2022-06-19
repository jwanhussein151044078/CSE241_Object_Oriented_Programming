
# include <iostream>
# include <vector>
# include <string>
# include <set>
# include <list>
# include "Iterator.h"
# include "Iterator.cpp"

# include "Collection.h"
# include "List.h"
# include "vector.h"
# include "vector.cpp"
# include "Arraylist.h"
# include "Arraylist.cpp"
# include "PriorityQueue.h"
# include "PriorityQueue.cpp"
# include "LinkedList.h"
# include "LinkedList.cpp"


using namespace std ;
using namespace jwan_ ;

 int main (){ 	 
 
 	cout << "______________    vector test (int)  _____________\n\n\n";
 	Iterator<int , std::vector > it1 , it2 , it3 , it4 ;
 	jwan_::vector<int , std::vector > a ;
 	jwan_::vector<int , std::vector > c ;
 	a.insert(1);
 	a.insert(5);
 	a.insert(2);
 	a.insert(3);
 	a.insert(0);
 	a.insert(8);
 	a.insert(7);
 	a.insert(11);
 	
 	c.insert(1);
 	c.insert(3);
 	c.insert(10);
 	
 	if (a.containsAll(c))
 		cout<< "contains All\n";

 	if (a.contains(5))
 		cout << "a contains 5  \n";

 	a.add(5);
 	it1 = a.iterator();
 	a.addAll(c);
 	it2 = a.iterator();
 	a.retainAll(c);
 	it3 = a.iterator();
 	a.removeAll(c);
 	it4 = a.iterator();

cout << "_______________________\n";

 	while (it1.hasnext() ){
 		cout << *it1 <<endl;
 		it1.next();

 	}
cout << "_______________________\n";

 	while (it2.hasnext() ){
 		cout << *it2 <<endl;
 		it2.next();

 	}
cout << "_______________________\n";

 	while (it3.hasnext() ){
 		cout << *it3 <<endl;
 		it3.next();

 	}
cout << "_______________________\n";

 	while (it4.hasnext() ){
 		cout << *it4 <<endl;
 		it4.next();

 	}
 	cout<<"\n\n___________________\n";

cout << "______________    vector test (string)  _____________\n\n\n";
	Iterator<string , std::set > it11 , it22 , it33 , it44 ;
 	jwan_::vector<string , std::set > str ;
 	jwan_::vector<string , std::set > str_1 ;
 	str.insert("jwan");
 	str.insert("hussein");
 	str.insert("gtu");
 	str.insert("bilgisayar");

 	str_1.insert("gtu");

 	if (str.contains("gtu")){
 		cout << "str contains gtu \n";
 	}

 	it11 = str.iterator();

 cout << "_______________________\n";

 	while (it11.hasnext() ){
 		cout << *it11 <<endl;
 		it11.next();

 	}

 	str_1.add("CSE241");

 	str.addAll(str_1);
 	it22 = str.iterator();	
 	str.removeAll(str_1);
 	it33 = str.iterator();

cout << "_______________________\n";

 	while (it22.hasnext() ){
 		cout << *it22 <<endl;
 		it22.next();

 	}
cout << "_______________________\n";

 	while (it33.hasnext() ){
 		cout << *it33 <<endl;
 		it33.next();

 	}

cout << "____________________ end vector test ______________\n";




cout << "____________________  Arraylist test (int)______________\n";
Arraylist<int,std::vector> array1 , array2 ;
Iterator<int ,std::vector> ar_it1 , ar_it2 ;

	array1.insert(1);
	array1.insert(4);
	array1.insert(2);
	array1.insert(9);
	array1.insert(2);

	array2.insert(1);
	array2.insert(9);

	array1.add(11);
	array1.addAll(array2);
	ar_it2 = array1.iterator();

	array1.remove(4);
	array1.retainAll(array2);
		
		if(array1.contains(9))
			cout << "contains 9\n";

		if(array1.containsAll(array2))
			cout << "array1 containsAll array2 \n";


	ar_it1 = array1.iterator();
cout << "_______________________\n";

 	while (ar_it2.hasnext() ){
 		cout << *ar_it2 <<endl;
 		ar_it2.next();

 	}	


cout << "_______________________\n";

 	while (ar_it1.hasnext() ){
 		cout << *ar_it1 <<endl;
 		ar_it1.next();

 	}	

cout << "____________________  Arraylist test (sting) ______________\n";
Arraylist<string,std::vector> array_str , array2_str ;
Iterator<string ,std::vector> ar_it1_str , ar_it2_str ;

	array_str.insert("i am");
	array_str.insert("test");
	array_str.insert("for");
	array_str.insert("Arraylist");
	array_str.insert("string");

	array2_str.insert("string");
	array2_str.insert("CSE241");

	array_str.add("hi");
	array_str.addAll(array2_str);
	ar_it2_str = array_str.iterator();

	array_str.remove("for");
	array_str.retainAll(array2_str);
		
		if(array_str.contains("for"))
			cout << "contains for\n";

		if(array_str.containsAll(array2_str))
			cout << "array1 containsAll array2 \n";


	ar_it1_str = array_str.iterator();
cout << "_______________________\n";

 	while (ar_it2_str.hasnext() ){
 		cout << *ar_it2_str <<endl;
 		ar_it2_str.next();

 	}	


cout << "_______________________\n";

 	while (ar_it1_str.hasnext() ){
 		cout << *ar_it1_str <<endl;
 		ar_it1_str.next();

 	}
 	cout << "____________________ end Arraylist test ______________\n";
	

cout << "____________________  PriorityQueue test (int)  ______________\n\n\n";
 	PriorityQueue<int , std::list> ob1 , ob2 ;
 	Iterator< int ,std::list> it_p1 , it_p2 ;

 	ob1.add(12);
 	ob1.add(0);
 	ob1.add(15);
 	ob1.add(56);
 	ob1.add(1);

 	it_p1 = ob1.iterator();
cout << "_______________________\n";

 	while (it_p1.hasnext() ){
 		cout << *it_p1 <<endl;
 		it_p1.next();

 	}

 	ob2.add(56);
 	ob2.add(123);	
 	ob1.addAll(ob2);
 	it_p1 = ob1.iterator();
cout << "_______________________\n";

 	while (it_p1.hasnext() ){
 		cout << *it_p1 <<endl;
 		it_p1.next();

 	}

 	ob1.pop();
 	ob1.pop();
 	ob1.add(156);
 	it_p1 = ob1.element();
cout << "_______________________\n";

 	while (it_p1.hasnext() ){
 		cout << *it_p1 <<endl;
 		it_p1.next();

 	}
 	

 	it_p1 = ob1.poll();
cout << "_______________________\n";

 	while (it_p1.hasnext() ){
 		cout << *it_p1 <<endl;
 		it_p1.next();

 	}
 	cout << "____________________ end PriorityQueue test ______________\n";


 	cout << "____________________  linkedlist test (sting) ______________\n\n\n";
 	LinkedList<string,std::vector> l_str , l_str2 ;
	Iterator<string ,std::vector> it_l1 , it_l2 ;

	l_str.add("midterm");
	l_str.add("final");
	l_str.add("quiz");
	l_str.add("grades");

	l_str2.add("final");
	l_str2.add("attendence");
	l_str2.add("grades");


	it_l1 = l_str.element();
cout << "_______________________\n";

 	while (it_l1.hasnext() ){
 		cout << *it_l1 <<endl;
 		it_l1.next();

 	}
 	l_str.pop();
	it_l1 = l_str.element();
cout << "_______________________\n";

 	while (it_l1.hasnext() ){
 		cout << *it_l1 <<endl;
 		it_l1.next();

 	}

cout << "____________________ end LinkedList test ______________\n";

 	return 0 ;
 }