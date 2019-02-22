import java.util.ArrayList;

public class DriverApp{

	public static final String ANSI_RESET = "\u001B[0m";
	public static final String ANSI_RED = "\u001B[31m";
	public static final String ANSI_GREEN = "\u001B[32m";

	public static void main(String[] args) {

		System.out.println("This program tests Custom Java Collection Containers.");
		System.out.println("Every method will be called, and our expectations and results will printed to compare.");
		System.out.println("------------------------------------------------------------");
		System.out.println(ANSI_GREEN+"Information messages about which method calls in which situations prints green.");
		System.out.println(ANSI_RED+"If any error occurs, or in testing exceptions method, error messages prints red."+ANSI_RESET);

		boolean errorOccured = false;

		try
		{
			System.out.println("------------------------------------------------------------");
			System.out.println("------------------------------------------------------------\n");
			test_ArrayList_Int();
			System.out.println("\n------------------------------------------------------------");
			System.out.println("------------------------------------------------------------\n");
			test_ArrayList_String();
			System.out.println("\n------------------------------------------------------------");
			System.out.println("------------------------------------------------------------\n");
			test_GtuHashSet_Int();
			System.out.println("\n------------------------------------------------------------");
			System.out.println("------------------------------------------------------------\n");
			test_GtuHashSet_String();
			System.out.println("\n------------------------------------------------------------");
			System.out.println("------------------------------------------------------------\n");
			test_GtuLinkedList_Int();
			System.out.println("\n------------------------------------------------------------");
			System.out.println("------------------------------------------------------------\n");
			test_GtuLinkedList_String();
			System.out.println("\n------------------------------------------------------------");
			System.out.println("------------------------------------------------------------\n");
		}
		catch(Exception ex)
		{
			System.out.println("Error occured : " + ex.getMessage());
			errorOccured=true;
		}
		finally
		{
			System.out.println("Container tests are Finished. ");
			if(errorOccured)
				System.out.println(ANSI_RED+"Error occured"+ANSI_RESET);
			else
				System.out.println(ANSI_GREEN+"No Error occured" + ANSI_RESET);			
		}

		System.out.println("\n------------------------------------------------------------");
		System.out.println("------------------------------------------------------------");
		test_exceptions();
		System.out.println("------------------------------------------------------------");
		System.out.println("------------------------------------------------------------");
		System.out.println(ANSI_GREEN +"All tests are finished, please scroll up and see the test results." + ANSI_RESET);
		
	}

