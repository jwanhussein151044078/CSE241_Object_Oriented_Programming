# include <iostream>
# include <string>
# include <fstream>
# include <cmath>
# include "SHAPES.h"
# include "ComposedShape.h"

typedef ComposedShape::ShapeElem in ;

////////////////////////         class ComposedShape          ////////////////////////


ComposedShape::ComposedShape(Rectangle& r1 , Rectangle& r2){
	ComposedShape::ShapeElem x1(r1);
	ComposedShape::ShapeElem x2(r2);
	*this += x1 ;
	*this += x2 ;
	optimalFit();
}
ComposedShape::ComposedShape(Rectangle& r, Circle& c){
	ComposedShape::ShapeElem x1(r);
	ComposedShape::ShapeElem x2(c);
	*this += x1 ;
	*this += x2 ;
	optimalFit();	
}
ComposedShape::ComposedShape(Rectangle& r, Triangle& t){
	ComposedShape::ShapeElem x1(r);
	ComposedShape::ShapeElem x2(t);
	*this += x1 ;
	*this += x2 ;
	optimalFit();
}
ComposedShape::ComposedShape(Circle& c, Rectangle& r){
	ComposedShape::ShapeElem x1(c);
	ComposedShape::ShapeElem x2(r);
	*this += x1 ;
	*this += x2 ;
	optimalFit();
}
ComposedShape::ComposedShape(Circle& c1, Circle& c2){
	ComposedShape::ShapeElem x1(c1);
	ComposedShape::ShapeElem x2(c2);
	*this += x1 ;
	*this += x2 ;
	optimalFit();
}
ComposedShape::ComposedShape(Circle& c, Triangle& t){
	ComposedShape::ShapeElem x1(c);
	ComposedShape::ShapeElem x2(t);
	*this += x1 ;
	*this += x2 ;
	optimalFit();
}
ComposedShape::ComposedShape(Triangle& t, Rectangle& r){
	ComposedShape::ShapeElem x1(t);
	ComposedShape::ShapeElem x2(r);
	*this += x1 ;
	*this += x2 ;
	optimalFit();
}
ComposedShape::ComposedShape(Triangle& t, Circle& c){
	ComposedShape::ShapeElem x1(t);
	ComposedShape::ShapeElem x2(c);
	*this += x1 ;
	*this += x2 ;
	optimalFit();
}
ComposedShape::ComposedShape(Triangle& t1, Triangle& t2){
	ComposedShape::ShapeElem x1(t1);
	ComposedShape::ShapeElem x2(t2);
	*this += x1 ;
	*this += x2 ;
	optimalFit();
}

ComposedShape& ComposedShape::operator +=(ShapeElem& temp){
	this->vec.push_back(temp);
	return *this ;	
}

in& ComposedShape::operator [](int i){
	if (i <= this->vec.size()){
		return this->vec.at(i);
	}
	cout <<"you are out of the range of the vector\n";
}

ostream& operator <<(ostream& outputStream,ComposedShape& a){
	char temp = '"';
	auto temp1 = a.get_size_vector() ;
	outputStream << "<svg width="<<temp<<a.vec[0].get_lengthorradius()<<temp<<" hight="<<temp
				 <<a.vec[0].get_widthorheight()<<temp<<"> \n";
	
	for (auto i = 0 ; i < temp1 ; i++){
		outputStream <<  a.vec[i] ;
	}

	outputStream <<  "\n</svg> ";
	return outputStream ;
}

void ComposedShape::optimalFit(){
	if (this->vec[0].get_shape_type() == rectangle && this->vec[1].get_shape_type() == rectangle){
		fit_R_R();
	}
	if (this->vec[0].get_shape_type() == rectangle && this->vec[1].get_shape_type() == circle){
		fit_C_R();
	}
	if (this->vec[0].get_shape_type() == rectangle && this->vec[1].get_shape_type() == triangle){
		fit_T_R();
	}

	if (this->vec[0].get_shape_type() == circle && this->vec[1].get_shape_type() == rectangle){
		fit_R_C();
	}
	if (this->vec[0].get_shape_type() == circle && this->vec[1].get_shape_type() == circle){
		fit_C_C();
	}
	if (this->vec[0].get_shape_type() == circle && this->vec[1].get_shape_type() == triangle){
		fit_T_C();
	}

	if (this->vec[0].get_shape_type() == triangle && this->vec[1].get_shape_type() == rectangle){
		fit_R_T();
	}
	if (this->vec[0].get_shape_type() == triangle && this->vec[1].get_shape_type() == circle){
		fit_C_T();
	}
	if (this->vec[0].get_shape_type() == triangle && this->vec[1].get_shape_type() == triangle){
		fit_T_T();
	}

}

