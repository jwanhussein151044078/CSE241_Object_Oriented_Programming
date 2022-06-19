#ifndef RECTANGLE_H_
#define RECTANGLE_H_
//#include <iostream>
#include "SHAPE.h"

using namespace std;

namespace jwan_{
	
	class RECTANGLE : public SHAPE{
		
		public:
			RECTANGLE():SHAPE(),length(0),width(0){}; 	
				
			RECTANGLE(double l, double w ):SHAPE(),length(l),width(w){
				check_data();
				set_area() ;
				set_perimeter();
			};
	
			RECTANGLE(double l, double w , double x , double y):SHAPE(x,y),length(l),width(w){
				check_data();
				set_area() ;
				set_perimeter();
			};

			RECTANGLE(double l, double w , double x , double y , int d , TYPE t)
					:SHAPE(x,y,t),length(l),width(w),direction(d){
				check_data();
				set_area() ;
				set_perimeter();
			};
			
			const double get_length()const;
			const double get_width()const;
			const int get_direction()const;
			const double get_area()const;
			const double get_perimeter()const;

			void set_length(double l);
			void set_width(double w);

			ostream& print_shape(ostream&);

			const RECTANGLE operator +(double doub)const;
			const RECTANGLE operator -(double doub)const;

			RECTANGLE& operator ++();
			RECTANGLE& operator ++(int ignore );
			RECTANGLE& operator --();
			RECTANGLE& operator --(int ignore);

			const void  print_data()const ;
			//friend ostream& operator <<(ostream& outputStream,const RECTANGLE& rect);

		private:
			
			double length , width ; 
			int direction ;
			void check_data();			
			void set_area();
			void set_perimeter();

	}; 



}
#endif /* RECTANGLE_H_ */