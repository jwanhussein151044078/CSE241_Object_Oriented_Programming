# include <iostream>
# include <string>
# include <fstream>
# include "Rectangle.h"
# define STOKE 2 

  using namespace std;

Rectangle::Rectangle(){
	length = 0 ;
	width = 0 ;
}

Rectangle::Rectangle(double l , double w){
	length = l ;
	width = w ;
}

bool Rectangle::set_length(double l ){
	if (l <= 0){
		return false ;
	}
	length = l ;
	return true ;
}

bool Rectangle::set_width(double w){
	if (w <= 0){
		return false ;
	}
	width = w ;
	return true ;
}

void Rectangle::set_position_direction(double start_x ,double start_y ,int d){
	s_p_x = start_x ;
	s_p_y = start_y;
	direction = d ;
}

double Rectangle::get_size()const{
	return length*width;
}

double Rectangle::get_length()const{
	return length ;
}

double Rectangle::get_width()const{
	return width ;
}

void Rectangle::draw_rect(ofstream & file , const string color)const{
	
	const char temp = '"' ;
	if ( direction == 1 ){
		file << "<path d=" <<temp<< "M" << s_p_x << " " << s_p_y << " L" 
			 << (s_p_x+length) << " " << s_p_y << " L" 
		 	 << (s_p_x+length) << " " << (s_p_y+width) << " L" 
		 	 << s_p_x<<" " << (s_p_y+width) << " Z" << temp 
		 	 << " stroke=" << temp << "black" << temp << " stroke-width=" << temp << STOKE << temp 
		 	 << " fill=" << temp << color << temp << " />\n" ;
	}
	if ( direction == 2 ){
		file << "<path d=" <<temp<< "M" << s_p_x << " " << s_p_y << " L" 
			 << (s_p_x+width) << " " << s_p_y << " L" 
		 	 << (s_p_x+width) << " " << (s_p_y+length) << " L" 
		 	 << s_p_x<<" " << (s_p_y+length) << " Z" << temp 
		 	 << " stroke=" << temp << "black" << temp << " stroke-width=" << temp << STOKE << temp 
		 	 << " fill=" << temp << color << temp << " />\n" ;
	}
}