void ComposedShape::fit_R_R(){ //fit rectangle in rectangle
	double len = this->vec[0].get_lengthorradius() ;
	double wid = this->vec[0].get_widthorheight() ;
	double s_len = this->vec[1].get_lengthorradius() ;
	double s_wid = this->vec[1].get_widthorheight() ;
	double num_on_x = len/s_len ;
    double num_on_y = wid/s_wid ;
    int i=0 , j=0 , q =0, w=0;
    vec.pop_back();
    
    if(num_on_x <  len/s_wid && num_on_y < wid/s_len){
    	num_on_x = len/s_wid ;
    	for (i=0 ; i <(static_cast<int> (num_on_x) ); i++){
    			Rectangle* a = new Rectangle(s_len,s_wid,i*(s_wid),0,'I',1);
	    		ShapeElem* b = new ShapeElem(*a);
	    		*this += *b ;	    		
	   }
	   
    }
    else {
	    for (i=0 ; i <(static_cast<int> (num_on_x) ); i++){
	    	for(j=0; j < (static_cast<int>(num_on_y)) ; j++){
	    		Rectangle* a = new Rectangle(s_len,s_wid,i*(s_len),j*(s_wid),'I',1);
	    		ShapeElem* b = new ShapeElem(*a);
	    		*this += *b ; 
	    	}
	    }
	    len -= i*s_len ;
	    num_on_x = len / s_wid ;
	    num_on_y = wid / s_len ;
	    for (q=0 ; q <(static_cast<int> (num_on_x) ); q++){
	    	for(w=0; w < (static_cast<int>(num_on_y)) ; w++){
	    		Rectangle* a = new Rectangle(s_len,s_wid,((i*s_len)+(q*s_wid)),(w)*(s_len),'I',2);
	    		ShapeElem* b = new ShapeElem(*a);
	    		*this += *b ;
	    	}
	    }
	}
	
}

void ComposedShape::fit_C_R(){ // fit circle in rectangle
	double num_on_x = this->vec[0].get_lengthorradius()/(this->vec[1].get_lengthorradius()*2) ;
    double num_on_y = this->vec[0].get_widthorheight()/(this->vec[1].get_widthorheight()*2) ;
    int i , j ;    
    double r = this->vec[1].get_lengthorradius() ;
    vec.pop_back();
    for (i=0;i<static_cast<int>(num_on_x);i++){
    	for(j=0;j<static_cast<int>(num_on_y);j++){
    		Circle* a = new Circle(r,(i*r*2)+r,(j*r*2)+r,'I');
	    	ShapeElem* b = new ShapeElem(*a);
	    	*this += *b ;
    	}
    }
}

void ComposedShape::fit_T_R(){ // fit triangle in rectangle 
	double higth_of_triangle = this->vec[1].get_widthorheight() ;
	double len = this->vec[0].get_lengthorradius();
	double width = this->vec[0].get_widthorheight();
	double s_len = this->vec[1].get_lengthorradius();
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
    			Triangle* a = new Triangle(s_len, i*s_len ,j*higth_of_triangle,2,'I');
	    		ShapeElem* b = new ShapeElem(*a);
	    		*this += *b ;
				
				if((len - ((i*s_len)+s_len/2)) >= s_len){
					w++;
    				Triangle* a = new Triangle(s_len, (i*s_len)+s_len/2 ,(j*higth_of_triangle)+higth_of_triangle,1,'I');
	    			ShapeElem* b = new ShapeElem(*a);
	    			*this += *b ;				
				}
			}
		}
	}
	else{
		w=0;
		for (i=0 ;i<static_cast<int>(len/higth_of_triangle); i++ ){
			for(j=0 ; j < static_cast<int>(width/s_len) ; j++){
    			Triangle* a = new Triangle(s_len, i*higth_of_triangle ,j*s_len,3,'I');
	    		ShapeElem* b = new ShapeElem(*a);
	    		*this += *b ;
				if((width - ((j*s_len)+s_len/2)) >= s_len){
					w++;
    				Triangle* a = new Triangle(s_len, (i*higth_of_triangle)+higth_of_triangle ,(j*s_len)+s_len/2 ,4,'I');
	    			ShapeElem* b = new ShapeElem(*a);
	    			*this += *b ;
				}
			}
		}
	}
}

