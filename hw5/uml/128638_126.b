class RECTANGLE
!!!141950.cpp!!!	check_data() : void
		if (length < 0){length *= -1 ;}
		if (width < 0){width *= -1 ;}
		if (direction != 1 || direction != 2){
			direction = 1 ;
		}
!!!142078.cpp!!!	set_area() : void
		area = length*width ;
!!!142206.cpp!!!	set_perimeter() : void
		perimeter = (length*2) + (width*2) ;
!!!140670.cpp!!!	set_length(in l : double) : void
		length = l ;
		check_data();
		if (width != 0){
			set_area();
			set_perimeter();
		}
!!!140798.cpp!!!	set_width(in w : double) : void
		width = w ;
		check_data();
		if (length != 0){
			set_area();
			set_perimeter();
		}
!!!140030.cpp!!!	get_length() : double
		return length ;
!!!140158.cpp!!!	get_width() : double
		return width ;
!!!140414.cpp!!!	get_area() : double
		return area ;
!!!140542.cpp!!!	get_perimeter() : double
		return perimeter ;
!!!140286.cpp!!!	get_direction() : int
		return direction ;
!!!141822.cpp!!!	print_data() : void
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

!!!141310.cpp!!!	operator ++() : RECTANGLE
		++start_point_x;
		++start_point_y;
		return *this;
!!!141438.cpp!!!	operator ++(in ignore : int) : RECTANGLE
		RECTANGLE *temp = this ;
		this->start_point_x +=1;
		this->start_point_y +=1;
		return *temp;
!!!141566.cpp!!!	operator --() : RECTANGLE
		--start_point_x;
		--start_point_y;
		return *this;
!!!141694.cpp!!!	operator --(in ignore : int) : RECTANGLE
		RECTANGLE *temp = this ;
		this->start_point_x -=1;
		this->start_point_y -=1;
		return *temp;
!!!141054.cpp!!!	operator +(in doub : double) : RECTANGLE
		auto temp = this->get_area() + doub ;
		auto w = this->get_width();
		auto x = this->get_start_point_x();
		auto y = this->get_start_point_y();
		auto d = this->get_direction();
		auto t = this->get_type();
		return RECTANGLE(temp/w,w,x,y,d,t);
!!!141182.cpp!!!	operator -(in doub : double) : RECTANGLE
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
!!!140926.cpp!!!	print_shape(inout t : ostream) : ostream
		
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
