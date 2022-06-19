@SuppressWarnings("unchecked")
public class LinkedHashSet<E> extends HashSet<E>{

	public LinkedHashSet(){
		size = 0 ;
		capacity = 1 ;
		arr = (E[])new Object[capacity];
	}

	public iterator<E> iterator(){
		it = new iterator<E>(arr);
		return it ;
	}
	public boolean add(E element){
		for (int i = 0 ; i < size() ; i++){
			if (arr[i] == element){
				return false ;
			}
		}
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
		int index=-1;
		E[] temp = arr;
		for (int i = 0 ;i < size() ;i++ ) {
			if (arr[i] == element){
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
	public boolean equals(Object o){
		if (o instanceof TreeSet){
			int i = 0 ;
			TreeSet<E> tree = (TreeSet<E>)o;
			iterator<E> it = tree.iterator();
			while(it.hasNext()){
				if (it.next() != arr[i++]){
					return false ;
				}
			}
		}
		return true ;
	}
	public Object[] toArray(){
		Object[] temp = new Object[size()];
		for(int i = 0 ; i < size() ; i++){
			temp[i] = arr[i];
		}
		return temp ;
	}
	public String toString(){
		return String.format("LinkedHashSet of length ( %d )\n",size);
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
