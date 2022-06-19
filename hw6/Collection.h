# ifndef Collection_H_
# define Collection_H_
# include <iostream>
# include "Iterator.h"

namespace jwan_ {
	
	template<class E , template <typename... > class Container>
	class Collection{
		public:

			virtual Iterator<E,Container> iterator() = 0 ;
			virtual int size() = 0 ;
			virtual bool isEmpty() = 0  ;
			virtual bool containsAll(Collection& c) = 0 ;  
			virtual bool contains(E e) = 0 ;
			virtual void clear() = 0 ;
			virtual void removeAll( Collection& c ) = 0 ;
			virtual void retainAll(Collection& c) = 0 ;
			virtual void remove(E e) = 0 ;
			virtual void addAll(Collection& c) =0 ;
			virtual void add(E e ) = 0 ;

	};
}
#endif /* Collection_H_ */