# ifndef PriorityQueue_H_
# define PriorityQueue_H_
# include <iostream>
# include "Queue.h"
# include "Iterator.h"
namespace jwan_ {

	template<class E , template <typename... > class Container>
	class PriorityQueue : public Queue<E,Container>{
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
			void removeAll( Collection<E,Container>& c )  { /*  according to FIFO this function can not work  */ } ;
			void retainAll(Collection<E,Container>& c) { /*  according to FIFO this function can not work  */ }  ;
			void remove(E e) { /*  according to FIFO this function can not work  */ } ;
			void addAll(Collection<E,Container>& c) ;
		
			void pop();

		private: 
			Container<E> container;
	};

}
#endif /* PriorityQueue_H_ */