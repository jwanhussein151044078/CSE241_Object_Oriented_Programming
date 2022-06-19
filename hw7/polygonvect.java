import java.awt.Graphics;
import javax.swing.JPanel;
import java.util.ArrayList;
import java.awt.Color;

public class polygonvect extends polygon {

	public polygonvect(){
		arr = new ArrayList<point2D>();
	}

	public polygonvect(SHAPE ob){
		arr = new ArrayList<point2D>();
	
	}

	public void add(point2D p){
		arr.add(p);
	}	

	public int get_point_number(){
		return arr.size() ;
	}
	public double get_area(){
		return 0 ;
	}
	public double get_perimeter(){
		return 0 ;
	}
	public double get_start_point_x(){
		return arr.get(0).get_x() ;
	}
	public double get_start_point_y(){
		return arr.get(0).get_y() ;
	}

	public void increment(){}
	public void decrement(){}

	public int compareTo(Object o){
		polygonvect t = (polygonvect)o;
		if(arr.size() > t.get_point_number()){
			return 1 ;
		}
		else if (arr.size() < t.get_point_number()){
			return -1 ;
		}
		return 0 ;
	}

	public String toString(){
		return String.format("the polygonvect has (%d) points \n",get_point_number()); 
	}


	public void draw(Graphics g){
		int[] x = new int[get_point_number()] ;
		int[] y = new int[get_point_number()] ;

		for (int i = 0 ; i < get_point_number() ; i++){
			x[i] = (int)arr.get(i).get_x();
			y[i] = (int)arr.get(i).get_y();
		}
		g.setColor(Color.black);
		g.drawPolygon(x,y,get_point_number());
		
	}

	


	private ArrayList<point2D> arr ;
}