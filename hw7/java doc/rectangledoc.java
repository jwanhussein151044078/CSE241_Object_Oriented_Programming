import java.awt.Graphics;
import java.awt.Graphics2D ;
import javax.swing.JPanel;
import java.awt.Color;
import javafx.scene.shape.Shape;
import java.awt.BasicStroke;

/**
* class rectangle
* @author jwan hussein
*/
public class rectangle extends JPanel implements SHAPE {
	/**
	* no param constructor 
	*/
	public rectangle();
	/**
	* two param constructor 
	* @param l the length of rectangle 
	* @param w the width of rectangle 
	*/
	public rectangle(double l , double w);
	/**
	* four param constructor 
	* @param l the length of rectangle 
	* @param w the width of rectangle 
	* @param x the start point of rectangle on x-axis 
	* @param y the start point of rectangle on y-axis
	*/
	public rectangle(double l , double w , double x , double y);
	/**
	* six param constructor 
	* @param l the length of rectangle 
	* @param w the width of rectangle 
	* @param x the start point of rectangle on x-axis 
	* @param y the start point of rectangle on y-axis
	* @param d the direction of the rectangle to be drawn 
	* @param t the type of rectangle (container or ineer)
	*/
	public rectangle(double l , double w , double x , double y , int d , char t);
	/**
	* @return  length of rectangle  
	*/
	public double get_length();
	/**
	* @return  width of rectangle  
	*/
	public double get_width();
	/**
	* @return  area of rectangle  
	*/
	public double get_area();
	/**
	* @return  perimeter of rectangle  
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
	* @return  direction of rectangle  
	*/
	public int get_direction();
	/**
	* @return  type of rectangle  
	*/
	public char get_type();

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
	* @param d the direction of the shape 
	*/
	public void set_direction(int d);

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
	* to string method convert the object to a string
	*/
	public String toString();
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
	* method to check data  
	*/
	private void check_erorrs();

	private double length ;
	private double width ;
	private double area ;
	private double perimeter ;
	private double start_point_x ;
	private double start_point_y ;
	private int direction ;
	private char type ;


}