void ComposedShape::fit_R_C(){ // fit rectangle in circle
	double r =this->vec[0].get_lengthorradius();
	double width =this->vec[1].get_lengthorradius();
	double hight = this->vec[1].get_widthorheight();
	vec.pop_back();
	int i , j ,q=0 ;
	if (r < sqrt((width*width+hight*hight)/4)){
		return ;
	}	
	if(width < hight){
		double temp = width ;
		width = hight ;
		hight = temp ;
	}

	double startpx = r - this->vec[0].equation_circle(hight/2);
	double startpy = r - hight/2 ;

	int num_on_x = static_cast<int>((2*r - 2*startpx)/width);
	int num_on_y = static_cast<int>((r - hight/2)/hight);
	startpx = (r*2 - (width*num_on_x))/2; 	
	for(i=0 ; i<num_on_x ;i++){
		Rectangle* a = new Rectangle(width,hight,startpx,startpy,'I',1);
	    ShapeElem* b = new ShapeElem(*a);
	    *this += *b ;	
		startpx += width;
		q++;
	}
	for(i=1;i<=num_on_y;i++){
		startpy -= hight ;
		startpx =r- this->vec[0].equation_circle(r- startpy) ;
		num_on_x =  static_cast<int>((2*r - 2*startpx)/width);
		startpx = (r*2 - (width*num_on_x))/2;
		for(j=0 ; j<num_on_x ;j++){
			Rectangle* a = new Rectangle(width,hight,startpx,startpy,'I',1);
	    	ShapeElem* b = new ShapeElem(*a);
	    	*this += *b ;
	    	Rectangle* t = new Rectangle(width,hight,startpx,startpy+2*i*hight,'I',1);
	    	ShapeElem* s = new ShapeElem(*t);
	    	*this += *s ;			
			startpx += width;
			q+= 2;
		} 
	}
}

