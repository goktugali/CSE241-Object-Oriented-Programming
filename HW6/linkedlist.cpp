#include "linkedlist.h"

namespace collectionsgtu{

	template<typename T,template <typename...> class Container>
	gtuiterator<T,Container> LinkedList<T,Container>::iterator(){
		gtuiterator<T,Container> iter(&_data);
		return iter;
	}
	template<typename T,template <typename...> class Container>
	void LinkedList<T,Container>::remove(T e){
		auto iterx=this->iterator();

		while((*iterx)!=e)
			iterx++;
		return iterx.remove();			
	}
	template<typename T,template <typename...> class Container>
	bool LinkedList<T,Container>::isEmpty()const {
		if(size()==0)
			return 1;
		return 0;
	}
	template<typename T,template <typename...> class Container>
	void LinkedList<T,Container>::add(T e){

		_data.insert(_data.end(),e);
	}
	template<typename T,template <typename...> class Container>
	bool LinkedList<T,Container>::contains(T e){
		for(auto iter=this->iterator(); iter.hasNext()!=0; iter++)
			if(*iter==e)
				return 1;
		return 0;
	}
	template<typename T,template <typename...> class Container>
	T LinkedList<T,Container>::element()throw(empty_container){
		if(this->isEmpty()==0){
			auto iter = this->iterator();
			return *iter;
		}
		else 
			throw empty_container();
	}
	template<typename T,template <typename...> class Container>
	void LinkedList<T,Container>::offer(T e){
		this->add(e);
	}
	template<typename T,template <typename...> class Container>
	T LinkedList<T,Container>::poll()throw (empty_container){
		if(this->isEmpty()==0){
			T temp;
			auto iter = this->iterator();
			temp = *iter;
			this->remove(*iter);

			return temp;
		}
		else
			throw empty_container();
	}

}