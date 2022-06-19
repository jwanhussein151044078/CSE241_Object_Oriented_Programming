# ifndef Queue_H_
# define Queue_H_
# include <iostream>
# include "Collection.h"
# include "Iterator.h"
namespace jwan_ {

	template<class E , template <typename... > class Container>
	class Queue : public Collection<E,Container>{
		public:
			virtual void add(E e) = 0 ;
			virtual Iterator<E,Container> element() = 0 ;
			virtual void offer(E e) = 0 ;
			virtual Iterator<E,Container> poll() = 0 ;

	};

}
#endif /* Queue_H_ */