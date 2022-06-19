
#ifndef SHAPES_H_
#define SHAPES_H_
# include <iostream>
using namespace std;
namespace jwan_{

	enum TYPE { inner ,container ,polygon};
	
	class SHAPE {
		public:
			SHAPE():start_point_x(0),start_point_y(0),type(container){};
			SHAPE(double x , double y ):start_point_x(x),start_point_y(y),type(container){
				check();
			};
			SHAPE(double x , double y , TYPE t):start_point_x(x),start_point_y(y),type(t){
				check();
			};

			const double get_start_point_x ()const{ return start_point_x ; }
			const double get_start_point_y ()const{ return start_point_y ; }
			const TYPE get_type ()const{ return type ; }

			void set_start_points(double x , double y );

			virtual const double get_area()const = 0 ;
			virtual const double get_perimeter()const = 0 ;
			virtual const void print_data()const = 0 ;
			
			virtual ostream& print_shape(ostream&) =0 ;

			virtual SHAPE& operator ++() = 0;
			virtual SHAPE& operator ++(int ignore) =0;
			virtual SHAPE& operator --() =0;
			virtual SHAPE& operator --(int ignore) =0;
		
			virtual const bool operator == ( const SHAPE& other );
			virtual const bool operator != ( const SHAPE& other );

			virtual const bool operator < ( const SHAPE& other );
			virtual const bool operator > ( const SHAPE& other );
		

		protected:
			double start_point_x , 
			 	   start_point_y ;

			double area , perimeter ;
			TYPE type ;

			void check();

	};


}
#endif /* SHAPES_H_ */