	public static void test_ArrayList_Int()
	{
		System.out.println(ANSI_GREEN + "#######  Testing GtuArrayList container with Integer.  #######" + ANSI_RESET);
		System.out.println("Initalize with different constructors : \n");
		System.out.println("# We have arrlist1 that constructed with no Parameter constructor.");
		System.out.println(">GtuArrayList<Integer>()");
		System.out.println("# We have arrlist2 that constructed with one Parameter ctor that accepts sizeValue");
		System.out.println(">GtuArrayList<Integer>(10)");
		System.out.println("# We have arrlist3 that constructed with one Parameter ctor that accepts class type");
		System.out.println(">GtuArrayList<Integer>(Integer[].class)");

		GtuArrayList<Integer> arrlist1 = new GtuArrayList<Integer>();
		GtuArrayList<Integer> arrlist2 = new GtuArrayList<Integer>(10);
		GtuArrayList<Integer> arrlist3 = new GtuArrayList<Integer>(Integer[].class);
		System.out.println("------");
		System.out.println("Firstly, printing their sizes :");
		System.out.printf("arrlist1 : %d , arrlist2 : %d, arrlist3 : %d\n",arrlist1.size(),arrlist2.size(),arrlist3.size());

		for (int i=0;i<15;++i) 
			arrlist1.add(i);

		for (int i=0;i<10;++i) 
			arrlist2.add(i);

		for (int i=0;i<5;++i) 
			arrlist3.add(i);
		
		System.out.printf(ANSI_GREEN+"-> Some integers added to theese list --add(T element)-- method tested\n"+ANSI_RESET);
		System.out.printf(ANSI_GREEN+"-> While printing, --get(int index)-- method tested\n"+ANSI_RESET);

		System.out.printf("arrlist1 : ");
		for (int i=0;i<arrlist1.size();++i) 
			System.out.printf("%d ",arrlist1.get(i));
		System.out.println("");
		System.out.printf("arrlist2 : ");
		for (int i=0;i<arrlist2.size();++i) 
			System.out.printf("%d ",arrlist2.get(i));
		System.out.println("");
				System.out.printf("arrlist3 : ");
		for (int i=0;i<arrlist3.size();++i) 
		System.out.printf("%d ",arrlist3.get(i));
		System.out.println("");
		System.out.println("------");
		System.out.println(ANSI_GREEN+"-> --containsAll(GtuCollection<T> c)-- tested."+ANSI_RESET);
		System.out.println("This method uses, --contains(T elem)-- method inside");
		System.out.println("If any unexpected behaviour occurs, error message will print with error format.\n");
		System.out.println(">arrlist1.containsAll(arrlist2) invoked");
		System.out.println(">arrlist2.containsAll(arrlist3) invoked");
		if(!arrlist1.containsAll(arrlist2))
			System.out.println(ANSI_RED+"Error occured : arrlist1.containsAll(arrlist2)");
		if(!arrlist2.containsAll(arrlist3))
			System.out.println(ANSI_RED+"Error occured : arrlist2.containsAll(arrlist3)");
		System.out.println("------");
		System.out.println(ANSI_GREEN+"-> --removeAll(GtuCollection<T> c)-- tested."+ANSI_RESET);
		System.out.println("This method uses, --remove(T elem)-- method inside.\n");
		System.out.println(">arrlist1.removeAll(arrlist2)");
		System.out.println(">arrlist2.removeAll(arrlist3)");
		System.out.println("After This, printing the arrlists: \n");
		arrlist1.removeAll(arrlist2);
		arrlist2.removeAll(arrlist3);
		System.out.printf("arrlist1 : ");
		for (int i=0;i<arrlist1.size();++i) 
			System.out.printf("%d ",arrlist1.get(i));
		System.out.println("");
		System.out.printf("arrlist2 : ");
		for (int i=0;i<arrlist2.size();++i) 
			System.out.printf("%d ",arrlist2.get(i));
		System.out.println("");
		System.out.println("------");
		System.out.println(ANSI_GREEN+"-> --addAll(GtuCollection<T> c)-- tested."+ANSI_RESET);
		System.out.println(">arrlist1.addAll(arrlist2) invoked");
		System.out.println(">arrlist2.addAll(arrlist3) invoked");
		System.out.println("After This, printing the arrlists: \n");
		arrlist1.addAll(arrlist2);
		arrlist2.addAll(arrlist3);
		System.out.printf("arrlist1 : ");
		for (int i=0;i<arrlist1.size();++i) 
			System.out.printf("%d ",arrlist1.get(i));
		System.out.println("");
		System.out.printf("arrlist2 : ");
		for (int i=0;i<arrlist2.size();++i) 
			System.out.printf("%d ",arrlist2.get(i));
		System.out.println("");
		System.out.println("------");
		System.out.println(ANSI_GREEN+"-> --retainAll(GtuCollection<T> c)-- tested."+ANSI_RESET);
		System.out.println("This method uses, --remove(T elem)-- method inside.\n");
		System.out.println(">arrlist1.retainAll(arrlist2) invoked");
		System.out.println(">arrlist2.retainAll(arrlist3) invoked");
		System.out.println("After This, printing the arrlists: \n");
		arrlist1.retainAll(arrlist2);
		arrlist2.retainAll(arrlist3);
		System.out.println("------");
		System.out.printf("arrlist1 : ");
		for (int i=0;i<arrlist1.size();++i) 
			System.out.printf("%d ",arrlist1.get(i));
		System.out.println("");
		System.out.printf("arrlist2 : ");
		for (int i=0;i<arrlist2.size();++i) 
			System.out.printf("%d ",arrlist2.get(i));
		System.out.println("");
		System.out.println("------");
		System.out.println(ANSI_GREEN+"Since GtuArrayList is a Iterable, we can use for each loop to print."+ANSI_RESET);
		System.out.println(ANSI_GREEN+"This property is additonal, Not menitoned in the HomeWork PDF."+ANSI_RESET);
		System.out.println("Print arrlist1 by for each :");
		System.out.printf("arrlist1 : ");
		for (int obj : arrlist1)
			System.out.printf("%d ",obj);
		System.out.println("");
		
	}
	public static void test_ArrayList_String()
	{
		System.out.println(ANSI_GREEN + "#######  Testing GtuArrayList container with String.  #######" + ANSI_RESET);
		System.out.println("* In String testing, to write easy code for me, Integers are converted to Strings");
		System.out.println("By Integer.toString(int) , we have strings like \"1\" , \"2\" ... \n");
		System.out.println("Initalize with different constructors : \n");
		System.out.println("# We have arrlist1 that constructed with no Parameter constructor.");
		System.out.println(">GtuArrayList<String>()");
		System.out.println("# We have arrlist2 that constructed with one Parameter ctor that accepts sizeValue");
		System.out.println(">GtuArrayList<String>(10)");
		System.out.println("# We have arrlist3 that constructed with one Parameter ctor that accepts class type");
		System.out.println(">GtuArrayList<String>(String[].class)");

		GtuArrayList<String> arrlist1 = new GtuArrayList<String>();
		GtuArrayList<String> arrlist2 = new GtuArrayList<String>(10);
		GtuArrayList<String> arrlist3 = new GtuArrayList<String>(String[].class);
		System.out.println("------");
		System.out.println("Firstly, printing their sizes :");
		System.out.printf("arrlist1 : %d , arrlist2 : %d, arrlist3 : %d\n",arrlist1.size(),arrlist2.size(),arrlist3.size());

		for (int i=0;i<15;++i) 
			arrlist1.add(Integer.toString(i));

		for (int i=0;i<10;++i) 
			arrlist2.add(Integer.toString(i));

		for (int i=0;i<5;++i) 
			arrlist3.add(Integer.toString(i));
		
		System.out.printf(ANSI_GREEN+"-> Some integers added to theese list --add(T element)-- method tested\n"+ANSI_RESET);
		System.out.printf(ANSI_GREEN+"-> While printing, --get(int index)-- method tested\n"+ANSI_RESET);

		System.out.printf("arrlist1 : ");
		for (int i=0;i<arrlist1.size();++i) 
			System.out.printf("%s ",arrlist1.get(i));
		System.out.println("");
		System.out.printf("arrlist2 : ");
		for (int i=0;i<arrlist2.size();++i) 
			System.out.printf("%s ",arrlist2.get(i));
		System.out.println("");
				System.out.printf("arrlist3 : ");
		for (int i=0;i<arrlist3.size();++i) 
		System.out.printf("%s ",arrlist3.get(i));
		System.out.println("");
		System.out.println("------");
		System.out.println(ANSI_GREEN+"-> --containsAll(GtuCollection<T> c)-- tested."+ANSI_RESET);
		System.out.println("This method uses, --contains(T elem)-- method inside");
		System.out.println("If any unexpected behaviour occurs, error message will print with error format.\n");
		System.out.println(">arrlist1.containsAll(arrlist2) invoked");
		System.out.println(">arrlist2.containsAll(arrlist3) invoked");
		if(!arrlist1.containsAll(arrlist2))
			System.out.println(ANSI_RED+"Error occured : arrlist1.containsAll(arrlist2)");
		if(!arrlist2.containsAll(arrlist3))
			System.out.println(ANSI_RED+"Error occured : arrlist2.containsAll(arrlist3)");
		System.out.println("------");
		System.out.println(ANSI_GREEN+"-> --removeAll(GtuCollection<T> c)-- tested."+ANSI_RESET);
		System.out.println("This method uses, --remove(T elem)-- method inside.\n");
		System.out.println(">arrlist1.removeAll(arrlist2)");
		System.out.println(">arrlist2.removeAll(arrlist3)");
		System.out.println("After This, printing the arrlists: \n");
		arrlist1.removeAll(arrlist2);
		arrlist2.removeAll(arrlist3);
		System.out.printf("arrlist1 : ");
		for (int i=0;i<arrlist1.size();++i) 
			System.out.printf("%s ",arrlist1.get(i));
		System.out.println("");
		System.out.printf("arrlist2 : ");
		for (int i=0;i<arrlist2.size();++i) 
			System.out.printf("%s ",arrlist2.get(i));
		System.out.println("");
		System.out.println("------");
		System.out.println(ANSI_GREEN+"-> --addAll(GtuCollection<T> c)-- tested."+ANSI_RESET);
		System.out.println(">arrlist1.addAll(arrlist2) invoked");
		System.out.println(">arrlist2.addAll(arrlist3) invoked");
		System.out.println("After This, printing the arrlists: \n");
		arrlist1.addAll(arrlist2);
		arrlist2.addAll(arrlist3);
		System.out.printf("arrlist1 : ");
		for (int i=0;i<arrlist1.size();++i) 
			System.out.printf("%s ",arrlist1.get(i));
		System.out.println("");
		System.out.printf("arrlist2 : ");
		for (int i=0;i<arrlist2.size();++i) 
			System.out.printf("%s ",arrlist2.get(i));
		System.out.println("");
		System.out.println("------");
		System.out.println(ANSI_GREEN+"-> --retainAll(GtuCollection<T> c)-- tested."+ANSI_RESET);
		System.out.println("This method uses, --remove(T elem)-- method inside.\n");
		System.out.println(">arrlist1.retainAll(arrlist2) invoked");
		System.out.println(">arrlist2.retainAll(arrlist3) invoked");
		System.out.println("After This, printing the arrlists: \n");
		arrlist1.retainAll(arrlist2);
		arrlist2.retainAll(arrlist3);
		System.out.printf("arrlist1 : ");
		for (int i=0;i<arrlist1.size();++i) 
			System.out.printf("%s ",arrlist1.get(i));
		System.out.println("");
		System.out.printf("arrlist2 : ");
		for (int i=0;i<arrlist2.size();++i) 
			System.out.printf("%s ",arrlist2.get(i));
		System.out.println("");
		System.out.println("------");
		System.out.println(ANSI_GREEN+"Since GtuArrayList is a Iterable, we can use for each loop to print."+ANSI_RESET);
		System.out.println(ANSI_GREEN+"This property is additonal, Not menitoned in the HomeWork PDF."+ANSI_RESET);
		System.out.println("Print arrlist1 by for each :");
		System.out.printf("arrlist1 : ");
		for (String obj : arrlist1)
			System.out.printf("%s ",obj);
		System.out.println("");
	}
	public static void test_GtuHashSet_Int()
	{
		System.out.println(ANSI_GREEN + "#######  Testing GtuHashSet container with Integer.  #######" + ANSI_RESET);
		System.out.println("Initalize with different constructors : \n");
		System.out.println("# We have arrlist1 that constructed with no Parameter constructor.");
		System.out.println(">GtuHashSet<Integer>()");
		System.out.println("# We have arrlist2 that constructed with one Parameter ctor that accepts sizeValue");
		System.out.println(">GtuHashSet<Integer>(10)");
		System.out.println("# We have arrlist3 that constructed with one Parameter ctor that accepts class type");
		System.out.println(">GtuHashSet<Integer>(Integer[].class)");
		System.out.println("In printig, for-each for loop used. This is additonal, I implement Iterable interface");

		GtuHashSet<Integer> hashset1 = new GtuHashSet<Integer>();
		GtuHashSet<Integer> hashset2 = new GtuHashSet<Integer>(10);
		GtuHashSet<Integer> hashset3 = new GtuHashSet<Integer>(Integer[].class);
		System.out.println("------");
		System.out.println("Firstly, printing their sizes :");
		System.out.printf("hashset1 : %d , hashset2 : %d, hashset3 : %d\n",hashset1.size(),hashset2.size(),hashset3.size());

		for (int i=0;i<15;++i) 
			hashset1.add(i);

		for (int i=0;i<10;++i) 
			hashset2.add(i);

		for (int i=0;i<5;++i) 
			hashset3.add(i);
		
		System.out.printf(ANSI_GREEN+"-> Some integers added to theese list --add(T element)-- method tested\n"+ANSI_RESET);
		System.out.printf(ANSI_GREEN+"-> While printing, --get(int index)-- method tested\n"+ANSI_RESET);

		System.out.printf("hashset1 : ");
		for (int t : hashset1) 
			System.out.printf("%d ",t);
		System.out.println("");
		System.out.printf("hashset2 : ");
		for (int t : hashset2) 
			System.out.printf("%d ",t);
		System.out.println("");
		System.out.printf("hashset3 : ");
		for (int t : hashset3) 
			System.out.printf("%d ",t);
		System.out.println("");
		System.out.println("------");

		System.out.println(ANSI_GREEN+"-> --containsAll(GtuCollection<T> c)-- tested."+ANSI_RESET);
		System.out.println("This method uses, --contains(T elem)-- method inside");
		System.out.println("If any unexpected behaviour occurs, error message will print with error format.\n");
		System.out.println(">hashset1.containsAll(hashset2) invoked");
		System.out.println(">hashset2.containsAll(hashset3) invoked");
		if(!hashset1.containsAll(hashset2))
			System.out.println(ANSI_RED+"Error occured : hashset1.containsAll(hashset2)");
		if(!hashset2.containsAll(hashset3))
			System.out.println(ANSI_RED+"Error occured : hashset2.containsAll(hashset3)");
		System.out.println("------");
		System.out.println(ANSI_GREEN+"-> --removeAll(GtuCollection<T> c)-- tested."+ANSI_RESET);
		System.out.println("This method uses, --remove(T elem)-- method inside.\n");
		System.out.println(">hashset1.removeAll(hashset2)");
		System.out.println(">hashset2.removeAll(hashset3)");
		System.out.println("After This, printing the hashsets: \n");
		hashset1.removeAll(hashset2);
		hashset2.removeAll(hashset3);
		System.out.printf("hashset1 : ");
		for (int t : hashset1) 
			System.out.printf("%d ",t);
		System.out.println("");
		System.out.printf("hashset2 : ");
		for (int t : hashset2) 
			System.out.printf("%d ",t);
		System.out.println("");
		System.out.println("------");
		System.out.println(ANSI_GREEN+"-> --addAll(GtuCollection<T> c)-- tested."+ANSI_RESET);
		System.out.println(">hashset1.addAll(hashset2) invoked");
		System.out.println(">hashset2.addAll(hashset3) invoked");
		System.out.println("After This, printing the hashsets: \n");
		hashset1.addAll(hashset2);
		hashset2.addAll(hashset3);
		System.out.printf("hashset1 : ");
		for (int t : hashset1) 
			System.out.printf("%d ",t);
		System.out.println("");
		System.out.printf("hashset2 : ");
		for (int t : hashset2) 
			System.out.printf("%d ",t);
		System.out.println("");
		System.out.println("------");
		System.out.println(ANSI_GREEN+"-> --retainAll(GtuCollection<T> c)-- tested."+ANSI_RESET);
		System.out.println("This method uses, --remove(T elem)-- method inside.\n");
		System.out.println(">hashset1.retainAll(hashset2) invoked");
		System.out.println(">hashset2.retainAll(hashset3) invoked");
		System.out.println("After This, printing the hashsets: \n");
		hashset1.retainAll(hashset2);
		hashset2.retainAll(hashset3);
		System.out.println("------");
		System.out.printf("hashset1 : ");
		for (int t : hashset1) 
			System.out.printf("%d ",t);
		System.out.println("");
		System.out.printf("hashset2 : ");
		for (int t : hashset2) 
			System.out.printf("%d ",t);
		System.out.println("");
		System.out.println("------");
		System.out.println("Special test for GtuHashSet container. Sets do not accept duplicating elements");
		System.out.println("hashset1.add(5) and hashset1.add(6) called. We expect, no adding .");
		System.out.println("After adding hashet1 : ");
		hashset1.add(5);
		hashset1.add(6);
		for (int x : hashset1) 
			System.out.printf("%d ",x);
		System.out.println();
		System.out.println("------");
	}

