#ifndef POLYGONVECT_H_
#define POLYGONVECT_H_
# include <iostream>
# include <vector>
# include "RECTANGLE.h"
# include "CIRCLE.h"
# include "TRIANGLE.h"
# include "POLYGON.h"
using namespace std;
namespace jwan_{
	class POLYGONVECT : public POLYGON {
		public:
			POLYGONVECT():POLYGON(){
				area = 0 ;
				perimeter = 0 ;
			};
			POLYGONVECT(vector<point2d>& v):vect(v){
				area = 0 ;
				perimeter = 0 ;
			};
			POLYGONVECT(point2d& p){
				vect.push_back(p);
				area = 0 ;
				perimeter = 0 ;
			};
			POLYGONVECT(RECTANGLE& r);
			POLYGONVECT(CIRCLE& c);
			POLYGONVECT(TRIANGLE& t);

			const double get_area()const;
			const double get_perimeter()const;
			const void print_data()const;
			
			ostream& print_shape(ostream&);

			POLYGONVECT& operator ++();
			POLYGONVECT& operator ++(int ignore);
			POLYGONVECT& operator --();
			POLYGONVECT& operator --(int ignore);

		private:
			vector<point2d> vect ; 
	};

}

#endif /* POLYGONVECT_H_ */