void ComposedShape::fit_C_C(){ // fit circle in circle
	double r = this->vec[0].get_widthorheight();
	double s_r = this->vec[1].get_widthorheight(); 
	vec.pop_back();
	if(s_r>r){
		return  ;
	}
	else if (2*s_r>r){
		Circle* a = new Circle(s_r,r,r,'I');
	    ShapeElem* b = new ShapeElem(*a);
	    *this += *b ;
	    return;
	}
	else if (r/s_r>2 && r/s_r<=2.4){
		Circle* a1 = new Circle(s_r, (r- s_r) , r-(s_r)*0.8, 'I');
	    ShapeElem* b1 = new ShapeElem(*a1);
	    *this += *b1 ;
		Circle* a2 = new Circle(s_r, (r+s_r) , r- (s_r)*0.8 , 'I');
	    ShapeElem* b2 = new ShapeElem(*a2);
	    *this += *b2 ;
		Circle* a3 = new Circle(s_r, r , r+s_r , 'I');
	    ShapeElem* b3 = new ShapeElem(*a3);
	    *this += *b3 ;
		
		return ; 

	}
	else if(r/s_r>2.4 && r/s_r<3){
		Circle* a1 = new Circle(s_r, (r- s_r),r- (s_r), 'I');
	    ShapeElem* b1 = new ShapeElem(*a1);
	    *this += *b1 ;
		Circle* a2 = new Circle(s_r, (r+s_r), r- (s_r), 'I');
	    ShapeElem* b2 = new ShapeElem(*a2);
	    *this += *b2 ;
		Circle* a3 = new Circle(s_r, (r-s_r), r+(s_r), 'I');
	    ShapeElem* b3 = new ShapeElem(*a3);
	    *this += *b3 ;
	    Circle* a4 = new Circle(s_r, (r+s_r), r+(s_r), 'I');
	    ShapeElem* b4 = new ShapeElem(*a4);
	    *this += *b4 ;
		return;
	}
	int i ,q=0;
	int num_on_x = static_cast<int>(r/s_r);
	double temp = s_r*sqrt(3);
	double startpx = r-(s_r*(num_on_x-1)) ;
	double startpy = r ;
	for (int i = 0; i < num_on_x; ++i){
		Circle* a = new Circle(s_r, startpx, startpy, 'I');
	    ShapeElem* b = new ShapeElem(*a);
	    *this += *b ;
		startpx += 2*s_r ;
	}
	startpy -= temp;
	while(startpy - s_r>=0){
		q++;
		num_on_x--;
		startpx = r-(s_r*(num_on_x-1));
		for (i=1; i <= num_on_x+2 ; i++){
			if (startpy-s_r >= r - vec[0].equation_circle(r-startpx+(2*s_r)) &&
				startpx-(2*s_r)-s_r >= r - vec[0].equation_circle(r-startpy) &&
				startpx-(2*s_r)+s_r <= r+ vec[0].equation_circle(r-startpy) ){
				Circle* a1 = new Circle(s_r, startpx-(2*s_r), startpy, 'I');
	    		ShapeElem* b1 = new ShapeElem(*a1);
	    		*this += *b1 ;
				Circle* a2 = new Circle(s_r, startpx-(2*s_r), startpy+(2*q*temp), 'I');
	    		ShapeElem* b2 = new ShapeElem(*a2);
	    		*this += *b2 ;
			}
			startpx += 2*s_r ;
		}
		startpy -= temp;

	}
}

void ComposedShape::fit_T_C(){ // fit tirangle in circle
	int i , j ;
	int num_on_x , num_on_y ;
	double hight_of_triangle = this->vec[1].get_widthorheight() ;
	double length = this->vec[1].get_lengthorradius();
	double radius = this->vec[0].get_lengthorradius();
	double startpx ,startpy ,temp = radius;
	vec.pop_back();
	if (radius < hight_of_triangle*2/3){
		return ;
	}
	if (radius >= hight_of_triangle*2/3 && radius < hight_of_triangle){
		startpx = radius - vec[0].equation_circle(radius- hight_of_triangle);
		startpx = (2*radius - 2*startpx -length)/2 +startpx ; 
			Triangle* a = new Triangle(length,startpx ,startpy+hight_of_triangle,1,'I');
	    	ShapeElem* b = new ShapeElem(*a);
	    	*this += *b ;			
		return ;
	}
	num_on_y = static_cast<int>(radius/hight_of_triangle);
	num_on_x = static_cast<int>(2*temp/length);
	startpx = radius - (length*num_on_x)/2;
	for(i=0;i<num_on_y;i++){
		for(j=0;j<num_on_x;j++ ){
			if (radius - vec[0].equation_circle(radius - temp ) <= startpx+(j*length) &&
				radius + vec[0].equation_circle(radius - temp ) >= startpx+(j*length)+length &&
				radius - vec[0].equation_circle(radius - (startpx+(j*length)+length/2)) <= temp- hight_of_triangle) {
				
				Triangle* a = new Triangle(length,startpx+(j*length) ,temp,1,'I');
	    		ShapeElem* b = new ShapeElem(*a);
	    		*this += *b ;
	    		Triangle* a1 = new Triangle(length,startpx+(j*length) ,temp+(2*i*hight_of_triangle),2,'I');
	    		ShapeElem* b1 = new ShapeElem(*a1);
	    		*this += *b1 ;					
			}

			if(radius - vec[0].equation_circle(radius - (temp -hight_of_triangle)) <= (startpx +(j*length)+length/2) &&
			   radius + vec[0].equation_circle(radius - (temp -hight_of_triangle)) >= (startpx +(j*length)+length*3/2)){
				
				Triangle* a = new Triangle(length,startpx+(j*length)+length/2,temp- hight_of_triangle,2,'I');
	    		ShapeElem* b = new ShapeElem(*a);
	    		*this += *b ;
	    		Triangle* a1 = new Triangle(length,startpx+(j*length)+(length/2)
	    									,temp+(2*(i)*hight_of_triangle)+hight_of_triangle,1,'I');
	    		ShapeElem* b1 = new ShapeElem(*a1);
	    		*this += *b1 ;
			}
		}
		temp -= hight_of_triangle ;
	}
}