	public static void test_GtuHashSet_String()
	{
		System.out.println(ANSI_GREEN + "#######  Testing GtuHashSet container with String.  #######" + ANSI_RESET);
		System.out.println("* In String testing, to write easy code for me, Integers are converted to Strings");
		System.out.println("By Integer.toString(int) , we have strings like \"1\" , \"2\" ... \n");
		System.out.println("Initalize with different constructors : \n");
		System.out.println("# We have arrlist1 that constructed with no Parameter constructor.");
		System.out.println(">GtuHashSet<Integer>()");
		System.out.println("# We have arrlist2 that constructed with one Parameter ctor that accepts sizeValue");
		System.out.println(">GtuHashSet<Integer>(10)");
		System.out.println("# We have arrlist3 that constructed with one Parameter ctor that accepts class type");
		System.out.println(">GtuHashSet<Integer>(Integer[].class)");
		System.out.println("In printig, for-each for loop used. This is additonal, I implement Iterable interface");

		GtuHashSet<String> hashset1 = new GtuHashSet<String>();
		GtuHashSet<String> hashset2 = new GtuHashSet<String>(10);
		GtuHashSet<String> hashset3 = new GtuHashSet<String>(String[].class);
		System.out.println("------");
		System.out.println("Firstly, printing their sizes :");
		System.out.printf("hashset1 : %d , hashset2 : %d, hashset3 : %d\n",hashset1.size(),hashset2.size(),hashset3.size());

		for (int i=0;i<15;++i) 
			hashset1.add(Integer.toString(i));

		for (int i=0;i<10;++i) 
			hashset2.add(Integer.toString(i));

		for (int i=0;i<5;++i) 
			hashset3.add(Integer.toString(i));
		
		System.out.printf(ANSI_GREEN+"-> Some integers added to theese list --add(T element)-- method tested\n"+ANSI_RESET);
		System.out.printf(ANSI_GREEN+"-> While printing, --get(int index)-- method tested\n"+ANSI_RESET);

		System.out.printf("hashset1 : ");
		for (String t : hashset1) 
			System.out.printf("%s ",t);
		System.out.println("");
		System.out.printf("hashset2 : ");
		for (String t : hashset2) 
			System.out.printf("%s ",t);
		System.out.println("");
		System.out.printf("hashset3 : ");
		for (String t : hashset3) 
			System.out.printf("%s ",t);
		System.out.println("");
		System.out.println("------");

		System.out.println(ANSI_GREEN+"-> --containsAll(GtuCollection<T> c)-- tested."+ANSI_RESET);
		System.out.println("This method uses, --contains(T elem)-- method inside");
		System.out.println("If any unexpected behaviour occurs, error message will print with error format.\n");
		System.out.println(">hashset1.containsAll(hashset2) invoked");
		System.out.println(">hashset2.containsAll(hashset3) invoked");
		if(!hashset1.containsAll(hashset2))
			System.out.println(ANSI_RED+"Error occured : hashset1.containsAll(hashset2)");
		if(!hashset2.containsAll(hashset3))
			System.out.println(ANSI_RED+"Error occured : hashset2.containsAll(hashset3)");
		System.out.println("------");
		System.out.println(ANSI_GREEN+"-> --removeAll(GtuCollection<T> c)-- tested."+ANSI_RESET);
		System.out.println("This method uses, --remove(T elem)-- method inside.\n");
		System.out.println(">hashset1.removeAll(hashset2)");
		System.out.println(">hashset2.removeAll(hashset3)");
		System.out.println("After This, printing the hashsets: \n");
		hashset1.removeAll(hashset2);
		hashset2.removeAll(hashset3);
		System.out.printf("hashset1 : ");
		for (String t : hashset1) 
			System.out.printf("%s ",t);
		System.out.println("");
		System.out.printf("hashset2 : ");
		for (String t : hashset2) 
			System.out.printf("%s ",t);
		System.out.println("");
		System.out.println("------");
		System.out.println(ANSI_GREEN+"-> --addAll(GtuCollection<T> c)-- tested."+ANSI_RESET);
		System.out.println(">hashset1.addAll(hashset2) invoked");
		System.out.println(">hashset2.addAll(hashset3) invoked");
		System.out.println("After This, printing the hashsets: \n");
		hashset1.addAll(hashset2);
		hashset2.addAll(hashset3);
		System.out.printf("hashset1 : ");
		for (String t : hashset1) 
			System.out.printf("%s ",t);
		System.out.println("");
		System.out.printf("hashset2 : ");
		for (String t : hashset2) 
			System.out.printf("%s ",t);
		System.out.println("");
		System.out.println("------");
		System.out.println(ANSI_GREEN+"-> --retainAll(GtuCollection<T> c)-- tested."+ANSI_RESET);
		System.out.println("This method uses, --remove(T elem)-- method inside.\n");
		System.out.println(">hashset1.retainAll(hashset2) invoked");
		System.out.println(">hashset2.retainAll(hashset3) invoked");
		System.out.println("After This, printing the hashsets: \n");
		hashset1.retainAll(hashset2);
		hashset2.retainAll(hashset3);
		System.out.println("------");
		System.out.printf("hashset1 : ");
		for (String t : hashset1) 
			System.out.printf("%s ",t);
		System.out.println("");
		System.out.printf("hashset2 : ");
		for (String t : hashset2) 
			System.out.printf("%s ",t);
		System.out.println("");
		System.out.println("------");
		System.out.println("Special test for GtuHashSet container. Sets do not accept duplicating elements");
		System.out.println("hashset1.add(\"5\") and hashset1.add(\"6\") called. We expect, no adding .");
		System.out.println("After adding hashet1 : ");
		hashset1.add("5");
		hashset1.add("6");
		for (String x : hashset1) 
			System.out.printf("%s ",x);
		System.out.println();
		System.out.println("------");
	}

