import java.awt.Graphics;
import javax.swing.JPanel;
import java.awt.Color;
import java.lang.StrictMath;


public class composedshape extends JPanel implements SHAPE {

	public composedshape(rectangle r1 , rectangle r2){
		arr = new SHAPE[25];
		r1.set_type('c');
		r1.set_direction(1);
		arr[0] = r1 ;
		r2.set_type('i');
		arr[1] = r2 ;
		used = 1 ;
		Fit_R_R();
	}
	public composedshape(rectangle r , circle c){
		arr = new SHAPE[25];
		r.set_type('c');
		r.set_direction(1);
		arr[0] = r ;
		c.set_type('i');
		arr[1] = c ;
		used = 1 ;
		Fit_C_R();
	}
	public composedshape(rectangle r , triangle t){
		arr = new SHAPE[25];
		r.set_type('c');
		r.set_direction(1);
		arr[0] = r ;
		t.set_type('i');
		arr[1] = t ;
		used = 1 ;
		Fit_T_R();
	}
	public composedshape(circle c , rectangle r){
		arr = new SHAPE[25];
		c.set_type('c');
		arr[0] = c ;
		r.set_type('i');
		arr[1] = r ;
		used = 1 ;
		Fit_R_C();
	}
	public composedshape(circle c1 , circle c2){
		arr = new SHAPE[25];
		c1.set_type('c');
		arr[0] = c1 ;
		c2.set_type('i');
		arr[1] = c2 ;
		used = 1 ;
		Fit_C_C();
	}
	public composedshape(circle c , triangle t){
		arr = new SHAPE[25];
		c.set_type('c');
		arr[0] = c ;
		t.set_type('i');
		arr[1] = t ;
		used = 1 ;
		Fit_T_C();
	}
	public composedshape(triangle t , rectangle r){
		arr = new SHAPE[25];
		t.set_direction(1);
		t.set_type('c');
		if(t.get_start_point_y() < t.get_height()){
			t.set_startpoints(t.get_start_point_x(),t.get_height());
		}
		arr[0] = t ;
		r.set_type('i');
		arr[1] = r ;
		used = 1 ;
		Fit_R_T();
	}
	public composedshape(triangle t , circle c){
		arr = new SHAPE[25];
		t.set_type('c');
		t.set_direction(1);
		if(t.get_start_point_y() < t.get_height()){
			t.set_startpoints(t.get_start_point_x(),t.get_height());
		}
		arr[0] = t ;
		c.set_type('i');
		arr[1] = c ;
		used = 1 ;
		Fit_C_T();
	}
	public composedshape(triangle t1 , triangle t2){
		arr = new SHAPE[25];
		t1.set_type('c');
		t1.set_direction(1);
		if(t1.get_start_point_y() < t1.get_height()){
			t1.set_startpoints(t1.get_start_point_x(),t1.get_height());
		}
		arr[0] = t1 ;
		t2.set_type('i');
		arr[1] = t2 ;
		used = 1 ;
		Fit_T_T();
	}
	public int get_used(){
		return used ;
	}

	public double get_area(){
		double total = 0 ;
		for(int i =1 ; i < get_used() ; i++){
			total += arr[i].get_area();
		}
		return total;
	}
	public double get_perimeter(){
		return 0 ;
	}

	public double get_start_point_x(){
		return arr[0].get_start_point_x() ;
	}
	public double get_start_point_y(){
		return arr[0].get_start_point_y() ;
	}

	public void increment(){}
	public void decrement(){}

	public int compareTo(Object o){
		return 0 ;
	}

	public void draw(Graphics g){
		for (int i = 0 ; i < get_used() ; i++){
			arr[i].draw(g);
		}		
	}
	public void paintComponent(Graphics g){
		super.paintComponent(g);
		draw(g);
	}

