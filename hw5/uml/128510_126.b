class COMPOSEDSHAPE
!!!130686.cpp!!!	COMPOSEDSHAPE(inout r1 : RECTANGLE, inout r2 : RECTANGLE)
		*this += &r1;
		*this += &r2;
		fit_R_R();
!!!130814.cpp!!!	COMPOSEDSHAPE(inout r : RECTANGLE, inout c : CIRCLE)
		*this += &r;
		*this += &c;
		fit_C_R();	
!!!130942.cpp!!!	COMPOSEDSHAPE(inout r : RECTANGLE, inout t : TRIANGLE)
		*this += &r;
		*this += &t;
		fit_T_R();
!!!131070.cpp!!!	COMPOSEDSHAPE(inout c : CIRCLE, inout r : RECTANGLE)
		*this += &c;
		*this += &r;
		fit_R_C();
!!!131198.cpp!!!	COMPOSEDSHAPE(inout c1 : CIRCLE, inout c2 : CIRCLE)
		*this += &c1;
		*this += &c2;
		fit_C_C();
!!!131326.cpp!!!	COMPOSEDSHAPE(inout c : CIRCLE, inout t : TRIANGLE)
		*this += &c;
		*this += &t;
		fit_T_C();
!!!131454.cpp!!!	COMPOSEDSHAPE(inout t : TRIANGLE, inout r : RECTANGLE)
		*this += &t;
		*this += &r;
		fit_R_T();
!!!131582.cpp!!!	COMPOSEDSHAPE(inout t : TRIANGLE, inout c : CIRCLE)
		*this += &t;
		*this += &c;
		fit_C_T();
!!!131710.cpp!!!	COMPOSEDSHAPE(inout t1 : TRIANGLE, inout t2 : TRIANGLE)
		*this += &t1;
		*this += &t2;
		fit_T_T();
!!!132990.cpp!!!	operator +=(inout temp : SHAPE) : COMPOSEDSHAPE
	this->vec.push_back(temp);
	return *this ;	
!!!133118.cpp!!!	operator [](in i : int) : SHAPE
		if (i < this->vec.size()){
			return this->vec.at(i);
		}
		cout <<"you are out of the range of the vector\n";
!!!132350.cpp!!!	print_shape(inout t : ostream) : ostream
		char temp = '"';
		auto temp1 = get_size_vector() ;
		t << "<svg width="<<temp<<1000<<temp<<" hight="<<temp<<1000<<temp<<"> \n";
	
		for (auto i = 0 ; i < temp1 ; i++){
			vec[i]->print_shape(t) ;
		}

		t <<  "\n</svg> ";
		return t ;
!!!133246.cpp!!!	fit_R_R() : void
   //fit rectangle in rectangle
		RECTANGLE *pC =  dynamic_cast<RECTANGLE*>(vec[0]); 
		RECTANGLE *pI =  dynamic_cast<RECTANGLE*>(vec[1]); 

		double len = pC->get_length() ;
		double wid = pC->get_width() ;
		double s_len = pI->get_length() ;
		double s_wid = pI->get_width() ;
		double num_on_x = len/s_len ;
	    double num_on_y = wid/s_wid ;
	    int i=0 , j=0 , q =0, w=0;
	    vec.pop_back();
		
	    if(num_on_x <  len/s_wid && num_on_y < wid/s_len){
	    	
	    	num_on_x = len/s_wid ;
	    	for (i=0 ; i <(static_cast<int> (num_on_x) ); i++){
	    			RECTANGLE* a = new RECTANGLE(s_len,s_wid,i*(s_wid),0,1,inner);
		    		*this += a ;	    		
		   }
		   
	    }
	    else {

		    for (i=0 ; i <(static_cast<int> (num_on_x) ); i++){

		    	for(j=0; j < (static_cast<int>(num_on_y)) ; j++){
		    		RECTANGLE* a = new RECTANGLE(s_len,s_wid,i*(s_len),j*(s_wid),1,inner);
		    		*this += a ; 
		    	}
		    }
		    len -= i*s_len ;
		    num_on_x = len / s_wid ;
		    num_on_y = wid / s_len ;
		    for (q=0 ; q <(static_cast<int> (num_on_x) ); q++){
		    	for(w=0; w < (static_cast<int>(num_on_y)) ; w++){
		    		RECTANGLE* a = new RECTANGLE(s_len,s_wid,((i*s_len)+(q*s_wid)),(w)*(s_len),2,inner);
		    		*this += a ;
		    	}
		    }
		}
