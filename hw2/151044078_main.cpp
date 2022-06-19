# include <iostream>
# include <fstream>  
# include "Rectangle.h"
# include "Circle.h"
# include "Triangle.h"
# include "ComposedShape.h"
# include "function.h"

# define color_continer "red"
# define color_inner "green"

  using namespace std;

int main (){
	

	string continer , inner ;
	double continer_length , continer_width , inner_length , inner_width ;
	
	take_data(&continer ,&continer_length , &continer_width , 1); // take data of the container 
	take_data(&inner,&inner_length,&inner_width , 2);  // take data of the inner shape 
	ComposedShape composedShape;
	ofstream file("output.svg"); // open file

	composedShape.set_container( continer , continer_length , continer_width ); 
	composedShape.set_inner(inner , inner_length,inner_width,0,0,1);
	composedShape.optimalFit(continer,inner);
	composedShape.draw_first_line( file , continer );
	composedShape.draw_container( file , continer , color_continer );
	composedShape.draw_optimized(file ,inner , color_inner);
	composedShape.draw_last_line(file);
	
	file.close(); // close file
	
	int number_of_small_shape = composedShape.get_size_v(inner);

	cout <<"I can fit at most " << number_of_small_shape <<" small shapes into the main container. The empty area ("
		 <<color_continer<<") in container is " 	
		 <<composedShape.get_size_container(continer) - (composedShape.get_size_inner(inner) * number_of_small_shape) <<"\n";

	return 0;
}