

/**
*	interface Queue
*	@author jwan hussein 
*/

public interface Queue<E> extends Collection<E>{
	/**
	*	Retrieves, but does not remove, the head of this queue.
	*	@return the head of this queue
	*/
	public E element();
	/**
	*	Inserts the specified element into this queue if it is possible to do so immediately without violating capacity restrictions. When using a capacity-restricted queue, this method is generally preferable to add(E),
	*	 which can fail to insert an element only by throwing an exception.
	*	@return     true if the element was added to this queue, else false
	*/
	public boolean offer(E element);
	/**
	*	Retrieves and removes the head of this queue, or returns null if this queue is empty.
	*	@return the head of this queue, or null if this queue is empty
	*/
	public E poll();
	/**
	*	Returns an array containing all of the elements in this list in proper sequence (from first to last element).
	*	@return an array containing all of the elements in this list in proper sequence
	*/
	public Object[] toArray();

}