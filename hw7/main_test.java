import javax.swing.JFrame;
import java.awt.Graphics;

public class main_test{
	public static void main (String[] args){
		
		rectangle r = new rectangle(200,130,20,25,1,'i');
		rectangle r1 = new rectangle(30,25,25,23,1,'c');
	
		circle c = new circle(100,0,200); 
		circle c2 = new circle(30); 
		
		triangle t = new triangle(250,0,300,3,'i');
		triangle t2 = new triangle(45,50,300,3,'i');
		
		polygon.point2D p1 = new  polygon.point2D(100,100);
		polygon.point2D p2 = new  polygon.point2D(100,50);
		polygon.point2D p3 = new  polygon.point2D(50,100);
		polygon.point2D p4 = new  polygon.point2D(250,100);
		polygon.point2D p5 = new  polygon.point2D(350,100);
		polygon.point2D p6 = new  polygon.point2D(150,400);
		polygon.point2D p7 = new  polygon.point2D(120,450);
		polygon.point2D p8 = new  polygon.point2D(190,140);

		polygonvect v = new polygonvect();
		v.add(p6);
		v.add(p2);
		v.add(p3);
		v.add(p5);
		v.add(p8);
		polygondyn d = new polygondyn();
		d.add(p1);
		d.add(p2);
		d.add(p3);
		d.add(p4);
		d.add(p8);
		d.add(p7);
		d.add(p5);
		composedshape com = new composedshape(t,t2);
		System.out.printf("%s\n",t);
		/*
		JFrame m = new JFrame("main test");
	
		m.add(t);

		m.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		m.setSize(800,650);
		m.setVisible(true);
		*/

		SHAPE[] arr = {r,c,t,com,d};
		System.out.printf("____________________________________drawAll test_________________________\n");
		function.drawAll(arr);
		System.out.printf("____________________________________end drawAll test_________________________\n\n\n");
		System.out.printf("____________________________________sort test_________________________\n");
		for (int i = 0 ;i < arr.length ;i++ ) {
			System.out.printf(">>> %s",arr[i]);
		}

		function.sortShapes(arr);

		for (int i = 0 ;i < arr.length ;i++ ) {
			System.out.printf("<<< %s",arr[i]);
		}
		System.out.printf("____________________________________end sort test_________________________\n\n\n");
		System.out.printf("____________________________________convert test_________________________\n");
		SHAPE[] temp = function.convertAll(arr); 
		for (int i = 0 ;i < temp.length ;i++ ) {
			System.out.printf("<<< %s",temp[i]);
		}
		System.out.printf("____________________________________end convert test_________________________\n");
	}

}