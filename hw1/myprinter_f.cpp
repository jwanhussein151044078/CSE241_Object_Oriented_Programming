#include "printer.h"

#define STOKE 2
#define Pi 3.14

int emplimainting(const char * filename ){
	
	string input_shape ; // to hold the input 
	shapes main_shape ;	// to hold the main container's shape
	cout << "Please enter the main container shape (R, C, T)\n" ;
	cin >> input_shape ;
	
	if (input_shape == "R"){
		main_shape = shapes::rect ;
	}
	else if (input_shape == "C"){
		main_shape = shapes::cir ;
	}
	else if (input_shape == "T"){
		main_shape = shapes::tri ;
	}
	else{
		cout << input_shape << "  is not an option!!\ntry again....\n";
		emplimainting(filename);
		return 0 ;
	}
	print_shape(filename , main_shape,"red","green");
	print_last_line(filename);
		
	return 0; 
}

void print_shape(const char * filename , enum shapes main_shape , const string color , const string color2){

	double length , width , radius , hight;
	int num_of_small_ship ;
	char temp = '"';
	double size ;

	if (main_shape == shapes::rect){
		cout << "Please enter the width\n";
		cin >> width ;
		cout << "Please enter the hight\n";
		cin >> hight ;
		if (check_input_validity(main_shape,width,hight)){
			
			print_first_line(filename,width,hight,main_shape);
			print_rectangle(filename , 0 , 0 , width , hight , color);
			num_of_small_ship = print_small_shape(filename,main_shape,width,hight,&size,color2);
			cout <<"I can fit at most " <<num_of_small_ship <<" small shapes into the main container. The empty area ("
				 <<color<<") in container is " ;
			if (num_of_small_ship == 0){	
				cout <<width*hight<<"\n";
			}
			else{
				cout <<(width*hight)-(size*num_of_small_ship)<<"\n";
			}

		}
		else{
			return print_shape(filename , main_shape,color,color2);
			
		}
	}
	if (main_shape == shapes::cir){
		cout << "Please enter the radius \n";
		cin >> radius ;
		
		if (check_input_validity(main_shape,radius,0)){
			print_first_line(filename,radius,0,main_shape);
			print_circle(filename,radius,radius,radius,color);
			num_of_small_ship = print_small_shape(filename,main_shape,radius,0,&size,color2);
			cout <<"I can fit at most " <<num_of_small_ship <<" small shapes into the main container. The empty area ("
				 <<color<<") in container is " ;
			if (num_of_small_ship == 0){	
				cout <<Pi*radius*radius<<"\n";
			}
			else{
				cout <<(Pi*radius*radius)-(size*num_of_small_ship)<<"\n";
			}
		}
		else{
			return print_shape(filename , main_shape,color,color2);
			
		}	
	}
	if (main_shape == shapes::tri){
		double hight_of_triangle ;
		cout << "Please enter the length of the triangle side \n";
		cin >> length;
		hight_of_triangle = length*sqrt_root(3) / 2 ;

		if (check_input_validity(main_shape,length,0)){
			print_first_line(filename,length,0,main_shape);
			print_triangle(filename,0,hight_of_triangle,length,hight_of_triangle,(length/2),0,color);
			num_of_small_ship = print_small_shape(filename,main_shape,length,0,&size,color2);
			cout <<"I can fit at most " <<num_of_small_ship <<" small shapes into the main container. The empty area ("
				 <<color<<") in container is " ;
			if (num_of_small_ship == 0){	
				cout <<sqrt_root(3)*length*length/4<<"\n";
			}
			else{
				cout << size <<"\n";
				cout <<(sqrt_root(3)*length*length/4)-(size*num_of_small_ship)<<"\n";
			}
		}
		else{
			return print_shape(filename , main_shape,color,color2);
			
		}
	}
	
}

void print_rectangle(const char * filename, double rx , double ry , double width , double hight , const string color){
	
	const char temp = '"' ;
	fstream f ;	
	f.open(filename, ios::app);

	f << "<path d=" <<temp<< "M" << rx << " " << ry << " L" << (rx+width) << " " << ry << " L" 
	 << (rx+width) << " " << (ry+hight) << " L" << rx<<" " << (ry+hight) << " Z" << temp 
	 << " stroke=" << temp << "black" << temp << " stroke-width=" << temp << STOKE << temp 
	 << " fill=" << temp << color << temp << " />\n" ;
	f.close() ;
}