	public static void test_GtuLinkedList_Int()
	{

		System.out.println(ANSI_GREEN + "#######  Testing GtuLinkedList container with Integer.  #######" + ANSI_RESET);
		System.out.println("Initalize with different constructors : \n");
		System.out.println("# We have arrlist1 that constructed with no Parameter constructor.");
		System.out.println(">GtuLinkedList<Integer>()");
		System.out.println("# We have arrlist2 that constructed with one Parameter ctor that accepts sizeValue");
		System.out.println(">GtuLinkedList<Integer>(10)");
		System.out.println("# We have arrlist3 that constructed with one Parameter ctor that accepts class type");
		System.out.println(">GtuLinkedList<Integer>(Integer[].class)");

		GtuLinkedList<Integer> linkedlist1 = new GtuLinkedList<Integer>();
		GtuLinkedList<Integer> linkedlist2 = new GtuLinkedList<Integer>(10);
		GtuLinkedList<Integer> linkedlist3 = new GtuLinkedList<Integer>(Integer[].class);
		System.out.println("------");
		System.out.println("Firstly, printing their sizes :");
		System.out.printf("linkedlist1 : %d , linkedlist2 : %d, linkedlist3 : %d\n",linkedlist1.size(),linkedlist2.size(),linkedlist3.size());

		for (int i=0;i<15;++i) 
			linkedlist1.add(i);

		for (int i=0;i<10;++i) 
			linkedlist2.add(i);

		for (int i=0;i<5;++i) 
			linkedlist3.add(i);
		
		System.out.printf(ANSI_GREEN+"-> Some integers added to theese list --add(T element)-- method tested\n"+ANSI_RESET);
		System.out.printf(ANSI_GREEN+"-> While printing, --get(int index)-- method tested\n"+ANSI_RESET);

		System.out.printf("linkedlist1 : ");
		for (int i=0;i<linkedlist1.size();++i) 
			System.out.printf("%d ",linkedlist1.get(i));
		System.out.println("");
		System.out.printf("linkedlist2 : ");
		for (int i=0;i<linkedlist2.size();++i) 
			System.out.printf("%d ",linkedlist2.get(i));
		System.out.println("");
				System.out.printf("linkedlist3 : ");
		for (int i=0;i<linkedlist3.size();++i) 
		System.out.printf("%d ",linkedlist3.get(i));
		System.out.println("");
		System.out.println("------");
		System.out.println(ANSI_GREEN+"-> --containsAll(GtuCollection<T> c)-- tested."+ANSI_RESET);
		System.out.println("This method uses, --contains(T elem)-- method inside");
		System.out.println("If any unexpected behaviour occurs, error message will print with error format.\n");
		System.out.println(">linkedlist1.containsAll(linkedlist2) invoked");
		System.out.println(">linkedlist2.containsAll(linkedlist3) invoked");
		if(!linkedlist1.containsAll(linkedlist2))
			System.out.println(ANSI_RED+"Error occured : linkedlist1.containsAll(linkedlist2)");
		if(!linkedlist2.containsAll(linkedlist3))
			System.out.println(ANSI_RED+"Error occured : linkedlist2.containsAll(linkedlist3)");
		System.out.println("------");
		System.out.println(ANSI_GREEN+"-> --removeAll(GtuCollection<T> c)-- tested."+ANSI_RESET);
		System.out.println("This method uses, --remove(T elem)-- method inside.\n");
		System.out.println(">linkedlist1.removeAll(linkedlist2)");
		System.out.println(">linkedlist2.removeAll(linkedlist3)");
		System.out.println("After This, printing the linkedlists: \n");
		linkedlist1.removeAll(linkedlist2);
		linkedlist2.removeAll(linkedlist3);
		System.out.printf("linkedlist1 : ");
		for (int i=0;i<linkedlist1.size();++i) 
			System.out.printf("%d ",linkedlist1.get(i));
		System.out.println("");
		System.out.printf("linkedlist2 : ");
		for (int i=0;i<linkedlist2.size();++i) 
			System.out.printf("%d ",linkedlist2.get(i));
		System.out.println("");
		System.out.println("------");
		System.out.println(ANSI_GREEN+"-> --addAll(GtuCollection<T> c)-- tested."+ANSI_RESET);
		System.out.println(">linkedlist1.addAll(linkedlist2) invoked");
		System.out.println(">linkedlist2.addAll(linkedlist3) invoked");
		System.out.println("After This, printing the linkedlists: \n");
		linkedlist1.addAll(linkedlist2);
		linkedlist2.addAll(linkedlist3);
		System.out.printf("linkedlist1 : ");
		for (int i=0;i<linkedlist1.size();++i) 
			System.out.printf("%d ",linkedlist1.get(i));
		System.out.println("");
		System.out.printf("linkedlist2 : ");
		for (int i=0;i<linkedlist2.size();++i) 
			System.out.printf("%d ",linkedlist2.get(i));
		System.out.println("");
		System.out.println("------");
		System.out.println(ANSI_GREEN+"-> --retainAll(GtuCollection<T> c)-- tested."+ANSI_RESET);
		System.out.println("This method uses, --remove(T elem)-- method inside.\n");
		System.out.println(">linkedlist1.retainAll(linkedlist2) invoked");
		System.out.println(">linkedlist2.retainAll(linkedlist3) invoked");
		System.out.println("After This, printing the linkedlists: \n");
		linkedlist1.retainAll(linkedlist2);
		linkedlist2.retainAll(linkedlist3);
		System.out.println("------");
		System.out.printf("linkedlist1 : ");
		for (int i=0;i<linkedlist1.size();++i) 
			System.out.printf("%d ",linkedlist1.get(i));
		System.out.println("");
		System.out.printf("linkedlist2 : ");
		for (int i=0;i<linkedlist2.size();++i) 
			System.out.printf("%d ",linkedlist2.get(i));
		System.out.println("");
		System.out.println("------");
		System.out.println("------");
		System.out.println("Testing Special methods for GtuLinkedList extended from Queue interface");
		System.out.println(ANSI_GREEN+"Testing offer(T elem) method for GtuLinkedList" + ANSI_RESET);
		System.out.printf("> linkedlist1.offer(34) invoked\nAfter Adding, linkedlist1 : ");
		linkedlist1.offer(34);
		for (int i=0;i<linkedlist1.size();++i ) {
			System.out.printf("%d ",linkedlist1.get(i));
		}
		System.out.println();
		System.out.println(ANSI_GREEN+"Testing poll() method for GtuLinkedList" + ANSI_RESET);
		System.out.printf("> linkedlist1.poll() invoked\nAfter Poll, linkedlist1 : ");
		int a = linkedlist1.poll();
		for (int i=0;i<linkedlist1.size();++i ) {
			System.out.printf("%d ",linkedlist1.get(i));
		}
		System.out.println();
		System.out.printf("polled = %d\n",a);
		System.out.println();
		System.out.println(ANSI_GREEN+"Testing element() method for GtuLinkedList" + ANSI_RESET);
		System.out.printf("> linkedlist1.element() invoked\n");
		int b = linkedlist1.element();
		System.out.printf("element returned = %d\n",b);
		System.out.println("------");
		System.out.println(ANSI_GREEN+"Since GtuLinkedList is a Iterable, we can use for each loop to print."+ANSI_RESET);
		System.out.println(ANSI_GREEN+"This property is additonal, Not menitoned in the HomeWork PDF."+ANSI_RESET);
		System.out.println("Print linkedlist1 by for each :");
		System.out.printf("linkedlist1 : ");
		for (int obj : linkedlist1)
			System.out.printf("%d ",obj);
		System.out.println("");
	}

