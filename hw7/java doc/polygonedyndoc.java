import java.awt.Graphics;
import javax.swing.JPanel;
import java.util.ArrayList;
import java.awt.Color;
/**
*  class polygondyn
* @author jwan hussein
*/
public class polygondyn extends polygon {
	/**
	* no param constructor 
	*/
	public polygondyn();
	/**
	* add element to the polygon
	* @param p the point to be added
	*/
	public void add(point2D p);
	/**
	* @return the number of points in the polygone
	*/
	public int get_point_number();
	/**
	* @return 0 since the polygon can be any shape 
	*/
	public double get_area();
	/**
	* @return 0 since the polygon can be any shape
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
	* @return the number of element in the array  
	*/
	public int get_used();
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
	* resizeing the array to fit more element
	*/
	private void resize_arr();

	private point2D[] arr ;
	private int used ;
}