



public interface Queue<E> extends Collection<E>{
	
	public E element();
	public boolean offer(E element);
	public E poll();
	public Object[] toArray();

}