	public static void test_GtuLinkedList_String()
	{
		System.out.println(ANSI_GREEN + "#######  Testing GtuLinkedList container with String.  #######" + ANSI_RESET);
		System.out.println("* In String testing, to write easy code for me, Integers are converted to Strings");
		System.out.println("By Integer.toString(int) , we have strings like \"1\" , \"2\" ... \n");
		System.out.println("Initalize with different constructors : \n");
		System.out.println("# We have arrlist1 that constructed with no Parameter constructor.");
		System.out.println(">GtuLinkedList<String>()");
		System.out.println("# We have arrlist2 that constructed with one Parameter ctor that accepts sizeValue");
		System.out.println(">GtuLinkedList<String>(10)");
		System.out.println("# We have arrlist3 that constructed with one Parameter ctor that accepts class type");
		System.out.println(">GtuLinkedList<String>(String[].class)");

		GtuLinkedList<String> linkedlist1 = new GtuLinkedList<String>();
		GtuLinkedList<String> linkedlist2 = new GtuLinkedList<String>(10);
		GtuLinkedList<String> linkedlist3 = new GtuLinkedList<String>(String[].class);
		System.out.println("------");
		System.out.println("Firstly, printing their sizes :");
		System.out.printf("linkedlist1 : %d , linkedlist2 : %d, linkedlist3 : %d\n",linkedlist1.size(),linkedlist2.size(),linkedlist3.size());

		for (int i=0;i<15;++i) 
			linkedlist1.add(Integer.toString(i));

		for (int i=0;i<10;++i) 
			linkedlist2.add(Integer.toString(i));

		for (int i=0;i<5;++i) 
			linkedlist3.add(Integer.toString(i));
		
		System.out.printf(ANSI_GREEN+"-> Some integers added to theese list --add(T element)-- method tested\n"+ANSI_RESET);
		System.out.printf(ANSI_GREEN+"-> While printing, --get(int index)-- method tested\n"+ANSI_RESET);

		System.out.printf("linkedlist1 : ");
		for (int i=0;i<linkedlist1.size();++i) 
			System.out.printf("%s ",linkedlist1.get(i));
		System.out.println("");
		System.out.printf("linkedlist2 : ");
		for (int i=0;i<linkedlist2.size();++i) 
			System.out.printf("%s ",linkedlist2.get(i));
		System.out.println("");
				System.out.printf("linkedlist3 : ");
		for (int i=0;i<linkedlist3.size();++i) 
		System.out.printf("%s ",linkedlist3.get(i));
		System.out.println("");
		System.out.println("------");
		System.out.println(ANSI_GREEN+"-> --containsAll(GtuCollection<T> c)-- tested."+ANSI_RESET);
		System.out.println("This method uses, --contains(T elem)-- method inside");
		System.out.println("If any unexpected behaviour occurs, error message will print with error format.\n");
		System.out.println(">linkedlist1.containsAll(linkedlist2) invoked");
		System.out.println(">linkedlist2.containsAll(linkedlist3) invoked");
		if(!linkedlist1.containsAll(linkedlist2))
			System.out.println(ANSI_RED+"Error occured : linkedlist1.containsAll(linkedlist2)");
		if(!linkedlist2.containsAll(linkedlist3))
			System.out.println(ANSI_RED+"Error occured : linkedlist2.containsAll(linkedlist3)");
		System.out.println("------");
		System.out.println(ANSI_GREEN+"-> --removeAll(GtuCollection<T> c)-- tested."+ANSI_RESET);
		System.out.println("This method uses, --remove(T elem)-- method inside.\n");
		System.out.println(">linkedlist1.removeAll(linkedlist2)");
		System.out.println(">linkedlist2.removeAll(linkedlist3)");
		System.out.println("After This, printing the linkedlists: \n");
		linkedlist1.removeAll(linkedlist2);
		linkedlist2.removeAll(linkedlist3);
		System.out.printf("linkedlist1 : ");
		for (int i=0;i<linkedlist1.size();++i) 
			System.out.printf("%s ",linkedlist1.get(i));
		System.out.println("");
		System.out.printf("linkedlist2 : ");
		for (int i=0;i<linkedlist2.size();++i) 
			System.out.printf("%s ",linkedlist2.get(i));
		System.out.println("");
		System.out.println("------");
		System.out.println(ANSI_GREEN+"-> --addAll(GtuCollection<T> c)-- tested."+ANSI_RESET);
		System.out.println(">linkedlist1.addAll(linkedlist2) invoked");
		System.out.println(">linkedlist2.addAll(linkedlist3) invoked");
		System.out.println("After This, printing the linkedlists: \n");
		linkedlist1.addAll(linkedlist2);
		linkedlist2.addAll(linkedlist3);
		System.out.printf("linkedlist1 : ");
		for (int i=0;i<linkedlist1.size();++i) 
			System.out.printf("%s ",linkedlist1.get(i));
		System.out.println("");
		System.out.printf("linkedlist2 : ");
		for (int i=0;i<linkedlist2.size();++i) 
			System.out.printf("%s ",linkedlist2.get(i));
		System.out.println("");
		System.out.println("------");
		System.out.println(ANSI_GREEN+"-> --retainAll(GtuCollection<T> c)-- tested."+ANSI_RESET);
		System.out.println("This method uses, --remove(T elem)-- method inside.\n");
		System.out.println(">linkedlist1.retainAll(linkedlist2) invoked");
		System.out.println(">linkedlist2.retainAll(linkedlist3) invoked");
		System.out.println("After This, printing the linkedlists: \n");
		linkedlist1.retainAll(linkedlist2);
		linkedlist2.retainAll(linkedlist3);
		System.out.printf("linkedlist1 : ");
		for (int i=0;i<linkedlist1.size();++i) 
			System.out.printf("%s ",linkedlist1.get(i));
		System.out.println("");
		System.out.printf("linkedlist2 : ");
		for (int i=0;i<linkedlist2.size();++i) 
			System.out.printf("%s ",linkedlist2.get(i));
		System.out.println("");
		System.out.println("------");
		System.out.println("------");
		System.out.println("Testing Special methods for GtuLinkedList extended from Queue interface");
		System.out.println(ANSI_GREEN+"Testing offer(T elem) method for GtuLinkedList" + ANSI_RESET);
		System.out.printf("> linkedlist1.offer(\"34\") invoked\nAfter Adding, linkedlist1 : ");
		linkedlist1.offer("34");
		for (int i=0;i<linkedlist1.size();++i ) {
			System.out.printf("%s ",linkedlist1.get(i));
		}
		System.out.println();
		System.out.println(ANSI_GREEN+"Testing poll() method for GtuLinkedList" + ANSI_RESET);
		System.out.printf("> linkedlist1.poll() invoked\nAfter Poll, linkedlist1 : ");
		String a = linkedlist1.poll();
		for (int i=0;i<linkedlist1.size();++i ) {
			System.out.printf("%s ",linkedlist1.get(i));
		}
		System.out.println();
		System.out.printf("polled = %s\n",a);
		System.out.println();
		System.out.println(ANSI_GREEN+"Testing element() method for GtuLinkedList" + ANSI_RESET);
		System.out.printf("> linkedlist1.element() invoked\n");
		String b = linkedlist1.element();
		System.out.printf("element returned = %s\n",b);
		System.out.println("------");
		System.out.println(ANSI_GREEN+"Since GtuLinkedList is a Iterable, we can use for each loop to print."+ANSI_RESET);
		System.out.println(ANSI_GREEN+"This property is additonal, Not menitoned in the HomeWork PDF."+ANSI_RESET);
		System.out.println("Print linkedlist1 by for each :");
		System.out.printf("linkedlist1 : ");
		for (String obj : linkedlist1)
			System.out.printf("%s ",obj);
		System.out.println("");
	}

