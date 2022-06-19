import java.awt.Graphics;
import javax.swing.JPanel;
import java.awt.Color;
import java.lang.StrictMath;
import java.awt.Graphics2D ;
import java.awt.BasicStroke;

public class triangle extends JPanel implements SHAPE {

	public triangle(){
		this(0,0,0,2,'i');
	}
	public triangle(double l){
		this(l,0,0,2,'i');
	}
	public triangle(double l , double x ,double y){
		this(l,x,y,2,'i');
	}
	public triangle(double l , double x ,double y , int d , char t){
		length = l ;
		start_point_x = x ;
		start_point_y = y ;
		direction = d ;
		type = t ;
		check_erorrs();
		height = length*Math.sqrt(3)/2 ;
		area = (Math.pow(length,2)*Math.sqrt(3))/4;
		perimeter = length*3;
	}	

	public double get_length(){
		return length ;
	}

	public double get_height(){
		return height ;
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

	public void set_direction(int d){
		direction = d ;
		check_erorrs();
	}

	public void set_type(char t){
		type = t ;
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
	public void draw(Graphics g){
		int len = (int)get_length();
		int x = (int)get_start_point_x();
		int y = (int)get_start_point_y();
		int[] sx = new int[3];
		int[] sy = new int[3];
		Graphics2D g2 = (Graphics2D) g;
		if (get_direction() == 1){
			sx[0] =(int)x ; 			    	sy[0] = (int)y ;
			sx[1] =(int)(x+get_length());		sy[1] = (int)y ;
			sx[2] =(int)(x+(get_length()/2));   sy[2] = (int)(y - get_height());
		}
		if (get_direction() == 2){
			sx[0] =(int)x ; 			    	sy[0] = (int)y ;
			sx[1] =(int)(x+get_length());		sy[1] = (int)y ;
			sx[2] =(int)(x+(get_length()/2));   sy[2] = (int)(y + get_height());
		}
		if (get_direction() == 3){
			sx[0] =(int)x ; 			    	sy[0] = (int)y ;
			sx[1] =(int)x ;						sy[1] = (int)(y+get_length()) ;
			sx[2] =(int)(x+(get_height())) ;    sy[2] = (int)(y+(get_length()/2));
		}
		if (get_direction() == 4){
			sx[0] =(int)x ; 			    	sy[0] = (int)y ;
			sx[1] =(int)x ;						sy[1] = (int)(y+get_length()) ;
			sx[2] =(int)(x-(get_height())) ;    sy[2] = (int)(y+(get_length()/2));
		}

		g2.setStroke(new BasicStroke(2));
		g2.setColor(Color.black);
		g2.drawPolygon(sx,sy,3);
		
		if (get_type()== 'c'){
			g2.setColor(Color.green);	
		}
		else{
			g2.setColor(Color.red);
		}
		
		g2.fillPolygon(sx,sy,3);
	}

	public void paintComponent(Graphics g){
		super.paintComponent(g);
		draw(g);
	}

	public String toString(){
		return String.format("triangle::\nlength = %f \nheigth = %f \narea = %f \nperimeter = %f \nstart_point_x = %f \nstart_point_y = %f \ntype = %c \ndirection = %d \n_________________________\n"
								,length,height,area,perimeter,start_point_x,start_point_y,type,direction); 
	}


	private void check_erorrs(){
		if (length < 0){
			length *= -1 ;
		}
		if (start_point_x < 0){
			start_point_x *= -1 ; 
		}
		if (start_point_y < 0){
			start_point_y *= -1 ; 
		}
		if (direction != 1 && direction != 2 && direction != 3 && direction != 4 ){
			direction = 2 ;
		}
		if (type != 'c' && type != 'i'){
			type = 'i' ;
		}
	}




	private double length ;
	private double height ;
	private double area ;
	private double perimeter ;
	private double start_point_x ;
	private double start_point_y ;
	private int direction ;
	private char type ;
}
