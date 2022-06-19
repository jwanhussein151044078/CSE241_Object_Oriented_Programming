class POLYGONVECT
!!!138110.cpp!!!	POLYGONVECT(inout r : RECTANGLE)
		
		area = r.get_area();
		perimeter = r.get_perimeter();
		type = polygon;
		double sx , sy ;
		sx = r.get_start_point_x();
		sy = r.get_start_point_y();
		point2d a(sx,sy);
		vect.push_back(a);

		if (r.get_direction() == 2 ){
			a.set_points( sx , sy+r.get_length());
			vect.push_back(a);
			a.set_points( sx+r.get_width() , sy+r.get_length() );
			vect.push_back(a);
			a.set_points( sx+r.get_width() , sy );
			vect.push_back(a);
		}
		else {
			a.set_points( sx , sy+r.get_width());
			vect.push_back(a);
			a.set_points( sx+r.get_length() , sy+r.get_width() );
			vect.push_back(a);
			a.set_points( sx+r.get_length() , sy );
			vect.push_back(a);
			
		}
!!!138238.cpp!!!	POLYGONVECT(inout c : CIRCLE)

		area = c.get_area();
		perimeter = c.get_perimeter();
		type = polygon;
		double px = c.get_start_point_x();
		double py = c.get_start_point_y();
		double radius = c.get_radius();

		point2d a;
		int count = 100;

		auto equation_circle = [](double radius , double x){
			return sqrt(radius*radius - x*x);
		};

		double x,y;

		double absi = radius / 25 ;

		for(int i = 0 ; i < count/2 ; i++){
			x = px - radius + (absi*i);	
			y = radius - equation_circle(radius , (x - px) );
			y = 2*radius + y +(py - 3*radius);
			a.set_points(x,y);
			vect.push_back(a);
		}
		for (int i = 0 ; i < count/2 ; ++i)
		{
			x = px + radius - (absi*i);	
			y = py + equation_circle(radius ,(x-px) );
			a.set_points(x,y);
			vect.push_back(a);
		}
		
!!!138366.cpp!!!	POLYGONVECT(inout t : TRIANGLE)
		point2d a ;
		area = t.get_area();
		perimeter = t.get_perimeter();
		type = polygon;
		double x = t.get_start_point_x();
		double y = t.get_start_point_y();
		a.set_points(x,y);
		vect.push_back(a);

		if (t.get_direction() == 2 ){
			a.set_points(x+t.get_length(),y);
			vect.push_back(a);
			a.set_points(x+(t.get_length()/2),y+t.get_height());
			vect.push_back(a);
		}
		else if (t.get_direction() == 3 ){
			a.set_points(x,y+t.get_length());
			vect.push_back(a);
			a.set_points(x+t.get_height(),y+t.get_length()/2);
			vect.push_back(a);
		}
		else if (t.get_direction() == 4 ){
			a.set_points(x-t.get_height(), y + (t.get_length()/2));
			vect.push_back(a);
			a.set_points(x , y+ t.get_length() );
			vect.push_back(a);
		}
		else{
			a.set_points(x+ t.get_length(), y );
			vect.push_back(a);
			a.set_points(x+ (t.get_length()/2) , y - t.get_height() );
			vect.push_back(a);
		}
!!!138494.cpp!!!	get_area() : double
		return area ;
!!!138622.cpp!!!	get_perimeter() : double
		return perimeter ;
!!!138750.cpp!!!	print_data() : void
		cout <<"______________\n";
		cout <<"POLYGONVECT has "<<vect.size()<<" point(s) \n";
		for (int i =0 ; i <vect.size() ; i++){
			cout <<"point "<< i << "    x = " << vect[i].get_x()<<"  y = "<<vect[i].get_y()<<endl;
		}
		cout << "_____________\n";

!!!138878.cpp!!!	print_shape(inout t : ostream) : ostream
		char temp = '"';
		t << "<svg width="<<temp<<1000<<temp<<" hight="<<temp<<1000<<temp<<"> \n";
		t << "<polygon points= "<<temp;
		for(int i =0 ; i < vect.size() ; i++){
			t << vect[i].get_x() << "," << vect[i].get_y()<<" ";
		}
		t << temp << " stroke=" << temp << "black" << temp << " stroke-width=" << temp << 1.5 << temp 
			 			 << " fill=" << temp << "green" << temp << " />\n" ;
		t <<  "\n</svg> ";
		return t ;
!!!139006.cpp!!!	operator ++() : POLYGONVECT
		for(int i =0 ; i < vect.size() ;i++){
			vect[i].set_points(vect[i].get_x()+1 ,vect[i].get_y()+1 );
		}
		return *this;
!!!139134.cpp!!!	operator ++(in ignore : int) : POLYGONVECT
		POLYGONVECT* temp = this ;
		for(int i =0 ; i < vect.size() ;i++){
			vect[i].set_points(vect[i].get_x()+1 ,vect[i].get_y()+1 );
		}
		return *temp;
!!!139262.cpp!!!	operator --() : POLYGONVECT
		for(int i =0 ; i < vect.size() ;i++){
			vect[i].set_points(vect[i].get_x()-1 ,vect[i].get_y()-1 );
		}
		return *this;
!!!139390.cpp!!!	operator --(in ignore : int) : POLYGONVECT
		POLYGONVECT* temp = this ;
		for(int i =0 ; i < vect.size() ;i++){
			vect[i].set_points(vect[i].get_x()-1 ,vect[i].get_y()-1 );
		}
		return *temp;
