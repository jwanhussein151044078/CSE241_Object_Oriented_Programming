# ifndef LinkedList_H_
# define LinkedList_H_
# include <iostream>
# include "Queue.h"
# include "List.h"
# include "Iterator.h"
namespace jwan_ {

	template<class E , template <typename... > class Container>
	class LinkedList : public Queue<E,Container> , public List<E,Container>{
		public:
			void add(E e)  ;
			Iterator<E,Container> element()  ;
			void offer(E e)  ;
			Iterator<E,Container> poll()  ;

			Iterator<E,Container> iterator()  ;
			int size()  ;
			bool isEmpty()   ;
			bool containsAll(Collection<E,Container>& c)  ;  
			bool contains(E e)  ;
			void clear()  ;
			void removeAll( Collection<E,Container>& c )  ;
			void retainAll(Collection<E,Container>& c)  ;
			void remove(E e) ;
			void addAll(Collection<E,Container>& c) ;
		
			void pop();

			void insert(E e) ;
			E operator [] (int index) ;

		private: 
			Container<E> container;
	};

}
#endif /* LinkedList_H_ */