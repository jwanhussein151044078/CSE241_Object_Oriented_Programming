class CIRCLE
!!!130174.cpp!!!	check_data() : void
		if (radius < 0){radius *= -1 ;}
!!!130302.cpp!!!	set_area() : void
		area =  pi*radius*radius ;
!!!130430.cpp!!!	set_perimeter() : void
		perimeter = 2*pi*radius ; 
!!!128638.cpp!!!	get_radius() : double
		return radius ;
!!!128766.cpp!!!	get_area() : double
		return area ;
!!!128894.cpp!!!	get_perimeter() : double
		return perimeter ;
!!!129022.cpp!!!	set_radius(in r : double) : void
		radius = r ;
		check_data();
		set_area();
		set_perimeter();
!!!129534.cpp!!!	operator ++() : CIRCLE
		++start_point_x;
		++start_point_y;
		return *this;
!!!129662.cpp!!!	operator ++(in ignore : int) : CIRCLE
		CIRCLE *temp = this ;
		this->start_point_x +=1;
		this->start_point_y +=1;
		return *temp;
!!!129790.cpp!!!	operator --() : CIRCLE
		--start_point_x;
		--start_point_y;
		return *this;
!!!129918.cpp!!!	operator --(in ignore : int) : CIRCLE
		CIRCLE *temp = this ;
		this->start_point_x -=1;
		this->start_point_y -=1;
		return *temp;
!!!129278.cpp!!!	operator +(in doub : double) : CIRCLE
		auto temp = this->get_area() + doub ;
		auto x = this->get_start_point_x();
		auto y = this->get_start_point_y();
		return CIRCLE(sqrt(temp/pi),x,y);
!!!129406.cpp!!!	operator -(in doub : double) : CIRCLE
		auto temp = this->get_area() - doub ;
		if (temp < 0){
			cout <<"the expression you are trying to do will set the area of the circle to less than zero !!!!\n"
				 <<"please check the expression in the source code\n"
				 <<"the circle have been returned without any changes !!!!!\n";
				 return *this;
		}
		auto x = this->get_start_point_x();
		auto y = this->get_start_point_y();
		return CIRCLE(sqrt(temp/pi),x,y);
!!!130046.cpp!!!	print_data() : void
		cout << "the data of the circle !!\n";
		cout << "_______________________________\n";
		cout<< "radius = " << get_radius()<< endl;
		cout<< "start_point_x = " << get_start_point_x()<< endl;
		cout<< "start_point_y = " << get_start_point_y()<< endl;
		cout<< "area = "<< get_area()<<endl;
		cout<< "perimeter = "<< get_perimeter()<<endl;
		if (get_type() == container)
			cout << "type = container "<<endl;
		else cout << "type = inner "<<endl;

		cout << "_______________________________\n";
!!!129150.cpp!!!	print_shape(inout t : ostream) : ostream
		double radius = get_radius();
		double start_point_x = get_start_point_x();
		double start_point_y = get_start_point_y();
		const char temp = '"' ;
		string color ;
		if (get_type() == container){
			color = C_color ;
		}
		else {
			color = I_color;
		}
		t << "<circle cx="<<temp<< start_point_x <<temp<<" cy="<<temp<< start_point_y <<temp
					 <<" r="<<temp<< radius <<temp
					 << " stroke=" << temp << "black" << temp << " stroke-width=" << temp << STOKE << temp
					 <<" fill="<<temp<<color<<temp<<"/>\n";
		return t ;
