# include "Iterator.h"
# include <iterator>
namespace jwan_{

	template<class E, template <class... > class Container>
	Iterator<E,Container>::Iterator(){

	}

	template<class E, template <class... > class Container>
	Iterator<E,Container>::Iterator(Container< E>& o){
		int i =0;
		it = new E[o.size()] ;
		auto temp = o.begin();
		for( i = 0 ; i <o.size() ; i++ ){
			it[i] = *temp++ ; 
		}
		end = new E ;
		end = &it[i] ;
	}

	template<class E, template <class... > class Container>
	Iterator<E,Container>::Iterator(const Iterator& o){
		it = new E ;
		it = o.it ;
		end = new E ;
		end = o.end ;
	}	
	
	template<class E, template <class... > class Container>
	void Iterator<E,Container>::print(){
		std::cout << *it ;
	}

	template<class E, template <class... > class Container>
	bool Iterator<E,Container>::hasnext(){
		if ( it < end  ){
			return true ;
		}
		return false ;
	}

	template<class E, template <class... > class Container>
	void Iterator<E,Container>::next(){
		if (hasnext()){
			it = it+1 ;
		}  
	}

	template<class E, template <class... > class Container>
	void Iterator<E,Container>::remove(){
		if ( it < end ){
			end = end - 2 ;
		}
	}

	template<class E, template <class... > class Container>
	Iterator<E,Container>& Iterator<E,Container>::operator = (const Iterator& o){
		if (o.it != it  ){
			it = new E ;
			it = o.it ;
			end = new E ;
			end = o.end ;
		}
	}

	template<class E, template <class... > class Container>
	E& Iterator<E,Container>::operator *(){
		return *it ;
	}
}