# include <iostream>
# include <fstream>  
# include <string>
# include "SHAPE.h"
# include "COMPOSEDSHAPE.h"
# include "RECTANGLE.h"
# include "CIRCLE.h"
# include "TRIANGLE.h"
# include "POLYGON.h"
# include "POLYGONVECT.h"
# include "POLYGONDYN.h"
# include "global_functions.h"
# include <cmath>
using namespace std ;
using namespace jwan_ ;

int main(){
	RECTANGLE r1(200,170,0,0,1,container) , r2(18,10);
	CIRCLE c1 (200,200,200,container) , c2(20);
	TRIANGLE t1(130,0,65*sqrt(3),1,container), t2(15);
	COMPOSEDSHAPE a(r1,r2) , b(r1,c2) , c(r1,t2) , d(c1,r2) , e(c1,c2) , f(c1,t2) , g(t1,r2) , h (t1,c2) , j(t1,t2) ;
	COMPOSEDSHAPE com[9] {{a},{b},{c},{d},{e},{f},{g},{h},{j}};
	string filename = "test1_composedshape.svg" ;
	for (int i = 0; i < 9; ++i)
	{
		filename[4] = '1'+i;
		ofstream f(filename);
		f << com[i] ;
		f.close();
	}
	r1 = r1 + 50 ;
	POLYGONVECT poly1(r1);
	ofstream f1("POLYGONVECT_test.svg");
		f1 << poly1 ;
	f1.close();
	POLYGONDYN poly2(r1);
	ofstream f2("POLYGONDYN_test.svg");
		f2 << poly2 ;
	f2.close();

	r1.print_data();
	++r1;
	r1.print_data();
	if (r1 == c1 )	
		cout <<"the rectangle area is equal to the circle area \n";
	else 
		cout <<"the rectangle area is not equal to the circle area \n";

 	vector<SHAPE*> vec ; 
 	vec.push_back(&r1);
 	vec.push_back(&c1);
 	vec.push_back(&t1);
 	vec.push_back(&poly1);
 	vec.push_back(&poly2);
 	cout << "test printall !!!!!!!!!!!!!!!!!\n\n\n";
 	printAll(cout , vec);
 	cout << "test printpoly !!!!!!!!!!!!!!!!!\n\n\n";
 	printPoly(cout , vec);


}