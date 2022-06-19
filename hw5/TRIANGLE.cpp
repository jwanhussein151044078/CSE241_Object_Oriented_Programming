# include <iostream>
# include <string>
# include <fstream>
# include <cmath>
# include "TRIANGLE.h"

# define STOKE 0.5  
# define C_color "green"
# define I_color "red"

namespace jwan_{
	const double TRIANGLE::get_length()const{  return length ; }
	const double TRIANGLE::get_height()const{  return height ; }
	const int TRIANGLE::get_direction()const{  return direction ; }
	const double TRIANGLE::get_area()const{  return area ; }
	const double TRIANGLE::get_perimeter()const{  return perimeter ; }

	void TRIANGLE::set_length(double l){
		length = l ;
		check_data();
		set_height();
		set_area();
		set_perimeter();
	}

	void TRIANGLE::check_data(){
		if (length < 0 )
			length *= -1 ;
		if (direction != 1 && direction != 2 && direction != 3 && direction != 4 ){
			direction = 1 ;
		}
	}
	void TRIANGLE::set_height(){
		height = length*sqrt(3)/2;
	}			
	void TRIANGLE::set_area(){
		area = (sqrt(3)/4)*pow(length,2);
	}
	void TRIANGLE::set_perimeter(){
		perimeter = length*3;
	}

	const TRIANGLE TRIANGLE::operator +(double doub)const{
		auto temp = this->get_area() + doub ;
		auto x = this->get_start_point_x();
		auto y = this->get_start_point_y();
	return TRIANGLE((2*sqrt(temp/sqrt(3))),x,y,direction,type);
	}

	const TRIANGLE TRIANGLE::operator -(double doub)const{
		auto temp = this->get_area() - doub ;
		if (temp < 0){
			cout <<"the expression you are trying to do will set the area of the circle to less than zero !!!!\n"
				 <<"please check the expression in the source code\n"
				 <<"the circle have been returned without any changes !!!!!\n";
				 return *this;
		}
		auto x = this->get_start_point_x();
		auto y = this->get_start_point_y();
		return TRIANGLE((2*sqrt(temp/sqrt(3))),x,y,direction,type);	
	}

	TRIANGLE& TRIANGLE::operator ++(){
		++start_point_x;
		++start_point_y;
		return *this;
	}
	TRIANGLE& TRIANGLE::operator ++(int ignore ){
		TRIANGLE *temp = this ;
		this->start_point_x +=1;
		this->start_point_y +=1;
		return *temp;
	}
	TRIANGLE& TRIANGLE::operator --(){
		--start_point_x;
		--start_point_y;
		return *this;
	}
	TRIANGLE& TRIANGLE::operator --(int ignore){
		TRIANGLE *temp = this ;
		this->start_point_x -=1;
		this->start_point_y -=1;
		return *temp;
	}

	const void  TRIANGLE::print_data()const {
		cout << "the data of the triangle !!\n";
		cout << "_______________________________\n";
		cout<< "length = " << get_length()<< endl;
		cout<< "height = " << get_height()<< endl;
		cout<< "start_point_x = " << get_start_point_x()<< endl;
		cout<< "start_point_y = " << get_start_point_y()<< endl;
		cout<< "area = "<< get_area()<<endl;
		cout<< "perimeter = "<< get_perimeter()<<endl;
		cout<< "direction = "<< get_direction() <<endl;
		if (get_type() == container)
			cout << "type = container "<<endl;
		else cout << "type = inner "<<endl;

		cout << "_______________________________\n";
	}