	public String toString(){
		String str="" ,str2="" ;
		String a = "rectangle";
		String b = "circle";
		String c = "triangle";
		
		if (arr[0] instanceof rectangle){ str = a; }
		if (arr[0] instanceof circle){ str = b; }
		if (arr[0] instanceof triangle){ str = c; }
		if (arr[1] instanceof rectangle){ str2 = a; }
		if (arr[1] instanceof circle){ str2 = b; }
		if (arr[1] instanceof triangle){ str2 = c; }
		
		return String.format("the composedshape container of (%s) and inner of (%s)\nthe container fit (%d) inner shape \nthe area of container = %f\nthe total area of inner shape = %f\n",
								str,str2,used-1,arr[0].get_area(),get_area());
	}

	private void Fit_R_R(){
		rectangle r1 = (rectangle)arr[0];
		rectangle r2 = (rectangle)arr[1];
		

		double len = r1.get_length();
		double wid = r1.get_width();
		double s_len = r2.get_length();
		double s_wid = r2.get_width();
		double x = r1.get_start_point_x();
		double y = r1.get_start_point_y();

		double num_on_x = len/s_len ;
	    double num_on_y = wid/s_wid ;
	    int i=0 , j=0 , q =0, w=0;

	    if(num_on_x <  len/s_wid && num_on_y < wid/s_len){
	    	
	    	num_on_x = len/s_wid ;
	    	for (i=0 ; i <(int)(num_on_x); i++){
	    		if ( arr.length <= get_used() ){
	    			resize_arr();
	    		}
	    		r2 = new rectangle(s_len,s_wid,(i*(s_wid))+x,y,1,'i');		
	    		arr[get_used()] = r2 ;
	    		used++;	    		
		   }
		   
	    }
	    else {

		    for (i=0 ; i <((int)(num_on_x) ); i++){

		    	for(j=0; j < ((int)(num_on_y)) ; j++){
		    		if ( arr.length <= get_used() ){
	    				resize_arr();
	    			}	
	    			r2 = new rectangle(s_len,s_wid,(i*(s_len))+x,(j*(s_wid)+y),1,'i');	
	    			arr[get_used()] = r2 ;
	    			used++;	    
		    	}
		    }
		    len -= i*s_len ;
		    num_on_x = len / s_wid ;
		    num_on_y = wid / s_len ;
		    for (q=0 ; q <((int)(num_on_x) ); q++){
		    	for(w=0; w < ((int)(num_on_y)) ; w++){
		    		if ( arr.length <= get_used() ){
	    				resize_arr();
	    			}	
		    		r2 = new rectangle(s_len,s_wid,((i*s_len)+(q*s_wid))+x,((w)*(s_len))+y,1,'i');		
		    		arr[get_used()] = r2 ;
	    			used++;
		    	}
		    }
		}		
	}

	private void Fit_C_R(){
		rectangle rec = (rectangle)arr[0];
		circle cir = (circle)arr[1];
		double r = cir.get_radius();
		double x = rec.get_start_point_x();
		double y = rec.get_start_point_y();
		double num_on_x = rec.get_length()/(r*2) ;
	   	double num_on_y = rec.get_width()/(r*2) ;
	  	int i , j ; 
	   	for (i=0;i<(int)(num_on_x);i++){
	    	for(j=0;j<(int)(num_on_y);j++){
	    		if ( arr.length <= get_used() ){
	    			resize_arr();
	    		}	
	   			cir = new circle(r,(i*r*2)+x,(j*r*2)+y,'i');
	   			arr[get_used()] = cir ;
		    	used++;
	   		}
	   	}
	}

