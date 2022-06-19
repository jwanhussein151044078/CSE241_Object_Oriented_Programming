# include <iostream>
# include <string>
# include "SHAPES.h"
# include "polygon.h"
# define C_color "green"
# define I_color "red"

namespace jwan_{


////////////////////////////////////////   point2D    /////////////////////////////////////

polygon::point2D::point2D(double a,double b){
	x = a ;
	y = b ;
	if (!polygon::point2D::check_point()){
		cout << "the coordinate must be positive !!!!!\nthe point has been set to (0,0)..\n";
		x = 0 ;
		y = 0 ;
	}
}

bool polygon::point2D::check_point(){
	if (x < 0 || y < 0){
		return false ;
	}
	return true ;
}	

void polygon::point2D::set_x_y(double a , double b){
	x = a ;
	y = b ;
	if (!polygon::point2D::check_point()){
		cout << "the coordinate must be positive !!!!!\nthe point has been set to (0,0)..\n";
		x = 0 ;
		y = 0 ;
	}
}



////////////////////////////////////////   polygon    /////////////////////////////////////
polygon::polygon(vector<point2D> vec){
	int i = vec.size();  // integer to hold the vector size ;
	x = new double[i];
	y = new double[i];
	count = i ;
	type = unknown ;
	shape = polygon_shape ;
	for(int j =0 ; j< i ; j++){
		x[j] = vec[j].get_x();
		y[j] = vec[j].get_y();
	}
}

polygon::polygon(point2D temp_point2D ){
	x = new double(temp_point2D.get_x());
	y = new double(temp_point2D.get_y());
	count = 1 ;
	type = unknown ;
	shape = point ;
}

polygon::polygon(Rectangle& rec ){
	count = 4 ;
	shape = rectangle_shape ;
	if (rec.get_type() == 'C'){
		set_type(container);
	}
	else{
		set_type(inner);	
	}
	x = new double[count];
	y = new double[count];
	if (rec.get_direction() == 2 ){
		x[0] = rec.get_start_point_x();
		y[0] = rec.get_start_point_y();
		x[1] = rec.get_start_point_x() + rec.get_width();
		y[1] = rec.get_start_point_y();	
		x[2] = rec.get_start_point_x() + rec.get_width() ;
		y[2] = rec.get_start_point_y() + rec.get_length();
		x[3] = rec.get_start_point_x() ;
		y[3] = rec.get_start_point_y() + rec.get_length();
	}
	else {
		x[0] = rec.get_start_point_x();
		y[0] = rec.get_start_point_y();
		x[1] = rec.get_start_point_x() + rec.get_length();
		y[1] = rec.get_start_point_y();	
		x[2] = rec.get_start_point_x() + rec.get_length() ;
		y[2] = rec.get_start_point_y() + rec.get_width();
		x[3] = rec.get_start_point_x() ;
		y[3] = rec.get_start_point_y() + rec.get_width();
	}
}

polygon::polygon(Triangle& tri ){
	count = 3 ;
	shape = triangle_shape ;
	if (tri.get_type() == 'C'){
		set_type(container);
	}
	else{
		set_type(inner);	
	}
	x = new double[count];
	y = new double[count];
	if (tri.get_direction() == 2 ){
		x[0] = tri.get_start_point_x();
		y[0] = tri.get_start_point_y();
		x[1] = tri.get_start_point_x() + tri.get_length();
		y[1] = tri.get_start_point_y();
		x[2] = tri.get_start_point_x() + (tri.get_length()/2);
		y[2] = tri.get_start_point_y() + tri.get_height();
	}
	else if (tri.get_direction() == 3 ){
		x[0] = tri.get_start_point_x();
		y[0] = tri.get_start_point_y();
		x[1] = tri.get_start_point_x();
		y[1] = tri.get_start_point_y() + tri.get_length();
		x[2] = tri.get_start_point_x() + tri.get_height();
		y[2] = tri.get_start_point_y() + (tri.get_length()/2);
	}
	else if (tri.get_direction() == 4 ){
		x[0] = tri.get_start_point_x();
		y[0] = tri.get_start_point_y();
		x[1] = tri.get_start_point_x() - tri.get_height();
		y[1] = tri.get_start_point_y() + (tri.get_length()/2);
		x[2] = tri.get_start_point_x();
		y[2] = tri.get_start_point_y() + tri.get_length();
	}
	else{
		x[0] = tri.get_start_point_x();
		y[0] = tri.get_start_point_y();
		x[1] = tri.get_start_point_x() + tri.get_length();
		y[1] = tri.get_start_point_y();
		x[2] = tri.get_start_point_x() + (tri.get_length()/2);
		y[2] = tri.get_start_point_y() - tri.get_height();
	}
}
polygon::polygon(Circle& cir ){
	count = 100 ;
	shape = circle_shape ;
	if (cir.get_type() == 'C'){
		set_type(container);
	}
	else{
		set_type(inner);	
	}
	x = new double[count];
	y = new double[count];
	double px = cir.get_start_point_x();
	double py = cir.get_start_point_y();

	double radius = cir.get_radius();
	double diameter = radius * 2 ;
	double absi = diameter / 50 ;
	for(int i = 0 ; i <= count/2 ; i++){
		x[i]= px - radius + (i*absi);
		x[count - i - 1]= x[i];
		y[i] =radius - cir.equation_circle( (x[i]-px) );
		y[i] = 2*radius + y[i] +(py - 3*radius);
		y[count - i - 1] = py + cir.equation_circle( (x[i]-px) ) ;
	}

}

const double polygon::get_biggest_x()const{
	double temp = 0 ;
	for (int i = 0; i < count; ++i){
		if(x[i] > temp ){
			temp = x[i];
		}
	}
	return temp ;
}
const double polygon::get_biggest_y()const{
	double temp = 0 ;
	for (int i = 0; i < count; ++i){
		if(y[i] > temp ){
			temp = y[i];
		}
	}
	return temp ;
}

void polygon::set_type(TYPE t){
	type = t ;
}
void polygon::set_shape(SHAPE s){
	shape = s ;
}

ostream& operator <<(ostream& outputStream,const polygon& pol){
	char temp = '"';
	string color ;
	if (pol.type == container){
		color = C_color;
	}
	else{
		color = I_color ;
	}
	outputStream << "<polygon points= "<<temp;
	for(int i =0 ; i < pol.count ; i++){
		outputStream << pol.x[i] << "," << pol.y[i]<<" ";
	}
	outputStream << temp << " stroke=" << temp << "black" << temp << " stroke-width=" << temp << 0.5 << temp 
		 			 << " fill=" << temp << color << temp << " />\n" ;
	
	return outputStream ;
}

const bool operator ==(const polygon& p1 , const polygon& p2){
	if (p1.get_size() == p2.get_size()){
		for(int i =0 ; i < p1.get_size() ; i++){
			if (p1.x[i] != p2.x[i] || p1.y[i] != p2.y[i]){
				return false;
			}
		}
		return true ;
	}
	return false ;
}

const bool operator !=(const polygon& p1 , const polygon& p2){
	if (p1.get_size() == p2.get_size()){
		for(int i =0 ; i < p1.get_size() ; i++){
			if (p1.x[i] != p2.x[i] || p1.y[i] != p2.y[i]){
				return true;
			}
		}
		return false ;
	}
	return true ;
}

const polygon::point2D polygon::operator [](int i){
	if (count != 0){
		if (i < count){
			return polygon::point2D(x[i],y[i]);
		}
		return polygon::point2D(0,0);
	}
	return polygon::point2D(0,0);
}

const polygon polygon::operator +(const polygon& p1){
	int j =0 ;
	vector<point2D> v ;
	for(int i =0 ; i < this->count ; i++){
		point2D* a = new point2D(*this->x++ , *this->y++);
		v.push_back(*a);
		delete a ;
	}
	for(int i =0 ; i < p1.get_size() ; i++ ){
		point2D* a = new point2D(p1.x[i] , p1.y[i]);
		v.push_back(*a);
		delete a ;	
	}
	return polygon(v);
}
////////////////////////////////////////   polyline   /////////////////////////////////////


polyline::polyline(vector<point2D> vec){
	int i = vec.size();  // integer to hold the vector size ;
	x = new double[i];
	y = new double[i];
	count = i ;
	type = unknown ;
	shape = polygon_shape ;
	for(int j =0 ; j< i ; j++){
		x[j] = vec[j].get_x();
		y[j] = vec[j].get_y();
	}
}
polyline::polyline(point2D temp_point2D ){
	x = new double(temp_point2D.get_x());
	y = new double(temp_point2D.get_y());
	count = 1 ;
	type = unknown ;
	shape = point ;
}
polyline::polyline(Rectangle& rec ){
	count = 4 ;
	shape = rectangle_shape ;
	if (rec.get_type() == 'C'){
		set_type(container);
	}
	else{
		set_type(inner);	
	}
	x = new double[count];
	y = new double[count];
	if (rec.get_direction() == 2 ){
		x[0] = rec.get_start_point_x();
		y[0] = rec.get_start_point_y();
		x[1] = rec.get_start_point_x() + rec.get_width();
		y[1] = rec.get_start_point_y();	
		x[2] = rec.get_start_point_x() + rec.get_width() ;
		y[2] = rec.get_start_point_y() + rec.get_length();
		x[3] = rec.get_start_point_x() ;
		y[3] = rec.get_start_point_y() + rec.get_length();
	}
	else {
		x[0] = rec.get_start_point_x();
		y[0] = rec.get_start_point_y();
		x[1] = rec.get_start_point_x() + rec.get_length();
		y[1] = rec.get_start_point_y();	
		x[2] = rec.get_start_point_x() + rec.get_length() ;
		y[2] = rec.get_start_point_y() + rec.get_width();
		x[3] = rec.get_start_point_x() ;
		y[3] = rec.get_start_point_y() + rec.get_width();
	}
}
polyline::polyline(Circle& cir ){
	count = 100 ;
	shape = circle_shape ;
	if (cir.get_type() == 'C'){
		set_type(container);
	}
	else{
		set_type(inner);	
	}
	x = new double[count];
	y = new double[count];
	double px = cir.get_start_point_x();
	double py = cir.get_start_point_y();

	double radius = cir.get_radius();
	double diameter = radius * 2 ;
	double absi = diameter / 50 ;
	for(int i = 0 ; i <= count/2 ; i++){
		x[i]= px - radius + (i*absi);
		x[count - i - 1]= x[i];
		y[i] =radius - cir.equation_circle( (x[i]-px) );
		y[i] = 2*radius + y[i] +(py - 3*radius);
		y[count - i - 1] = py + cir.equation_circle( (x[i]-px) ) ;
	}

}
polyline::polyline(Triangle& tri ){
	count = 3 ;
	shape = triangle_shape ;
	if (tri.get_type() == 'C'){
		set_type(container);
	}
	else{
		set_type(inner);	
	}
	x = new double[count];
	y = new double[count];
	if (tri.get_direction() == 2 ){
		x[0] = tri.get_start_point_x();
		y[0] = tri.get_start_point_y();
		x[1] = tri.get_start_point_x() + tri.get_length();
		y[1] = tri.get_start_point_y();
		x[2] = tri.get_start_point_x() + (tri.get_length()/2);
		y[2] = tri.get_start_point_y() + tri.get_height();
	}
	else if (tri.get_direction() == 3 ){
		x[0] = tri.get_start_point_x();
		y[0] = tri.get_start_point_y();
		x[1] = tri.get_start_point_x();
		y[1] = tri.get_start_point_y() + tri.get_length();
		x[2] = tri.get_start_point_x() + tri.get_height();
		y[2] = tri.get_start_point_y() + (tri.get_length()/2);
	}
	else if (tri.get_direction() == 4 ){
		x[0] = tri.get_start_point_x();
		y[0] = tri.get_start_point_y();
		x[1] = tri.get_start_point_x() - tri.get_height();
		y[1] = tri.get_start_point_y() + (tri.get_length()/2);
		x[2] = tri.get_start_point_x();
		y[2] = tri.get_start_point_y() + tri.get_length();
	}
	else{
		x[0] = tri.get_start_point_x();
		y[0] = tri.get_start_point_y();
		x[1] = tri.get_start_point_x() + tri.get_length();
		y[1] = tri.get_start_point_y();
		x[2] = tri.get_start_point_x() + (tri.get_length()/2);
		y[2] = tri.get_start_point_y() - tri.get_height();
	}
}

const bool operator ==(const polyline& p1 , const polyline& p2){
	if (p1.get_size() == p2.get_size()){
		for(int i =0 ; i < p1.get_size() ; i++){
			if (p1.x[i] != p2.x[i] || p1.y[i] != p2.y[i]){
				return false;
			}
		}
		return true ;
	}
	return false ;
}
const bool operator !=(const polyline& p1 , const polyline& p2){
	if (p1.get_size() == p2.get_size()){
		for(int i =0 ; i < p1.get_size() ; i++){
			if (p1.x[i] != p2.x[i] || p1.y[i] != p2.y[i]){
				return true;
			}
		}
		return false ;
	}
	return true ;
}
ostream& operator <<(ostream& outputStream,const polyline& pol){
	char temp = '"';
	string color ;
	
	outputStream << "<polyline points= "<<temp;
	for(int i =0 ; i < pol.count ; i++){
		outputStream << pol.x[i] << "," << pol.y[i]<<" ";
	}
	outputStream << temp << " stroke=" << temp << "black" << temp << " stroke-width=" << temp << 3 << temp 
		 			 << " fill=" << temp << "none" << temp << " />\n" ;
	
	return outputStream ;
}

const polyline::point2D polyline::operator [](int i){
	if (count != 0){
		if (i < count){
			return polyline::point2D(x[i],y[i]);
		}
		return polyline::point2D(0,0);
	}
	return polyline::point2D(0,0);

}
const polyline polyline::operator +(const polyline& p1){
	int j =0 ;
	vector<point2D> v ;
	for(int i =0 ; i < this->count ; i++){
		point2D* a = new point2D(*this->x++ , *this->y++);
		v.push_back(*a);
		delete a ;
	}
	for(int i =0 ; i < p1.get_size() ; i++ ){
		point2D* a = new point2D(p1.x[i] , p1.y[i]);
		v.push_back(*a);
		delete a ;	
	}
	return polyline(v);
}
			
}


