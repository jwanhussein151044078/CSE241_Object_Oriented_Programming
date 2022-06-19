
/**
*	interface SEt
*	@author jwan hussein 
*/
public interface Set<E> extends Collection<E>{
	/**
	*	Compares the specified object with this set for equality.
	*	@param o - object to be compared for equality with this set
	*	@return 
	*/
	public boolean equals(Object o);
	/**
	*	Returns an array containing all of the elements in this set. If this set makes any guarantees as to what order its elements are returned by its iterator, this method must return the elements in the same order. 
	*	@return an array containing all the elements in this set
	*/
	public Object[] toArray();
}