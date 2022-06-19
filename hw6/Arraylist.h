
# ifndef Arraylist_H_
# define Arraylist_H_
# include <iostream>
# include "Iterator.h"
# include "List.h"


namespace jwan_ {
	template<class E, template <typename... > class Container>
	class Arraylist: public List<E,Container>{
		public:

			Iterator<E,Container> iterator() ;
			int size() ;
			bool isEmpty() ;
			bool containsAll(Collection<E,Container>& c) ;  
			bool contains(E e);
			void clear();
			void removeAll( Collection<E,Container>& c );
			void retainAll(Collection<E,Container>& c);
			void remove(E e);
			void addAll(Collection<E,Container>& c);
			void add (E e);

			void insert(E e);
			E operator [] (int index);

		private:
			Container<E> container ;
	};
}

# endif /* Arraylist_H_ */ 