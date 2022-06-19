
import java.lang.IllegalArgumentException;
@SuppressWarnings("unchecked")
public class iterator<E> {

	public iterator(){
		
	}
	public iterator(E[] other){
		arr = other ;

		for(int i =0 ; i < other.length ; i++){
			arr[i] = other[i] ;
		}
		index = 0 ;
	}

	public E next(){
		try{
			if(index < arr.length){
				index++;
				return arr[index-1];
			}
			else {
				throw new IllegalAccessException("no next element in itration\n");
			}
			
		}catch(IllegalAccessException e){
			System.out.printf(e.getMessage());
		}
		return null;

	}
	public boolean hasNext(){
		if(index < arr.length){
			return true ;
		}
		return false ;
	}
	public void remove(){
		E[] temp = arr ;
		int new_size =  arr.length-1 ;
		arr = (E[])new Object[new_size];
		for(int i = 0 ; i < arr.length ; i++){
			arr[i] = temp[i];
		}
	}


	private E[] arr ;
	private int index;

}