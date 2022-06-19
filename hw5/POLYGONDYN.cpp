# include <iostream>
# include "POLYGONDYN.h"

namespace jwan_{
	POLYGONDYN::POLYGONDYN(point2d& p):POLYGON(){
		point = new POLYGON::point2d[1];
		point[0].set_points( p.get_x() , p.get_y());
		size = 1 ;
		area =0 ;
		perimeter = 0 ;
		type = polygon;
	}

	POLYGONDYN::POLYGONDYN(RECTANGLE& r):POLYGON(){
		point = new POLYGON::point2d[4] ;
		size = 4 ;
		area = r.get_area();
		perimeter = r.get_perimeter();
		type = polygon;
		double spx = r.get_start_point_x();
		double spy = r.get_start_point_y();
		point[0].set_points(spx,spy);
		if (r.get_direction() == 2 ){
			point[1].set_points(spx + r.get_width() , spy);
			point[2].set_points(spx + r.get_width() , spy + r.get_length() );
			point[3].set_points(spx ,spy + r.get_length() );
		}
		else {
			point[1].set_points(spx + r.get_length() , spy);
			point[2].set_points(spx + r.get_length() , spy + r.get_width() );
			point[3].set_points(spx ,spy + r.get_width() );
		}


	}

	POLYGONDYN::POLYGONDYN(CIRCLE& c):POLYGON(){
		size = 100 ;
		
		point = new POLYGON::point2d[size];
		double temp_x , temp_y , temp_y1 ;
		double px = c.get_start_point_x();
		double py = c.get_start_point_y();

		double radius = c.get_radius();
		
		double diameter = radius * 2 ;
		double absi = diameter / 50 ;

		auto equation_circle = [](double radius , double x){
			return sqrt(radius*radius - x*x);
		};

		for(int i = 0 ; i <= size/2 ; i++){
			temp_x = px - radius + (i*absi);
			temp_y =radius - equation_circle(radius ,(temp_x - px) );
			temp_y = 2*radius + temp_y +(py - 3*radius);
			point[i].set_points(temp_x,temp_y);

			temp_y1 = py + equation_circle(radius , (temp_x - px ) ) ;
			point[size - i - 1].set_points(temp_x,temp_y1);

		}
		type = polygon;
		area = c.get_area();
		perimeter = c.get_perimeter();
	}

	POLYGONDYN::POLYGONDYN(TRIANGLE& t):POLYGON(){
		point = new POLYGON::point2d[3] ;
		size = 3 ;
		area = t.get_area();
		perimeter = t.get_perimeter();
		type = polygon;
		double spx = t.get_start_point_x();
		double spy = t.get_start_point_y();
		point[0].set_points(spx,spy);
		
		if (t.get_direction() == 2 ){
			point[1].set_points(spx + t.get_length() ,spy);
			point[2].set_points(spx + (t.get_length()/2) ,spy + t.get_height() );
		}
		else if (t.get_direction() == 3 ){
			point[1].set_points(spx , spy + t.get_length() );
			point[2].set_points(spx +  t.get_height() ,spy +(t.get_length()/2));
		}
		else if (t.get_direction() == 4 ){
			point[1].set_points(spx - t.get_height() , spy +(t.get_length()/2));
			point[2].set_points(spx  , spy + t.get_length());
		}
		else{
			point[1].set_points(spx + t.get_length() ,spy);
			point[2].set_points(spx + (t.get_length()/2) ,spy - t.get_height() );
		}
	}

	POLYGONDYN::POLYGONDYN(const POLYGONDYN& o){
		point = new point2d[o.size];
		for(int i =0 ; i < o.size ; i++){
			point[i] = o.point[i];
		}
		size = o.size ;
   		
	}

	POLYGONDYN::~POLYGONDYN(){
		if (point != nullptr){
			delete point ;
			point = NULL ;
		}
	}

	const double POLYGONDYN::get_area()const{ return area ;}
	const double POLYGONDYN::get_perimeter()const{ return perimeter ;}
	
	const void POLYGONDYN::print_data()const{
		cout <<"______________\n";
		cout <<"POLYGONDYN has "<<size<<" point(s) \n";
		for (int i =0 ; i < size ; i++){
			cout <<"point "<< i << "    x = " << point[i].get_x()<<"  y = "<<point[i].get_y()<<endl;
		}
		cout << "_____________\n";
	}
			
	ostream& POLYGONDYN::print_shape(ostream& t){
		char temp = '"';
		t << "<svg width="<<temp<<1000<<temp<<" hight="<<temp<<1000<<temp<<"> \n";
		t << "<polygon points= "<<temp;
		for(int i =0 ; i < size ; i++){
			t << point[i].get_x() << "," << point[i].get_y()<<" ";
		}
		t << temp << " stroke=" << temp << "black" << temp << " stroke-width=" << temp << 1.5 << temp 
			 			 << " fill=" << temp << "green" << temp << " />\n" ;
		t <<  "\n</svg> ";
		return t ;
	}


	POLYGONDYN& POLYGONDYN::operator ++(){
		for(int i =0 ; i < size ;i++){
			point[i].set_points(point[i].get_x()+1 ,point[i].get_y()+1 );
		}
		return *this;
	}

	POLYGONDYN& POLYGONDYN::operator ++(int ignore){
		POLYGONDYN* temp(this) ;
		for(int i =0 ; i < size ;i++){
			point[i].set_points(point[i].get_x()+1 ,point[i].get_y()+1 );
		}
		return *temp;
	}

	POLYGONDYN& POLYGONDYN::operator --(){
		for(int i =0 ; i < size ;i++){
			point[i].set_points(point[i].get_x()-1 ,point[i].get_y()-1 );
		}
		return *this;
	}

	POLYGONDYN& POLYGONDYN::operator --(int ignore){
		POLYGONDYN* temp(this) ;
		for(int i =0 ; i < size ;i++){
			point[i].set_points(point[i].get_x()-1 ,point[i].get_y()-1 );
		}
		return *temp;
	}

	POLYGONDYN& POLYGONDYN::operator = ( const POLYGONDYN& o){
		if (this != &o){
			point = new point2d[o.size];
			for(int i =0 ; i < o.size ; i++){
				point[i] = o.point[i];
			}
			size = o.size ;
		}
		return *this ;
	}

	const POLYGON::point2d POLYGONDYN::operator [] (int i){
		if (i < size && i >= 0 ){
			return point[i];
		}
		cout << "out of range !! ";
		
		return POLYGON::point2d(0,0);
	}


}