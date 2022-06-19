#ifndef TRIANGLE_H_
#define TRIANGLE_H_
#include "SHAPE.h"
#include "cmath"

using namespace std;
namespace jwan_{
	
	class TRIANGLE : public SHAPE{
		
		public:
			TRIANGLE():SHAPE(),length(0){}; 	
				
			TRIANGLE(double l):SHAPE(),length(l){
				check_data();
				set_height();
				set_area() ;
				set_perimeter();
			};
	
			TRIANGLE(double l, double x , double y):SHAPE(x,y),length(l){
				check_data();
				set_height();
				set_area() ;
				set_perimeter();
			};

			TRIANGLE(double l, double x , double y ,int d, TYPE t):SHAPE(x,y,t),length(l),direction(d){
				check_data();
				set_height();
				set_area() ;
				set_perimeter();
			};
			
			const double get_length()const;
			const double get_height()const;
			const int get_direction()const;
			const double get_area()const;
			const double get_perimeter()const;

			void set_length(double l);

			ostream& print_shape(ostream&);

			const TRIANGLE operator +(double doub)const;
			const TRIANGLE operator -(double doub)const;

			TRIANGLE& operator ++();
			TRIANGLE& operator ++(int ignore );
			TRIANGLE& operator --();
			TRIANGLE& operator --(int ignore);

			const void  print_data()const ;
			//friend ostream& operator <<(ostream& outputStream,const TRIANGLE& tri);

		private:
			
			double length , height;
			int direction ; 
			void check_data();
			void set_height();			
			void set_area();
			void set_perimeter();

	}; 



}
#endif /* TRIANGLE_H_ */