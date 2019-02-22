import java.util.NoSuchElementException;
/*
*
*******************
*******************
*   CSE 241 HW8   *
* Goktug Ali Akin *
*******************
*******************
* Sources that i search about..
* https://docs.oracle.com/javase/7/docs/api/java/util/Queue.html
***********************************************************************************/

/**
* @author Goktug Akin
* @since 2019
* @version HW8
*/
public interface GtuQueue<T> extends GtuCollection<T>{

	/**
	* Returns an iterator over the elements in this collection. 
	* @return an Iterator over the elements in this collection
	*/
	public GtuIterator<T> iterator();
	/**
	* Inserts the specified element into this queue
	* @param elem the element to add
	* @return True after adding.
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
	* @return true if this collection contains no elements
	*/
	public boolean isEmpty();
	/**
	* Removes a single instance of the specified element from this collection
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
	* Adds all of the elements in the specified collection to this collection.
	* @param c collection containing elements to be added to this collection.
	* @return true if adding procces is succesfully finished.
	*/
	public boolean addAll(GtuCollection<T> c);
	/**
	* Removes all of the elements from this collection
	*/
	public void clear();
	/**
	* Retrieves the size of collection.
	* @return size of the collection.
	*/
	public int size();
	/**
	* Removes all of this collection's elements that are also contained in the specified collection
	* @param c collection containing elements to be removed from this collection
	* @return true if this collection changed as a result of the call.
	*/
	public boolean removeAll(GtuCollection<T> c);
	/**
	* Retains only the elements in this collection that are contained in the specified collection
	* @param c collection containing elements to be retained in this collection
	* @return true if the collection changed as a result of the call
	*/
	public boolean retainAll(GtuCollection<T> c);
	/**
	* Retrieves, but does not remove, the head (first element) of this list.
	* @return the head of this list
	* @throws NoSuchElementException If list is empty.
	*/
	public T element()throws NoSuchElementException;
	/**
	* Add element to the collection.
	* @param e Element that will be added to this collections.
	*/
	public void offer(T e);
	/**
	* Retrieves and removes the head (first element) of this list.
	* @return the head of this list.
	* @throws NoSuchElementException If list is empty.
	*/
	public T poll()throws NoSuchElementException;
}