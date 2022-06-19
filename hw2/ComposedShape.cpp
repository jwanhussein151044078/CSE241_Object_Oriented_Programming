# include <iostream>
# include <string>
# include <vector>
# include <fstream>
# include <cmath>
# include "Rectangle.h"
# include "Circle.h"
# include "Triangle.h"
# include "ComposedShape.h"

using namespace std;


void ComposedShape::set_container(const string x ,double length,double width){
	if ( x == "R"){
		R_container.set_length(length);
		R_container.set_width(width);
		R_container.set_position_direction( 0 , 0 ,1);
	}
	if ( x == "C"){
		C_container.set_radius(length);
		C_container.set_position( C_container.get_radius() , C_container.get_radius() );
	}
	if ( x == "T"){
		T_container.set_length(length);
		T_container.set_position_direction(0,T_container.get_hight(),1);
	}
}

void ComposedShape::set_inner(const string x ,double length,double width, double start_x, double start_y, int d){
	if ( x == "R"){
		R_inner.set_length(length);
		R_inner.set_width(width);
		R_inner.set_position_direction(start_x,start_y,d);
	}
	if ( x == "C"){
		C_inner.set_radius(length);
		C_inner.set_position(start_x,start_y);
	}
	if ( x == "T"){
		T_inner.set_length(length);
		T_inner.set_position_direction(start_x,start_y,d);
	}
}

void ComposedShape::draw_first_line(ofstream & file , const string x )const{
	
	const char temp = '"' ;
	if ( x == "R"){
		file << "<svg width="<<temp<<R_container.get_length()<<temp<<" hight="<<temp<<R_container.get_width()<<temp<<"> \n";
	}
	if ( x == "C"){
		file << "<svg width="<<temp<<2*C_container.get_radius()<<temp<<" hight="<<temp<<2*C_container.get_radius()<<temp<<"> \n";
	}
	if ( x == "T"){
		file << "<svg width="<<temp<<T_container.get_length()<<temp<<" hight="<<temp<<T_container.get_hight()<<temp<<"> \n";
	}
}

void ComposedShape::inssert_to_vector(const string x){
	if ( x == "R"){
		Rv.push_back(R_inner);
	}
	if ( x == "C"){
		Cv.push_back(C_inner);	
	}
	if ( x == "T"){
		Tv.push_back(T_inner);
	}
}

int ComposedShape::get_size_v(const string x)const{

	if ( x == "R"){
		return Rv.size();
	}
	if ( x == "C"){
		return Tv.size();	
	}
	if ( x == "T"){
		return Tv.size();
	}
}
double ComposedShape::get_size_container(const string x)const{

	if ( x == "R"){
		return R_container.get_size();
	}
	if ( x == "C"){
		return C_container.get_size();	
	}
	if ( x == "T"){
		return T_container.get_size();
	}
}

double ComposedShape::get_size_inner(const string x)const{

	if ( x == "R"){
		return R_inner.get_size();
	}
	if ( x == "C"){
		return C_inner.get_size();	
	}
	if ( x == "T"){
		return T_inner.get_size();
	}
}

void ComposedShape::draw_container(ofstream & file ,const string x, const string color)const{
	cout<< "ok\n";
	if ( x == "R"){
		R_container.draw_rect(file ,color);
	}
	if ( x == "C"){
		C_container.draw_Circle(file,color);
	}
	if ( x == "T"){
		T_container.draw_Triangle(file,color);
	}
}

void ComposedShape::draw_optimized(ofstream & file ,const string x ,const string color)const{
	if ( x == "R"){
		for (auto i = Rv.begin(); i != Rv.end(); i++){ 
        	 i->draw_rect(file,color); 
        }
	}
	if ( x == "C"){
		for (auto i = Cv.begin(); i != Cv.end(); i++){ 
        	 i->draw_Circle(file,color); 
        }
	}
	if ( x == "T"){
		for (auto i = Tv.begin(); i != Tv.end(); i++){ 
        	 i->draw_Triangle(file,color); 
        }
	}
}

void ComposedShape::draw_last_line(ofstream & file)const{
	file << "\n</svg> ";
}

void ComposedShape::optimalFit(const string container , const string inner){
	
	if (container == "R" && inner == "R"){
		fit_R_R();
	}
	else if (container == "R" && inner == "C"){		
		fit_C_R();
	}
	else if (container == "R" && inner == "T"){
		fit_T_R();
	}
	else if (container == "C" && inner == "R"){
		fit_R_C();
	}
	else if (container == "C" && inner == "C"){
		fit_C_C();
	}
	else if (container == "C" && inner == "T"){
		fit_T_C();
	}
	else if (container == "T" && inner == "R"){
		fit_R_T();
	}
	else if (container == "T" && inner == "C"){
		fit_C_T();
	}
	else if (container == "T" && inner == "T"){
		fit_T_T();
	}
}

