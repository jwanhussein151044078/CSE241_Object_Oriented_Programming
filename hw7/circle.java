import java.awt.Graphics;
import javax.swing.JPanel;
import java.awt.Color;
import java.lang.StrictMath;
import java.awt.Graphics2D ;
import java.awt.BasicStroke;

public class circle extends JPanel implements SHAPE {

	public circle(){
		this(0,0,0,'i');
	}
	public circle(double r){
		this(r,0,0,'i');
	}
	public circle(double r,double x,double y){
		this(r,x,y,'i');
	}
	public circle(double r,double x,double y,char t){
		radius = r ;
		start_point_x = x ;
		start_point_y = y ;
		type = t ; 
		check_erorrs();
		area = (Math.PI*Math.pow(radius,2)) ;
		perimeter = 2*Math.PI*radius;
	}
	


	public double eq_cir(double x){
		return Math.sqrt(Math.pow(radius,2)-Math.pow(x,2));
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

	public char get_type(){
		return type ;
	}

	public double get_radius(){
		return radius ;
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
		int r = (int)get_radius();
		int x = (int)get_start_point_x();
		int y = (int)get_start_point_y();
		
		Graphics2D g2 = (Graphics2D) g;
		g2.setColor(Color.black);
		g2.setStroke(new BasicStroke(2));
		g2.drawOval(x,y,r*2,r*2);
		
		if (get_type()== 'c'){
			g2.setColor(Color.green);	
		}
		else{
			g2.setColor(Color.red);
		}
		
		g2.fillOval(x,y,r*2,r*2);
		
	}
	public void paintComponent(Graphics g){
		super.paintComponent(g);
		draw(g);
	}

	public String toString(){
		return String.format("circle::\nradius = %.2f\nx = %.2f\ny = %.2f\ntype = %c\narea = %f\nperimeter = %f\n_____________\n",
								radius,start_point_x,start_point_y,type,area,perimeter);
	}



	private void check_erorrs(){
		
		if (radius < 0){
			radius *= -1 ;
		}
		if (start_point_x < 0){
			start_point_x *= -1 ; 
		}
		if (start_point_y < 0){
			start_point_y *= -1 ; 
		}
		if (type != 'c' && type != 'i'){
			type = 'i' ;
		}
	}

	private double radius ;
	private double area ;
	private double perimeter ;
	private double start_point_x ;
	private double start_point_y ;
	private char type ;

}