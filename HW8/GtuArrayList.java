import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.NoSuchElementException;
import java.util.Iterator;

/*
*
*******************
*******************
*   CSE 241 HW8   *
* Goktug Ali Akin *
*******************
*******************
* Sources that i search about..
* https://stackoverflow.com/questions/529085/how-to-create-a-generic-array-in-java
* https://docs.oracle.com/javase/8/docs/api/java/util/ArrayList.html
***********************************************************************************/
/**
* @author Goktug Akin
* @since 2019
* @version HW8
*/
public class GtuArrayList<T> implements GtuList<T>{
		
	private T [] arr;
	private int capacity=0;
	private int used=0;
	private static final int GROW_SIZE=10;

	private void ensureCapacity()
	{	
		arr = Arrays.copyOf(arr,capacity+GROW_SIZE);
		capacity = capacity + GROW_SIZE;
	}

	/**
	* Default constructor initially creates with 10. 
	*/
	@SuppressWarnings("unchecked") // This statement added for Casting with generics arrays issues.
	public GtuArrayList()
	{
		this(10); // Delagation
	}
	/**
	* Constructor that accepts size value. User of this class, can construct with GtuArrayList(size) with initial size value.
	* @param capacityVal capacity value that will be initialized.
	* @param virtualParam is not acceptable parameter. Do not provide a value for that param.
	* @throws IllegalArgumentException If second paramater provided to this constructor.
	*/
	@SuppressWarnings("unchecked") // This statement added for Casting with generics arrays issues.
	public GtuArrayList(int capacityVal,T... virtualParam)
	{
		/*
		* This constructor can be called with this invocation : 
		* GtuArrayList(10); where 10 is size value. Instead of other constructor that accepts class type,
		* user can construct without giving class type.
		*
		* virtualParam is not real parameter, it just for trick that getting the T is type.
		* This algorithm is used for bad issues about "Generics Arrays" in Java language and handling this problem
		*/
		if(virtualParam.length > 0)
			throw new IllegalArgumentException("Do not provide value for virtualParam. It is not acceptable!");

		Class<?> type = virtualParam.getClass().getComponentType();
		arr = (T [])(Array.newInstance(type,capacityVal));
		used=0;
		capacity=capacityVal;
	}
	/**
	* Use can create GtuArrayList with GtuArrayList(className[].class) notation.
	* @param classType Parameter that describes the type that will be contained in ArrayList.
	*/
	public GtuArrayList(Class<T[]> classType)
	{
    	used=0;
    	capacity=1;
    	arr = classType.cast(Array.newInstance(classType.getComponentType(), 1));
	}
	/**
	* Returns an iterator over the ArrayList.
	* @return Iterator for iterating over the collection ArrayList.
	*/
	@Override
	public GtuIterator<T> iterator()
	{
		return new GtuArrayListIterator();
	}
	/**
	* Gets the size of (used) data location in ArrayList.
	* @return Size of the collection ArrayList.
	*/
	@Override
	public int size()
	{
		return used;
	}
	/**
	* Ensures that this collection contains the specified element
	* @param elem Element that will be added to this collection ArrayList.
	* @return true after adding.
	*/
	@Override
	public boolean add(T elem)
	{	
		if(used==capacity)
			ensureCapacity();
		
		arr[used]=elem;
		++used;
		return true;
	}
	/**
	* Inserts the specified element at the specified position in this list.
	* @param index index at which the specified element is to be inserted
	* @param elem element to be inserted.
	* @return true after adding.
	* @throws IndexOutOfBoundsException if the index is out of range.
	*/
	@SuppressWarnings("unchecked")// This statement added for Casting with generics arrays issues.
	@Override
	public boolean add(int index, T elem)throws IndexOutOfBoundsException
	{	
		if(index<0 || index>=this.size())
			throw new IndexOutOfBoundsException("param index is invalid");

		Class<?> t = arr.getClass().getComponentType();
		T [] temp_arr = (T [])(Array.newInstance(t, used));
		//T [] temp_arr = data_type.cast(Array.newInstance(data_type.getComponentType(), used));
		for (int i=0;i<used; ++i)
			temp_arr[i]=arr[i];
		if(used==capacity)
			ensureCapacity();

		int j=0;
		for (int i=0;i<this.size()+1;++i)
		{
			if(i==index)
				arr[i]=elem;
			else{
				arr[i]=temp_arr[j];
				++j;
			}	 
		}
		++used;		
		return true;
	}
	/**
	* Appends all of the elements in the specified collection to the end of this list.
	* @param c collection containing elements to be added to this list.
	* @return True if parameter collection succesfully added to this collection.
	*/
	@Override
	public boolean addAll(GtuCollection<T> c)
	{	
		if(c.size()==0)
			return false;
		GtuIterator<T> iter = c.iterator();
		while(iter.hasNext())
			this.add(iter.next());
		return true;	
	}
	/**
	* Removes all of the elements from this list. The list will be empty after this call returns.
	*/
	@Override
	public void clear()
	{	
		used = 0;
		capacity = 0;
		arr = null;
	}
	/**
	* Returns true if this list contains the specified element.
	* @param elem element whose presence in this list is to be tested.
	* @return true if this list contains the specified element
	*/
	@Override
	public boolean contains(T elem)
	{	
		GtuIterator<T> iter = this.iterator();
		while(iter.hasNext())
			if(iter.next().equals(elem))
				return true;

		return false;
	}
	/**
	* Returns true if this list contains all of elements in the parameter passed c collection.
	* @param c collection whose presence in this list is to be tested.
	* @return true if this list contains all of the elements in the parameter passed c collection.
	*/
	@Override
	public boolean containsAll(GtuCollection<T> c)
	{
		if(this.size() < c.size())
			return false;
		
		GtuIterator<T> iter = c.iterator();
		while(iter.hasNext())
			if(!this.contains(iter.next()))
				return false;	
		return true;	
	}
	/**
	* Couns the number of occurences by giving element.
	* @param elem Element whose occurence number in this list is to be tested.
	* @return Number of occurences of element gived by parameter elem.
	*/
	@Override
	public int count(T elem)
	{
		int count = 0;
		for (int i=0;i<used;++i)
			if(arr[i].equals(elem))
				count++;
		return count;	
	}
	/**
	* Replaces the element at the specified position in this list with the specified element.
	* @param index index of the element to replace
	* @param elem element to be stored at the specified position
	* @return the element previously at the specified position
	* @throws IndexOutOfBoundsException if the index is out of range 
	*/
	@Override
	public T set(int index,T elem)throws IndexOutOfBoundsException 
	{	
		if(index<0 || index>=this.size())
			throw new IndexOutOfBoundsException("param index is invalid");

		arr[index]=elem;
		return arr[index];
	}
	/**
	* Returns the element at the specified position in this list.
	* @param index index of the element to return
	* @return the element at the specified position in this list
	* @throws IndexOutOfBoundsException if the index is out of range 
	*/
	@Override
	public T get(int index)throws IndexOutOfBoundsException
	{
		if(index<0 || index>=this.size())
			throw new IndexOutOfBoundsException("param index is invalid");
		return arr[index];
	}
	/**
	* Returns the index of the first occurrence of the specified element in this list, or -1 if this list does not contain the element.
	* @param elem element to search for
	* @return the index of the first occurrence of the specified element in this list, or -1 if this list does not contain the element
	*/
	@Override
	public int indexOf(T elem)
	{
		for (int i=0;i<this.size();++i)
			if(arr[i]==elem)
				return i;
			
		return -1;
	}
	/**
	* If the list is empty, returns 1 , els return 0.
	* @return If the list is empty, returns 1 , els return 0.
	*/
	@Override
	public boolean isEmpty()
	{
		return (used==0) ? true : false;
	}
	/**
	* Removes the first occurrence of the specified element from this list, if it is present.
	* @param elem element to be removed from this list, if present
	* @return true if this list contained the specified element 
	*/
	@SuppressWarnings("unchecked")// This statement added for Casting with generics arrays issues.
	@Override
	public boolean remove(T elem)
	{
		if(!(this.contains(elem)) || used==0)
			return false;
		
		Class<?> t = arr.getClass().getComponentType();
		T [] temp_arr = (T[])(Array.newInstance(t, capacity-1));

		boolean resume = true;
		int foundIndex = -1;
		for (int i=0;i<used && resume;++i) {
			if(arr[i].equals(elem)){
				foundIndex=i;
				resume = false;
			}
		}
		int j=0;
		for (int i=0;i<used;++i){
			if(i!=foundIndex){
				temp_arr[j]=arr[i];
				++j;
			}	
		}

		used=used-1;
		arr = (T[])(Array.newInstance(t, capacity));
		for (int i=0;i<used; ++i) 
			arr[i]=temp_arr[i];

		return true;
	}
	/**
	* Removes from this list all of its elements that are contained in the specified collection.
	* @param c collection containing elements to be removed from this list
	* @return True if succesfully removed.
	*/
	@Override
	public boolean removeAll(GtuCollection<T> c)
	{	
		if(c.isEmpty() || this.isEmpty())
			return false;

		GtuIterator<T> iter = c.iterator();
		while(iter.hasNext()){
			T elem = iter.next();
			if(this.contains(elem))
				this.remove(elem);
		}
		return true;
	}
	/**
	* Retains only the elements in this list that are contained in the specified collection. In other words, removes from this list all of its elements that are not contained in the specified collection.
	* @param c collection containing elements to be retained in this list
	* @return true if this list changed as a result of the call
	*/
	@Override
	public boolean retainAll(GtuCollection<T> c)
	{
		if(c.isEmpty())
			return false;
		
		GtuIterator<T> iter = this.iterator();
		while(iter.hasNext())
			if(!c.contains(iter.next()))
				iter.remove();	
		return true;
	}
	@Override
	public String toString()
	{
		return String.format("GtuArrayList that contains %d elements", used);
	}
	private class GtuArrayListIterator implements GtuIterator<T>{

		int position=0;
		int lastRet=-1;
		@Override
		public boolean hasNext()
		{			
			if(position<used)	
				return true;
			return false;
		}
		@Override
		public T next()
		{	
			int i=position;
			position=i+1;
			lastRet=i;
			return arr[lastRet];
		}
		@Override
		public void remove()
		{	
			if(lastRet<0)
				throw new UnsupportedOperationException("Illegal usage of iterator! Must call next() before removing!");

			GtuArrayList.this.remove(arr[lastRet]);
			position=lastRet;
			lastRet=-1;
		}   	
	}		
}