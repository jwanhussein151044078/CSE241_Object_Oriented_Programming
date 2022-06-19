import java.awt.Graphics;
import javax.swing.JPanel;
/**
* abstract class polygon
* @author jwan hussein
*/
public abstract class polygon  extends JPanel implements SHAPE {
	
	/**
	* add element to the polygon
	* @param p the point to be added
	*/
	public abstract void add(point2D p);
	/**
	* @return the number of points in the polygone
	*/
	public abstract int get_point_number();
	/**
	* @return 0 since the polygon can be any shape 
	*/
	public abstract double get_area();
	/**
	* @return 0 since the polygon can be any shape
	*/
	public abstract double get_perimeter();
	/**
	* the strt point of the shape on X-axis
	* @return start point on x-axis   
	*/
	public abstract double get_start_point_x();
	/**
	* the strt point of the shape on y-axis
	* @return start point on y-axis   
	*/
	public abstract double get_start_point_y();
	/**
	* increase the start points by 1    
	*/
	public abstract void increment();
	/**
	* decrease the start points by 1    
	*/
	public abstract void decrement();
	/**
	* compair to object according to their area 
	* @param o the object to compair with 
	* @return <code>1</code> in case true <code>-1</code> in case of false <code>0</code> in case of equivalent     
	*/
	public abstract int compareTo(Object o);
	/**
	* draw the shape to the panel 
	* @param g grafic object      
	*/
	public void paintComponent(Graphics g);
	/**
	* draw the shape to the panel 
	* @param g grafic object      
	*/
	public abstract void draw(Graphics g);
	/**
	* inner class point2D
	*/
	public static class point2D {
		/**
		* no param constructor 
		*/
		public point2D();
		/**
		* two param constructor 
		* @param a the position of point on x-axix 
		* @param b the position of point on y-axix
		*/
		public point2D(double a, double b);
		/**
		* @return the position of point on x-axix 
		*/
		public double get_x(){return x ;}
		/**
		* @return the position of point on y-axix 
		*/
		public double get_y(){return y ;}
		/**
		* @param a the strt point of the point on x-axis
		* @param b the strt point of the point on y-axis   
		*/
		public void set_points(double a , double b);
		/**
		* to string method convert the object to a string
		*/
		public String toString();
		/**
		* method to check data  
		*/
		private void check();
		private double x , y ;
	}
}