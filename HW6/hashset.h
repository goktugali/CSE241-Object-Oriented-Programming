#ifndef HASHET_H_
#define HASHET_H_
#include "set.h"

namespace collectionsgtu
{
	template<typename T,template <typename...> class Container>
	class HashSet : public set<T,Container>
	{
	public:
		virtual gtuiterator<T,Container> iterator()override;
		virtual void remove(T e)override;
		virtual bool isEmpty()const override;
		virtual int size()const override{return _data.size();}
		virtual void clear()override{_data.clear();}
		virtual void add(T e)override;
		virtual	bool contains(T e)override;
	private:
		Container<T> _data;
	};	
}
#endif