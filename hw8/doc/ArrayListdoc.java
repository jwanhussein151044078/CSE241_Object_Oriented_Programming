/**
* class ArrayList
* @author jwan hussein 
*/
public class ArrayList<E> implements List<E>{
	/**
	*	no param constructor
	*
	*/
	public ArrayList();
	/**
	*	return the capacity of the ArrayList 
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