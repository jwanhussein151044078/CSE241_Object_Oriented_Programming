

#ifndef ComposedShape_H_
#define ComposedShape_H_

using namespace std;
# include <vector>

enum SHAPES_TYPE{ rectangle , circle , triangle };
namespace jwan_{
class ComposedShape {
	public:
		
		
		class ShapeElem{

			public:
				ShapeElem(Rectangle& );
				ShapeElem(Circle&);
				ShapeElem(Triangle&);

				void set_shape_type(SHAPES_TYPE t){
					shape = t ;
				}
				void set_all(double , double , double ,double ,int ,char);

				const SHAPES_TYPE get_shape_type()const{ return shape; }
				const double get_lengthorradius()const;
				const double get_widthorheight()const;
				const double get_start_point_x()const;
				const double get_start_point_y()const;
				const double get_direction()const;
				const double get_type()const;
				const double get_perimeter()const;
				const double get_area()const;
				const double equation_circle(double x)const;
				
				friend ostream& operator <<(ostream& outputStream,ShapeElem& );

			private:
			void *p ;
			SHAPES_TYPE shape ;
		}; 
		ComposedShape(){};
		ComposedShape(Rectangle& , Rectangle& );
		ComposedShape(Rectangle& , Circle& );
		ComposedShape(Rectangle& , Triangle& );
		ComposedShape(Circle& , Rectangle& );
		ComposedShape(Circle& , Circle& );
		ComposedShape(Circle& , Triangle& );
		ComposedShape(Triangle& , Rectangle& );
		ComposedShape(Triangle& , Circle& );
		ComposedShape(Triangle& , Triangle& );

		void optimalFit();
		void fit_R_R();
		void fit_C_R();
		void fit_T_R();

		void fit_R_C();
		void fit_C_C();
		void fit_T_C();

		void fit_R_T();
		void fit_C_T();
		void fit_T_T();

		const int get_size_vector(){  return vec.size() ; }
		
		polygon& operator [](int i);
		ComposedShape& operator +=(polygon& temp);

		friend ostream& operator <<(ostream& outputStream,ComposedShape& );

	private:
		vector<polygon> vec ;
};

}
#endif /* ComposedShape_H_ */