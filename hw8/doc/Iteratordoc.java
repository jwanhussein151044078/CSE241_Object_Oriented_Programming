/**
* class iterator
* @author jwan hussein 
*/
import java.lang.IllegalArgumentException;

public class iterator<E> {
	/**
	*	no param constructor
	*
	*/
	public iterator(){
		
	}
	/**
	*	one param constructor 
	*   @param other - the array 
	*
	*/
	public iterator(E[] other);
	/**
	*	return the next element in iteration 
	*	@return the next element in iteration
	*
	*/
	public E next();
	/**
	*	check if the next element is not null
	*	@return true if the iteration has more element 
	*
	*/
	public boolean hasNext();
	/**
	*	remove the last element in the iteration 
	*
	*/
	public void remove();

	private E[] arr ;
	private int index;

}