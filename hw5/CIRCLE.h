#ifndef CIRCLE_H_
#define CIRCLE_H_
#include "SHAPE.h"
using namespace std;
namespace jwan_{
	
	class CIRCLE : public SHAPE{
		
		public:
			CIRCLE():SHAPE(),radius(0){}; 	
				
			CIRCLE(double r):SHAPE(),radius(r){
				check_data();
				set_area() ;
				set_perimeter();
			};
	
			CIRCLE(double r, double x , double y):SHAPE(x,y),radius(r){
				check_data();
				set_area() ;
				set_perimeter();
			};

			CIRCLE(double r, double x , double y , TYPE t):SHAPE(x,y,t),radius(r){
				check_data();
				set_area() ;
				set_perimeter();
			};
			
			const double get_radius()const;
			const double get_area()const;
			const double get_perimeter()const;

			void set_radius(double r);

			ostream& print_shape(ostream&);

			const CIRCLE operator +(double doub)const;
			const CIRCLE operator -(double doub)const;

			CIRCLE& operator ++();
			CIRCLE& operator ++(int ignore );
			CIRCLE& operator --();
			CIRCLE& operator --(int ignore);

			const void  print_data()const ;
			//friend ostream& operator <<(ostream& outputStream,const CIRCLE& cir);

		private:
			
			double radius; 
			void check_data();			
			void set_area();
			void set_perimeter();

	}; 



}
#endif /* CIRCLE_H_ */