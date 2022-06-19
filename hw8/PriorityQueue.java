@SuppressWarnings("unchecked")
public class PriorityQueue<E> implements Queue<E>{
	public PriorityQueue(){
		size = 0 ;
		capacity = 1 ;
		arr = (E[])new Object[capacity];
	}

	public iterator<E> iterator(){
		it = new iterator<E>(arr);
		return it;
	}
	public boolean add(E element){
		if(size >= capacity){
			resize();
		}
		arr[size] = element ;
		size++;
		return true ;
	}
	public boolean addAll(Collection<E> elements){
		iterator<E> it = elements.iterator();
		while(it.hasNext()){
			add(it.next());
		}
		return true ;		
	}
	public void clear(){
		arr = (E[])new Object[0];
		size = 0 ; 
		capacity = 1 ;
	}
	public boolean contains(E element){
		for(int i = 0 ; i < size() ; i++){
			if (element == arr[i]){
				return true ;
			}			
		}
		return false ;
	}
	public boolean containsAll(Collection<E> elements){
		int found = 0;
		
		if (elements.size() > size()){
			return false ;
		}
		for(int i =0 ;i < size() ; i++){
			iterator<E> it = elements.iterator();
			while(it.hasNext()){
				if(it.next() == arr[i]){
					found++;
				}
			}
		}
		if (found >= elements.size()){
			return true ;
		}
		
		return false ;

	}
	public boolean isEmpty(){
		if(size == 0 ){
			return true ;
		}
		return false ;
	}
	public void remove(E element){
		int index = -1;
		E[] temp = arr;
		for (int i = 0 ; i < size() ; i++){
			if (element == arr[i]){
				index = i ;
				break;
			}
		} 
		if ( index != -1){
			capacity--;
			arr = (E[])new Object[capacity];
			for (int i = 0 ,j=0; i < size() ; i++){
				if( i != index ){
					arr[j] = temp[i];
					j++;
				}
			}
		}
		size = capacity;
	}
	public void removeAll(Collection<E> elements){
		iterator<E> it = elements.iterator();
		while(it.hasNext()){
			remove(it.next());
		}
	}
	public void retainAll(Collection<E> elements){
		boolean found  ;
		for(int i = 0 ; i < size() ; i++){
			iterator<E> it = elements.iterator();
			found = false;
			while(it.hasNext()){
				if(it.next() == arr[i]){
					found = true ; 
				}
			}
			if(!found){
				remove(arr[i]);
				i--;
			}
		}
		
	}
	public int size(){
		return size ;
	}
	public E element(){
		try{
			if(!isEmpty()){
				return arr[0];
			}
			else {
				throw new IllegalAccessException("empty queue \n");
			}
		}catch(IllegalAccessException e){
			System.out.printf(e.getMessage());
		}
		return null;
	}
	public boolean offer(E element){
		try{
			if(size < capacity){
				add(element);
				return true ;
			}
			else {
				throw new IllegalAccessException("no space in the queue \n");
			}
		}catch(IllegalAccessException e){
			System.out.printf(e.getMessage());
		}
		return false;
	}
	public E poll(){
		if (!isEmpty()){
			E temp = arr[0];
			remove(arr[0]);
			return temp ;
		}
		return null;
	}
	public Object[] toArray(){
		Object[] temp = new Object[size()];
		for(int i = 0 ; i < size() ; i++){
			temp[i] = arr[i];
		}
		return temp ;
	}
	public String toString(){
		return String.format("PriorityQueue of length ( %d )\n",size);
	}

	private void resize(){
		E[] temp = arr ;
		capacity += 1 ;
		arr = (E[])new Object[capacity];
		for (int i =0 ; i < size ; i++ ){
			arr[i] = temp [i];
		}
	}
	
	private E[] arr ;
	private int size ;
	private int capacity;
	private iterator<E> it ;
}