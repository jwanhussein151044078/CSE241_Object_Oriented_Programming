#ifndef COMPOSEDSHAPE_H_
#define COMPOSEDSHAPE_H_

#include "RECTANGLE.h"
#include "CIRCLE.h"
#include "TRIANGLE.h"
# include <vector>

using namespace std;

namespace jwan_{
	
	class COMPOSEDSHAPE : public SHAPE {
		
		public:
			COMPOSEDSHAPE() {};
			COMPOSEDSHAPE(RECTANGLE& r1 , RECTANGLE& r2);
			COMPOSEDSHAPE(RECTANGLE& r, CIRCLE& c);
			COMPOSEDSHAPE(RECTANGLE& r, TRIANGLE& t);
			COMPOSEDSHAPE(CIRCLE& c, RECTANGLE& r);
			COMPOSEDSHAPE(CIRCLE& c1, CIRCLE& c2);
			COMPOSEDSHAPE(CIRCLE& c, TRIANGLE& t);
			COMPOSEDSHAPE(TRIANGLE& t, RECTANGLE& r);
			COMPOSEDSHAPE(TRIANGLE& t, CIRCLE& c);
			COMPOSEDSHAPE(TRIANGLE& t1, TRIANGLE& t2);
			

			const int get_size_vector(){  return vec.size() ; }

			const double get_area()const{};
			const double get_perimeter()const{};
			const void print_data()const{};

			ostream& print_shape(ostream&);

			COMPOSEDSHAPE& operator++(){};
			COMPOSEDSHAPE& operator++(int ignore ){};
			COMPOSEDSHAPE& operator --(){};
			COMPOSEDSHAPE& operator --(int ignore){};

			COMPOSEDSHAPE& operator +=(SHAPE* temp);
			SHAPE* operator [](int i);
			//friend ostream& operator << ( ostream& outputStream, COMPOSEDSHAPE* );

			void fit_R_R();
			void fit_C_R();
			void fit_T_R();

			void fit_R_C();
			void fit_C_C();
			void fit_T_C();

			void fit_R_T();
			void fit_C_T();
			void fit_T_T();

		private:
			vector<SHAPE*>	vec;

	};


}
#endif /* COMPOSEDSHAPE_H_ */