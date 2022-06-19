# ifndef vector_H_
# define vector_H_
# include <iostream>
# include "List.h"
# include "Iterator.h"



namespace jwan_ {
	template<class E, template <typename... > class Container>
	class vector : public List<E,Container>{
		public:
			vector(){

			} ;

			Iterator<E,Container> iterator() ;
			int size() ;
			bool isEmpty() ;
			bool containsAll(Collection<E,Container>& c) ;  
			bool contains(E e) ;
			void clear() ;
			void removeAll( Collection<E,Container>& c );
			void retainAll(Collection<E,Container>& c) ;
			void remove(E e)  ;
			void addAll(Collection<E,Container>& c) ;
			void add (E e) ;

			void insert(E e);
			E operator [] (int index);
			
			private:
				Container<E> container ;
	};
}

#endif /* vector_H_ */