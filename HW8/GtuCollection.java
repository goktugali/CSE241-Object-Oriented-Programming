/**
* This interface extends from Iterable interface to create relation which is "GtuCollection is a Iterable" for using collections
* in for-each loop statement provided by Java.
* This property is additional, not mentioned in the homework PDF.
* I add this because I want to use for-each loops.
* @author Goktug Akin
* @since 2019
* @version HW8
*/
public interface GtuCollection<T> extends Iterable<T>{

	/**
	* Returns an iterator over the elements in this collection. 
	*/
	public GtuIterator<T> iterator();
	/**
	* Ensures that this collection contains the specified element 
	* @param elem Element that will be added to this collection
	* @return true if this collection changed as a result of the call
	*/
	public boolean add(T elem);
	/**
	* Returns true if this collection contains the specified element. 
	* @param elem element whose presence in this collection is to be tested
	* @return true if this collection contains the specified element
	*/
	public boolean contains(T elem);
	/**
	* Returns true if this collection contains no elements.
	* @return true if this collection contains no elements.
	*/
	public boolean isEmpty();
	/**
	* Removes a single instance of the specified element from this collection.
	* @param elem element to be removed from this collection, if present
	* @return true if an element was removed as a result of this call
	*/
	public boolean remove(T elem);
	/**
	* Returns true if this collection contains all of the elements in the specified collection.
	* @param c collection to be checked for containment in this collection
	* @return true if this collection contains all of the elements in the specified collection
	*/
	public boolean containsAll(GtuCollection<T> c);
	/**
	* Adds all of the elements in the specified collection to this collection (optional operation)
	* @param c collection containing elements to be added to this collection
	* @return true if this collection changed as a result of the call
	*/
	public boolean addAll(GtuCollection<T> c);
	/**
	* Removes all of the elements from this collection (optional operation).
	*/
	public void clear();
	/**
	* Returns the number of elements in this collection.
	* @return the number of elements in this collection
	*/
	public int size();
	/**
	* Removes all of this collection's elements that are also contained in the specified collection.
	* @param c collection containing elements to be removed from this collection
	* @return true if this collection changed as a result of the call
	*/
	public boolean removeAll(GtuCollection<T> c);
	/**
	* Retains only the elements in this collection that are contained in the specified collection.
	* @param c collection containing elements to be retained in this collection
	* @return true if this collection changed as a result of the call
	*/
	public boolean retainAll(GtuCollection<T> c);
}