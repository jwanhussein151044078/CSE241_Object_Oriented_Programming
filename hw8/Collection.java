

public interface Collection<E> {
	public iterator<E> iterator();
	public boolean add(E element);
	public boolean addAll(Collection<E> elements);
	public void clear();
	public boolean contains(E element);
	public boolean containsAll(Collection<E> elements);
	public boolean isEmpty();
	public void remove(E element);
	public void removeAll(Collection<E> elements);
	public void retainAll(Collection<E> elements);
	public int size();

}