#ifndef ITERATOR_H_
#define ITERATOR_H_

namespace collectionsgtu
{
	template<typename T,template <typename...>class Container>
	class gtuiterator
	{

	using iterator = typename Container<T>::iterator;

	public:
		explicit gtuiterator(Container<T>* current);
		explicit gtuiterator(iterator ptr);
		gtuiterator(const gtuiterator& copy);
		gtuiterator& operator=(const gtuiterator& other);
		const T& operator*() const noexcept ;
		const T* operator->() const noexcept ;
		bool operator == (const gtuiterator &other) const noexcept;
		bool operator != (const gtuiterator &other) const noexcept;
		gtuiterator& operator ++ () noexcept;
		gtuiterator operator ++ (int ignore) noexcept;
		gtuiterator& operator -- () noexcept;
		gtuiterator& operator -- (int ignore) noexcept;
		bool hasNext()const ;
		gtuiterator& next();
		void remove();
	private:
		iterator _ptr;
		Container<T>* iterating_container;	
	};
}
#endif