/**
*	interface NavigableSet
*	@author jwan hussein 
*/
public interface NavigableSet<E> extends SortedSet<E>{
	/**
	*	Returns the greatest element in this set less than or equal to the given element, or null if there is no such element.
	*	@param element - the value to match
	*	@return the greatest element less than or equal to e, or null if there is no such element
	*/
	public E floor(E element);
	/**
	*	Returns the greatest element in this set strictly less than the given element, or null if there is no such element.
	*	@param element - the value to match
	*	@Returns the greatest element less than e, or null if there is no such element
	*/
	public E lower(E element);
}