void ComposedShape::fit_R_T(){ // fit rectangle in triangle
	int i , j , count=0 ;
	double hight_of_triangle = this->vec[0].get_widthorheight();
	double width =this->vec[1].get_lengthorradius();
	double hight = this->vec[1].get_widthorheight();
	double length = this->vec[0].get_lengthorradius();
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
    		Rectangle* a = new Rectangle(width,hight,startpx ,startpy,'I',1);
	    	ShapeElem* b = new ShapeElem(*a);
	    	*this += *b ;
			startpx += width ;
			count++;	
		}
		startpx += width ;
	}
}



void ComposedShape::fit_C_T(){ // fit circle in triangle 
	int i , j ;
	double hight_of_triangle = this->vec[0].get_widthorheight() ;
	double length = this->vec[0].get_lengthorradius();
	double r =this->vec[1].get_lengthorradius();
	double startpx ,startpy ;
	int num_on_x ,num_on_y;
	vec.pop_back();
	if (r > hight_of_triangle/3){
		return ;
	}
	if (r == hight_of_triangle/3){
		Circle* a = new Circle(r,length/2,3*hight_of_triangle/2,'I');
	    ShapeElem* b = new ShapeElem(*a);
	    *this += *b ;
		return ;
	}
	startpx= 3*r/sqrt(3) ;
	startpy = hight_of_triangle - r ;
	num_on_x =	static_cast<int>((length-(6*r/sqrt(3)))/(2*r))+1;
	num_on_y = num_on_x;
	for(j=0;j<num_on_y;j++){
		for(i=0;i<num_on_x ; i++){
			Circle* a = new Circle(r,startpx+(i*2*r),startpy,'I');
	   		ShapeElem* b = new ShapeElem(*a);
	    	*this += *b ;
		}
		startpy -= r*sqrt(3);
		startpx += r ;
		num_on_x--;  
	}
}

void ComposedShape::fit_T_T(){ // fit triangle in triangle
	int i , j ;
	double hight_of_triangle = this->vec[0].get_widthorheight() ;
	double hight_of_s_triangle = this->vec[1].get_widthorheight() ;
	double len = this->vec[0].get_lengthorradius();
	double s_len = this->vec[1].get_lengthorradius();
	vec.pop_back();
	double startpx ,startpy ;
	int num_on_x , temp = len;
	int num_on_y = static_cast<int>(hight_of_triangle/hight_of_s_triangle);
	startpy = hight_of_triangle ;
	for(i=1 ; i<= num_on_y ; i++){
		num_on_x = static_cast<int>(temp/s_len);
		startpx = (len- (s_len*num_on_x))/2;
		for(j=1;j<=num_on_x;j++){
			Triangle* a = new Triangle(s_len, startpx ,startpy ,1,'I');
	    	ShapeElem* b = new ShapeElem(*a);
	    	*this += *b ;
			startpx += s_len ;
			if (j < num_on_x){
				Triangle* a = new Triangle(s_len, startpx-(s_len/2) ,startpy-hight_of_s_triangle ,2,'I');
	    		ShapeElem* b = new ShapeElem(*a);
	    		*this += *b ;
			}
		}
		startpy -= hight_of_s_triangle;		
		temp = temp*(hight_of_triangle - hight_of_s_triangle)/hight_of_triangle ;
		hight_of_triangle -= hight_of_s_triangle ;
	}
}


////////////////////////         class Shapeelem          ////////////////////////////

in::ShapeElem(Rectangle &r ){
	p = &r ;
	set_shape_type(rectangle) ;
}
in::ShapeElem(Circle &c){
	p = &c ;
	set_shape_type(circle) ;
}
in::ShapeElem(Triangle &t){
	p = &t ;
	set_shape_type(triangle) ;
}

