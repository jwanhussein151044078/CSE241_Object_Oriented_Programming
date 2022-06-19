

#ifndef SHAPES_H_
#define SHAPES_H_

using namespace std;


class Circle;
class Triangle;
class Rectangle {
	public:
		
		Rectangle():length(0),width(0),s_p_x(0),s_p_y(0),direction(1){};

		Rectangle(double l , double w): length(l) , width(w){ 
			check_dimensions(); 
			total_area_rectangle += get_area();
			total_perimeter_rectangle += get_perimeter();
		};
		
		Rectangle(double l , double w , double x , double y)
				  : length(l), width(w), s_p_x(x), s_p_y(y){
			check_dimensions(); 
			total_area_rectangle += get_area();
			total_perimeter_rectangle += get_perimeter();
		};

		Rectangle(double l , double w , double x , double y , int d)
				  : length(l), width(w), s_p_x(x), s_p_y(y), direction(d){ 
			check_dimensions(); 
			total_area_rectangle += get_area();
			total_perimeter_rectangle += get_perimeter();
		};

		Rectangle(double l , double w , double x , double y , char t , int d)
				  : length(l), width(w), s_p_x(x), s_p_y(y), type(t), direction(d){ 
			check_dimensions(); 
			total_area_rectangle += get_area();
			total_perimeter_rectangle += get_perimeter();
		};
		  
		void set_dimensions(double l , double w){
			length = l ;
			width = w ;
		}
		void set_start_points(double x , double y){
			s_p_x = x ;
			s_p_y = y ;
		}
		void set_type(char c){	type = c ; }
		void set_direction(int d){	direction = d ; }

		Rectangle operator ++();
		Rectangle operator ++(int ignore);
		Rectangle operator --();
		Rectangle operator --(int ignore);

		const Rectangle operator +(double doub)const;
		const Rectangle operator -(double doub)const;

		const double get_length()const{	return length ;	}
		const double get_width()const{	return width ;	}
		const double get_start_point_x()const{	return s_p_x ;	}
		const double get_start_point_y()const{	return s_p_y ;	}
		const double get_area()const{	return length*width ;  }
		const double get_perimeter()const{  return (2*(length+width)) ;  }
		const int get_direction()const{		return direction ; 	}
		const char get_type()const{	  return type ;	}

		friend const bool operator ==(const Rectangle& r1,const Rectangle& r2);
		friend const bool operator !=(const Rectangle& r1,const Rectangle& r2);		

		friend const bool operator ==(const Rectangle& r,const Circle& c);
		friend const bool operator !=(const Rectangle& r,const Circle& c);

		friend const bool operator ==(const Rectangle& r,const Triangle& t);
		friend const bool operator !=(const Rectangle& r,const Triangle& t);

		friend ostream& operator <<(ostream& outputStream,const Rectangle& rect);

		static double get_total_area(){  return total_area_rectangle ;}
		static double get_total_perimeter(){  return total_perimeter_rectangle ;}

	private:
		double length , width ; 	// the length and the width of the rectangle
		double s_p_x , s_p_y ;		// start point on x and y 
		int direction ;		// to define if the rectangle will be drawn horizontally or vertically
		char type;		// to define if the rectangle will be a container or inner shape 
		static double total_area_rectangle ;
		static double total_perimeter_rectangle;
		void check_dimensions();
};


class Circle {
	public:
		
		Circle():radius(0),s_p_x(0),s_p_y(0){};

		Circle(double r):radius(r){  
			check_radius() ;
			total_area_circle += get_area();
			total_circumference += get_circumference();
		};

		Circle(double r , double x , double y):radius(r),s_p_x(x),s_p_y(y){ 
			check_radius() ; 
			total_area_circle += get_area();
			total_circumference += get_circumference();
		};

		Circle(double r , double x , double y , char t):radius(r),s_p_x(x),s_p_y(y),type(t){  
			check_radius() ; 
			total_area_circle += get_area();
			total_circumference += get_circumference();
		};

