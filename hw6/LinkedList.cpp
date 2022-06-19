# include "LinkedList.h"
namespace jwan_ {

	template<class E, template <typename... > class Container>
	Iterator<E,Container> LinkedList<E,Container>::iterator(){

		return Iterator<E,Container>(container);
	}

	template<class E, template <typename... > class Container>
	int LinkedList<E,Container>::size(){
		return container.size() ;
	}

	template<class E, template <typename... > class Container>
	bool LinkedList<E,Container>::isEmpty(){
		return container.empty();
	}

	template<class E, template <typename... > class Container>
	E LinkedList<E,Container>::operator [] (int index){
		Iterator<E,Container> temp ;
		temp = this->iterator();

		if (index < container.size() && index >= 0 ){
			for(int i = 0 ; i <= index ; i++){
				temp.next();
			}
			return *temp; 
		}
		std::cout<<"out of range !! ";
		
	}

	template<class E, template <typename... > class Container>
	bool LinkedList<E,Container>::contains(E e){
		Iterator<E,Container> temp ;
		temp = this->iterator();

		while(temp.hasnext()){
			if ( *temp == e ){
				return true ;
			}
			temp.next();
		}
		return false ;
	}

	template<class E, template <typename... > class Container>
	bool LinkedList<E,Container>::containsAll(Collection<E,Container>& c){
		
		LinkedList<E,Container>* v = dynamic_cast< LinkedList<E,Container>* > (&c);
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
	void LinkedList<E,Container>::insert(E e){
		container.insert(container.end() , e );
		
	}

	template<class E, template <typename... > class Container>
	void LinkedList<E,Container>::clear(){
		container.clear();		
	}

	template<class E, template <typename... > class Container>
	void LinkedList<E,Container>::remove(E e) {
		auto temp = container.begin();
		
		for (int i = 0 ; i < container.size() ; i++){
			if ( *temp == e ){
				container.erase(temp);
			}
			temp++;
		}		
	}

	template<class E, template <typename... > class Container>
	void LinkedList<E,Container>::removeAll(Collection<E,Container>& c){
		LinkedList<E,Container>* v = dynamic_cast< LinkedList<E,Container>* > (&c);	
		auto temp = v->iterator();
		for (int i = 0 ; i < v->size() ; i++){
			this->remove(*temp);
			temp.next();
		}
	}

	template<class E, template <typename... > class Container>
	void LinkedList<E,Container>::add(E e){
		this->insert(e);
	}

	template<class E, template <typename... > class Container>
	void LinkedList<E,Container>::addAll(Collection<E,Container>& c){
		LinkedList<E,Container>* v = dynamic_cast< LinkedList<E,Container>* > (&c);	
		auto temp = v->iterator();
		for (int i =0 ; i < v->size() ; i++){
			this->add(*temp);
			temp.next();
		}
	}

	template<class E, template <typename... > class Container>
	void LinkedList<E,Container>::retainAll(Collection<E,Container>& c){
		LinkedList<E,Container>* v = dynamic_cast< LinkedList<E,Container>* > (&c);	
		auto temp = this->iterator();
		int found=0; 
		while (temp.hasnext()){
			found = 0 ;
			auto temp1 = v->iterator();
			while(temp1.hasnext()){
				if ( *temp == *temp1 ){
					found = 1 ;
				}
				temp1.next();
			}
			if(found == 0 ){
				this->remove(*temp);
			}
			temp.next();
		}
	}

	template<class E, template <typename... > class Container>
	void LinkedList<E,Container>::pop(){
		container.erase(container.begin());		
	}

	template<class E, template <typename... > class Container>
	Iterator<E,Container> LinkedList<E,Container>::element(){
		return this->iterator();
		
	}

	template<class E, template <typename... > class Container>
	void LinkedList<E,Container>::offer(E e){
		this->add(e);		
	}

	template<class E, template <typename... > class Container>
	Iterator<E,Container> LinkedList<E,Container>::poll(){
		container.erase(container.begin());
		return this->element();
	}


}