# include <vector>

  using namespace std;

#ifndef ComposedShape_H_
#define ComposedShape_H_

class ComposedShape {
	public:
		ComposedShape():R_container(0,0),R_inner(0,0),C_container(0),C_inner(0),T_container(0),T_inner(0){};

		
		ComposedShape( Rectangle container , Rectangle inner):R_container(container),R_inner(inner){};
		ComposedShape( Rectangle container , Circle inner):R_container(container),C_inner(inner){};
		ComposedShape( Rectangle container , Triangle inner):R_container(container),T_inner(inner){};
		
		ComposedShape( Circle container , Rectangle inner):C_container(container),R_inner(inner){};
		ComposedShape( Circle container , Circle inner):C_container(container),C_inner(inner){};
		ComposedShape( Circle container , Triangle inner):C_container(container),T_inner(inner){};

		ComposedShape( Triangle container , Rectangle inner):T_container(container),R_inner(inner){};
		ComposedShape( Triangle container , Circle inner):T_container(container),C_inner(inner){};
		ComposedShape( Triangle container , Triangle inner):T_container(container),T_inner(inner){};

		void set_container(const string x ,double length,double width);
		void set_inner(const string x ,double length,double width , double start_x, double start_y, int d);

		
		void inssert_to_vector(const string x);
		void optimalFit(const string container , const string inner);

		int get_size_v(const string x)const;
		double get_size_container(const string x)const;
		double get_size_inner(const string x)const;

		void draw_container(ofstream & file ,const string x , const string color)const;
		void draw_optimized(ofstream & file ,const string x ,const string color)const;
		
		void draw_first_line(ofstream & file , const string x )const;
		void draw_last_line(ofstream & file)const;

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
		
		Rectangle R_container , R_inner ;
		Circle C_container , C_inner ;
		Triangle T_container , T_inner ;
		
		vector <Rectangle> Rv ;
		vector <Circle> Cv ;
		vector <Triangle> Tv ;
};

#endif /* ComposedShape_H_ */