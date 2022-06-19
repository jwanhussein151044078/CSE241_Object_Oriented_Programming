# include <iostream>
# include <string>
# include <fstream>
# include <cmath>
# include "CIRCLE.h"

# define pi 3.14 
# define STOKE 0.5  
# define C_color "green"
# define I_color "red"

namespace jwan_{

	void CIRCLE::check_data(){
		if (radius < 0){radius *= -1 ;}
	}			
	void CIRCLE::set_area(){
		area =  pi*radius*radius ;
	}

	void CIRCLE::set_perimeter(){
		perimeter = 2*pi*radius ; 
	}
	
	const double CIRCLE::get_radius()const{
		return radius ;
	}
	const double CIRCLE::get_area()const{
		return area ;
	}
	const double CIRCLE::get_perimeter()const{
		return perimeter ;
	}

	void CIRCLE::set_radius(double r){
		radius = r ;
		check_data();
		set_area();
		set_perimeter();
	}

	CIRCLE& CIRCLE::operator ++(){
		++start_point_x;
		++start_point_y;
		return *this;
	}

	CIRCLE& CIRCLE::operator++(int ignore ){
		CIRCLE *temp = this ;
		this->start_point_x +=1;
		this->start_point_y +=1;
		return *temp;
	}

	CIRCLE& CIRCLE::operator --(){
		--start_point_x;
		--start_point_y;
		return *this;
	}
	
	CIRCLE& CIRCLE::operator --(int ignore){
		CIRCLE *temp = this ;
		this->start_point_x -=1;
		this->start_point_y -=1;
		return *temp;
	}

	const CIRCLE CIRCLE::operator +(double doub)const{
		auto temp = this->get_area() + doub ;
		auto x = this->get_start_point_x();
		auto y = this->get_start_point_y();
		return CIRCLE(sqrt(temp/pi),x,y);
	}

	const CIRCLE CIRCLE::operator -(double doub)const{
		auto temp = this->get_area() - doub ;
		if (temp < 0){
			cout <<"the expression you are trying to do will set the area of the circle to less than zero !!!!\n"
				 <<"please check the expression in the source code\n"
				 <<"the circle have been returned without any changes !!!!!\n";
				 return *this;
		}
		auto x = this->get_start_point_x();
		auto y = this->get_start_point_y();
		return CIRCLE(sqrt(temp/pi),x,y);
	}
	const void  CIRCLE::print_data()const {
		cout << "the data of the circle !!\n";
		cout << "_______________________________\n";
		cout<< "radius = " << get_radius()<< endl;
		cout<< "start_point_x = " << get_start_point_x()<< endl;
		cout<< "start_point_y = " << get_start_point_y()<< endl;
		cout<< "area = "<< get_area()<<endl;
		cout<< "perimeter = "<< get_perimeter()<<endl;
		if (get_type() == container)
			cout << "type = container "<<endl;
		else cout << "type = inner "<<endl;

		cout << "_______________________________\n";
	}

	ostream& CIRCLE::print_shape(ostream& t){
		double radius = get_radius();
		double start_point_x = get_start_point_x();
		double start_point_y = get_start_point_y();
		const char temp = '"' ;
		string color ;
		if (get_type() == container){
			color = C_color ;
		}
		else {
			color = I_color;
		}
		t << "<circle cx="<<temp<< start_point_x <<temp<<" cy="<<temp<< start_point_y <<temp
					 <<" r="<<temp<< radius <<temp
					 << " stroke=" << temp << "black" << temp << " stroke-width=" << temp << STOKE << temp
					 <<" fill="<<temp<<color<<temp<<"/>\n";
		return t ;
	}

	/*ostream& operator <<(ostream& outputStream,const CIRCLE& cir){
		double radius = cir.get_radius();
		double start_point_x = cir.get_start_point_x();
		double start_point_y = cir.get_start_point_y();
		const char temp = '"' ;
		string color ;
		if (cir.get_type() == container){
			color = C_color ;
		}
		else {
			color = I_color;
		}
		outputStream << "<circle cx="<<temp<< start_point_x <<temp<<" cy="<<temp<< start_point_y <<temp
					 <<" r="<<temp<< radius <<temp
					 << " stroke=" << temp << "black" << temp << " stroke-width=" << temp << STOKE << temp
					 <<" fill="<<temp<<color<<temp<<"/>\n";
		return outputStream;
	}*/

}