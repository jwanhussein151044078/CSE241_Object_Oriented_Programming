# ifndef List_H_
# define List_H_
# include <iostream>
# include "Collection.h"
# include "Iterator.h"


namespace jwan_ {
	template<class E, template <typename... > class Container>
	class List : public Collection<E,Container>{
		public:

			virtual Iterator<E,Container> iterator() = 0 ;
			virtual int size() = 0 ;
			virtual bool isEmpty() = 0  ;
			virtual bool containsAll(Collection<E,Container>& c) = 0 ;  
			virtual bool contains(E e) = 0 ;
			virtual void clear() = 0 ;
			virtual void removeAll( Collection<E,Container>& c ) = 0 ;
			virtual void retainAll(Collection<E,Container>& c) = 0 ;
			virtual void remove(E e) = 0 ;
			virtual void addAll(Collection<E,Container>& c) =0 ;
			virtual void add( E e ) = 0 ;

			virtual void insert(E e) = 0 ;
			virtual E operator [] (int index) =0;

	};
}

#endif /* List_H_ */