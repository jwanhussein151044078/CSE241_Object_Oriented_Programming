#ifndef POLYGON_H_
#define POLYGON_H_
# include <iostream>
# include "SHAPE.h"
using namespace std;
namespace jwan_{

	class POLYGON : public SHAPE {
		public:
			class point2d {
				public:	
					point2d():x(0),y(0){};
					point2d(double a , double b):x(a),y(b){
						check_point();
					};

					void set_points(double , double );

					const double get_x()const;
					const double get_y()const;

					void const print_point()const;

				private:
					double x,y;	
					bool check_point();
			};

			POLYGON():SHAPE(0,0,polygon){};
			POLYGON(double a,double b):SHAPE(a,b,polygon){};
		
	};
}
#endif /* POLYGON_H_ */