!!!133374.cpp!!!	fit_C_R() : void
 // fit circle in rectangle
		RECTANGLE *pC =  dynamic_cast<RECTANGLE*>(vec[0]); 
		CIRCLE *pI =  dynamic_cast<CIRCLE*>(vec[1]); 
		double num_on_x = pC->get_length()/(pI->get_radius()*2) ;
	   	double num_on_y = pC->get_width()/(pI->get_radius()*2) ;
	    int i , j ; 
	    double r = pI->get_radius() ;
	    vec.pop_back();
	    for (i=0;i<static_cast<int>(num_on_x);i++){
	    	for(j=0;j<static_cast<int>(num_on_y);j++){
	    		CIRCLE* a = new CIRCLE(r,(i*r*2)+r,(j*r*2)+r,inner);
		    	*this += a ;
	    	}
	    }
!!!133502.cpp!!!	fit_T_R() : void
 // fit triangle in rectangle 
		RECTANGLE *pC =  dynamic_cast<RECTANGLE*>(vec[0]); 
		TRIANGLE *pI =  dynamic_cast<TRIANGLE*>(vec[1]); 
		double len = pC->get_length();
		double width = pC->get_width();
		double s_len = pI->get_length();
		double higth_of_triangle = pI->get_height() ;
		double num_on_x = len/s_len ;
		double num_on_y = width/higth_of_triangle ;
		int i , j ,w=0 , temp;
		vec.pop_back();
		for (i=0 ;i<static_cast<int>(num_on_x); i++ ){
			for(j=0 ; j < static_cast<int>(num_on_y) ; j++){
				if((len - ((i*s_len)+s_len/2)) >= s_len){
					w++;
				}
			}
		}
		temp = (i*j)+w;
		w=0;
		for (i=0 ;i<static_cast<int>(len/higth_of_triangle); i++ ){
			for(j=0 ; j < static_cast<int>(width/s_len) ; j++){
				if((width - ((j*s_len)+s_len/2)) >= s_len){
					w++;
				}
			}
		}
		if (temp > (i*j)+w){
			w=0;
			for (i=0 ;i<static_cast<int>(num_on_x); i++ ){
				for(j=0 ; j < static_cast<int>(num_on_y) ; j++){
	    			TRIANGLE* a = new TRIANGLE(s_len, i*s_len ,j*higth_of_triangle,2,inner);
		    		*this += a ;
					
					if((len - ((i*s_len)+s_len/2)) >= s_len){
						w++;
	    				TRIANGLE* a = new TRIANGLE(s_len, (i*s_len)+s_len/2 ,(j*higth_of_triangle)+higth_of_triangle,1,inner);
		    			*this += a;				
					}
				}
			}
		}
		else{
			w=0;
			for (i=0 ;i<static_cast<int>(len/higth_of_triangle); i++ ){
				for(j=0 ; j < static_cast<int>(width/s_len) ; j++){
	    			TRIANGLE* a = new TRIANGLE(s_len, i*higth_of_triangle ,j*s_len,3,inner);
		    		*this += a ;
					if((width - ((j*s_len)+s_len/2)) >= s_len){
						w++;
	    				TRIANGLE* a = new TRIANGLE(s_len, (i*higth_of_triangle)+higth_of_triangle ,(j*s_len)+s_len/2 ,4,inner);
		    			*this += a ;
					}
				}
			}
		}
