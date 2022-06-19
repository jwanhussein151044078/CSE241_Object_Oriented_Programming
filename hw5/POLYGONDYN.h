#ifndef POLYGONDYN_H_
#define POLYGONDYN_H_
# include <iostream>
# include <vector>
# include "RECTANGLE.h"
# include "CIRCLE.h"
# include "TRIANGLE.h"
# include "POLYGON.h"
using namespace std;
namespace jwan_{
	class POLYGONDYN : public POLYGON {
		public:
			POLYGONDYN():POLYGON(){
				area = 0 ;
				perimeter =0 ;
			};
			POLYGONDYN(point2d& p);
			POLYGONDYN(RECTANGLE& r);
			POLYGONDYN(CIRCLE& c);
			POLYGONDYN(TRIANGLE& t);
			POLYGONDYN(const POLYGONDYN& );
			~POLYGONDYN();

			const double get_area()const;
			const double get_perimeter()const;
			const void print_data()const;
			
			ostream& print_shape(ostream&);

			POLYGONDYN& operator ++();
			POLYGONDYN& operator ++(int ignore);
			POLYGONDYN& operator --();
			POLYGONDYN& operator --(int ignore);

			POLYGONDYN& operator = ( const POLYGONDYN& );
			const point2d operator [] (int );


		private:
			point2d* point;
			int size ; 
	};

}

#endif /* POLYGONDYN_H_ */