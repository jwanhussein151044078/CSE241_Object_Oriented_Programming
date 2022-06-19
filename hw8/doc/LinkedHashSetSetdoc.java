/**
* class LinkedHashSet
* @author jwan hussein 
*/
public class LinkedHashSet<E> extends HashSet<E>{
	/**
	*	no param constructor
	*
	*/
	public LinkedHashSet();
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