	public static void test_exceptions()
	{

		System.out.println(ANSI_GREEN + "############### EXCEPTION TESTING #############" + ANSI_RESET +"\nThis method tests exceptions with different styles.");
		System.out.println("----------------------------------------------------");
		System.out.println("## Testing GtuArrayList exceptions : ");
		System.out.println("Passing illegal index to GtuArrayList add(int index, T elem) method :");
		try
		{
			GtuArrayList<Integer> arrlist1 = new GtuArrayList<Integer>();
			arrlist1.add(5);
			arrlist1.add(-1,10);
		}
		catch(Exception ex)
		{
			System.out.println(ANSI_RED+"Error occured : "+ ex.getMessage() + ANSI_RESET );
		}
		System.out.println("-----");
		System.out.println("Passing illegal index to GtuArrayList set(int index, T elem) method :");
		try
		{	
			GtuArrayList<Integer> arrlist1 = new GtuArrayList<Integer>();
			arrlist1.set(-1,10);
		}
		catch(Exception ex)
		{
			System.out.println(ANSI_RED + "Error occured : " + ex.getMessage() + ANSI_RESET);
		}
		System.out.println("-----");
		System.out.println("Illegal usage of iterator before next method call.");
		try
		{	
			GtuArrayList<Integer> arrlist1 = new GtuArrayList<Integer>();
			GtuIterator<Integer> iter = arrlist1.iterator();
			iter.remove();
		}
		catch(Exception ex)
		{
			System.out.println(ANSI_RED + "Error occured : " + ex.getMessage() + ANSI_RESET);
		}
		System.out.println("------------------------------------------");
		/*********************************************************************************/
		/*********************************************************************************/
		System.out.println("## Testing GtuLinkedList exceptions : ");
		System.out.println("Passing illegal index to GtuLinkedList add(int index, T elem) method :");
		try
		{
			GtuLinkedList<Integer> linkedlist1 = new GtuLinkedList<Integer>();
			linkedlist1.add(5);
			linkedlist1.add(-1,10);
		}
		catch(Exception ex)
		{
			System.out.println(ANSI_RED+"Error occured : "+ ex.getMessage() + ANSI_RESET );
		}
		System.out.println("-----");
		System.out.println("Passing illegal index to GtuLinkedList set(int index, T elem) method :");
		try
		{	
			GtuLinkedList<Integer> linkedlist1 = new GtuLinkedList<Integer>();
			linkedlist1.set(-1,10);
		}
		catch(Exception ex)
		{
			System.out.println(ANSI_RED + "Error occured : " + ex.getMessage() + ANSI_RESET);
		}
		System.out.println("-----");
		System.out.println("Illegal usage of iterator before next method call.");
		try
		{	
			GtuLinkedList<Integer> linkedlist1 = new GtuLinkedList<Integer>();
			GtuIterator<Integer> iter = linkedlist1.iterator();
			iter.remove();
		}
		catch(Exception ex)
		{
			System.out.println(ANSI_RED + "Error occured : " + ex.getMessage() + ANSI_RESET);
		}
		System.out.println("-----");
		System.out.println("Illegal usage of poll method to empty LinkedList");
		try
		{
			GtuLinkedList<Integer> linkedlist1 = new GtuLinkedList<Integer>();
			linkedlist1.poll();
		}
		catch(Exception ex)
		{	
			System.out.println(ANSI_RED + "Error occured : " + ex.getMessage() + ANSI_RESET);
		}
		System.out.println("------------------------------------------");
	}
}