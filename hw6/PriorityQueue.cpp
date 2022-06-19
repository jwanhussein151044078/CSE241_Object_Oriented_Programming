# include "PriorityQueue.h"
namespace jwan_ {
	template<class E, template <typename... > class Container>
	Iterator<E,Container> PriorityQueue<E,Container>::iterator(){

		return Iterator<E,Container>(container);
	}

	template<class E, template <typename... > class Container>
	int PriorityQueue<E,Container>::size(){
		return container.size() ;
	}

	template<class E, template <typename... > class Container>
	bool PriorityQueue<E,Container>::isEmpty(){
		return container.empty();
	}

	template<class E, template <typename... > class Container>
	void PriorityQueue<E,Container>::add(E e){
		container.insert(container.end() , e );
		
	}

	template<class E, template <typename... > class Container>
	Iterator<E,Container> PriorityQueue<E,Container>::element(){
		return this->iterator();
		
	}

	template<class E, template <typename... > class Container>
	void PriorityQueue<E,Container>::offer(E e){
		this->add(e);		
	}

	template<class E, template <typename... > class Container>
	Iterator<E,Container> PriorityQueue<E,Container>::poll(){
		container.erase(container.begin());
		return this->element();
	}

	template<class E, template <typename... > class Container>
	void PriorityQueue<E,Container>::clear(){
		container.clear();
		
	}

	template<class E, template <typename... > class Container>
	bool PriorityQueue<E,Container>::contains(E e){
		auto temp = container.begin();
		for(int i =0 ; i < container.size() ; i++){
			if (*temp == e ){
				return true ;
			}
			temp++ ;
		}
		return false ;
		
	}	

	template<class E, template <typename... > class Container>
	bool PriorityQueue<E,Container>::containsAll(Collection<E,Container>& c){
		
		PriorityQueue<E,Container>* v = dynamic_cast< PriorityQueue<E,Container>* > (&c);
		if (this->size() < v->size()){
			return false ;
		}
		Iterator<E,Container> temp ;
		temp = this->iterator();
		int counter =0 ;
		while (temp.hasnext()){
			Iterator<E,Container> temp1 = v->iterator();
			while(temp1.hasnext()){
				if (*temp == *temp1){
					counter++;
				}
				temp1.next();
			}
			temp.next();
		}
		if (counter >= v->size()){
			return true ;
		}
		return false ;
	}

	template<class E, template <typename... > class Container>
	void PriorityQueue<E,Container>::addAll(Collection<E,Container>& c){
		PriorityQueue<E,Container>* v = dynamic_cast< PriorityQueue<E,Container>* > (&c);	
		auto temp = v->iterator();
		for (int i =0 ; i < v->size() ; i++){
			this->add(*temp);
			temp.next();
		}
	}

	template<class E, template <typename... > class Container>
	void PriorityQueue<E,Container>::pop(){
		container.erase(container.begin());		
	}



}