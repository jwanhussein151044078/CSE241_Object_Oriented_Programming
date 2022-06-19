# include <iostream>
# include <string>
# include <fstream>
# include "RECTANGLE.h"

# define STOKE 0.5 
# define pi 3.14 
# define C_color "green"
# define I_color "red"

namespace jwan_{
	
	void RECTANGLE::check_data(){
		if (length < 0){length *= -1 ;}
		if (width < 0){width *= -1 ;}
		if (direction != 1 || direction != 2){
			direction = 1 ;
		}
	}
	
	void RECTANGLE::set_area(){
		area = length*width ;
	}

	void RECTANGLE::set_perimeter(){
		perimeter = (length*2) + (width*2) ;
	}

	void RECTANGLE::set_length(double l){
		length = l ;
		check_data();
		if (width != 0){
			set_area();
			set_perimeter();
		}
	}
	void RECTANGLE::set_width(double w){
		width = w ;
		check_data();
		if (length != 0){
			set_area();
			set_perimeter();
		}
	}

	const double RECTANGLE::get_length()const{
		return length ;
	}

	const double RECTANGLE::get_width()const{
		return width ;
	}

	const double RECTANGLE::get_area()const{
		return area ;
	} 
			
	const double RECTANGLE::get_perimeter()const{
		return perimeter ;
	}

	const int RECTANGLE::get_direction()const{
		return direction ;
	}
			


	const void  RECTANGLE::print_data()const {
		cout << "the data of the rectangle !!\n";
		cout << "_______________________________\n";
		cout<< "length = " << get_length()<< endl;
		cout<< "whidth = " << get_width()<< endl;
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

	RECTANGLE& RECTANGLE::operator ++(){
		++start_point_x;
		++start_point_y;
		return *this;
	}

	RECTANGLE& RECTANGLE::operator++(int ignore ){
		RECTANGLE *temp = this ;
		this->start_point_x +=1;
		this->start_point_y +=1;
		return *temp;
	}

	RECTANGLE& RECTANGLE::operator --(){
		--start_point_x;
		--start_point_y;
		return *this;
	}
	
	RECTANGLE& RECTANGLE::operator --(int ignore){
		RECTANGLE *temp = this ;
		this->start_point_x -=1;
		this->start_point_y -=1;
		return *temp;
	}

	const RECTANGLE RECTANGLE::operator +( double doub)const{
		auto temp = this->get_area() + doub ;
		auto w = this->get_width();
		auto x = this->get_start_point_x();
		auto y = this->get_start_point_y();
		auto d = this->get_direction();
		auto t = this->get_type();
		return RECTANGLE(temp/w,w,x,y,d,t);
	}

	const RECTANGLE RECTANGLE::operator -(double doub)const{
		auto temp = this->get_area() - doub ;
		if (temp < 0){
			cout <<"the expression you are trying to do will set the area of the rectangle to less than zero !!!!\n"
				 <<"please check the expression in the source code\n"
				 <<"the rectangle have been returned without any changes \n";
			return *this;
		}
		auto w = this->get_width();
		auto x = this->get_start_point_x();	
		auto y = this->get_start_point_y();
		auto d = this->get_direction();
		auto t = this->get_type();
		return RECTANGLE(temp/w,w,x,y,d,t);	
	}

	ostream& RECTANGLE::print_shape(ostream& t){
		
		double start_point_x = get_start_point_x();
		double start_point_y = get_start_point_y();
		double length = get_length();
		double width = get_width();
		int direction = get_direction();
		const char temp = '"' ;
		string color ;
		if (get_type() == container){
			color = C_color ;
		}
		else {
			color = I_color;
		}	

		if ( direction == 1 ){
			t << "<path d=" <<temp<< "M" << start_point_x << " " << start_point_y << " L" 
				 		 << (start_point_x+length) << " " << start_point_y << " L" 
		 				 << (start_point_x+length) << " " << (start_point_y+width) << " L" 
		 				 << start_point_x<<" " << (start_point_y+width) << " Z" << temp 
		 				 << " stroke=" << temp << "black" << temp << " stroke-width=" << temp << STOKE << temp 
		 				 << " fill=" << temp << color << temp << " />\n" ;
		}
		if ( direction == 2 ){
			t << "<path d=" <<temp<< "M" << start_point_x << " " << start_point_y << " L" 
						 << (start_point_x+width) << " " << start_point_y << " L" 
		 				 << (start_point_x+width) << " " << (start_point_y+length) << " L" 
		 				 << start_point_x<<" " << (start_point_y+length) << " Z" << temp 
				 		 << " stroke=" << temp << "black" << temp << " stroke-width=" << temp << STOKE << temp 
				 		 << " fill=" << temp << color << temp << " />\n" ;
		}
		
		return t;
	}

	/*ostream& operator <<(ostream& outputStream,const RECTANGLE& rect){

		double start_point_x = rect.get_start_point_x();
		double start_point_y = rect.get_start_point_y();
		double length = rect.get_length();
		double width = rect.get_width();
		int direction = rect.get_direction();
		const char temp = '"' ;
		string color ;
		if (rect.get_type() == container){
			color = C_color ;
		}
		else {
			color = I_color;
		}	

		if ( direction == 1 ){
			outputStream << "<path d=" <<temp<< "M" << start_point_x << " " << start_point_y << " L" 
				 		 << (start_point_x+length) << " " << start_point_y << " L" 
		 				 << (start_point_x+length) << " " << (start_point_y+width) << " L" 
		 				 << start_point_x<<" " << (start_point_y+width) << " Z" << temp 
		 				 << " stroke=" << temp << "black" << temp << " stroke-width=" << temp << STOKE << temp 
		 				 << " fill=" << temp << color << temp << " />\n" ;
		}
		if ( direction == 2 ){
			outputStream << "<path d=" <<temp<< "M" << start_point_x << " " << start_point_y << " L" 
						 << (start_point_x+width) << " " << start_point_y << " L" 
		 				 << (start_point_x+width) << " " << (start_point_y+length) << " L" 
		 				 << start_point_x<<" " << (start_point_y+length) << " Z" << temp 
				 		 << " stroke=" << temp << "black" << temp << " stroke-width=" << temp << STOKE << temp 
				 		 << " fill=" << temp << color << temp << " />\n" ;
		}
		return outputStream;
	}*/



}