ostream& operator <<(ostream& outputStream, in& temp){

	if (temp.shape == rectangle){
		Rectangle* r =  reinterpret_cast<Rectangle*>(temp.p);
		outputStream <<  *r ;
		return outputStream ;
	}
	if (temp.shape == circle){
		Circle* c =  reinterpret_cast<Circle*>(temp.p);
		outputStream <<  *c ;
		return outputStream ;
	}
	if (temp.shape == triangle){
		Triangle* t =  reinterpret_cast<Triangle*>(temp.p);
		outputStream <<  *t ;
		return outputStream ;
	}
}

void in::set_all(double l, double w, double x,double y,int d,char c){
	if (shape == rectangle ){
		(static_cast<Rectangle*>(p))->set_dimensions(l,w);
		(static_cast<Rectangle*>(p))->set_start_points(x,y);
		(static_cast<Rectangle*>(p))->set_direction(d);
		(static_cast<Rectangle*>(p))->set_type(c);
	}
}

const double in::get_lengthorradius()const{
	if (shape == rectangle){
		Rectangle *temp = (static_cast<Rectangle*>(p)) ;
		return temp->get_length();
	}
	else if (shape == circle){
		Circle *temp = (static_cast<Circle*>(p));
		return temp->get_radius();
	}
	else if (shape == triangle){
		Triangle *temp = (static_cast<Triangle*>(p));
		return temp->get_length();
	}
}

const double in::get_widthorheight()const{
	if (shape == rectangle){
		Rectangle *temp = (static_cast<Rectangle*>(p)) ;
		return temp->get_width();
	}
	if (shape == triangle){
		Triangle *temp = (static_cast<Triangle*>(p));
		return temp->get_height();
	}
	if (shape == circle){
		Circle *temp = (static_cast<Circle*>(p));
		return temp->get_radius();
	}
}


const double in::get_area()const{
	if (shape == rectangle){
		Rectangle *temp = static_cast<Rectangle*>(p);
		return temp->get_area();
	}
	if (shape == triangle){
		Triangle *temp = static_cast<Triangle*>(p);
		return temp->get_area();
	}
	if (shape == circle){
		Circle *temp = static_cast<Circle*>(p);
		return temp->get_area() ;
	
	}
}

const double in::get_perimeter()const{
	if (shape == rectangle){	
		return (static_cast<Rectangle*>(p))->get_perimeter();
	}
	if (shape == triangle){
		return (static_cast<Triangle*>(p))->get_perimeter();
	}
	if (shape == circle){
		return (static_cast<Circle*>(p))->get_circumference();
	}
}

const double in::get_start_point_x()const{
	if (shape == rectangle){	
		return (static_cast<Rectangle*>(p))->get_start_point_x();
	}
	if (shape == triangle){
		return (static_cast<Triangle*>(p))->get_start_point_x();
	}
	if (shape == circle){
		return (static_cast<Circle*>(p))->get_start_point_x();
	}
}
const double in::get_start_point_y()const{
	if (shape == rectangle){	
		return (static_cast<Rectangle*>(p))->get_start_point_y();
	}
	if (shape == triangle){
		return (static_cast<Triangle*>(p))->get_start_point_y();
	}
	if (shape == circle){
		return (static_cast<Circle*>(p))->get_start_point_y();
	}
}
const double in::get_direction()const{
	if (shape == rectangle){	
		return (static_cast<Rectangle*>(p))->get_direction();
	}
	if (shape == triangle){
		return (static_cast<Triangle*>(p))->get_direction();
	}
	
}
const double in::get_type()const{
	if (shape == rectangle){	
		return (static_cast<Rectangle*>(p))->get_type();
	}
	if (shape == triangle){
		return (static_cast<Triangle*>(p))->get_type();
	}
	if (shape == circle){
		return (static_cast<Circle*>(p))->get_type();
	}
}

const double in::equation_circle(double x)const{
	if (shape == circle){
		return (static_cast<Circle*>(p))->equation_circle(x);
	}
	cout<<"the shape is not circle !!!!\n";
}
