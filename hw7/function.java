import javax.swing.JFrame;
import java.awt.Graphics;
import javax.swing.JPanel;
import java.awt.BorderLayout;
import java.awt.FlowLayout;
import javax.swing.BoxLayout;

public class function{
	
	public static void drawAll(SHAPE[] arr){
		
		JFrame f = new JFrame("drawall");
		JPanel p = new JPanel();
		p.setLayout(new BoxLayout(p, BoxLayout.LINE_AXIS));
		for (int i =0 ;i < arr.length ;i++ ) {
			if (arr[i] instanceof rectangle){
				rectangle rec = (rectangle)arr[i];
				p.add(rec);
			}
			if (arr[i] instanceof circle){
				circle cir = (circle)arr[i];
				p.add(cir);
			}
			if (arr[i] instanceof triangle){
				triangle tri = (triangle)arr[i];
				p.add(tri);
			}
			if (arr[i] instanceof composedshape){
				composedshape com = (composedshape)arr[i];
				p.add(com);
			}
			if (arr[i] instanceof polygonvect){
				polygonvect vec = (polygonvect)arr[i];
				p.add(vec);
			}
			if (arr[i] instanceof polygondyn){
				polygondyn dyn = (polygondyn)arr[i];
				p.add(dyn);
			}

		}
		f.add(p);
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		f.setSize(1500,800);
		f.setVisible(true);

	}



	public static void sortShapes(SHAPE[] arr) {
		SHAPE temp ;
		for (int i =0 ; i < arr.length ; i++){
			for (int j = i+1 ; j < arr.length ; j++){
				if (arr[i].get_area() > arr[j].get_area()){
					temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp ;
				}
			}
		}
	}


	public static SHAPE[] convertAll(SHAPE[] arr){
		SHAPE[] temp = new SHAPE[arr.length];
		for (int i =0 ; i < arr.length ; i++){
			temp[i] = new polygonvect(arr[i]);
		}

		return temp;
	}
}