#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include "queue.h"
#include "list.h"

namespace collectionsgtu
{
	template<typename T,template <typename...> class Container>
	class LinkedList : public list<T,Container>, public queue<T,Container>
	{
	public:
		virtual gtuiterator<T,Container> iterator()override;
		virtual void remove(T e)override;
		virtual bool isEmpty()const override;
		virtual int size()const override{return _data.size();}
		virtual void clear()override{_data.clear();}
		virtual void add(T e)override;
		virtual	bool contains(T e)override;
		virtual T element()throw(empty_container) override;
		virtual void offer(T e)override;
		virtual T poll()throw (empty_container) override;
	private:
		Container<T> _data;	
	};

}
#endif