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
public class circle extends JPanel implements SHAPE {
	/**
	* no param constructor 
	*/
	public circle();
	/**
	* one param constructor 
	* @param r the radius of circle 
	*/
	public circle(double r);
	/**
	* three param constructor 
	* @param r the radius of circle 
	* @param x the start point of circle on x-axis 
	* @param y the start point of circle on y-axis
	*/
	public circle(double r,double x,double y);
	/**
	* four param constructor 
	* @param r the radius of circle 
	* @param x the start point of circle on x-axis 
	* @param y the start point of circle on y-axis
	* @param t the type of circle (container or ineer)
	*/
	public circle(double r,double x,double y,char t);
	/**
	* @param the first point on the circle 
	* @return the equation of circle 
	*/
	public double eq_cir(double x);
	/**
	* @return  area of circle  
	*/
	public double get_area();
	/**
	* @return  perimeter of circle  
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
	* @return  type of circle  
	*/
	public char get_type();
	/**
	* @return  the radius of circle  
	*/
	public double get_radius();
	/**
	* @param x the strt point of the shape on x-axis
	* @param y the strt point of the shape on y-axis   
	*/
	public void set_startpoints(double x , double y);
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
	* draw the shape to the panel 
	* @param g grafic object      
	*/
	public String toString();

	/**
	* method to check data  
	*/
	private void check_erorrs();

	private double radius ;
	private double area ;
	private double perimeter ;
	private double start_point_x ;
	private double start_point_y ;
	private char type ;

}