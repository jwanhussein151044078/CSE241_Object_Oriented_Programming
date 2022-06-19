# include <iostream>
# include <string>
# include <fstream>
# include <cmath>
# include "SHAPES.h"
# define STOKE 0.5 
# define pi 3.14 
# define C_color "green"
# define I_color "red"


double Rectangle::total_area_rectangle = 0 ;
double Rectangle::total_perimeter_rectangle = 0 ;
double Circle::total_area_circle = 0 ;
double Circle::total_circumference = 0 ;		
double Triangle::total_area_triangle = 0 ;
double Triangle::total_perimeter_triangle = 0 ;

///////////////   function for the rectangle's shape /////////////////////////////////////////////////////////

ostream& operator <<(ostream& outputStream,const Rectangle& rect){

	double start_point_x = rect.get_start_point_x();
	double start_point_y = rect.get_start_point_y();
	double length = rect.get_length();
	double width = rect.get_width();
	int direction = rect.get_direction();
	const char temp = '"' ;
	string color ;
	if (rect.get_type() == 'C'){
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
}

const bool operator ==(const Rectangle& r1,const Rectangle& r2){
	return (r1.get_area() == r2.get_area());
}
const bool operator !=(const Rectangle& r1,const Rectangle& r2){
	return (r1.get_area() != r2.get_area());	
}
const bool operator ==(const Rectangle& r,const Circle& c){
	return ( r.get_area() == c.get_area() );
}
const bool operator !=(const Rectangle& r,const Circle& c){
	return ( r.get_area() != c.get_area() );
}
const bool operator ==(const Rectangle& r,const Triangle& t){
	return ( r.get_area() == t.get_area() );	
}
const bool operator !=(const Rectangle& r,const Triangle& t){
	return ( r.get_area() != t.get_area() );
}


Rectangle Rectangle::operator ++(){
	return Rectangle(length,width,++s_p_x,++s_p_y,type,direction);
}

Rectangle Rectangle::operator ++(int ignore){
	double temp_x = s_p_x;
	double temp_y = s_p_y;
	++s_p_x;
	++s_p_y;
	return Rectangle(length,width,temp_x,temp_y,type,direction);
}
Rectangle Rectangle::operator --(){
	return Rectangle(length,width,--s_p_x,--s_p_y,type,direction);
}
Rectangle Rectangle::operator --(int ignore){
	double temp_x = s_p_x;
	double temp_y = s_p_y;
	--s_p_x;
	--s_p_y;
	return Rectangle(length,width,temp_x,temp_y,type,direction);
}

const Rectangle Rectangle::operator +( double doub)const{
	auto temp = this->get_area() + doub ;
	auto w = this->get_width();
	auto x = this->get_start_point_x();
	auto y = this->get_start_point_y();
	auto d = this->get_direction();
	return Rectangle(temp/w,w,x,y,d);
}

const Rectangle Rectangle::operator -(double doub)const{
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
	return Rectangle(temp/w,w,x,y,d);	
}

void Rectangle::check_dimensions(){
	if (length <= 0 || width <= 0 ){
		cout << "invaild dimensions for Rectangle constructor !!\nplease enter the length\n";
		cin >> length ;
		cout << "please enter the width\n";
		cin >> width ;
		check_dimensions();
	}
}




///////////////   function for the Circle's shape /////////////////////////////////////////////////////////

const double Circle::get_area()const{
	return radius*radius*pi;
}

const double Circle::equation_circle(double x)const{
	return sqrt(radius*radius - x*x);
}

const double Circle::get_circumference()const{
	return 2*radius*pi ;
}

ostream& operator <<(ostream& outputStream,const Circle& cir){
	double radius = cir.get_radius();
	double start_point_x = cir.get_start_point_x();
	double start_point_y = cir.get_start_point_y();
	const char temp = '"' ;
	string color ;
	if (cir.get_type() == 'C'){
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
}

const bool operator ==(const Circle& c1,const Circle& c2){
	return (c1.get_area() == c2.get_area());
}
const bool operator !=(const Circle& c1,const Circle& c2){
	return (c1.get_area() != c2.get_area());
}
const bool operator ==(const Circle& c,const Rectangle& r){
	return (c.get_area() == r.get_area());
}
const bool operator !=(const Circle& c,const Rectangle& r){
	return (c.get_area() != r.get_area());
}
const bool operator ==(const Circle& c,const Triangle& t){
	return (c.get_area() == t.get_area());
}
const bool operator !=(const Circle& c,const Triangle& t){
	return (c.get_area() != t.get_area());
}	

Circle Circle::operator ++(){
	return Circle(radius,++s_p_x,++s_p_y,type);
}
Circle Circle::operator ++(int ignore){
	double temp_x = s_p_x;
	double temp_y = s_p_y;
	++s_p_x;
	++s_p_y;
	return Circle(radius,temp_x,temp_y,type);
}
Circle Circle::operator --(){
	return Circle(radius,--s_p_x,--s_p_y,type);
}
Circle Circle::operator --(int ignore){
	double temp_x = s_p_x;
	double temp_y = s_p_y;
	--s_p_x;
	--s_p_y;
	return Circle(radius,temp_x,temp_y,type);
}

const Circle Circle::operator +(double doub)const{
	auto temp = this->get_area() + doub ;
	auto x = this->get_start_point_x();
	auto y = this->get_start_point_y();
	return Circle(sqrt(temp/pi),x,y);
}
const Circle Circle::operator -(double doub)const{
	auto temp = this->get_area() - doub ;
	if (temp < 0){
		cout <<"the expression you are trying to do will set the area of the circle to less than zero !!!!\n"
			 <<"please check the expression in the source code\n"
			 <<"the circle have been returned without any changes !!!!!\n";
			 return *this;
	}
	auto x = this->get_start_point_x();
	auto y = this->get_start_point_y();
	return Circle(sqrt(temp/pi),x,y);
}

void Circle::check_radius(){
	if (radius <= 0){
		cout << "invaild radius for Circle constructor !!\nplease enter the radius\n";
		cin >> radius ;
		check_radius();
	}
}

///////////////   function for the triangle's shape /////////////////////////////////////////////////////////




const double Triangle::get_height()const{
	return length*sqrt(3)/2 ;
}

const double Triangle::get_area()const{
	return pow(length,2)*sqrt(3)/4;
}

ostream& operator <<(ostream& outputStream,const Triangle& tri){

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
}

const bool operator ==(const Triangle& t,const Circle& c){
	return (t.get_area() == c.get_area());
}
const bool operator !=(const Triangle& t,const Circle& c){
	return (t.get_area() != c.get_area());
}
const bool operator ==(const Triangle& t,const Rectangle& r){
	return (t.get_area() == r.get_area());
}
const bool operator !=(const Triangle& t,const Rectangle& r){
	return (t.get_area() != r.get_area());
}
const bool operator ==(const Triangle& t1,const Triangle& t2){
	return (t1.get_area() == t2.get_area());
}
const bool operator !=(const Triangle& t1,const Triangle& t2){
	return (t1.get_area() != t2.get_area());
}	

Triangle Triangle::operator ++(){
	return Triangle(length,++s_p_x,++s_p_y,direction,type);
}

Triangle Triangle::operator ++(int ignore){
	double temp_x = s_p_x;
	double temp_y = s_p_y;
	++s_p_x;
	++s_p_y;
	return Triangle(length,temp_x,temp_y,direction,type);
}
Triangle Triangle::operator --(){
	return Triangle(length,--s_p_x,--s_p_y,direction,type);
}
Triangle Triangle::operator --(int ignore){
	double temp_x = s_p_x;
	double temp_y = s_p_y;
	--s_p_x;
	--s_p_y;
	return Triangle(length,temp_x,temp_y,direction,type);
}

const Triangle Triangle::operator +(double doub)const{
	auto temp = this->get_area() + doub ;
	auto x = this->get_start_point_x();
	auto y = this->get_start_point_y();
	return Triangle((2*sqrt(temp/sqrt(3))),x,y);
}
const Triangle Triangle::operator -(double doub)const{
	auto temp = this->get_area() - doub ;
	if (temp < 0){
		cout <<"the expression you are trying to do will set the area of the circle to less than zero !!!!\n"
			 <<"please check the expression in the source code\n"
			 <<"the circle have been returned without any changes !!!!!\n";
			 return *this;
	}
	auto x = this->get_start_point_x();
	auto y = this->get_start_point_y();
	return Triangle((2*sqrt(temp/sqrt(3))),x,y);	

}

void Triangle::check_length(){
	if (length <= 0){
		cout << "invaild length for Triangle constructor !!\nplease enter the length\n";
		cin >> length ;
		check_length();
	}
}