/**
* class vector
* @author jwan hussein 
*/
public class vector<E> implements List<E>{
	/**
	*	no param constructor
	*
	*/
	public vector();
	/**
	*	return the capacity of the vector 
	*	@return capacity
	*/
	public int capacity();
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