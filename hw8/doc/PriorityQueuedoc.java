
/**
* class PriorityQueue
* @author jwan hussein 
*/

public class PriorityQueue<E> implements Queue<E>{
	/**
	*	no param constructor
	*
	*/
	public PriorityQueue();
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