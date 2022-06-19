
/**
* class LinkedList
* @author jwan hussein 
*/

public class LinkedList<E> implements Queue<E> , List<E>{
	/**
	*	no param constructor
	*
	*/
	public LinkedList();
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

