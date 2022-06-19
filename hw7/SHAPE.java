import java.awt.Graphics;
import javax.swing.JFrame;



public interface SHAPE  extends Comparable {
	

	public double get_area();
	public double get_perimeter();

	public double get_start_point_x();
	public double get_start_point_y();

	public void increment();
	public void decrement();

	public int compareTo(Object o);

	public void draw(Graphics g);

	
}