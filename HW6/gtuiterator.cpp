#include "gtuiterator.h"

namespace collectionsgtu{
	template<typename T,template <typename...>class Container>
	gtuiterator<T,Container>::gtuiterator(Container<T>* current) : iterating_container(current), _ptr(current->begin()) {}

	template<typename T,template <typename...>class Container>
	gtuiterator<T,Container>::gtuiterator(iterator ptr) : _ptr(ptr){}

	template<typename T,template <typename...>class Container>
	gtuiterator<T,Container>::gtuiterator(const gtuiterator<T,Container>& copy) : _ptr(copy._ptr), iterating_container(copy.iterating_container){/* */}

	template<typename T,template <typename...>class Container>
	gtuiterator<T,Container>& gtuiterator<T,Container>::operator=(const gtuiterator<T,Container>& other) {
		_ptr = other._ptr;
		iterating_container = other.iterating_container;
		return *this;
	}

	template<typename T,template <typename...>class Container>
	const T& gtuiterator<T,Container>::operator*() const noexcept {
		return *_ptr;
	}

	template<typename T,template <typename...>class Container>
	const T* gtuiterator<T,Container>::operator->() const noexcept {
		return _ptr;
	}

	template<typename T,template <typename...>class Container>
	bool gtuiterator<T,Container>::operator == (const gtuiterator &other) const noexcept{
		return this->_ptr == other._ptr;	
	}

	template<typename T,template <typename...>class Container>
	bool gtuiterator<T,Container>::operator != (const gtuiterator &other) const noexcept{
		return !(*this==other);
	}

	template<typename T,template <typename...>class Container>
	gtuiterator<T,Container>& gtuiterator<T,Container>::operator ++ () noexcept{
		_ptr++;
		return *this;
	}

	template<typename T,template <typename...>class Container>
	gtuiterator<T,Container> gtuiterator<T,Container>::operator ++ (int ignore) noexcept{
		gtuiterator tmp = *this;
		_ptr++;
		return tmp;
	}

	template<typename T,template <typename...>class Container>
	gtuiterator<T,Container>& gtuiterator<T,Container>::operator -- () noexcept{
		_ptr--;
		return *this;
	}

	template<typename T,template <typename...>class Container>
	gtuiterator<T,Container>& gtuiterator<T,Container>::operator -- (int ignore) noexcept{	
		gtuiterator tmp = *this;
		_ptr--;
		return tmp;
	}

	template<typename T,template <typename...>class Container>
	bool gtuiterator<T,Container>::hasNext()const {

		return _ptr!=iterating_container->end();
	}

	template<typename T,template <typename...>class Container>
	gtuiterator<T,Container>& gtuiterator<T,Container>::next(){
		_ptr++;
		return *this;
	}

	template<typename T,template <typename...>class Container>
	void gtuiterator<T,Container>::remove(){
		iterating_container->erase(_ptr);					
	}
}