void print_circle(const char * filename , double cx , double cy , double radius , const string color){
	
	const char temp = '"' ;
	fstream f ;	
	f.open(filename, ios::app);

	f << "<circle cx="<<temp<<cx<<temp<<" cy="<<temp<<cy<<temp<<" r="
		  <<temp<<radius<<temp
		  << " stroke=" << temp << "black" << temp << " stroke-width=" << temp << STOKE << temp
		  <<" fill="<<temp<<color<<temp<<"/>\n";

	f.close() ;	
}

void print_triangle(const char * filename , double point1_x , double point1_y , double point2_x , double point2_y ,
					double point3_x , double point3_y ,const string color){
	
	const char temp = '"' ;
	fstream f ;	
	f.open(filename, ios::app);

	f << "<polygon points="<<temp<<" " << point1_x << " " << point1_y << ", " << point2_x << " " << point2_y 
	  << ", " << point3_x << " " << point3_y << temp 
	  << " " << " stroke=" << temp << "black" << temp << " stroke-width=" << temp << STOKE << temp
	  <<" fill="<<temp<<color<<temp<<"/>\n";
	f.close() ;	
}




void print_first_line(const char * filename , double width , double hight , enum shapes main_shape){
	
	const char temp = '"' ;
	fstream f ;	
	f.open(filename, ios::out);
	if (main_shape == shapes::rect){
		f << "<svg width="<<temp<<width<<temp<<" hight="<<temp<<hight<<temp<<"> \n";
	}
	if (main_shape == shapes::cir){
		f << "<svg width="<<temp<<width*2<<temp<<" hight="<<temp<<width*2<<temp<<"> \n";
	}
	if (main_shape == shapes::tri){
		f << "<svg width="<<temp<<width<<temp<<" hight="<<temp<<(width*sqrt_root(3)/2)<<temp<<"> \n";
	}
	f.close();	
}

int print_small_shape(const char * filename ,enum shapes main_shape, double width , double hight , 
					  double *size , const string color){

	shapes small_shape ;
	string	input_shape ;
	double s_width , s_hight , s_radius , s_length ;
	int num_of_small_ship ;
	
	cout << "Please enter the small shape (R, C, T)\n";
	cin >> input_shape ;

	if(input_shape == "R"){
		small_shape = shapes::rect ;
		cout << "enter the width of rectangle \n";
		cin >> s_width ;
		cout << "enter the hight of rectangle \n";
		cin >> s_hight ;
		if (check_input_validity(small_shape,s_width,s_hight)){
			if( main_shape == shapes::rect){
				num_of_small_ship = print_rect_in_rect(filename,width,hight,s_width,s_hight,color);
			}
			if( main_shape == shapes::cir){
				num_of_small_ship = print_rect_in_cir(filename,width,s_width,s_hight,color);
			}
			if( main_shape == shapes::tri){
				num_of_small_ship = print_rect_in_tri(filename,width,s_width,s_hight,color);
			}
			*size = s_width*s_hight ;
		}
		else {
			return print_small_shape(filename,main_shape,width,hight,size,color);
		}
	}
	else if(input_shape == "C"){
		small_shape = shapes::cir ;
		cout << "enter the radius of circle \n";
		cin >> s_radius ;
		if (check_input_validity(small_shape,s_radius,0)){
			if( main_shape == shapes::rect){
				if( main_shape == shapes::rect){
				num_of_small_ship = print_cir_in_rect(filename,width,hight,s_radius,color);
				}
			}
			if( main_shape == shapes::cir){
				num_of_small_ship = print_cir_in_cir(filename,width,s_radius,color);
			}
			if( main_shape == shapes::tri){
				num_of_small_ship = print_cir_in_tri(filename,width,s_radius,color);
			}
			*size = Pi*s_radius*s_radius ;		
		}
		else {
			return print_small_shape(filename,main_shape,width,hight,size,color);
		}
	}
	else if (input_shape == "T"){
		small_shape = shapes::tri ;
		cout << "enter the length of triangle \n";
		cin >> s_length ;
		if (check_input_validity(small_shape,s_length,0)){
			if( main_shape == shapes::rect){
				num_of_small_ship = print_tri_in_rect(filename,width,hight,s_length,color);
			}
			if( main_shape == shapes::cir){
				num_of_small_ship = print_tri_in_cir(filename,width,s_length,color);	
			}
			if( main_shape == shapes::tri){
				num_of_small_ship = print_tri_in_tri(filename,width,s_length,color);
			}
			*size = (sqrt_root(3)*s_length*s_length/4 );
		}
		else {
			return print_small_shape(filename,main_shape,width,hight,size,color);
		}
	}
	else {
		cout << input_shape << "  is not an option !!\ntry again ....\n";
		return print_small_shape( filename,main_shape,width,hight,size,color );
	}




	return num_of_small_ship ;
}


