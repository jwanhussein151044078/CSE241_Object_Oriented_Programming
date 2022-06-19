
/**
*	interface SortedSet
*	@author jwan hussein 
*/

public interface SortedSet<E> extends Set<E>{
	/**
	*	Returns the first (lowest) element currently in this set.
	*	@return the first (lowest) element currently in this set
	*/
	public E first();
	/**
	*	Returns the last (highest) element currently in this set.
	*	@return the last (highest) element currently in this set
	*/
	public E last();


}