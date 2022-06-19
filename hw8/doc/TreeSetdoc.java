/**
* class TreehSet
* @author jwan hussein 
*/
public class TreeSet<E> implements NavigableSet<E>{
	/**
	*	no param constructor
	*
	*/
	public TreeSet();
	/**
	*	Returns a string representation of this collection
	*	@return a string representation of this collection
	*/
	public String toString();
	private void resize();
	
	private E[] arr ;
	private int size ;
	private int capacity;
	private iterator<E> it ;
}