#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_
#include "gtuiterator.h"
#include "list.h"

namespace collectionsgtu
{
	template<typename T,template <typename...> class Container>
	class ArrayList : public list<T,Container>
	{
	public:
		virtual gtuiterator<T,Container> iterator()override;
		virtual void remove(T e)override;
		virtual bool isEmpty()const override;
		virtual int size()const override{return _data.size();}
		virtual void clear()override{_data.clear();}
		virtual void add(T e)override;
		virtual	 bool contains(T e)override;
	private:
		Container<T> _data;	
	};
}
#endif