	private void Fit_T_R(){
		rectangle rec = (rectangle)arr[0];
		triangle tri = (triangle)arr[1];
		double len = rec.get_length();
		double wid = rec.get_width();
		double x = rec.get_start_point_x();
		double y = rec.get_start_point_y();
		double s_len = tri.get_length();
		double higth_of_triangle = tri.get_height() ;
		double num_on_x = len/s_len ;
		double num_on_y = wid/higth_of_triangle ;
		int i=0 , j=0 ,w=0 , temp;

		for (i=0 ;i<(int)(num_on_x); i++ ){
			for(j=0 ; j < (int)(num_on_y) ; j++){
				if((len - ((i*s_len)+s_len/2)) >= s_len){
					w++;
				}
			}
		}
		temp = (i*j)+w;
		w=0;
		for (i=0 ;i<(int)(len/higth_of_triangle); i++ ){
			for(j=0 ; j < (int)(wid/s_len) ; j++){
				if((wid - ((j*s_len)+s_len/2)) >= s_len){
					w++;
				}
			}
		}
		if (temp > (i*j)+w){
			w=0;
			for (i=0 ;i<(int)(num_on_x); i++ ){
				for(j=0 ; j < (int)(num_on_y) ; j++){
					if ( arr.length <= get_used() ){
	    				resize_arr();
	    			}	
	    			tri = new triangle(s_len, (i*s_len)+x ,(j*higth_of_triangle)+y,2,'i');
		    		arr[used]= tri ;
		    		used++;
					
					if((len - ((i*s_len)+s_len/2)) >= s_len){
						if ( arr.length <= get_used() ){
	    					resize_arr();
	    				}	
						w++;
	    				tri = new triangle(s_len, ((i*s_len)+s_len/2)+x ,((j*higth_of_triangle)+higth_of_triangle)+y,1,'i');
		    			arr[used] = tri ;
		    			used++;				
					}
				}
			}
		}
		else{
			w=0;
			for (i=0 ;i<(int)(len/higth_of_triangle); i++ ){
				for(j=0 ; j < (int)(wid/s_len) ; j++){
	    			if ( arr.length <= get_used() ){
	    				resize_arr();
	    			}	
	    			tri = new triangle(s_len, (i*higth_of_triangle )+x,(j*s_len)+y,3,'i');
		    		arr[used]=tri;
		    		used++;
					if((wid - ((j*s_len)+s_len/2)) >= s_len){
						if ( arr.length <= get_used() ){
	    					resize_arr();
	    				}	
						w++;
	    				tri = new triangle(s_len, (i*higth_of_triangle)+higth_of_triangle+x ,((j*s_len)+s_len/2)+y ,4,'i');
		    			arr[used]=tri;
		    			used++;
					}
				}
			}
		}
		
	}

	private void Fit_R_C(){
		rectangle rec = (rectangle)arr[1];
		circle cir = (circle)arr[0];

		double r =cir.get_radius();
		double width = rec.get_length();
		double hight = rec.get_width();
		double x = cir.get_start_point_x();
		double y = cir.get_start_point_y();
		int i , j ,q=0 ;
		if (r < Math.sqrt((width*width+hight*hight)/4)){
			return ;
		}
		if(width < hight){
			double temp = width ;
			width = hight ;
			hight = temp ;
		}
		double startpx = r - cir.eq_cir(hight/2);
		double startpy = r - hight/2 ;
		int num_on_x = (int)((2*r - 2*startpx)/width);
		int num_on_y = (int)((r - hight/2)/hight);
		startpx = (r*2 - (width*num_on_x))/2; 
		for(i=0 ; i<num_on_x ;i++){
			if ( arr.length <= get_used() ){
	    		resize_arr();
	    	}
			rec = new rectangle(width,hight,startpx+x,startpy+y,1,'i');
		    arr[used]=rec;
		    used++;	
			startpx += width;
			q++;
		}
		for(i=1;i<=num_on_y;i++){
			startpy -= hight ;
			startpx =r- cir.eq_cir(r- startpy) ;
			num_on_x =  (int)((2*r - 2*startpx)/width);
			startpx = (r*2 - (width*num_on_x))/2;
			for(j=0 ; j<num_on_x ;j++){
				if ( arr.length <= get_used()+1 ){
	    			resize_arr();
	    		}
				rec = new rectangle(width,hight,startpx+x,y+startpy,1,'i');
		    	arr[used]=rec;
		    	used++;
		    	rec = new rectangle(width,hight,startpx+x,y+startpy+2*i*hight,1,'i');
		    	arr[used]=rec;
		    	used++;			
				startpx += width;
				q += 2;
			} 
		}

	}