		void set_radius(double r){ 
			radius = r ;
		}

		void set_start_points(double x ,double y){ 
			s_p_x = x ;
			s_p_y = y ;
		}
		void set_type(char t){
			type = t ;
		}

		Circle operator ++();
		Circle operator ++(int ignore);
		Circle operator --();
		Circle operator --(int ignore);
		
		const Circle operator +(double doub)const;
		const Circle operator -(double doub)const;

		const double get_radius()const{	return radius ;	}
		const double get_start_point_x()const{	return s_p_x; }
		const double get_start_point_y()const{	return s_p_y; }
		const char get_type()const{	return type;	}
		const double get_area()const;
		const double get_circumference()const;
		const double equation_circle(double x)const;

		friend const bool operator ==(const Circle& c1,const Circle& c2);
		friend const bool operator !=(const Circle& c1,const Circle& c2);

		friend const bool operator ==(const Circle& r,const Rectangle& c);
		friend const bool operator !=(const Circle& r,const Rectangle& c);

		friend const bool operator ==(const Circle& r,const Triangle& t);
		friend const bool operator !=(const Circle& r,const Triangle& t);		
		
		friend ostream& operator <<(ostream& outputStream,const Circle& cir);

		static double get_total_area(){return total_area_circle; }
		static double get_total_circumference(){return total_circumference ;}

	private:
		double radius ;
		double s_p_x , s_p_y ;
		char type ;
		static double total_area_circle ;
		static double total_circumference ;
		void check_radius();
};


class Triangle{
	public:
		Triangle():length(0),s_p_x(0),s_p_y(0),direction(1){};

		Triangle(double l):length(l){
			check_length();
			total_area_triangle += get_area();
			total_perimeter_triangle += 3*get_length();
		};

		Triangle(double l ,double x ,double y):length(l),s_p_x(x),s_p_y(y){
			check_length();
			total_area_triangle += get_area();
			total_perimeter_triangle += 3*get_length();
		};

		Triangle(double l ,double x ,double y ,int d ,char t ):length(l),s_p_x(x),s_p_y(y),direction(d),type(t){
			check_length();
			total_area_triangle += get_area();
			total_perimeter_triangle += 3*get_length();
		};

		void set_length(double l){
			length = l ;
		}	
		void set_start_points(double x, double y){
			s_p_x = x ;
			s_p_y = y ;
		}
		void set_direction(int d){	direction = d ; }
		void set_type(char t){	type = t;	}

		Triangle operator ++();
		Triangle operator ++(int ignore);
		Triangle operator --();
		Triangle operator --(int ignore);

		const Triangle operator +(double doub)const;
		const Triangle operator -(double doub)const;

		const double get_length()const {  return length ;  }
		const double get_start_point_x()const {  return s_p_x ;	}
		const double get_start_point_y()const {  return s_p_y ;	}
		const int get_direction()const {  return direction ;  }
		const char get_type()const {  return type ;  }
		const double get_perimeter()const{  return 3*length ;  }
		const double get_height()const;
		const double get_area()const;


		friend const bool operator ==(const Triangle& t1,const Triangle& t2);
		friend const bool operator !=(const Triangle& t1,const Triangle& t2);

		friend const bool operator ==(const Triangle& t,const Rectangle& r);
		friend const bool operator !=(const Triangle& t,const Rectangle& r);

		friend const bool operator ==(const Triangle& r,const Circle& c);
		friend const bool operator !=(const Triangle& r,const Circle& c);			
		
		friend ostream& operator <<(ostream& outputStream,const Triangle& tri);

		static double get_total_area(){  return total_area_triangle ;}
		static double get_total_perimeter(){  return total_perimeter_triangle ;}

	private:
		double length ;
		double s_p_x ,s_p_y ;
		int direction;
		char type;
		static double total_area_triangle ;
		static double total_perimeter_triangle;
		void check_length();
};

#endif /* SHAPES_H_ */