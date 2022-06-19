class SHAPE
!!!144254.cpp!!!	operator ==(in other : SHAPE) : bool
		return ( this->area == other.area );
!!!144382.cpp!!!	operator !=(in other : SHAPE) : bool
		return ( this->area != other.area );
!!!144510.cpp!!!	operator <(in other : SHAPE) : bool
		return ( this->area < other.area );
!!!144638.cpp!!!	operator >(in other : SHAPE) : bool
		return ( this->area > other.area );
!!!144766.cpp!!!	check() : void
		if (start_point_x < 0)
			start_point_x *= -1 ;

		if (start_point_y < 0)
			start_point_y *= -1 ;

		if (type != container )
			type = inner ;

!!!143102.cpp!!!	set_start_points(in x : double, in y : double) : void
		start_point_x = x ;
		start_point_y = y ; 
		check();
