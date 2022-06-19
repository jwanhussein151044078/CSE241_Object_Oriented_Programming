import java.awt.Graphics;
import javax.swing.JPanel;
import java.awt.Color;
import java.lang.StrictMath;
import java.awt.Graphics2D ;
import java.awt.BasicStroke;
/**
* class circle
* @author jwan hussein
*/
public class triangle extends JPanel implements SHAPE {
	/**
	* no param constructor 
	*/
	public triangle();
	/**
	* one param constructor 
	* @param r the length of triangle 
	*/
	public triangle(double l);
	/**
	* three param constructor 
	* @param r the length of triangle 
	* @param x the start point of triangle on x-axis 
	* @param y the start point of triangle on y-axis
	*/
	public triangle(double l , double x ,double y);
	/**
	* five param constructor 
	* @param r the length of triangle 
	* @param x the start point of triangle on x-axis 
	* @param y the start point of triangle on y-axis
	* @param d the direction of the triangle to be drawn 
	* @param t the type of triangle (container or ineer)
	*/
	public triangle(double l , double x ,double y , int d , char t);
	/**
	* @return  length of triangle  
	*/
	public double get_length();
	/**
	* @return  height of triangle  
	*/
	public double get_height();
	/**
	* @return  area of triangle  
	*/
	public double get_area();
	/**
	* @return  perimeter of triangle  
	*/
	public double get_perimeter();
	/**
	* the strt point of the shape on X-axis
	* @return start point on x-axis   
	*/
	public double get_start_point_x();
	/**
	* the strt point of the shape on y-axis
	* @return start point on y-axis   
	*/
	public double get_start_point_y();
	/**
	* @return  direction of triangle  
	*/
	public int get_direction();
	/**
	* @return  type of triangle  
	*/
	public char get_type();
	/**
	* @param x the strt point of the shape on x-axis
	* @param y the strt point of the shape on y-axis   
	*/
	public void set_startpoints(double x , double y);
	/**
	* @param d the direction of the shape 
	*/
	public void set_direction(int d);
	/**
	* @param t the type of the shape 
	*/
	public void set_type(char t);
	/**
	* increase the start points by 1    
	*/
	public void increment();
	/**
	* decrease the start points by 1    
	*/
	public void decrement();
	/**
	* compair to object according to their area 
	* @param o the object to compair with 
	* @return <code>1</code> in case true <code>-1</code> in case of false <code>0</code> in case of equivalent     
	*/
	public int compareTo(Object o);
	/**
	* draw the shape to the panel 
	* @param g grafic object      
	*/
	public void draw(Graphics g);
	/**
	* draw the shape to the panel 
	* @param g grafic object      
	*/
	public void paintComponent(Graphics g);
	/**
	* to string method convert the object to a string
	*/
	public String toString();
	/**
	* method to check data  
	*/
	private void check_erorrs();
	private double length ;
	private double height ;
	private double area ;
	private double perimeter ;
	private double start_point_x ;
	private double start_point_y ;
	private int direction ;
	private char type ;
}
