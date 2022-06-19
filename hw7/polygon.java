import java.awt.Graphics;
import javax.swing.JPanel;

public abstract class polygon  extends JPanel implements SHAPE {
	

	public abstract void add(point2D p);
	public abstract int get_point_number();
	public abstract double get_area();
	public abstract double get_perimeter();

	public abstract double get_start_point_x();
	public abstract double get_start_point_y();

	public abstract void increment();
	public abstract void decrement();

	public abstract int compareTo(Object o);

	public void paintComponent(Graphics g){
		super.paintComponent(g);
		draw(g);
	}

	public abstract void draw(Graphics g);
	
	public static class point2D {
		public point2D(){
			this(0,0);
		}
		public point2D(double a, double b){
			set_points(a,b);
		}

		public double get_x(){return x ;}
		public double get_y(){return y ;}
		public void set_points(double a , double b){
			x = a ; 
			y = b ;
			check();
		}
		public String toString(){
			return String.format("x = %f\ny = %f \n________\n",x,y);
		}
		private void check(){
			if (x < 0){
				x *= -1 ;
			}
			if (y < 0){
				y *= -1 ;
			}
		}
		private double x , y ;
	}
}