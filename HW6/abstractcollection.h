#ifndef ABSTRACTCOLLECTION_H_
#define ABSTRACTCOLLECTION_H_
#include "collections.h"
/*	

	@ this "abstract class" is a interlayer class
	between collection and data structures(queue,list,set)
	like Java Collection Hiearcyh in Java.

	@ This class implemented to, call like this statements :
	arrrlist<int,vector> test1
	arrrlist<int,list> test2
	test1.containsAll(test2)... or another functions that
	accepts any collection param. 

*/
namespace collectionsgtu
{

template<typename T,template <typename...> class Container>
class AbstractCollection : public collections<T,Container>{

	public:
		template<template <typename...> class C>
		bool containsAll(collections<T,C>& c);
		template<template <typename...> class C>
		bool removeAll(collections<T,C>& c);
		template<template <typename...> class C>
		bool retainAll(collections<T,C>& c);
		template<template <typename...> class C>
		void addAll(collections<T,C>& c)throw(empty_param_container);
		virtual gtuiterator<T,Container> iterator()=0;
		virtual void remove(T e)=0;
		virtual bool isEmpty()const=0;
		virtual int size()const=0;
		virtual void clear()=0;
		virtual void add(T e)=0;
		virtual bool contains(T e)=0;

};
}
#endif