void print_last_line (const char * filename){

	fstream f ;
	f.open(filename,ios::app);
	f << "\n</svg> ";
	f.close();
}

bool check_input_validity(enum shapes main_shape , double width , double hight){
	
	if (main_shape == shapes::rect){
		if (width*hight <= 0){
			cout << "invaild input!!\n"
			     << "the width and hight should be bigger than zero !!\n"
			     << "try again" ;
			return false ;
		}
		if (width == hight){
			cout << "The square shape is not allowed!!\ntry again....\n" ;
			return false ;
		}
	}
	else if (main_shape == shapes::tri) {
		if (width <= 0){
			cout << "the length should be bigger than zero !!\ntry again .....\n";
			return false ;
		}
	}
	else {
		if (width <= 0){
			cout << "the radius should be bigger than zero !!\ntry again .....\n";
			return false ;
		}
	}
	return true ;
}

int print_rect_in_rect(const char *filename,double width,double hight,double s_width,double s_hight,const string color){

	double num_on_x = width/s_width ;
    double num_on_y = hight/s_hight ;
    int num_of_small_ship = 0 ;
    int i=0 , j=0 , q =0, w=0;
    if(num_on_x <  width / s_hight && num_on_y < hight / s_width){
    	num_on_x = width/s_hight ;
    	for (i=0 ; i <(static_cast<int> (num_on_x) ); i++){
	    		print_rectangle(filename,i*(s_hight),0,s_hight,s_width,color);
	   }
	   return i ;
    }
    else {
	    for (i=0 ; i <(static_cast<int> (num_on_x) ); i++){
	    	for(j=0; j < (static_cast<int>(num_on_y)) ; j++){
	    		print_rectangle(filename,i*(s_width),j*(s_hight),s_width,s_hight,color);
	    	}
	    }
	    width -= i*s_width ;
	    num_on_x = width / s_hight ;
	    num_on_y = hight / s_width ;
	    for (q=0 ; q <(static_cast<int> (num_on_x) ); q++){
	    	for(w=0; w < (static_cast<int>(num_on_y)) ; w++){
	    		print_rectangle(filename,((i*s_width)+(q*s_hight)),(w)*(s_hight),s_hight,s_width,color);
	    	}
	    }
	}
	num_of_small_ship = (i*j)+(q*w) ;
	return num_of_small_ship ;
}

int print_cir_in_rect(const char *filename,double width,double hight,double radius,const string color){

	double num_on_x = width/(radius*2) ;
    double num_on_y = hight/(radius*2) ;
    int i , j ;

    for (i=0;i<static_cast<int>(num_on_x);i++){
    	for(j=0;j<static_cast<int>(num_on_y);j++){
    		print_circle(filename,(i*radius*2)+radius,(j*radius*2)+radius,radius,color);
    	}
    }
    return i*j;
}