void ComposedShape::fit_R_R(){ //fit rectangle in rectangle
	
	double len = R_container.get_length() ;
	double wid = R_container.get_width() ;
	double s_len = R_inner.get_length() ;
	double s_wid = R_inner.get_width() ;

	double num_on_x = len/s_len ;
    double num_on_y = wid/s_wid ;


    int i=0 , j=0 , q =0, w=0;
    
    if(num_on_x <  len/s_wid && num_on_y < wid/s_len){
    	num_on_x = len/s_wid ;
    	for (i=0 ; i <(static_cast<int> (num_on_x) ); i++){
    			set_inner("R",s_len,s_wid,i*(s_wid),0,1);
	    		inssert_to_vector("R");
	   }
	   
    }
    else {
	    for (i=0 ; i <(static_cast<int> (num_on_x) ); i++){
	    	for(j=0; j < (static_cast<int>(num_on_y)) ; j++){
	    		set_inner("R",s_len,s_wid,i*(s_len),j*(s_wid),1);
	    		inssert_to_vector("R");	    		                                       
	    	}
	    }
	    len -= i*s_len ;
	    num_on_x = len / s_wid ;
	    num_on_y = wid / s_len ;
	    for (q=0 ; q <(static_cast<int> (num_on_x) ); q++){
	    	for(w=0; w < (static_cast<int>(num_on_y)) ; w++){
	    		set_inner("R",s_len,s_wid,((i*s_len)+(q*s_wid)),(w)*(s_wid),2);
	    		inssert_to_vector("R");	
	    	}
	    }
	}
	
}

void ComposedShape::fit_C_R(){ // fit circle in rectangle
	double num_on_x = R_container.get_length()/(C_inner.get_radius()*2) ;
    double num_on_y = R_container.get_width()/(C_inner.get_radius()*2) ;
    int i , j ;
    double r =  C_inner.get_radius() ;

    for (i=0;i<static_cast<int>(num_on_x);i++){
    	for(j=0;j<static_cast<int>(num_on_y);j++){
    		set_inner("C",r,0, (i*r*2)+r , (j*r*2)+r ,0);
    		inssert_to_vector("C");
    		
    	}
    }
}

void ComposedShape::fit_T_R(){ // fit triangle in rectangle 
	double higth_of_triangle = T_inner.get_hight() ;
	double len = R_container.get_length();
	double width = R_container.get_width();
	double s_len = T_inner.get_length();
	double num_on_x = len/s_len ;
	double num_on_y = width/higth_of_triangle ;
	int i , j ,w=0 , temp;

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
				set_inner("T",s_len,0, i*s_len , j*higth_of_triangle ,2);
    			inssert_to_vector("T");
				
				if((len - ((i*s_len)+s_len/2)) >= s_len){
					w++;
					set_inner("T",s_len,0,(i*s_len)+s_len/2 ,(j*higth_of_triangle)+higth_of_triangle ,1);
    				inssert_to_vector("T");				
				}
			}
		}
	}
	else{
		w=0;
		for (i=0 ;i<static_cast<int>(len/higth_of_triangle); i++ ){
			for(j=0 ; j < static_cast<int>(width/s_len) ; j++){
				set_inner("T",s_len,0,i*higth_of_triangle ,j*s_len  ,3);
    			inssert_to_vector("T");
				if((width - ((j*s_len)+s_len/2)) >= s_len){
					w++;
					set_inner("T",s_len,0, (i*higth_of_triangle)+higth_of_triangle , (j*s_len)+s_len/2 ,4);
    				inssert_to_vector("T");
				}
			}
		}
	}
}

