#ifndef COLLECTIONS_H_
#define COLLECTIONS_H_
#include "gtuiterator.h"
#include "gtuexceptions.h"
#include <cstdlib>

using namespace gtuExceptions;

/* 			CSE-241 HW6 
		JAVA COLLECTION HIERARCYH 
*/
/*----------------------------------------*/
/*	@ author : 		Goktug Ali Akin		 */
/*	@ student id :  161044018 			*/
/*-------------------------------------*/

/*------------------------------------*/
/*----<<COLLECTIONS INTERFACE<-------*/
/*----------------------------------*/

/* @ This file is an interface file that user
	can call methods, and not contains implementation.
	For more details, --> please check AbstractCollection 
	implemetation.
*/

namespace collectionsgtu
{
	template<typename T,template <typename...> class Container>
	class collections
	{
	public:
		virtual gtuiterator<T,Container> iterator()=0;
		virtual void remove(T e)=0;
		virtual bool isEmpty()const=0;
		virtual int size()const=0;
		virtual void clear()=0;
		virtual void add(T e)=0;
		virtual bool contains(T e)=0;
	protected:
		/*
		@	functions that accept collections object.
			Theese are templated in the abstractcollection.h which is used to
			implementation file.
			By this, below example of function call can call.
			-> ArrList<int,std::vector> test1;
			-> ArrList<int,std::list> test2;
			-> test1.containsAll(test2); --> This will not work,If theese were
			not implemented like this.

			@ These methods are protected to avoid calling and seperating 
			  them. Intentionally not pure virtual.		  
		*/
		bool containsAll(collections<T,Container>& c);		
		bool removeAll(collections<T,Container>& c)throw(empty_param_container);
		bool retainAll(collections<T,Container>& c);
		void addAll(collections<T,Container>& c)throw(empty_param_container);
							
	};
}
#endif