int print_tri_in_rect(const char *filename,double width,double hight,double length,const string color){

	double hight_of_triangle = sqrt_root(3)*length/2 ;
	double num_on_x = width/length ;
	double num_on_y = hight/hight_of_triangle ;
	int i , j ,w=0 , temp;

	for (i=0 ;i<static_cast<int>(num_on_x); i++ ){
		for(j=0 ; j < static_cast<int>(num_on_y) ; j++){
			if((width - ((i*length)+length/2)) >= length){
				w++;
			}
		}
	}
	temp = (i*j)+w;
	w=0;
	for (i=0 ;i<static_cast<int>(width/hight_of_triangle); i++ ){
		for(j=0 ; j < static_cast<int>(hight/length) ; j++){
			if((hight - ((j*length)+length/2)) >= length){
				w++;
			}
		}
	}
	if (temp > (i*j)+w){
		w=0;
		for (i=0 ;i<static_cast<int>(num_on_x); i++ ){
			for(j=0 ; j < static_cast<int>(num_on_y) ; j++){
				print_triangle (filename , i*length , j* hight_of_triangle , (i*length)+length ,j*hight_of_triangle ,
								(i*length)+length/2 ,(j*hight_of_triangle)+hight_of_triangle,color  );
				if((width - ((i*length)+length/2)) >= length){
					w++;
					print_triangle (filename ,(i*length)+length/2 ,(j*hight_of_triangle)+hight_of_triangle,
									 (i*length)+length ,j*hight_of_triangle ,(i*length)+length/2+length ,
										(j*hight_of_triangle)+hight_of_triangle ,color);
				}
			}
		}
	}
	else{
		w=0;
		for (i=0 ;i<static_cast<int>(width/hight_of_triangle); i++ ){
			for(j=0 ; j < static_cast<int>(hight/length) ; j++){
				print_triangle (filename , i*hight_of_triangle , j* length ,i*hight_of_triangle ,(j*length)+length ,
								(i*hight_of_triangle)+hight_of_triangle,(j*length)+length/2 ,color  );
				if((hight - ((j*length)+length/2)) >= length){
					w++;
					print_triangle (filename ,(i*hight_of_triangle)+hight_of_triangle,(j*length)+length/2 ,
									 i*hight_of_triangle ,(j*length)+length ,(i*hight_of_triangle)+hight_of_triangle ,
									 (j*length)+length/2+length ,color);	
				}
			}
		}
	}
	return (i*j)+w;
}

int print_rect_in_cir(const char *filename , double radius,double width,double hight,const string color){

	int i , j ,q=0;
	if (radius < sqrt_root((width*width+hight*hight)/4)){
		return 0 ;
	}
	if(width < hight){
		return print_rect_in_cir(filename,radius,hight,width,color);
	}
	double startpx = radius - equation_circle(hight/2,radius);
	double startpy = radius - hight/2 ;
	int num_on_x = static_cast<int>((2*radius - 2*startpx)/width);
	int num_on_y = static_cast<int>((radius - hight/2)/hight);
	startpx = (radius*2 - (width*num_on_x))/2; 	
	for(i=0 ; i<num_on_x ;i++){
		print_rectangle(filename,startpx,startpy,width,hight,color);
		startpx += width;
		q++;
	}
	for(i=1;i<=num_on_y;i++){
		startpy -= hight ;
		startpx =radius- equation_circle(radius- startpy,radius) ;
		num_on_x =  static_cast<int>((2*radius - 2*startpx)/width);
		startpx = (radius*2 - (width*num_on_x))/2;
		for(j=0 ; j<num_on_x ;j++){
			print_rectangle(filename,startpx,startpy,width,hight,color);
			print_rectangle(filename,startpx,startpy+2*i*hight,width,hight,color);
			startpx += width;
			q+= 2;
		} 
	}
	return q ;
}