!!!133630.cpp!!!	fit_R_C() : void
 // fit rectangle in circle
		CIRCLE *pC =  dynamic_cast<CIRCLE*>(vec[0]); 
		RECTANGLE *pI =  dynamic_cast<RECTANGLE*>(vec[1]); 

		double r =pC->get_radius();
		double width = pI->get_length();
		double hight = pI->get_width();
		vec.pop_back();
		int i , j ,q=0 ;

		auto equation_circle = [](double radius , double x){
			return sqrt(radius*radius - x*x);
		};

		if (r < sqrt((width*width+hight*hight)/4)){
			return ;
		}	
		if(width < hight){
			double temp = width ;
			width = hight ;
			hight = temp ;
		}

		double startpx = r - equation_circle(r ,hight/2);
		double startpy = r - hight/2 ;

		int num_on_x = static_cast<int>((2*r - 2*startpx)/width);
		int num_on_y = static_cast<int>((r - hight/2)/hight);
		startpx = (r*2 - (width*num_on_x))/2; 	
		for(i=0 ; i<num_on_x ;i++){
			RECTANGLE* a = new RECTANGLE(width,hight,startpx,startpy,1,inner);
		    *this += a ;	
			startpx += width;
			q++;
		}
		for(i=1;i<=num_on_y;i++){
			startpy -= hight ;
			startpx =r- equation_circle(r,r- startpy) ;
			num_on_x =  static_cast<int>((2*r - 2*startpx)/width);
			startpx = (r*2 - (width*num_on_x))/2;
			for(j=0 ; j<num_on_x ;j++){
				RECTANGLE* a = new RECTANGLE(width,hight,startpx,startpy,1,inner);
		    	*this += a ;
		    	RECTANGLE* t = new RECTANGLE(width,hight,startpx,startpy+2*i*hight,1,inner);
		    	*this += t ;			
				startpx += width;
				q+= 2;
			} 
		}
!!!133758.cpp!!!	fit_C_C() : void
 // fit circle in circle
		CIRCLE *pC =  dynamic_cast<CIRCLE*>(vec[0]); 
		CIRCLE *pI =  dynamic_cast<CIRCLE*>(vec[1]); 

		double r = pC->get_radius();
		double s_r = pI->get_radius(); 
		vec.pop_back();

		auto equation_circle = [](double radius , double x){
			return sqrt(radius*radius - x*x);
		};

		if(s_r>r){
			return  ;
		}
		else if (2*s_r>r){
			CIRCLE* a = new CIRCLE(s_r,r,r,inner);		   
		    *this += a ;
		    return;
		}
		else if (r/s_r>2 && r/s_r<=2.4){
			CIRCLE* a1 = new CIRCLE(s_r, (r- s_r) , r-(s_r)*0.8, inner);
		    *this += a1 ;
			CIRCLE* a2 = new CIRCLE(s_r, (r+s_r) , r- (s_r)*0.8 , inner);
		    *this += a2 ;
			CIRCLE* a3 = new CIRCLE(s_r, r , r+s_r , inner);
		    *this += a3 ;
			
			return ; 

		}
		else if(r/s_r>2.4 && r/s_r<3){
			CIRCLE* a1 = new CIRCLE(s_r, (r- s_r),r- (s_r), inner);
		    *this += a1 ;
			CIRCLE* a2 = new CIRCLE(s_r, (r+s_r), r- (s_r), inner);
		    *this += a2 ;
			CIRCLE* a3 = new CIRCLE(s_r, (r-s_r), r+(s_r), inner);
		    *this += a3 ;
		    CIRCLE* a4 = new CIRCLE(s_r, (r+s_r), r+(s_r), inner);
		    *this += a4 ;
			return;
		}
		int i ,q=0;
		int num_on_x = static_cast<int>(r/s_r);
		double temp = s_r*sqrt(3);
		double startpx = r-(s_r*(num_on_x-1)) ;
		double startpy = r ;
		for (int i = 0; i < num_on_x; ++i){
			CIRCLE* a = new CIRCLE(s_r, startpx, startpy, inner);
		    *this += a ;
			startpx += 2*s_r ;
		}
		startpy -= temp;
		while(startpy - s_r>=0){
			q++;
			num_on_x--;
			startpx = r-(s_r*(num_on_x-1));
			for (i=1; i <= num_on_x+2 ; i++){
				if (startpy-s_r >= r - equation_circle(r,r-startpx+(2*s_r)) &&
					startpx-(2*s_r)-s_r >= r - equation_circle(r,r-startpy) &&
					startpx-(2*s_r)+s_r <= r+ equation_circle(r,r-startpy) ){
					CIRCLE* a1 = new CIRCLE(s_r, startpx-(2*s_r), startpy, inner);
		    		*this += a1 ;
					CIRCLE* a2 = new CIRCLE(s_r, startpx-(2*s_r), startpy+(2*q*temp), inner);
		    		*this += a2 ;
				}
				startpx += 2*s_r ;
			}
			startpy -= temp;

		}
