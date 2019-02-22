/**
* @author Goktug Akin
* @since 2019
* @version HW8
*/
public interface GtuList<T> extends GtuCollection<T>
{	
	/**
	* Returns an iterator over the ArrayList.
	* @return Iterator for iterating over the collection List.
	*/
	public GtuIterator<T> iterator();
	/**
	* Ensures that this collection contains the specified element
	* @param elem Element that will be added to this collectionList.
	* @return true after adding.
	*/
	public boolean add(T elem);
	/**
	* Inserts the specified element at the specified position in this list.
	* @param index index at which the specified element is to be inserted
	* @param elem element to be inserted.
	* @return true after adding.
	* @throws IndexOutOfBoundsException if the index is out of range
	*/
	public boolean add(int index, T elem)throws IndexOutOfBoundsException;
	/**
	* Returns true if this list contains the specified element.
	* @param elem element whose presence in this list is to be tested.
	* @return true if this list contains the specified element
	*/
	public boolean contains(T elem);
	/**
	* If the list is empty, returns 1 , els return 0.
	* @return If the list is empty, returns 1 , els return 0.
	*/
	public boolean isEmpty();
	/**
	* Removes the first occurrence of the specified element from this list, if it is present.
	* @param elem element to be removed from this list, if present
	* @return true if this list contained the specified element 
	*/
	public boolean remove(T elem);
	/**
	* Returns true if this list contains all of elements in the parameter passed c collection.
	* @param c collection whose presence in this list is to be tested.
	* @return true if this list contains all of the elements in the parameter passed c collection.
	*/
	public boolean containsAll(GtuCollection<T> c);
	/**
	* Appends all of the elements in the specified collection to the end of this list.
	* @param c collection containing elements to be added to this list.
	* @return True if parameter collection succesfully added to this collection.
	*/
	public boolean addAll(GtuCollection<T> c);
	/**
	* Removes all of the elements from this list. The list will be empty after this call returns.
	*/
	public void clear();
	/**
	* Gets the size of (used) data location in ArrayList.
	* @return Size of the collection ArrayList.
	*/
	public int size();
	/**
	* Removes from this list all of its elements that are contained in the specified collection.
	* @param c collection containing elements to be removed from this list
	* @return True if succesfully removed.
	*/
	public boolean removeAll(GtuCollection<T> c);
	/**
	* Retains only the elements in this list that are contained in the specified collection. In other words, removes from this list all of its elements that are not contained in the specified collection.
	* @param c collection containing elements to be retained in this list
	* @return true if this list changed as a result of the call
	*/
	public boolean retainAll(GtuCollection<T> c);
	/**
	* Replaces the element at the specified position in this list with the specified element.
	* @param index index of the element to replace
	* @param elem element to be stored at the specified position
	* @return the element previously at the specified position
	* @throws IndexOutOfBoundsException if the index is out of range
	*/
	public T set(int index,T elem)throws IndexOutOfBoundsException; //additonal
	/**
	* Returns the element at the specified position in this list.
	* @param index index of the element to return
	* @return the element at the specified position in this list
	* @throws IndexOutOfBoundsException if the index is out of range
	*/
	public T get(int index)throws IndexOutOfBoundsException; //additonal
	/**
	* Returns the index of the first occurrence of the specified element in this list, or -1 if this list does not contain the element.
	* @param elem element to search for
	* @return the index of the first occurrence of the specified element in this list, or -1 if this list does not contain the element
	*/
	public int indexOf(T elem); //additonal
	/**
	* Couns the number of occurences by giving element.
	* @param elem Element whose occurence number in this list is to be tested.
	* @return Number of occurences of element gived by parameter elem.
	*/
	public int count(T elem); //additonal
}