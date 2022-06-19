# include <iostream>
# include <string>
# include "function.h"

using namespace std;

void take_data(string *shape , double *length , double *width , int i){
	if (i == 1 ){
		cout << "Please enter the main shape shape (R, C, T)\n";
	}
	if (i == 2){
		cout << "Please enter the inner shape (R, C, T)\n";
	}
	cin >> *shape ;
	if (*shape == "R"){
		cout << "Please enter the length\n";
		cin >> *length ;
		while (*length <= 0){
			cout << "the length should be bigger than zero!!\ntry again..\n";
			cout << "Please enter the length\n";
			cin >> *length ;
		}
		cout << "Please enter the width\n";
		cin >> *width ;
		while (*width <= 0){
			cout << "the width should be bigger than zero!!\ntry again..\n";
			cout << "Please enter the width\n";
			cin >> *width ;
		}
	}
	else if (*shape == "C"){

		cout << "please enter the radius \n" ;
		cin >> *length ;
		while (*length <= 0){
			cout << "the radius should be bigger than zero!!\ntry again..\n";
			cout << "Please enter the radius\n";
			cin >> *length ;
		}

	}
	else if (*shape == "T"){
		cout << "Please enter the length\n";
		cin >> *length ;
		while (*length <= 0){
			cout << "the length should be bigger than zero!!\ntry again..\n";
			cout << "Please enter the length\n";
			cin >> *length ;
		}
	}
	else {
		cout << *shape << " is not an option !! \ntry again..\n";
		return take_data(shape , length , width , i);
	}
}

