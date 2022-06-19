
#ifndef polygon_H_
#define polygon_H_
using namespace std;
# include <vector>
enum TYPE { container , inner , unknown};
enum SHAPE { rectangle_shape , circle_shape , triangle_shape , point , polygon_shape };
namespace jwan_{
	class polygon{

		public:
			class point2D {
				public:
					point2D(): x(0), y(0){};
					point2D(double a,double b);

					const double get_x()const{	return x; }
					const double get_y()const{	return y; }

					void set_x_y(double a , double b);

				private:
					double x ;
					double y ;
					bool check_point();					
			};
			
			polygon(){};
			polygon(vector<point2D> vec);
			polygon(point2D temp_point2D );
			polygon(Rectangle& rec );
			polygon(Circle& cir );
			polygon(Triangle& tri );

			void set_type(TYPE t);
			void set_shape(SHAPE s);

			const TYPE get_type(){	return type; }
			const SHAPE get_shape()const{	return shape; }
			const int get_size()const{	return count ; }
			const double get_biggest_x()const;
			const double get_biggest_y()const;
			
			const polygon::point2D operator [](int);
			const polygon operator +(const polygon& p1);
			friend const bool operator ==(const polygon& p1 , const polygon& p2);
			friend const bool operator !=(const polygon& p1 , const polygon& p2);
			friend ostream& operator <<(ostream& outputStream,const polygon& pol);

		protected:
			double *x ;
			double *y ;
			int count ;
			TYPE type ;
			SHAPE shape ;
	};

	class polyline : public polygon{
		public:
			polyline(){};
			polyline(vector<point2D> vec);
			polyline(point2D temp_point2D );
			polyline(Rectangle& rec );
			polyline(Circle& cir );
			polyline(Triangle& tri );

			const polyline::point2D operator [](int);
			const polyline operator +(const polyline& p1);
			
			friend const bool operator ==(const polyline& p1 , const polyline& p2);
			friend const bool operator !=(const polyline& p1 , const polyline& p2);
			friend ostream& operator <<(ostream& outputStream,const polyline& pol);

	};



}

#endif /* polygon_H_ */
