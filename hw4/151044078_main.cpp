# include <iostream>
# include <fstream> 
# include <cmath> 
# include "SHAPES.h"
# include "polygon.h"
# include "ComposedShape.h"
# include "function.h"
#define sqrt3 1.73205
using namespace jwan_;

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
		Circle c(S_length,S_length,S_length);
		ComposedShape a(r,c);
		f << a ;
	}
	if (c == "R" && i == "T"){ 
		Rectangle r(length , width , 0 , 0 , 'C' , 1) ;
		Triangle t(S_length,0,S_length*sqrt(3)/2);
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
		Circle c2(S_length,S_length,S_length);
		ComposedShape a(c1,c2);
		f << a ;
	}
	if (c == "C" && i == "T"){ 
		Circle c(length , length , length , 'C' ) ;
		Triangle t(S_length,0,S_length*sqrt(3)/2);
		ComposedShape a(c,t);
		f << a ;
	}
	if (c == "T" && i == "R"){ 
		Triangle t(length , 0 , length*sqrt(3)/2 , 1 , 'C' ) ;
		Rectangle r(S_length , S_width);
		ComposedShape a(t,r);
		f << a ;
	}
	if (c == "T" && i == "C"){ 
		Triangle t(length , 0 , length*sqrt(3)/2 , 1 , 'C' ) ;
		Circle c(S_length,S_length,S_length);
		ComposedShape a(t,c);
		f << a ;
	}
	if (c == "T" && i == "T"){ 
		Triangle t1(length , 0 , length*sqrt(3)/2 , 1 , 'C' ) ;
		Triangle t2(S_length,0,S_length*sqrt(3)/2);
		ComposedShape a(t1,t2);
		f << a ;
	}
	
	
	f.close();
	cout << "the shape hase been drawn to the out put file \n" ;
	string filename = "test1.svg" ;


	Rectangle r1(314,100,0,0,'C',1) , r2(350,140,0,0,'C',1) , r3(30,25,0,0) , r4(40,20,0,0) ;
	
	Circle c1(200,200,200,'C') , c2(300,300,300,'C') , c3(100,100,100) , c4(20,20,20) ;
	
	Triangle t1(200,0,200*sqrt3/2,1,'C') ,t2(350,0,350*sqrt(3)/2,1,'C') , t3(40,0,40*sqrt(3)/2) , t4(20,0,20*sqrt(3)/2) ;
	
	
	polygon::point2D points[5] = {polygon::point2D(10,30),polygon::point2D(150,300),polygon::point2D(250,100),
									polygon::point2D(175,75),polygon::point2D(100,500) };


	ComposedShape a1(r1,c4) , a2(c2,t4) , a3(t2,r4) , a4(r2,t3) , a5(r2,r4) , a6(c1,c4) , a7(c2,r3) , a8(t2,c3) , a9(t2,t4) ;
	
	ComposedShape aa[9] {{a1},{a2},{a3},{a4},{a5},{a6},{a7},{a8},{a9}};
	
	for (int i = 0; i < 9; ++i)
	{
		filename[4] = '1'+i;
		ofstream f(filename);
		f << aa[i] ;
		f.close();
		
	}



	vector<polygon::point2D> vec ;
	for(int i = 0 ; i < 5 ; i++){
		vec.push_back(points[i]);
	}
	
	polygon pol(vec), pol1(r1) , pol2(c1) , pol3(t1) , pol4(polygon::point2D(100,100));
	polygon pol_arr[5] = {{pol},{pol1},{pol2},{pol3},{pol4}};
	
	polyline poli(vec), poli1(r1) , poli2(c1) , poli3(t1) , poli4(polygon::point2D(100,100));
	polyline poli_arr[5] = {{poli},{poli1},{poli2},{poli3},{poli4}};

	char temp = '"';
	string file = "polygon_test1.svg";
	string filei = "polyline_test1.svg" ;
	for (int i = 0; i < 3; ++i)
	{
		file[12] = '1'+i;
		ofstream f1(file);
		f1 << "<svg width="<<temp<<500<<temp<<" hight="<<temp
				 <<500<<temp<<"> \n";
		f1 << pol_arr[i] ;
		f1 <<  "\n</svg> ";

	f1.close();
	}

	for (int i = 0; i < 3; ++i)
	{
		filei[13] = '1'+i;
		ofstream f2(filei);
		f2 << "<svg width="<<temp<<500<<temp<<" hight="<<temp
				 <<500<<temp<<"> \n";
		f2 << poli_arr[i] ;
		f2 <<  "\n</svg> ";

		f2.close();
	}

	




	




	
	return 0 ;


}