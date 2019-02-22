/*
*
*******************
*******************
*   CSE 241 HW8   *
* Goktug Ali Akin *
*******************
*******************
* Sources that i search about..
* https://docs.oracle.com/javase/7/docs/api/java/util/Set.html#remove(java.lang.Object)
***********************************************************************************/

/**
* @author Goktug Akin
* @since 2019
* @version HW8
*/
public interface GtuSet<T> extends GtuCollection<T>{

	/**
	* Returns an iterator over the elements in this set.
	* @return an iterator over the elements in this set 
	*/
	public GtuIterator<T> iterator();
	/**
	* Adds the specified element to this set if it is not already present (optional operation).
	* @param elem element to be added to this set
	* @return true if this set did not already contain the specified element
	*/
	public boolean add(T elem);
	/**
	* Returns true if this set contains the specified element
	* @param elem element whose presence in this set is to be tested
	* @return true if this set contains the specified element
	*/
	public boolean contains(T elem);
	/**
	* Returns true if this set contains no elements.
	* @return true if this collection has no elements.
	*/
	public boolean isEmpty();
	/**
	* Removes the specified element from this set if it is present
	* @param elem object to be removed from this set, if present
	* @return true if this set contained the specified element
	*/
	public boolean remove(T elem);
	/**
	* Returns true if this set contains all of the elements of the specified collection. 
	* @param c collection to be checked for containment in this set
	* @return true if this set contains all of the elements of the specified collection
	*/
	public boolean containsAll(GtuCollection<T> c);
	/**
	* Adds all of the elements in the specified collection to this set if they're not already present
	* @param c collection containing elements to be added to this set
	* @return true if this set changed as a result of the call
	*/
	public boolean addAll(GtuCollection<T> c);
	/**
	* Removes all of the elements from this set
	*/
	public void clear();
	/**
	* Returns the number of elements in this set
	* @return the number of elements in this set (its cardinality)
	*/
	public int size();
	/**
	* Removes from this set all of its elements that are contained in the specified collection
	* @param c collection containing elements to be removed from this set
	* @return true if this set changed as a result of the call
	*/
	public boolean removeAll(GtuCollection<T> c);
	/**
	* Retains only the elements in this set that are contained in the specified collection
	* @param c collection containing elements to be retained in this set
	* @return true if this set changed as a result of the call
	*/
	public boolean retainAll(GtuCollection<T> c);

}