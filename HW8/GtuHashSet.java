import java.lang.reflect.Array;
import java.util.Arrays;

/*
*
*******************
*******************
*   CSE 241 HW8   *
* Goktug Ali Akin *
*******************
*******************
* Sources that i search about..
* https://docs.oracle.com/javase/7/docs/api/java/util/Set.html
***********************************************************************************/

/**
* @author Goktug Akin
* @since 2019
* @version HW8
*/
public class GtuHashSet<T> implements GtuSet<T>{

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
	public GtuHashSet()
	{
		this(10); // Delagation
	}
	/**
	* Constructor that accepts size value. User of this class, can construct with GtuHashSet(size) with initial size value.
	* @param capacityVal capacity value that will be initialized.
	* @param virtualParam is not acceptable parameter. Do not provide a value for that param.
	* @throws IllegalArgumentException If second paramater provided to this constructor.
	*/
	@SuppressWarnings("unchecked") // This statement added for Casting with generics arrays issues.
	public GtuHashSet(int capacityVal,T... virtualParam)
	{
		/*
		* This constructor can be called with this invocation : 
		* GtuHashSet(10); where 10 is size value. Instead of other constructor that accepts class type,
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
	* Use can create GtuHashSet with GtuHashSet(className[].class) notation.
	* @param classType Parameter that describes the type that will be contained in ArrayList.
	*/
	public GtuHashSet(Class<T[]> classType)
	{
    	used=0;
    	capacity=1;
    	arr = classType.cast(Array.newInstance(classType.getComponentType(), 1));
	}
	/**
	* Returns an iterator over the elements in this set.
	* @return an Iterator over the elements in this set
	*/
	@Override
	public GtuIterator<T> iterator()
	{
		return new GtuHashSetIterator();
	}
	/**
	* Returns the number of elements in this set (its cardinality).
	* @return the number of elements in this set (its cardinality)
	*/
	@Override
	public int size()
	{
		return used;
	}
	/**
	* Adds the specified element to this set if it is not already present.If this set already contains the element, the call leaves the set unchanged and returns false.
	* @param elem element to be added to this set
	* @return true if this set did not already contain the specified element
	*/
	@Override
	public boolean add(T elem)
	{	
		if(this.contains(elem))
			return false;

		if(used==capacity)
			ensureCapacity();
		
		arr[used]=elem;
		++used;
		return true;
	}
	/**
	* Adds all of the elements in the specified collection to this set if they're not already present
	* @param c collection containing elements to be added to this set
	* @return true if this set changed as a result of the call
	*/
	@Override
	public boolean addAll(GtuCollection<T> c)
	{	
		if(c.isEmpty())
			return false;

		GtuIterator<T> iter = c.iterator();
		while(iter.hasNext())
			this.add(iter.next());	
		return true;
	}
	/**
	* Removes all of the elements from this set (optional operation).
	*/
	@Override
	public void clear()
	{	
		used = 0;
		capacity = 0;
		arr=null;
	}
	/**
	* Returns true if this set contains the specified element.
	* @param elem element whose presence in this set is to be tested
	* @return true if this set contains the specified element
	*/
	@Override
	public boolean contains(T elem)
	{	
		GtuIterator<T> iter = this.iterator();
		while(iter.hasNext())
			if(elem.equals(iter.next()))
				return true;
		return false;
	}
	/**
	* Returns true if this set contains all of the elements of the specified collection.
	* @param c collection to be checked for containment in this set
	* @return true if this set contains all of the elements of the specified collection
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
	* Returns the if set is empty.
	* @return True if set is empty.
	*/
	@Override
	public boolean isEmpty()
	{
		return (used==0) ? true : false;
	}
	/**
	* Removes the specified element from this set if it is present
	* @param elem object to be removed from this set, if present
	* @return true if this set contained the specified element
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
	* Removes from this set all of its elements that are contained in the specified collection
	* @param c - collection containing elements to be removed from this set
	* @return true if this set changed as a result of the call
	*/
	@Override
	public boolean removeAll(GtuCollection<T> c)
	{	
		if(c.isEmpty() || this.isEmpty())
			return false;

		GtuIterator<T> iter = c.iterator();
		while(iter.hasNext())
		{
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
		return String.format("GtuHashSet that contains %d elements", used);
	}
	private class GtuHashSetIterator implements GtuIterator<T>{

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
		public void remove()throws UnsupportedOperationException
		{
			if(lastRet<0)
				throw new UnsupportedOperationException("Illegal usage of iterator!");

			GtuHashSet.this.remove(arr[lastRet]);
			position=lastRet;
			lastRet=-1;
		}	
	}
}