int print_cir_in_cir(const char *filename , double radius,double s_radius,const string color){
	
	if(s_radius>radius){
		return 0 ;
	}
	else if (2*s_radius>radius){
		print_circle(filename,radius,radius,s_radius,color);
		return 1 ;
	}
	else if (radius/s_radius>2 && radius/s_radius<=2.4){
		print_circle(filename,radius-s_radius,radius- (s_radius)*0.8,s_radius,color );
		print_circle(filename,radius+s_radius,radius- (s_radius)*0.8,s_radius,color );
		print_circle(filename,radius,radius+ s_radius,s_radius,color );
		return 3; 

	}
	else if(radius/s_radius>2.4 && radius/s_radius<3){
		print_circle(filename,radius-s_radius,radius- s_radius,s_radius,color );
		print_circle(filename,radius+s_radius,radius- s_radius,s_radius,color );
		print_circle(filename,radius-s_radius,radius+ s_radius,s_radius,color );
		print_circle(filename,radius+s_radius,radius+ s_radius,s_radius,color );
		return 4 ;
	}
	int i ,q=0 ,count =0;
	int num_on_x = static_cast<int>(radius/s_radius);
	double temp = s_radius*sqrt_root(3);
	double startpx = radius-(s_radius*(num_on_x-1)) ;
	double startpy = radius ;
	for (int i = 0; i < num_on_x; ++i){
		print_circle(filename,startpx,startpy,s_radius,color);
		startpx += 2*s_radius ;
		count++;
	}
	startpy -= temp;
	while(startpy - s_radius>=0){
		q++;
		num_on_x--;
		startpx = radius-(s_radius*(num_on_x-1));
		for (i=1; i <= num_on_x+2 ; i++){
			if (startpy-s_radius >= radius-equation_circle(radius-startpx+(2*s_radius),radius) &&
				startpx-(2*s_radius)-s_radius >= radius-equation_circle(radius-startpy,radius) &&
				startpx-(2*s_radius)+s_radius <= radius+equation_circle(radius-startpy,radius) ){
				print_circle(filename,startpx-(2*s_radius),startpy,s_radius,color);
				print_circle(filename,startpx-(2*s_radius),startpy+(2*q*temp),s_radius,color);
				count+=2;
			}
			startpx += 2*s_radius ;
		}
		startpy -= temp;

	}
	return count;
}

int print_tri_in_cir(const char *filename , double radius,double length,const string color){

	int i , j ,count =0;
	int num_on_x , num_on_y ;
	double hight_of_triangle = sqrt_root(3)*length/2 ;
	double startpx ,startpy ,temp = radius;
	if (radius < hight_of_triangle*2/3){
		return 0 ;
	}
	if (radius >= hight_of_triangle*2/3 && radius < hight_of_triangle){
		startpx = radius - equation_circle(radius- hight_of_triangle,radius);
		startpx = (2*radius - 2*startpx -length)/2 +startpx ; 
		print_triangle(filename,radius,startpy,startpx,startpy+hight_of_triangle,
						startpx+length,startpy+hight_of_triangle,color);
		return 1;
	}
	num_on_y = static_cast<int>(radius/hight_of_triangle);
	num_on_x = static_cast<int>(2*temp/length);
	startpx = radius - (length*num_on_x)/2;
	for(i=0;i<num_on_y;i++){
		for(j=0;j<num_on_x;j++ ){
			if (radius - equation_circle(radius - temp , radius) <= startpx+(j*length) &&
				radius + equation_circle(radius - temp , radius) >= startpx+(j*length)+length &&
				radius - equation_circle(radius - (startpx+(j*length)+length/2) ,radius) <= temp- hight_of_triangle) {
				
				print_triangle(filename,startpx+(j*length),temp,startpx+(j*length)+length,temp,
								startpx+(j*length)+length/2,temp- hight_of_triangle,color);
				print_triangle(filename,startpx+(j*length),temp+(2*i*hight_of_triangle) ,startpx+(j*length)+length,
								 temp+(2*i*hight_of_triangle),startpx+(j*length)+length/2 ,
								 temp+(2*i*hight_of_triangle)+hight_of_triangle,color );
				count+=2;
			}

			if(radius - equation_circle(radius - (temp -hight_of_triangle), radius) <= (startpx +(j*length)+length/2) &&
			   radius + equation_circle(radius - (temp -hight_of_triangle), radius) >= (startpx +(j*length)+length*3/2)){
				
				print_triangle(filename,startpx+(j*length)+length,temp,startpx+(j*length)+length/2,temp- hight_of_triangle,
								startpx+(j*length)+length*3/2,temp- hight_of_triangle,color);
				print_triangle(filename,startpx+(j*length)+length,temp+(2*i*hight_of_triangle),startpx+(j*length)+length/2,
								temp+(2*i*hight_of_triangle)+hight_of_triangle , startpx+(j*length)+length*3/2 ,
								temp+(2*i*hight_of_triangle)+hight_of_triangle ,color);
				count+=2;
			}
		}
		temp -= hight_of_triangle ;
	}
	return count ;

}