void ComposedShape::fit_R_C(){ // fit rectangle in circle
	double r = C_container.get_radius();
	double width = R_inner.get_length();
	double hight = R_inner.get_width();
	int i , j ,q=0 ;
	if (r < sqrt((width*width+hight*hight)/4)){
		return ;
	}
	if(width < hight){
		double temp = width ;
		width = hight ;
		hight = temp ;
	}
	double startpx = r - C_container.equation_circle(hight/2);
	double startpy = r - hight/2 ;
	int num_on_x = static_cast<int>((2*r - 2*startpx)/width);
	int num_on_y = static_cast<int>((r - hight/2)/hight);
	startpx = (r*2 - (width*num_on_x))/2; 	
	for(i=0 ; i<num_on_x ;i++){
		set_inner("R",width,hight,startpx,startpy,1);
	    inssert_to_vector("R");
		
		startpx += width;
		q++;
	}
	for(i=1;i<=num_on_y;i++){
		startpy -= hight ;
		startpx =r- C_container.equation_circle(r- startpy) ;
		num_on_x =  static_cast<int>((2*r - 2*startpx)/width);
		startpx = (r*2 - (width*num_on_x))/2;
		for(j=0 ; j<num_on_x ;j++){
			set_inner("R",width,hight,startpx,startpy,1);
	    	inssert_to_vector("R");
			set_inner("R",width,hight,startpx,startpy+2*i*hight,1);
		    inssert_to_vector("R");
			startpx += width;
			q+= 2;
		} 
	}
}

void ComposedShape::fit_C_C(){ // fit circle in circle
	double r = C_container.get_radius();
	double s_r = C_inner.get_radius(); 

	if(s_r>r){
		return  ;
	}
	else if (2*s_r>r){
		set_inner("C",s_r,0,r,r,1);
	    inssert_to_vector("C");
		return ;
	}
	else if (r/s_r>2 && r/s_r<=2.4){
		set_inner("C",s_r,0,(r- s_r),r- (s_r)*0.8,1);
	    inssert_to_vector("C");
		set_inner("C",s_r,0,(r+s_r), r- (s_r)*0.8 ,1);
	    inssert_to_vector("C");
		set_inner("C",s_r,0,r, r+s_r ,1);
	    inssert_to_vector("C");
		return ; 

	}
	else if(r/s_r>2.4 && r/s_r<3){
		set_inner("C",s_r,0,(r- s_r),r- (s_r),1);
	    inssert_to_vector("C");
		set_inner("C",s_r,0,(r+s_r), r- (s_r) ,1);
	    inssert_to_vector("C");
		set_inner("C",s_r,0,(r-s_r), r+(s_r) ,1);
	    inssert_to_vector("C");
		set_inner("C",s_r,0,(r+s_r), r+(s_r) ,1);
	    inssert_to_vector("C");
		return;
	}
	int i ,q=0;
	int num_on_x = static_cast<int>(r/s_r);
	double temp = s_r*sqrt(3);
	double startpx = r-(s_r*(num_on_x-1)) ;
	double startpy = r ;
	for (int i = 0; i < num_on_x; ++i){
		set_inner("C",s_r,0,startpx, startpy ,1);
	    inssert_to_vector("C");
		startpx += 2*s_r ;
	}
	startpy -= temp;
	while(startpy - s_r>=0){
		q++;
		num_on_x--;
		startpx = r-(s_r*(num_on_x-1));
		for (i=1; i <= num_on_x+2 ; i++){
			if (startpy-s_r >= r - C_container.equation_circle(r-startpx+(2*s_r)) &&
				startpx-(2*s_r)-s_r >= r - C_container.equation_circle(r-startpy) &&
				startpx-(2*s_r)+s_r <= r+ C_container.equation_circle(r-startpy) ){
				set_inner("C",s_r,0,startpx-(2*s_r), startpy ,1);
	    		inssert_to_vector("C");
				set_inner("C",s_r,0,startpx-(2*s_r), startpy+(2*q*temp) ,1);
	    		inssert_to_vector("C");
			}
			startpx += 2*s_r ;
		}
		startpy -= temp;

	}
}

