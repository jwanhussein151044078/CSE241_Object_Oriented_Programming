/**
* class HashSet
* @author jwan hussein 
*/
public class HashSet<E> implements Set<E>{
	/**
	*	no param constructor
	*
	*/
	public HashSet();
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
