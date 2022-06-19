  

  using namespace std;

#ifndef Triangle_H_
#define Triangle_H_

class Triangle {
	public:
		
		Triangle();
		Triangle(double l);
		
		bool set_length(double l);
		void set_position_direction(double start_x,double start_y,int d); 
		
		double get_size()const;
		double get_hight()const;
		double get_length()const;

		void draw_Triangle(ofstream & file, const string color )const;

	private:
		double length;
		double s_p_x , s_p_y ;
		int direction ;
};

#endif /* Triangle_H_ */