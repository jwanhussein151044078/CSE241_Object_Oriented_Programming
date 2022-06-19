

public interface List<E> extends Collection<E>{

	public boolean equals(Object o);
	public int indexOf(Object o);
	public Object[] toArray();
	public E get(int index);
}