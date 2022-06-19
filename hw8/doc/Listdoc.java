
/**
*	interface Lest
*	@author jwan hussein 
*/
public interface List<E> extends Collection<E>{
	/**
	*	Compares the specified object with this set for equality.
	*	@param o - object to be compared for equality with this set
	*	@return 
	*/
	public boolean equals(Object o);
	/**
	*	Returns the index of the first occurrence of the specified element in this list, or -1 if this list does not contain the element.
	*	@return he index of the first occurrence of the specified element in this list, or -1 if this list does not contain the element
	*/
	public int indexOf(Object o);
	/**
	*	Returns an array containing all of the elements in this list in proper sequence (from first to last element).
	*	@return an array containing all of the elements in this list in proper sequence
	*/
	public Object[] toArray();
	/**
	*	Returns the element at the specified position in this list.
	*	@param	index - index of the element to return
	*	@return the element at the specified position in this list
	*/
	public E get(int index);
}