
/**
*	interface collection
*	@author jwan hussein 
*/
public interface Collection<E> {
	/**
	*	iterator over the collection from first to last 
	*	@return iterator over the collection 
	*/
	public iterator<E> iterator();
	/**
	*	Ensures that this collection contains the specified element (optional operation).
	* 	@return true if this collection changed as a result of the call
	*/
	public boolean add(E element);
	/**
	*	Adds all of the elements in the specified collection to this collection (optional operation).
	*	@param element - element whose presence in this collection is to be ensured
	*	@return true if this collection changed as a result of the call
	*/
	public boolean addAll(Collection<E> elements);
	/**
	*	Removes all of the elements from this collection
	*	@param elements - elements whose presence in this collection is to be ensured
	*	@return true if this collection changed as a result of the call
	*/
	public void clear();
	/**
	*	Returns true if this collection contains the specified element.
	*	@return true if this collection contains the specified element
	*/
	public boolean contains(E element);
	/**
	*	Returns true if this collection contains all of the elements in the specified collection.
	*	@param elements - elements whose presence in this collection is to be ensured
	*	@return rue if this collection contains all of the elements in the specified collection
	*/
	public boolean containsAll(Collection<E> elements);
	/**
	*	Returns true if this collection contains no elements.
	*	@return true if this collection contains no elements
	*/
	public boolean isEmpty();
	/**
	*	Removes a single instance of the specified element from this collection, if it is present 
	*	@param element - element whose presence in this collection is to be ensured
	*/
	public void remove(E element);
	/**
	*	Removes all of this collection's elements that are also contained in the specified collection 
	*	@param elements - elements whose presence in this collection is to be ensured
	*	@param element - element whose presence in this collection is to be ensured
	*/
	public void removeAll(Collection<E> elements);
	/**
	*	Retains only the elements in this collection that are contained in the specified collection
	*	@param elements - elements whose presence in this collection is to be ensured
	*/
	public void retainAll(Collection<E> elements);
	/**
	*	@return Returns the number of elements in this collection.
	*/
	public int size();

}