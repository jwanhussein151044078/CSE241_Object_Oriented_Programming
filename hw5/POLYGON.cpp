# include "POLYGON.h"

namespace jwan_{
	typedef POLYGON::point2d in ;


	bool in::check_point(){
		if (x<0)
			x *= -1 ;
		if (y<0)
			y *= -1 ;
	}

	void in::set_points(double a, double b){
		x = a ;
		y = b ;
		check_point();
	}

	const double in::get_x()const {	return x ;}
	const double in::get_y()const {	return y ;}

	void const in::print_point()const{
		cout << "________________\n";
		cout << "x =  "<< x << endl ;
		cout << "y =  "<< y << endl ;
		cout << "________________\n";
	}
}