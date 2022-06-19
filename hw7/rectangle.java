import java.awt.Graphics;
import java.awt.Graphics2D ;
import javax.swing.JPanel;
import java.awt.Color;
import java.awt.BasicStroke;


public class rectangle extends JPanel implements SHAPE {
	public rectangle(){
		this(0,0,0,0,1,'i');
	}

	public rectangle(double l , double w){
		this(l,w,0,0,1,'i');
	}

	public rectangle(double l , double w , double x , double y){
		this(l,w,x,y,1,'i');

	}
	public rectangle(double l , double w , double x , double y , int d , char t){
		length = l ;
		width = w ;
		start_point_x = x ;
		start_point_y = y ;
		direction = d ;
		type = t ;
		check_erorrs();
		area = length*width ;
		perimeter = length*2 + width*2 ;

	}




	public double get_length(){
		return length ;
	}
	public double get_width(){
		return width ;
	}

	public double get_area(){
		return area ;
	}
	public double get_perimeter(){
		return perimeter ;
	}

	public double get_start_point_x(){
		return start_point_x ;
	}
	public double get_start_point_y(){
		return start_point_y ;
	}

	public int get_direction(){
		return direction ;
	}
	public char get_type(){
		return type ;
	}


	public void set_startpoints(double x , double y){
		start_point_x = x ;
		start_point_y = y ;
		check_erorrs();

	}

	public void set_type(char t){
		type = t ;
		check_erorrs();
	}

	public void set_direction(int d){
		direction = d ;
		check_erorrs();
	}


	public void increment(){
		start_point_x++;
		start_point_y++;
	}
	public void decrement(){
		start_point_x--;
		start_point_y--;	
	}

	public int compareTo(Object o){
		SHAPE ob = (SHAPE) o ; 
		if (ob.get_area() > get_area()){
			return -1 ;
		}
		if (ob.get_area() < get_area()){
			return 1 ;
		}
		return 0;
	}

	public String toString(){
		return String.format("rectangle::\nlength = %.2f\nwidth = %.2f\nx = %.2f\ny = %.2f\ndirection = %d\ntype = %c\narea = %f\nperimeter = %f\n_____________\n",
								length,width,start_point_x,start_point_y,direction,type,area,perimeter);
	}

	public void draw(Graphics g){
		Graphics2D g2 = (Graphics2D) g;
		int len = (int)get_length();
		int wid = (int)get_width();
		int x = (int)get_start_point_x();
		int y = (int)get_start_point_y();
		
		if (direction == 2){
			int temp = len ;
			len = wid ; 
			wid = temp ; 
		}

		g2.setColor(Color.black);
		g2.setStroke(new BasicStroke(2));
		g2.drawRect(x,y,len,wid);
		
		if (get_type()== 'c'){
			g2.setColor(Color.green);	
		}
		else{
			g2.setColor(Color.red);
		}
		
		g2.fillRect(x,y,len,wid);
		

	}

	public void paintComponent(Graphics g){
		super.paintComponent(g);
		draw(g);
	}



	private void check_erorrs(){
		if (length < 0){
			length *= -1 ;
		}
		if (width < 0){
			width *= -1 ;
		}
		if (start_point_x < 0){
			start_point_x *= -1 ; 
		}
		if (start_point_y < 0){
			start_point_y *= -1 ; 
		}
		if (direction != 1 && direction != 2 ){
			direction = 1 ;
		}
		if (type != 'c' && type != 'i'){
			type = 'i' ;
		}
	}


	private double length ;
	private double width ;
	private double area ;
	private double perimeter ;
	private double start_point_x ;
	private double start_point_y ;
	private int direction ;
	private char type ;


}
