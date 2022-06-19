# include <iostream>
# include <string>
# include "function.h"

using namespace std;

void take_data(string *shape , double *length , double *width , int i){
	if (i == 1 ){
		cout << "Please enter the main shape shape (R, C, T) >>  ";
	}
	if (i == 2){
		cout << "Please enter the inner shape (R, C, T) >>  ";
	}
	cin >> *shape ;
	if (*shape == "R"){
		cout << "Please enter the length  >> ";
		cin >> *length ;
		cout << "Please enter the width >> ";
		cin >> *width ;
	}
	else if (*shape == "C"){

		cout << "please enter the radius >> " ;
		cin >> *length ;

	}
	else if (*shape == "T"){
		cout << "Please enter the length >> ";
		cin >> *length ;
	}
	else {
		cout << *shape << " is not an option !! \ntry again..\n";
		return take_data(shape , length , width , i);
	}
}

