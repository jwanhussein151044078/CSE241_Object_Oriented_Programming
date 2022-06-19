import java.awt.Graphics;
import javax.swing.JPanel;
import java.awt.Color;
import java.lang.StrictMath;

/**
*  class composedshape
* @author jwan hussein
*/
public class composedshape extends JPanel implements SHAPE {
	/**
	* two param constructor 
	* @param r1 rectangle shape 
	* @param r2 rectangle shape
	*/
	public composedshape(rectangle r1 , rectangle r2);
	/**
	* two param constructor 
	* @param r rectangle shape 
	* @param c circle shape 
	*/
	public composedshape(rectangle r , circle c);
	/**
	* two param constructor 
	* @param r rectangle shape 
	* @param t triangle shape 
	*/
	public composedshape(rectangle r , triangle t);
	/**
	* two param constructor 
	* @param c circle shape
	* @param  r rectangle shape 
	*/
	public composedshape(circle c , rectangle r);
	/**
	* two param constructor 
	* @param c1 circle shape 
	* @param c2 circle shape
	*/
	public composedshape(circle c1 , circle c2);
	/**
	* two param constructor 
	* @param c circle shape
	* @param t triangle shape
	*/
	public composedshape(circle c , triangle t);
	/**
	* two param constructor 
	* @param t triangle shape
	* @param r rectangle shape 
	*/
	public composedshape(triangle t , rectangle r);
	/**
	* two param constructor 
	* @param t triangle shape
	* @param c circle shape
	*/
	public composedshape(triangle t , circle c);
	/**
	* two param constructor 
	* @param t1 triangle shape
	* @param t2 triangle shape
	*/
	public composedshape(triangle t1 , triangle t2);
	/**
	* @return the number of element in the array  
	*/
	public int get_used();
	/**
	* @return the total area of inner shape
	*/
	public double get_area();
	/**
	* @return the total perimeter of inner shape
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
	*	do nothing
	*/
	public void increment();
	/**
	*	do nothing
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
}