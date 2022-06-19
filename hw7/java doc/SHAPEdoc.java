import java.awt.Graphics;
import javax.swing.JFrame;


/**
* interface shape  
* @author jwan hussein 
*/
public interface SHAPE  extends Comparable {
	
	/**
	* caculate area
	* @return the area of the shape   
	*/
	public double get_area();
	/**
	* caculate perimeter
	* @return the perimeter of the shape   
	*/
	public double get_perimeter();
	/**
	* the strt point of the shape on X-axis
	* @return start point on x-axis   
	*/
	public double get_start_point_x();
	/**
	* the strt point of the shape on Y-axis
	* @return start point on y-axis   
	*/
	public double get_start_point_y();
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

	
}