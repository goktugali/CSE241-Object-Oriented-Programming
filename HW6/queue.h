#ifndef QUEUE_H_
#define QUEUE_H_
#include "abstractcollection.h"
#include "gtuexceptions.h"

/* 			CSE-241 HW6 
		JAVA COLLECTION HIERARCYH 
*/
/*----------------------------------------*/
/*	@ author : 		Goktug Ali Akin		 */
/*	@ student id :  161044018 			*/
/*-------------------------------------*/

/*------------------------------------*/
/*--------<<QUEUE INTERFACE>---------*/
/*----------------------------------*/

/* @ This file is an interface file that user
	can call methods, and not contains implementation.
*/

/*
	@ *removeAll,containsAll,retainAll,adAll method
	@ templated and comes from Abstract class name
	@ "AbstractCollections.h" 
*/

using namespace gtuExceptions;

namespace collectionsgtu
{
	template<typename T,template <typename...> class Container>
	class queue : public virtual AbstractCollection<T,Container>
	{
	public:
		virtual gtuiterator<T,Container> iterator()=0;
		virtual void remove(T e)=0;
		virtual bool isEmpty()const=0;
		virtual int size()const=0;
		virtual void clear()=0;
		virtual void add(T e)=0;
		virtual bool contains(T e)=0;
		virtual T element()throw(empty_container)=0;
		virtual void offer(T e)=0;
		virtual T poll()throw(empty_container)=0;//throw
		
	};
}
#endif