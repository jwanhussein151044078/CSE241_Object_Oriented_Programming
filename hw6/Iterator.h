# ifndef Iterator_H_
# define Iterator_H_
# include <iostream>

# include <fstream> 

namespace jwan_{

	template<class E, template <class... > class Container>
	class Iterator{
		
		public:
			
			Iterator();
			Iterator(Container< E >& o);
			Iterator(const Iterator& o);
			
			bool hasnext();
			void next();
			void remove();
			void print() ;

			Iterator& operator = (const Iterator& );
			E& operator *();
		
		private:
			E*  it ;
			E* end ;

	};
	
}
# endif /* Iterator_H_ */