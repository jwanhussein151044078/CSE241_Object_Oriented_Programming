# include "SHAPE.h"

namespace jwan_{

	
	const bool SHAPE::operator == ( const SHAPE& other ){
		return ( this->area == other.area );
	}

	
	const bool SHAPE::operator != ( const SHAPE& other ){
		return ( this->area != other.area );
	}

	
	const bool SHAPE::operator < ( const SHAPE& other ){
		return ( this->area < other.area );
	}

	
	const bool SHAPE::operator > ( const SHAPE& other ){
		return ( this->area > other.area );
	}
	void SHAPE::check(){
		if (start_point_x < 0)
			start_point_x *= -1 ;

		if (start_point_y < 0)
			start_point_y *= -1 ;

		if (type != container )
			type = inner ;

	}

	void SHAPE::set_start_points(double x , double y ){
		start_point_x = x ;
		start_point_y = y ; 
		check();
	}
}