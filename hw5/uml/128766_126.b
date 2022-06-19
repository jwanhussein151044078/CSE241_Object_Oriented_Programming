class TRIANGLE
!!!145406.cpp!!!	get_length() : double
  return length ;
!!!145534.cpp!!!	get_height() : double
  return height ;
!!!145662.cpp!!!	get_direction() : int
  return direction ;
!!!145790.cpp!!!	get_area() : double
  return area ;
!!!145918.cpp!!!	get_perimeter() : double
  return perimeter ;
!!!146046.cpp!!!	set_length(in l : double) : void
		length = l ;
		check_data();
		set_height();
		set_area();
		set_perimeter();
!!!147198.cpp!!!	check_data() : void
		if (length < 0 )
			length *= -1 ;
		if (direction != 1 && direction != 2 && direction != 3 && direction != 4 ){
			direction = 1 ;
		}
!!!147326.cpp!!!	set_height() : void
		height = length*sqrt(3)/2;
!!!147454.cpp!!!	set_area() : void
		area = (sqrt(3)/4)*pow(length,2);
!!!147582.cpp!!!	set_perimeter() : void
		perimeter = length*3;
!!!146302.cpp!!!	operator +(in doub : double) : TRIANGLE
		auto temp = this->get_area() + doub ;
		auto x = this->get_start_point_x();
		auto y = this->get_start_point_y();
	return TRIANGLE((2*sqrt(temp/sqrt(3))),x,y,direction,type);
!!!146430.cpp!!!	operator -(in doub : double) : TRIANGLE
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
!!!146558.cpp!!!	operator ++() : TRIANGLE
		++start_point_x;
		++start_point_y;
		return *this;
!!!146686.cpp!!!	operator ++(in ignore : int) : TRIANGLE
		TRIANGLE *temp = this ;
		this->start_point_x +=1;
		this->start_point_y +=1;
		return *temp;
!!!146814.cpp!!!	operator --() : TRIANGLE
		--start_point_x;
		--start_point_y;
		return *this;
!!!146942.cpp!!!	operator --(in ignore : int) : TRIANGLE
		TRIANGLE *temp = this ;
		this->start_point_x -=1;
		this->start_point_y -=1;
		return *temp;
!!!147070.cpp!!!	print_data() : void
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
!!!146174.cpp!!!	print_shape(inout t : ostream) : ostream
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
