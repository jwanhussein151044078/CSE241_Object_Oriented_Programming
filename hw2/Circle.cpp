# include <iostream>
# include <string>
# include <fstream>
# include <cmath>
# include "Circle.h"

# define Pi 3.14
# define STOKE 2 
  
  using namespace std;

Circle::Circle(){
	radius = 0 ;
}

Circle::Circle(double r){
	radius = r ;
}

bool Circle::set_radius(double r ){
	if (r <= 0){
		return false ;
	}
	radius = r ;
	return true ;
}

double Circle::equation_circle(double x){
	return sqrt(radius*radius - x*x);
}

void Circle::set_position(double start_x , double start_y ){
	s_p_x = start_x ;
	s_p_y = start_y;
}

double Circle::get_radius()const{
	return radius ;
}

double Circle::get_size()const{
	return radius*radius*Pi;
}

void Circle::draw_Circle(ofstream & file , const string color)const{
	const char temp = '"' ;
	file << "<circle cx="<<temp<< s_p_x <<temp<<" cy="<<temp<< s_p_y <<temp
		 <<" r="<<temp<< radius <<temp
		 << " stroke=" << temp << "black" << temp << " stroke-width=" << temp << STOKE << temp
		 <<" fill="<<temp<<color<<temp<<"/>\n";
}