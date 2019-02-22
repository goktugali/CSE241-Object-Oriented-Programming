#include "hashset.h"

namespace collectionsgtu
{

	template<typename T,template <typename...> class Container>
	gtuiterator<T,Container> HashSet<T,Container>::iterator()
	{
		gtuiterator<T,Container> iter(&_data);
		return iter;
	}
	template<typename T,template <typename...> class Container>
	void HashSet<T,Container>::remove(T e){
		auto iterx=this->iterator();

		while((*iterx)!=e)
			iterx++;
		return iterx.remove();			
	}
	template<typename T,template <typename...> class Container>
	bool HashSet<T,Container>::isEmpty()const {
		if(size()==0)
			return 1;
		return 0;
	}
	
	template<typename T,template <typename...> class Container>
	void HashSet<T,Container>::add(T e){
		if(!this->contains(e))
			_data.insert(_data.end(),e);
	}
	template<typename T,template <typename...> class Container>
	bool HashSet<T,Container>::contains(T e){
		for(auto iter=this->iterator(); iter.hasNext()!=0; iter++)
			if(*iter==e)
				return 1;
		return 0;
	}

}