void ComposedShape::fit_T_C(){ // fit tirangle in circle
	int i , j ;
	int num_on_x , num_on_y ;
	double hight_of_triangle = T_inner.get_hight() ;
	double length = T_inner.get_length();
	double radius = C_container.get_radius();
	double startpx ,startpy ,temp = radius;
	if (radius < hight_of_triangle*2/3){
		return ;
	}
	if (radius >= hight_of_triangle*2/3 && radius < hight_of_triangle){
		startpx = radius - C_container.equation_circle(radius- hight_of_triangle);
		startpx = (2*radius - 2*startpx -length)/2 +startpx ; 
			set_inner("T",length,0,startpx ,startpy+hight_of_triangle ,1);
    		inssert_to_vector("T");			
		return ;
	}
	num_on_y = static_cast<int>(radius/hight_of_triangle);
	num_on_x = static_cast<int>(2*temp/length);
	startpx = radius - (length*num_on_x)/2;
	for(i=0;i<num_on_y;i++){
		for(j=0;j<num_on_x;j++ ){
			if (radius - C_container.equation_circle(radius - temp ) <= startpx+(j*length) &&
				radius + C_container.equation_circle(radius - temp ) >= startpx+(j*length)+length &&
				radius - C_container.equation_circle(radius - (startpx+(j*length)+length/2)) <= temp- hight_of_triangle) {
				set_inner("T",length,0,startpx+(j*length) ,temp,1);
    			inssert_to_vector("T");	
				set_inner("T",length,0,startpx+(j*length) ,temp+(2*i*hight_of_triangle),2);
    			inssert_to_vector("T");					
			}

			if(radius - C_container.equation_circle(radius - (temp -hight_of_triangle)) <= (startpx +(j*length)+length/2) &&
			   radius + C_container.equation_circle(radius - (temp -hight_of_triangle)) >= (startpx +(j*length)+length*3/2)){
				set_inner("T",length,0,startpx+(j*length)+length/2,temp- hight_of_triangle,2);
    			inssert_to_vector("T");	
				set_inner("T",length,0,startpx+(j*length)+(length/2),temp+(2*(i)*hight_of_triangle)+hight_of_triangle,1);
    			inssert_to_vector("T");	
			}
		}
		temp -= hight_of_triangle ;
	}
}

void ComposedShape::fit_R_T(){ // fit rectangle in triangle
	int i , j , count=0 ;
	double hight_of_triangle = T_container.get_hight() ;
	double width = R_inner.get_length();
	double hight = R_inner.get_width();
	double length = T_container.get_length();
	double startpx ,startpy ,temp = length;
	int num_on_x ,num_on_y;
	num_on_y = static_cast<int>(hight_of_triangle/hight);
	for(i=0 ;i<num_on_y;i++){
		temp = temp -2*hight/sqrt(3);
		num_on_x = static_cast<int>(temp/width);
		startpx = hight/sqrt(3)*(i+1);
		startpy = hight_of_triangle - hight*(i+1) ;

		for(j=0;j<num_on_x;j++){
			set_inner("R",width,hight,startpx ,startpy ,1);
    		inssert_to_vector("R");
			startpx += width ;
			count++;	
		}
		startpx += width ;
	}
}

void ComposedShape::fit_C_T(){ // fit circle in triangle 
	int i , j , count = 0;
	double hight_of_triangle = T_container.get_hight() ;
	double length = T_container.get_length();
	double r = C_inner.get_radius();
	double startpx ,startpy ;
	int num_on_x ,num_on_y;

	if (r > hight_of_triangle/3){
		return ;
	}
	if (r == hight_of_triangle/3){
		set_inner("C",r,0,length/2 ,3*hight_of_triangle/2 ,1);
    	inssert_to_vector("C");
		return ;
	}
	startpx= 3*r/sqrt(3) ;
	startpy = hight_of_triangle - r ;
	num_on_x =	static_cast<int>((length-(6*r/sqrt(3)))/(2*r))+1;
	num_on_y = num_on_x;
	for(j=0;j<num_on_y;j++){
		for(i=0;i<num_on_x ; i++){
			set_inner("C",r,0,startpx+(i*2*r) ,startpy ,1);
    		inssert_to_vector("C");
			count++;
		}
		startpy -= r*sqrt(3);
		startpx += r ;
		num_on_x--;  
	}
}

void ComposedShape::fit_T_T(){ // fit triangle in triangle
	int i , j ;
	double hight_of_triangle = T_container.get_hight() ;
	double hight_of_s_triangle = T_inner.get_hight() ;
	double len = T_container.get_length();
	double s_len = T_inner.get_length();
	double startpx ,startpy ;
	int num_on_x , temp = len;
	int num_on_y = static_cast<int>(hight_of_triangle/hight_of_s_triangle);
	startpy = hight_of_triangle ;
	for(i=1 ; i<= num_on_y ; i++){
		num_on_x = static_cast<int>(temp/s_len);
		startpx = (len- (s_len*num_on_x))/2;
		for(j=1;j<=num_on_x;j++){
			set_inner("T",s_len,0,startpx ,startpy ,1);
    		inssert_to_vector("T");
			startpx += s_len ;
			if (j < num_on_x){
				set_inner("T",s_len,0,startpx-(s_len/2) ,startpy-hight_of_s_triangle ,2);
    			inssert_to_vector("T");
			}
		}
		startpy -= hight_of_s_triangle;		
		temp = temp*(hight_of_triangle - hight_of_s_triangle)/hight_of_triangle ;
		hight_of_triangle -= hight_of_s_triangle ;
	}
}