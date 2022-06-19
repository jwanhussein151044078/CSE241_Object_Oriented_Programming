import java.awt.Graphics;
import javax.swing.JPanel;
import java.util.ArrayList;
import java.awt.Color;

public class polygondyn extends polygon {

	public polygondyn(){
		arr = new point2D[25];
		used = 0 ;
	}

	public void add(point2D p){
		if (arr.length <= used ){
			resize_arr();
		}
		arr[used] = p;
		used++;
	}	

	public int get_point_number(){
		return used ;
	}
	public double get_area(){
		return 0 ;
	}
	public double get_perimeter(){
		return 0 ;
	}
	public double get_start_point_x(){
		return arr[0].get_x() ;
	}
	public double get_start_point_y(){
		return arr[0].get_y() ;
	}
	public int get_used(){
		return used ;
	}

	public void increment(){}
	public void decrement(){}

	public int compareTo(Object o){
		polygondyn t = (polygondyn)o;
		if(get_point_number() > t.get_point_number()){
			return 1 ;
		}
		else if (get_point_number() < t.get_point_number()){
			return -1 ;
		}
		return 0 ;
	}

	public String toString(){
		return String.format("the polygondyn has (%d) points \n",get_point_number()); 
	}


	public void draw(Graphics g){
		int[] x = new int[get_point_number()] ;
		int[] y = new int[get_point_number()] ;

		for (int i = 0 ; i < get_point_number() ; i++){
			x[i] = (int)arr[i].get_x();
			y[i] = (int)arr[i].get_y();
		}
		g.setColor(Color.black);
		g.drawPolygon(x,y,get_point_number());
		
	}

	
	private void resize_arr(){
		point2D[] temp = new point2D[get_used()];
		for(int i = 0 ; i < get_used() ; i++){
			temp[i] = arr[i];
		}
		arr = new point2D[get_used()+25];
		for (int i =0 ; i < get_used() ; i++){
			arr[i] = temp[i] ;
		}
	}

	private point2D[] arr ;
	private int used ;
}