	private void Fit_C_C(){
		circle cir = (circle)arr[0];
		circle cir2 = (circle)arr[1];

		double r = cir.get_radius();
		double s_r = cir2.get_radius(); 
		double x = cir.get_start_point_x();
		double y = cir.get_start_point_y();
		
		if(s_r>r){
			return  ;
		}
		else if (2*s_r>r){
			if ( arr.length <= get_used() ){
	    		resize_arr();
	    	}
			cir2 = new circle(s_r,r+x,r+y,'i');		   
		    arr[used] = cir2 ;
		    used++;
		    return;
		}
		else if (r/s_r>2 && r/s_r<=2.4){
			if ( arr.length <= get_used()+3 ){
	    		resize_arr();
	    	}
			cir2 = new circle(s_r, (r- s_r)+x ,y+ r-(s_r)*0.8, 'i');
		    arr[used] = cir2 ;
		    used++;
			cir2 = new circle(s_r, (r+s_r)+x ,y+ r- (s_r)*0.8 , 'i');
		    arr[used] = cir2 ;
		    used++;
			cir2 = new circle(s_r, r+x , y+r+s_r , 'i');
		    arr[used] = cir2 ;
		    used++;			
			return ; 

		}
		else if(r/s_r>2.4 && r/s_r<3){
			if ( arr.length <= get_used()+4 ){
	    		resize_arr();
	    	}
			cir2 = new circle(s_r, x+(r- s_r),y+r- (s_r), 'i');
		    arr[used] = cir2 ;
		    used++;
			cir2 = new circle(s_r,x+ (r+s_r),y+ r- (s_r), 'i');
		    arr[used] = cir2 ;
		    used++;
			cir2 = new circle(s_r,x+ (r-s_r),y+ r+(s_r), 'i');
		    arr[used] = cir2 ;
		    used++;
		    cir2 = new circle(s_r,x+ (r+s_r),y+ r+(s_r), 'i');
		    arr[used] = cir2 ;
		    used++;
			return;
		}
		int i ,q=0;
		int num_on_x = (int)(r/s_r);
		double temp = s_r*Math.sqrt(3);
		double startpx = r-(s_r*(num_on_x-1)) ;
		double startpy = r ;
		for ( i = 0; i < num_on_x; ++i){
			if ( arr.length <= get_used()+4 ){
	    		resize_arr();
	    	}
			cir2 = new circle(s_r, startpx+x-s_r,y+ startpy-s_r, 'i');
		    arr[used] = cir2 ;
		    used++;
			startpx += 2*s_r ;
		}
		startpy -= temp;
		while(startpy - s_r>=0){
			q++;
			num_on_x--;
			startpx = r-(s_r*(num_on_x-1));
			for (i=1; i <= num_on_x+2 ; i++){
				if (startpy-s_r >= r - cir.eq_cir(r-startpx+(2*s_r)) &&
					startpx-(2*s_r)-s_r >= r - cir.eq_cir(r-startpy) &&
					startpx-(2*s_r)+s_r <= r+ cir.eq_cir(r-startpy) ){
					if ( arr.length <= get_used()+1 ){
	    				resize_arr();
	    			}
					cir2 = new circle(s_r, startpx-(2*s_r)+x-s_r,y+ startpy-s_r, 'i');
		    		arr[used] = cir2 ;
		  			used++;
					cir2 = new circle(s_r, startpx-(2*s_r)+x-s_r,y+ startpy+(2*q*temp)-s_r, 'i');
		    		arr[used] = cir2 ;
		  			used++;
				}
				startpx += 2*s_r ;
			}
			startpy -= temp;

		}

	}
	private void Fit_T_C(){
		circle cir = (circle)arr[0];
		triangle tri = (triangle)arr[1];

		int i , j ;
		int num_on_x , num_on_y ;
		double hight_of_triangle = tri.get_height() ;
		double length = tri.get_length();
		double radius = cir.get_radius();
		double x = cir.get_start_point_x();
		double y = cir.get_start_point_y();
		double startpx ,startpy=0 ,temp = radius;
		if (radius < hight_of_triangle*2/3){
			return ;
		}
		if (radius >= hight_of_triangle*2/3 && radius < hight_of_triangle){
			startpx = radius - cir.eq_cir(radius- hight_of_triangle);
			startpx = (2*radius - 2*startpx -length)/2 +startpx ; 
				if ( arr.length <= get_used() ){
	    			resize_arr();
	    		}
				tri = new triangle(length,startpx+x ,startpy+hight_of_triangle+y,1,'i');
		    	arr[used]=tri;
		    	used++;			
			return ;
		}
		num_on_y = (int)(radius/hight_of_triangle);
		num_on_x = (int)(2*temp/length);
		startpx = radius - (length*num_on_x)/2;
		for(i=0;i<num_on_y;i++){
			for(j=0;j<num_on_x;j++ ){
				if (radius - cir.eq_cir(radius - temp ) <= startpx+(j*length) &&
					radius + cir.eq_cir(radius - temp ) >= startpx+(j*length)+length &&
					radius - cir.eq_cir(radius - (startpx+(j*length)+length/2)) <= temp- hight_of_triangle) {
					if ( arr.length <= get_used()+1 ){
	    				resize_arr();
	    			}
					tri = new triangle(length,startpx+(j*length)+x ,temp+y,1,'i');
		    		arr[used]=tri;
		    		used++;	
		    		tri = new triangle(length,startpx+(j*length)+x ,temp+(2*i*hight_of_triangle)+y,2,'i');
		    		arr[used]=tri;
		    		used++;					
				}

				if(radius - cir.eq_cir(radius - (temp -hight_of_triangle)) <= (startpx +(j*length)+length/2) &&
				   radius + cir.eq_cir(radius - (temp -hight_of_triangle)) >= (startpx +(j*length)+length*3/2)){
					if ( arr.length <= get_used()+1 ){
	    				resize_arr();
	    			}
					tri = new triangle(length,x+startpx+(j*length)+length/2,y+temp- hight_of_triangle,2,'i');
		    		arr[used]=tri;
		    		used++;		
		    		tri = new triangle(length,x+startpx+(j*length)+(length/2)
		    									,y+temp+(2*(i)*hight_of_triangle)+hight_of_triangle,1,'i');
		    		arr[used]=tri;
		    		used++;		
				}
			}
			temp -= hight_of_triangle ;
		}
	}
	private void Fit_R_T(){
		triangle tri =  (triangle)arr[0];
		rectangle rec =  (rectangle)arr[1]; 


		int i , j , count=0 ;
		double hight_of_triangle = tri.get_height();
		double length = tri.get_length();
		double width =rec.get_length();
		double hight = rec.get_width();
		double x = tri.get_start_point_x();
		double y = tri.get_start_point_y()-tri.get_height();
		double startpx ,startpy ,temp = length;
		int num_on_x ,num_on_y;

		num_on_y = (int)(hight_of_triangle/hight);
		for(i=0 ;i<num_on_y;i++){
			temp = temp -2*hight/Math.sqrt(3);
			num_on_x = (int)(temp/width);
			startpx = hight/Math.sqrt(3)*(i+1);
			startpy = hight_of_triangle - hight*(i+1) ;

			for(j=0;j<num_on_x;j++){
	    		if ( arr.length <= get_used() ){
	    			resize_arr();
	    		}
	    		rec = new rectangle(width,hight,startpx+x ,startpy+y,1,'i');
		    	arr[used]=rec;
		    	used++;
				startpx += width ;
				count++;	
			}
			startpx += width ;
		}
	}
	private void Fit_C_T(){
		triangle tri =  (triangle)arr[0];
		circle cir =  (circle)arr[1]; 


		int i , j ;
		double hight_of_triangle = tri.get_height() ;
		double length = tri.get_length();
		double r =cir.get_radius();
		double x = tri.get_start_point_x();
		double y = tri.get_start_point_y()-tri.get_height();
		double startpx ,startpy ;
		int num_on_x ,num_on_y;

	
		if (r > hight_of_triangle/3){
			return ;
		}
		if (r == hight_of_triangle/3){
			if ( arr.length <= get_used() ){
	    		resize_arr();
	    	}
			cir = new circle(r,(length/2)+x-r,(3*hight_of_triangle/2)+y-r,'i');
		    arr[used]=cir;
		    used++;
			return ;
		}
		startpx= 3*r/Math.sqrt(3) ;
		startpy = hight_of_triangle - r ;
		num_on_x =	(int)((length-(6*r/Math.sqrt(3)))/(2*r))+1;
		num_on_y = num_on_x;
		for(j=0;j<num_on_y;j++){
			for(i=0;i<num_on_x ; i++){
				if ( arr.length <= get_used() ){
	    			resize_arr();
	    		}
				cir = new circle(r,x+startpx+(i*2*r)-r,y+startpy-r,'i');
		   		arr[used]=cir;
		  		used++;
			}
			startpy -= r*Math.sqrt(3);
			startpx += r ;
			num_on_x--;  
		}
	}
	private void Fit_T_T(){
		triangle tri =  (triangle)arr[0];
		triangle tri2 =  (triangle)arr[1];



		int i , j ;
		double hight_of_triangle = tri.get_height() ;
		double len = tri.get_length();
		double hight_of_s_triangle = tri2.get_height() ;
		double s_len = tri2.get_length();
		double x = tri.get_start_point_x();
		double y = tri.get_start_point_y()-tri.get_height();
		
		double startpx ,startpy ;
		int num_on_x , temp = (int)len;
		int num_on_y = (int)(hight_of_triangle/hight_of_s_triangle);
		startpy = hight_of_triangle ;
		for(i=1 ; i<= num_on_y ; i++){
			num_on_x = (int)(temp/s_len);
			startpx = (len- (s_len*num_on_x))/2;
			for(j=1;j<=num_on_x;j++){
				if ( arr.length <= get_used() ){
	    			resize_arr();
	    		}
				tri2 = new triangle(s_len, startpx+x ,startpy+y ,1,'i');
		    	arr[used]= tri2;
		    	used++;
				startpx += s_len ;
				if (j < num_on_x){
					if ( arr.length <= get_used() ){
	    				resize_arr();
	    			}
					tri2 = new triangle(s_len, startpx-(s_len/2)+x ,startpy-hight_of_s_triangle+y ,2,'i');
		    		arr[used]=tri2;
		    		used++;
				}
			}
			startpy -= hight_of_s_triangle;		
			temp = (int)(temp*(hight_of_triangle - hight_of_s_triangle)/hight_of_triangle) ;
			hight_of_triangle -= hight_of_s_triangle ;
		}
	}

	private void resize_arr(){
		SHAPE[] temp = new SHAPE[get_used()];
		for(int i = 0 ; i < get_used() ; i++){
			temp[i] = arr[i];
		}
		arr = new SHAPE[get_used()+25];
		for (int i =0 ; i < get_used() ; i++){
			arr[i] = temp[i] ;
		}
	}

	private SHAPE[] arr ;
	private int used ;
}