int print_rect_in_tri(const char *filename ,double length,double width,double hight,const string color){
	int i , j , count=0 ;
	double hight_of_triangle = sqrt_root(3)*length/2 ;
	double startpx ,startpy ,temp = length;
	int num_on_x ,num_on_y;
	if (hight > width){
		return print_rect_in_tri(filename,length,hight,width,color);
	}
	num_on_y = static_cast<int>(hight_of_triangle/hight);
	for(i=0 ;i<num_on_y;i++){
		temp = temp -2*hight/sqrt_root(3);
		num_on_x = static_cast<int>(temp/width);
		startpx = hight/sqrt_root(3)*(i+1);
		startpy = hight_of_triangle - hight*(i+1) ;

		for(j=0;j<num_on_x;j++){
			print_rectangle(filename,startpx,startpy,width,hight,color);
			startpx += width ;
			count++;	
		}
		startpx += width ;

	}
	hight_of_triangle= sqrt_root(3)*startpy/2;

	return count ;
}

int print_cir_in_tri(const char *filename ,double length,double radius ,const string color){
	int i , j , count = 0;
	double hight_of_triangle = sqrt_root(3)*length/2 ;
	double startpx ,startpy ;
	int num_on_x ,num_on_y;

	if (radius > hight_of_triangle/3){
		return 0;
	}
	if (radius == hight_of_triangle/3){
		print_circle(filename,length/2,3*hight_of_triangle/2,radius,color);
		return 1;
	}
	startpx= 3*radius/sqrt_root(3) ;
	startpy = hight_of_triangle - radius ;
	num_on_x =	static_cast<int>((length-(6*radius/sqrt_root(3)))/(2*radius))+1;
	num_on_y = num_on_x;
	for(j=0;j<num_on_y;j++){
		for(i=0;i<num_on_x ; i++){
		print_circle(filename,startpx+(i*2*radius),startpy,radius,color);
		count++;
		}
		startpy -= radius*sqrt_root(3);
		startpx += radius ;
		num_on_x--;  
	}
	return count ;
}

int print_tri_in_tri(const char *filename ,double length,double s_length ,const string color){
	
	int i , j , count=0;
	double hight_of_triangle = sqrt_root(3)*length/2 ;
	double hight_of_s_triangle = sqrt_root(3)*s_length/2 ;
	double startpx ,startpy ;
	int num_on_x , temp = length;
	int num_on_y = static_cast<int>(hight_of_triangle/hight_of_s_triangle);
	startpy = hight_of_triangle ;
	for(i=1 ; i<= num_on_y ; i++){
		num_on_x = static_cast<int>(temp/s_length);
		startpx = (length- (s_length*num_on_x))/2;
		for(j=1;j<=num_on_x;j++){
			print_triangle(filename,startpx,startpy,startpx+s_length,startpy,startpx+s_length/2,
							startpy- hight_of_s_triangle,color );
			startpx += s_length ;
			if (j < num_on_x){
				print_triangle(filename,startpx,startpy,startpx-s_length/2,startpy- hight_of_s_triangle,startpx+s_length/2,
							startpy- hight_of_s_triangle,color );
				count++;
			}
			count++;
		}
		startpy -= hight_of_s_triangle;		
		temp = temp*(hight_of_triangle - hight_of_s_triangle)/hight_of_triangle ;
		hight_of_triangle -= hight_of_s_triangle ;
	}
	return count ;
}
double sqrt_root(double num){
	int i ,j;
	double temp ,avg ,temp2;
	if (num<0){
		return 0;
	}
	else if(num >= 1){
		for(i=0;i<num/2;i++){
			if ((i+1)*(i+1) > num){
				temp = num / i ;
				avg = (temp+i)/2 ;
				for (j=0;j<5;j++){
					temp2 = num/avg ;
					avg = (temp2+avg)/2;
				}
				return avg ;
			}
		}
	}
}

double equation_circle(double x , double radius){
	return sqrt_root(radius*radius - x*x);
}