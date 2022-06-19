# include <iostream>
# include <fstream>  
# include "SHAPES.h"
# include "ComposedShape.h"
# include "function.h"
#define sqrt3 1.73205


int main(){
	string c , i ;
	double length ,width , S_length , S_width , radius , S_radius ;
	take_data( &c , &length , &width , 1 );
	take_data( &i , &S_length , &S_width , 2 );


	ofstream f("output.svg");
	
	if (c == "R" && i == "R"){ 
		Rectangle r1(length , width , 0 , 0 , 'C' , 1) ;
		Rectangle r2(S_length , S_width);
		ComposedShape a(r1,r2);
		f << a ;
	}
	if (c == "R" && i == "C"){ 
		Rectangle r(length , width , 0 , 0 , 'C' , 1) ;
		Circle c(S_length);
		ComposedShape a(r,c);
		f << a ;
	}
	if (c == "R" && i == "T"){ 
		Rectangle r(length , width , 0 , 0 , 'C' , 1) ;
		Triangle t(S_length);
		ComposedShape a(r,t);
		f << a ;
	}
	if (c == "C" && i == "R"){ 
		Circle c(length , length , length , 'C' ) ;
		Rectangle r(S_length , S_width);
		ComposedShape a(c,r);
		f << a ;
	}
	if (c == "C" && i == "C"){ 
		Circle c1(length , length , length , 'C' ) ;
		Circle c2(S_length);
		ComposedShape a(c1,c2);
		f << a ;
	}
	if (c == "C" && i == "T"){ 
		Circle c(length , length , length , 'C' ) ;
		Triangle t(S_length);
		ComposedShape a(c,t);
		f << a ;
	}
	if (c == "T" && i == "R"){ 
		Triangle t(length , 0 , length*sqrt3/2 , 1 , 'C' ) ;
		Rectangle r(S_length , S_width);
		ComposedShape a(t,r);
		f << a ;
	}
	if (c == "T" && i == "C"){ 
		Triangle t(length , 0 , length*sqrt3/2 , 1 , 'C' ) ;
		Circle c(S_length);
		ComposedShape a(t,c);
		f << a ;
	}
	if (c == "T" && i == "T"){ 
		Triangle t1(length , 0 , length*sqrt3/2 , 1 , 'C' ) ;
		Triangle t2(S_length);
		ComposedShape a(t1,t2);
		f << a ;
	}
	
	
	f.close();
	cout << "the shape hase been drawn to the out put file \n" ;
	string filename = "test1.svg" ;
	cout << "//////////////////////////////test function from SHAPE.h //////////////////////////\n";
	Rectangle r1(314,100,0,0,'C',1) , r2(350,140,0,0,'C',1) , r3(30,25) , r4(40,20) ;
	Circle c1(200,200,200,'C') , c2(300,300,300,'C') , c3(100) , c4(20) ;
	Triangle t1(200,0,200*sqrt3/2,1,'C') ,t2(350,0,350*sqrt3/2,1,'C') , t3(40) , t4(20) ;
	ComposedShape::ShapeElem sh1(r1) , sh2(c1) , sh3(t1) , sh4(c2) ;
	ComposedShape a1(r1,c4) , a2(c2,t4) , a3(t2,r4) , a4(r2,t3);
	ComposedShape a5[4] {{a1},{a2},{a3},{a4}};
	for (int i = 0; i < 4; ++i)
	{
		filename[4] = '1'+i;
		ofstream f(filename);
		f << a5[i] ;
		f.close();
		
	}




	cout << "the start point of the first rect are "<< r1.get_start_point_x() << " and " << r1.get_start_point_y() <<"\n";
	cout << "the start point of the first cir are "<< c1.get_start_point_x() << " and " << c1.get_start_point_y() <<"\n";
	cout << "the start point of the first tri are "<< t1.get_start_point_x() << " and " << t1.get_start_point_y() <<"\n";
	r1++; 
	c1++;
	t1++;
	cout << "the new start point of the first after incrasement rect are "<< r1.get_start_point_x() << " and " << r1.get_start_point_y() <<"\n";
	cout << "the new start point of the first after incrasement cir are "<< c1.get_start_point_x() << " and " << c1.get_start_point_y() <<"\n";
	cout << "the new start point of the first after incrasement tri are "<< t1.get_start_point_x() << " and " << t1.get_start_point_y() <<"\n\n";
	r1--; 
	c1--;
	t1--;
	cout << "the new start point of the first after decrasement rect are "<< r1.get_start_point_x() << " and " << r1.get_start_point_y() <<"\n";
	cout << "the new start point of the first after decrasement cir are "<< c1.get_start_point_x() << " and " << c1.get_start_point_y() <<"\n";
	cout << "the new start point of the first after decrasement tri are "<< t1.get_start_point_x() << " and " << t1.get_start_point_y() <<"\n\n\n";
	if (r1 == c3){
		cout << "the size of r1 is equal to the size of c3 \n\n";
	}
	else {
		cout << "the size of r1 is not equal to the size of c3 \n\n";
	}


	cout << "the length and width of rect r1 are "<< r1.get_length() << " and " << r1.get_width() <<"\nr1 size =  "<<r1.get_area() << "\n";
	r1 = r1 + 5000 ;
	cout << "the new length and width and size are "<< r1.get_length() <<" "<< r1.get_width() << " " << r1.get_area() <<"\n";
	r1 = r1 - 7500 ;
	cout << "the new length and width and size are "<< r1.get_length() <<" "<< r1.get_width() << " " << r1.get_area() <<"\n";

	cout << "the radius c2 is "<< c2.get_radius()  <<"\nr1 size =  "<<c2.get_area() << "\n";
	c2 = c2 + 5000 ;
	cout << "the new radius and size are "<< c2.get_radius() <<" " << c2.get_area() <<"\n";
	c2 = c2 - 9999999999 ;
	cout << "the new radius and size are "<< c2.get_radius() << " " << c2.get_area() <<"\n";

	if (r1 == c3){
		cout << "the size of r1 is equal to the size of c3 \n\n";
	}
	else {
		cout << "the size of r1 is not equal to the size of c3 \n\n";
	}

	if (r1 != r3){
		cout << "the size of r1 is not equal to the size of r3 \n\n";
	}
	else {
		cout << "the size of r1 is  equal to the size of r3 \n\n";
	}


	ComposedShape q ;

	q += sh1 ;
	q += sh2 ;
	ofstream f1("test5.svg");
	f1 << q ;
	f1.close();
	
	cout << "the total area and perimeter of rectangle class is >> "<<Rectangle::get_total_area()<< " "<<  Rectangle::get_total_perimeter()<<"\n" ;
	cout << "the total area and perimeter of circle class is >> "<<Circle::get_total_area()<< " "<<  Circle::get_total_circumference()<<"\n" ;
	cout << "the total area and perimeter of Triangle class is >> "<<Triangle::get_total_area()<< " "<<  Triangle::get_total_perimeter()<<"\n" ;
	
	return 0 ;

}