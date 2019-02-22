#include "abstractcollection.h"

namespace collectionsgtu{

	template<typename T,template <typename...> class Container>
	template<template <typename...> class C>
	bool AbstractCollection<T,Container>::containsAll(collections<T,C>& c){
			
			for(auto iter=c.iterator(); iter.hasNext()!=0; iter++)
				if(!this->contains(*iter))
					return false;
			return true;
			
	}
	template<typename T,template <typename...> class Container>
	template<template <typename...> class C>
	bool AbstractCollection<T,Container>::removeAll(collections<T,C>& c){

		if(c.isEmpty()==1)
			throw empty_param_container();

		for(auto iter=c.iterator(); iter.hasNext()!=0; ++iter){
			if(this->contains(*iter))
				this->remove(*iter);
		}
		return true;
	}
	template<typename T,template <typename...> class Container>
	template<template <typename...> class C>
	bool AbstractCollection<T,Container>::retainAll(collections<T,C>& c){

		bool capture;
		for(auto iter=this->iterator(); iter.hasNext()!=0;iter=iter){
			capture=false;
			for(auto iter1=c.iterator(); iter1.hasNext()!=0;++iter1){
				if(*iter == *iter1)
					capture = true;
			}
			if(capture==false)	
				this->remove(*iter);
			else
				iter++;
		}
		return true;			
	}
	template<typename T,template <typename...> class Container>
	template<template <typename...> class C>
	void AbstractCollection<T,Container>::addAll(collections<T,C>& c)throw(empty_param_container){

		if(c.isEmpty()==1)
			throw empty_param_container();

		for(auto iter=c.iterator(); iter.hasNext()!=0; ++iter)
				this->add(*iter);
		
	}
}