	ostream& TRIANGLE::print_shape(ostream& t){
		double length = get_length();	
		double start_point_x = get_start_point_x();
		double start_point_y = get_start_point_y();
		double height = get_height();
		int direction = get_direction();
		const char temp = '"' ;
		string color ;
		if (get_type() == container){
			color = C_color ;
		}
		else {
			color = I_color;
		}
		if (direction == 1){
			t << "<polygon points="<<temp<<" " << start_point_x << " " << start_point_y << ", " 
						 << (start_point_x + length) << " " << (start_point_y) << ", " 
						 << (start_point_x + (length/2)) << " " << (start_point_y - height) << temp << " " 
						 << " stroke=" << temp << "black" << temp << " stroke-width=" << temp << STOKE << temp
		 		 		 <<" fill="<<temp<<color<<temp<<"/>\n";
		}
		if (direction == 2){
			t << "<polygon points="<<temp<<" " << start_point_x << " " << start_point_y << ", " 
						 << (start_point_x + length) << " " << (start_point_y) << ", " 
						 << (start_point_x + (length/2)) << " " << (start_point_y + height) << temp << " " 
						 << " stroke=" << temp << "black" << temp << " stroke-width=" << temp << STOKE << temp
				  		 <<" fill="<<temp<<color<<temp<<"/>\n";
		}
		if (direction == 3){
			t << "<polygon points="<<temp<<" " << start_point_x << " " << start_point_y << ", " 
						 << (start_point_x ) << " " << (start_point_y + length ) << ", " 
						 << (start_point_x +height) << " " << (start_point_y+(length/2)) << temp << " " 
						 << " stroke=" << temp << "black" << temp << " stroke-width=" << temp << STOKE << temp
				  		 <<" fill="<<temp<<color<<temp<<"/>\n";
		}
		if (direction == 4){
			t << "<polygon points="<<temp<<" " << start_point_x << " " << start_point_y << ", " 
						 << (start_point_x - height) << " " << (start_point_y + (length/2) ) << ", " 
						 << (start_point_x ) << " " << (start_point_y+length) << temp << " " 
						 << " stroke=" << temp << "black" << temp << " stroke-width=" << temp << STOKE << temp
				  		 <<" fill="<<temp<<color<<temp<<"/>\n";

		}
		return t ;
	}
/*	ostream& operator <<(ostream& outputStream,const TRIANGLE& tri){
		double length = tri.get_length();	
		double start_point_x = tri.get_start_point_x();
		double start_point_y = tri.get_start_point_y();
		double height = tri.get_height();
		int direction = tri.get_direction();
		const char temp = '"' ;
		string color ;
		if (tri.get_type() == 'C'){
			color = C_color ;
		}
		else {
			color = I_color;
		}
		if (direction == 1){
			outputStream << "<polygon points="<<temp<<" " << start_point_x << " " << start_point_y << ", " 
						 << (start_point_x + length) << " " << (start_point_y) << ", " 
						 << (start_point_x + (length/2)) << " " << (start_point_y - height) << temp << " " 
						 << " stroke=" << temp << "black" << temp << " stroke-width=" << temp << STOKE << temp
		 		 		 <<" fill="<<temp<<color<<temp<<"/>\n";
		}
		if (direction == 2){
			outputStream << "<polygon points="<<temp<<" " << start_point_x << " " << start_point_y << ", " 
						 << (start_point_x + length) << " " << (start_point_y) << ", " 
						 << (start_point_x + (length/2)) << " " << (start_point_y + height) << temp << " " 
						 << " stroke=" << temp << "black" << temp << " stroke-width=" << temp << STOKE << temp
				  		 <<" fill="<<temp<<color<<temp<<"/>\n";
		}
		if (direction == 3){
			outputStream << "<polygon points="<<temp<<" " << start_point_x << " " << start_point_y << ", " 
						 << (start_point_x ) << " " << (start_point_y + length ) << ", " 
						 << (start_point_x +height) << " " << (start_point_y+(length/2)) << temp << " " 
						 << " stroke=" << temp << "black" << temp << " stroke-width=" << temp << STOKE << temp
				  		 <<" fill="<<temp<<color<<temp<<"/>\n";
		}
		if (direction == 4){
			outputStream << "<polygon points="<<temp<<" " << start_point_x << " " << start_point_y << ", " 
						 << (start_point_x - height) << " " << (start_point_y + (length/2) ) << ", " 
						 << (start_point_x ) << " " << (start_point_y+length) << temp << " " 
						 << " stroke=" << temp << "black" << temp << " stroke-width=" << temp << STOKE << temp
				  		 <<" fill="<<temp<<color<<temp<<"/>\n";
		}
		return outputStream;
	}*/

}