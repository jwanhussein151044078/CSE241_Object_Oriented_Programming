  
  using namespace std;

#ifndef RECTANGLE_H_
#define RECTANGLE_H_



class Rectangle {
	public:
		
		Rectangle();
		Rectangle(double l , double w);

		bool set_length(double l);
		bool set_width(double w);
		void set_position_direction(double start_x ,double start_y ,int d);
		
		double get_length()const;
		double get_width()const;
		double get_size()const;

		void draw_rect(ofstream & file , const string color)const;


	private:
		double length , width ; 
		double s_p_x , s_p_y ;
		int direction ;
};

#endif /* RECTANGLE_H_ */