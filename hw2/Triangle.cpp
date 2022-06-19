# include <iostream>
# include <cmath>
# include <string>
# include <fstream>
# include "Triangle.h"

# define STOKE 2 

  using namespace std;


Triangle::Triangle(){
	length = 0 ;
}

Triangle::Triangle(double l){
	length = l ;
}

bool Triangle::set_length(double l ){
	if (l <= 0){
		return false ;
	}
	length = l ;
	return true ;
}
void Triangle::set_position_direction(double start_x,double start_y,int d){
	s_p_x = start_x ;
	s_p_y = start_y ;
	direction = d ;
}

double Triangle::get_size()const{
	return sqrt(3)*length*length/4;
}

double Triangle::get_hight()const{
	return (length*sqrt(3))/2;
}

double Triangle::get_length()const{
	return length ;
}

void Triangle::draw_Triangle(ofstream & file ,const string color )const{
	
	const char temp = '"' ;
	if (direction == 1){
		file << "<polygon points="<<temp<<" " << s_p_x << " " << s_p_y << ", " 
			 << (s_p_x + length) << " " << (s_p_y) << ", " 
			 << (s_p_x + (length/2)) << " " << (s_p_y - get_hight()) << temp << " " 
			 << " stroke=" << temp << "black" << temp << " stroke-width=" << temp << STOKE << temp
	  		 <<" fill="<<temp<<color<<temp<<"/>\n";
	}
	if (direction == 2){
		file << "<polygon points="<<temp<<" " << s_p_x << " " << s_p_y << ", " 
			 << (s_p_x + length) << " " << (s_p_y) << ", " 
			 << (s_p_x + (length/2)) << " " << (s_p_y + get_hight()) << temp << " " 
			 << " stroke=" << temp << "black" << temp << " stroke-width=" << temp << STOKE << temp
	  		 <<" fill="<<temp<<color<<temp<<"/>\n";
	}
	if (direction == 3){
		file << "<polygon points="<<temp<<" " << s_p_x << " " << s_p_y << ", " 
			 << (s_p_x ) << " " << (s_p_y + length ) << ", " 
			 << (s_p_x +get_hight()) << " " << (s_p_y+(length/2)) << temp << " " 
			 << " stroke=" << temp << "black" << temp << " stroke-width=" << temp << STOKE << temp
	  		 <<" fill="<<temp<<color<<temp<<"/>\n";
	}
	if (direction == 4){
		file << "<polygon points="<<temp<<" " << s_p_x << " " << s_p_y << ", " 
			 << (s_p_x - get_hight()) << " " << (s_p_y + (length/2) ) << ", " 
			 << (s_p_x ) << " " << (s_p_y+length) << temp << " " 
			 << " stroke=" << temp << "black" << temp << " stroke-width=" << temp << STOKE << temp
	  		 <<" fill="<<temp<<color<<temp<<"/>\n";
	}

}