!!!133886.cpp!!!	fit_T_C() : void
 // fit tirangle in circle
		CIRCLE *pC =  dynamic_cast<CIRCLE*>(vec[0]); 
		TRIANGLE *pI =  dynamic_cast<TRIANGLE*>(vec[1]); 


		int i , j ;
		int num_on_x , num_on_y ;
		double hight_of_triangle = pI->get_height() ;
		double length = pI->get_length();
		double radius = pC->get_radius();
		double startpx ,startpy ,temp = radius;
		vec.pop_back();

		auto equation_circle = [](double radius , double x){
			return sqrt(radius*radius - x*x);
		};

		if (radius < hight_of_triangle*2/3){
			return ;
		}
		if (radius >= hight_of_triangle*2/3 && radius < hight_of_triangle){
			startpx = radius - equation_circle(radius,radius- hight_of_triangle);
			startpx = (2*radius - 2*startpx -length)/2 +startpx ; 
				TRIANGLE* a = new TRIANGLE(length,startpx ,startpy+hight_of_triangle,1,inner);
		    	*this += a ;			
			return ;
		}
		num_on_y = static_cast<int>(radius/hight_of_triangle);
		num_on_x = static_cast<int>(2*temp/length);
		startpx = radius - (length*num_on_x)/2;
		for(i=0;i<num_on_y;i++){
			for(j=0;j<num_on_x;j++ ){
				if (radius - equation_circle(radius,radius - temp ) <= startpx+(j*length) &&
					radius + equation_circle(radius,radius - temp ) >= startpx+(j*length)+length &&
					radius - equation_circle(radius,radius - (startpx+(j*length)+length/2)) <= temp- hight_of_triangle) {
					
					TRIANGLE* a = new TRIANGLE(length,startpx+(j*length) ,temp,1,inner);
		    		*this += a ;
		    		TRIANGLE* a1 = new TRIANGLE(length,startpx+(j*length) ,temp+(2*i*hight_of_triangle),2,inner);
		    		*this += a1 ;					
				}

				if(radius - equation_circle(radius,radius - (temp -hight_of_triangle)) <= (startpx +(j*length)+length/2) &&
				   radius + equation_circle(radius,radius - (temp -hight_of_triangle)) >= (startpx +(j*length)+length*3/2)){
					
					TRIANGLE* a = new TRIANGLE(length,startpx+(j*length)+length/2,temp- hight_of_triangle,2,inner);
		    		*this += a ;
		    		TRIANGLE* a1 = new TRIANGLE(length,startpx+(j*length)+(length/2)
		    									,temp+(2*(i)*hight_of_triangle)+hight_of_triangle,1,inner);
		    		*this += a1 ;
				}
			}
			temp -= hight_of_triangle ;
		}
