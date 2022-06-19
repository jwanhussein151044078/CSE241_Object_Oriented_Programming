
 using namespace std;

#ifndef Circle_H_
#define Circle_H_

class Circle {
	public:
		Circle();
		Circle(double r);
		
		bool set_radius(double r);
		void set_position(double start_x , double start_y );
		double equation_circle(double x);
		
		double get_radius()const;
		double get_size()const;

		void draw_Circle(ofstream & file , const string color)const;

	private:
		double radius;
		double s_p_x , s_p_y ; 
};

#endif /* Circle_H_ */