!!!134014.cpp!!!	fit_R_T() : void
 // fit rectangle in triangle
		TRIANGLE *pC =  dynamic_cast<TRIANGLE*>(vec[0]); 
		RECTANGLE *pI =  dynamic_cast<RECTANGLE*>(vec[1]); 


		int i , j , count=0 ;
		double hight_of_triangle = pC->get_height();
		double length = pC->get_length();
		double width =pI->get_length();
		double hight = pI->get_width();
		double startpx ,startpy ,temp = length;
		int num_on_x ,num_on_y;


		vec.pop_back();

		num_on_y = static_cast<int>(hight_of_triangle/hight);
		for(i=0 ;i<num_on_y;i++){
			temp = temp -2*hight/sqrt(3);
			num_on_x = static_cast<int>(temp/width);
			startpx = hight/sqrt(3)*(i+1);
			startpy = hight_of_triangle - hight*(i+1) ;

			for(j=0;j<num_on_x;j++){
	    		RECTANGLE* a = new RECTANGLE(width,hight,startpx ,startpy,1,inner);
		    	*this += a ;
				startpx += width ;
				count++;	
			}
			startpx += width ;
		}
!!!134142.cpp!!!	fit_C_T() : void
 // fit circle in triangle 
		TRIANGLE *pC =  dynamic_cast<TRIANGLE*>(vec[0]); 
		CIRCLE *pI =  dynamic_cast<CIRCLE*>(vec[1]); 

		int i , j ;
		double hight_of_triangle = pC->get_height() ;
		double length = pC->get_length();
		double r =pI->get_radius();
		double startpx ,startpy ;
		int num_on_x ,num_on_y;

		vec.pop_back();
		if (r > hight_of_triangle/3){
			return ;
		}
		if (r == hight_of_triangle/3){
			CIRCLE* a = new CIRCLE(r,length/2,3*hight_of_triangle/2,inner);
		    *this += a ;
			return ;
		}
		startpx= 3*r/sqrt(3) ;
		startpy = hight_of_triangle - r ;
		num_on_x =	static_cast<int>((length-(6*r/sqrt(3)))/(2*r))+1;
		num_on_y = num_on_x;
		for(j=0;j<num_on_y;j++){
			for(i=0;i<num_on_x ; i++){
				CIRCLE* a = new CIRCLE(r,startpx+(i*2*r),startpy,inner);
		   		*this += a ;
			}
			startpy -= r*sqrt(3);
			startpx += r ;
			num_on_x--;  
		}
!!!134270.cpp!!!	fit_T_T() : void
 // fit triangle in triangle
		TRIANGLE *pC =  dynamic_cast<TRIANGLE*>(vec[0]); 
		TRIANGLE *pI =  dynamic_cast<TRIANGLE*>(vec[1]); 


		int i , j ;
		double hight_of_triangle = pC->get_height() ;
		double len = pC->get_length();
		double hight_of_s_triangle = pI->get_height() ;
		double s_len = pI->get_length();
		
		vec.pop_back();
		double startpx ,startpy ;
		int num_on_x , temp = len;
		int num_on_y = static_cast<int>(hight_of_triangle/hight_of_s_triangle);
		startpy = hight_of_triangle ;
		for(i=1 ; i<= num_on_y ; i++){
			num_on_x = static_cast<int>(temp/s_len);
			startpx = (len- (s_len*num_on_x))/2;
			for(j=1;j<=num_on_x;j++){
				TRIANGLE* a = new TRIANGLE(s_len, startpx ,startpy ,1,inner);
		    	*this += a ;
				startpx += s_len ;
				if (j < num_on_x){
					TRIANGLE* a = new TRIANGLE(s_len, startpx-(s_len/2) ,startpy-hight_of_s_triangle ,2,inner);
		    		*this += a ;
				}
			}
			startpy -= hight_of_s_triangle;		
			temp = temp*(hight_of_triangle - hight_of_s_triangle)/hight_of_triangle ;
			hight_of_triangle -= hight_of_s_triangle ;
		}
