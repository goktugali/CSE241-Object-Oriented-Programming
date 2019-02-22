#include <iostream>
#include "arraylist.h"
#include "arraylist.cpp"
#include "hashset.h"
#include "hashset.cpp"
#include "linkedlist.h"
#include "linkedlist.cpp"
#include "gtuiterator.cpp"
#include "abstractcollection.h"
#include "abstractcollection.cpp"
#include <list>
#include <vector>
#include <set>
#include <string>

/* 			CSE-241 HW6 
		JAVA COLLECTION HIERARCYH 
*/
/*----------------------------------------*/
/*	@ author : 		Goktug Ali Akin		 */
/*	@ student id :  161044018 			*/
/*-------------------------------------*/

/*
	@ This file is a driver(client) file that tests
	different possibilites of containers I implemented.
	Info messages will print the screen.
*/

using namespace std;
using namespace collectionsgtu;

void test_specific_linkedlist();
void test_specific_set();
void test_exceptions();

template <template <class, template <class...> class> class container_type>
void test_int(string container_name);

template <template <class, template <class...> class> class container_type>
void test_string(string container_name);

int main(int argc, char const *argv[])
{	

	cout << "This program(client) test Java Collection Hierarchy with different containers." << endl
		<< "(std::set,std::list,std::vector) tested." << endl
		<< "If any error occurs, Error Messages will be print to the screen wit this format" << endl 
		<< "-------------------------------------------------------------------------------" << endl
		<< "\033[1;31m# Error occured : \033[0m [variable : _var_name, method : _method_name]" << endl
		<< "-------------------------------------------------------------------------------" << endl << endl;
	cout << "In string testing, integers are converted to strings by std::to_string(_int_val)" << endl
		<< "for simple testing."
		<< "i.e data structures have strings like that : \"1\" .. \"2\" .. " << endl << endl;

	cout << "Testing order : " << endl
		<< "1) ArrayList with INT --> ArrayList<int,vector>,ArrayList<int,list>,ArrayList<int,list>" << endl
		<< "2) ArrayList with STRING --> ArrayList<string,vector>,ArrayList<string,list>,ArrayList<string,list>" << endl
		<< "3) HashSet with INT --> HashSet<int,vector>,HashSet<int,list>,HashSet<int,list>" << endl
		<< "4) HashSet with STRING --> HashSet<string,vector>,HashSet<string,list>,HashSet<string,list>" << endl
		<< "5) LinkedList with INT --> LinkedList<int,vector>,LinkedList<int,list>,LinkedList<int,list>" << endl
		<< "6) LinkedList with STRING --> LinkedList<string,vector>,LinkedList<string,list>,LinkedList<string,list>" << endl
		<< "7) test_specific_linkedlist --> (poll,offer,element)" << endl
		<< "8) test_specific_set --> (adding same element to the set)" << endl
		<< "9) exceptions testing." << endl << endl;

	cout << "--------------------------------------------------------------" << endl;
	cout << "--------------------------------------------------------------" << endl << endl;;
	cout << "\033[1;32m# Testing the ArrayList data structure with INT\033[0m" << endl << endl;
	test_int<ArrayList>("arraylist");
	cout << endl << "\033[1;32m# ArrayList data structure with INT test finished\033[0m" << endl; 
	cout << endl << "--------------------------------------------------------------" << endl;
	cout << "--------------------------------------------------------------" << endl << endl;
	cout << "\033[1;32m# Testing the ArrayList data structure with STRING\033[0m" << endl << endl;
	test_string<ArrayList>("ArrayList");
	cout << endl << "\033[1;32m# ArrayList data structure with STRING test finished\033[0m" << endl;
	cout << endl << "--------------------------------------------------------------" << endl;
	cout << "**************************************************************" << endl;
	cout << "--------------------------------------------------------------" << endl << endl;
	cout << "\033[1;32m# Testing the HashSet data structure with INT\033[0m" << endl << endl;
	test_int<HashSet>("hashset");
	cout << endl << "\033[1;32m# HashSet data structure with INT test finished\033[0m" << endl;
	cout << endl << "--------------------------------------------------------------" << endl;
	cout << "--------------------------------------------------------------" << endl << endl;
	cout << "\033[1;32m# Testing the HashSet data structure with STRING\033[0m" << endl << endl;
	test_string<HashSet>("hashset");
	cout << endl << "\033[1;32m# HashSet data structure with STRING test finished\033[0m" << endl;
	cout << endl << "--------------------------------------------------------------" << endl;
	cout << "**************************************************************" << endl;
	cout << "--------------------------------------------------------------" << endl << endl;
	cout << "\033[1;32m# Testing the LinkedList data structure with INT\033[0m" << endl << endl;
	test_int<LinkedList>("linkedlist");
	cout << endl << "\033[1;32m# LinkedList data structure with INT test finished\033[0m" << endl;
	cout << endl << "--------------------------------------------------------------" << endl;
	cout << "--------------------------------------------------------------" << endl << endl;
	cout << "\033[1;32m# Testing the LinkedList data structure with STRING\033[0m" << endl << endl;
	test_string<LinkedList>("linkedlist");
	cout << endl << "\033[1;32m# LinkedList data structure with STRING test finished\033[0m" << endl;
	cout << endl << "--------------------------------------------------------------" << endl;
	cout << "**************************************************************" << endl;
	cout << "--------------------------------------------------------------" << endl << endl;
	test_specific_linkedlist();
	cout << endl << "--------------------------------------------------------------" << endl;
	cout << "**************************************************************" << endl;
	cout << "--------------------------------------------------------------" << endl << endl;
	test_specific_set();
	cout << endl << "--------------------------------------------------------------" << endl;
	cout << "**************************************************************" << endl;
	cout << "--------------------------------------------------------------" << endl << endl;
	test_exceptions();

	cout << "----------------------" << endl
		<<"Driver execution finished, Program Terminated" << endl;

	return 0;
}
template <template <class, template <class...> class> class container_type>
void test_int(string container_name){

	container_type<int,vector> container1;
	container_type<int,std::set> container2;
	container_type<int,std::list> container3;

 	cout<< "--> TYPE = INT --> CLASS = "<<container_name<< endl				
		<< "We have 3 different types of storing(vector,set,list)" << endl
		<< "Variables :" << endl
		<< "-> ArrayList<int,std::vector>"<< container_name << "1" <<  endl
		<< "-> ArrayList<int,std::set> "<< container_name <<"2" << endl
		<< "-> ArrayList<int,std::list> "<< container_name <<"3" << endl;


	cout << "Check for [isEmpty] method before adding elements. Now, arrlists are empty." << endl
		<< "If any error occurs, error message will print to the screen" << endl;

	if(container1.isEmpty()==0)
		cerr << "\033[1;31m# Error occured : \033[0m [variable : "<< container_name <<"1, method : isEmpty]" << endl;
	if(container2.isEmpty()==0)
		cerr << "\033[1;31m# Error occured : \033[0m [variable : "<< container_name <<"2, method : isEmpty]" << endl;
	if(container3.isEmpty()==0)
		cerr << "\033[1;31m# Error occured : \033[0m [variable : "<< container_name <<"3, method : isEmpty]" << endl;

	cout << "--------------------------------------------------------------" << endl;

	cout << "Check for [add] method for theese variables, arrlist will be printed below after adding." << endl;
	for (int i = 0; i <= 10; ++i)
		container1.add(i);
	for (int i = 0; i <= 5; ++i)
		container2.add(i);
	for (int i = 0; i <= 3; ++i)
		container3.add(i);

	cout << "-> "<< container_name <<"1 : ";
	for(auto iter=container1.iterator(); iter.hasNext()!=0; iter++)
		cout << *iter << " ";
	cout << endl;
	cout << "-> "<< container_name <<"2 : ";
	for(auto iter=container2.iterator(); iter.hasNext()!=0; iter++)
		cout << *iter << " ";
	cout << endl;
	cout << "-> "<< container_name <<"3 : ";
	for(auto iter=container3.iterator(); iter.hasNext()!=0; iter++)
		cout << *iter << " ";
	cout << endl;
	
	cout << "--------------------------------------------------------------" << endl;
	
	cout << "Check for [containsAll] method for containers with different types." << endl
		<< "If any error occurs, error message will print to the screen" << endl;

	cout << "-> "<< container_name <<"1.containsAll("<< container_name <<"2) checked." << endl;
	if(container1.containsAll(container1)==0)
		cerr << "\033[1;31m# Error occured : \033[0m [variable : "<< container_name <<"1,"<< container_name <<"2 , method : containsAll]" << endl;
	cout << "-> "<< container_name <<"2.containsAll("<< container_name <<"1) checked." << endl;
	if(container2.containsAll(container1)==1)
		cerr << "\033[1;31m# Error occured : \033[0m [variable : "<< container_name <<"2,"<< container_name <<"1 , method : containsAll]" << endl;
	cout << "-> "<< container_name <<"2.containsAll("<< container_name <<"3) checked." << endl;
	if(container2.containsAll(container3)==0)
		cerr << "\033[1;31m# Error occured : \033[0m [variable : "<< container_name <<"2,"<< container_name <<"3 , method : containsAll]" << endl;

	cout << "--------------------------------------------------------------" << endl;
	
	cout << "Check for [remove] and [contains] method for containers with different types." << endl
		<< "If any error occurs, error message will print to the screen" << endl;
	cout << "Removing 1(int) from all arrlists. And test with contains(1) function." << endl;
	container1.remove(1);
	container2.remove(1);
	container3.remove(1);
	cout << "Check for [contains] method for containers now. Checking variable 1(int) which is removed." << endl
		<< "(containerX.contains(1) method..)" << endl;
	if(container1.contains(1)==1)
		cerr << "\033[1;31m# Error occured : \033[0m [variable : "<< container_name <<"1, method : contains or remove]" << endl;
	if(container2.contains(1)==1)
		cerr << "\033[1;31m# Error occured : \033[0m [variable : "<< container_name <<"2, method : contains or remove]" << endl;
	if(container3.contains(1)==1)
		cerr << "\033[1;31m# Error occured : \033[0m [variable : "<< container_name <<"3, method : contains or remove]" << endl;

	cout << "--------------------------------------------------------------" << endl;

	cout << "Check for [removeAll] method before adding elements. Now, arrlists are empty." << endl
		<< "If any error occurs, error message will print to the screen" << endl;

	cout << "Before removeAll method, arrlists are : " << endl;
	cout << "-> "<< container_name <<"1 : ";
	for(auto iter=container1.iterator(); iter.hasNext()!=0; iter++)
		cout << *iter << " ";
	cout << endl;
	cout << "-> "<< container_name <<"2 : ";
	for(auto iter=container2.iterator(); iter.hasNext()!=0; iter++)
		cout << *iter << " ";
	cout << endl;
	cout << "-> "<< container_name <<"3 : ";
	for(auto iter=container3.iterator(); iter.hasNext()!=0; iter++)
		cout << *iter << " ";
	cout << endl;
	cout<<"-------" << endl;

	cout << "-> "<< container_name <<"1.removeAll("<< container_name <<"2) called. (<int,std::vector> "<< container_name <<"1, <int,std::set> "<< container_name <<"2)" << endl
		<< "-> "<< container_name <<"2.removeAll("<< container_name <<"3) called. (<int,std::set> "<< container_name <<"2, <int,std::list> "<< container_name <<"3)" << endl
		<< "Removed : " << endl;
	container1.removeAll(container2);
	container2.removeAll(container3);
	cout << "-> "<< container_name <<"1 : ";
	for(auto iter=container1.iterator(); iter.hasNext()!=0; iter++)
		cout << *iter << " ";
	cout << endl;
	cout << "-> "<< container_name <<"2 : ";
	for(auto iter=container2.iterator(); iter.hasNext()!=0; iter++)
		cout << *iter << " ";
	cout << endl;

	cout << "--------------------------------------------------------------" << endl;

	cout << "Check for [retainAll] method before adding elements. Now, arrlists are empty." << endl
		<< "If any error occurs, error message will print to the screen" << endl;
	cout << "You can see current containers up. ^^" << endl;
	cout << "-> "<< container_name <<"1.retainAll("<< container_name <<"2) called. (<int,std::vector> "<< container_name <<"1, <int,std::set> "<< container_name <<"2)" << endl
		<< "We expect, there will be no element in "<< container_name <<"1" << endl;

	container1.retainAll(container2);
	cout << "-> "<< container_name <<"1 : ";
	for(auto iter=container1.iterator(); iter.hasNext()!=0; iter++)
		cout << *iter << " ";
	cout << endl;

	cout << "--------------------------------------------------------------" << endl;

	cout << "Check for [addAll] method.Before adding,old containers will be printed." << endl 
		<< "Check the results: " << endl;
	cout << "-> "<< container_name <<"2 : ";
	for(auto iter=container2.iterator(); iter.hasNext()!=0; iter++)
		cout << *iter << " ";
	cout << endl;
	cout << "-> "<< container_name <<"3 : ";
	for(auto iter=container3.iterator(); iter.hasNext()!=0; iter++)
		cout << *iter << " ";
	cout << endl;
	container2.addAll(container3);
	cout << "* "<< container_name <<"2.addAll("<< container_name <<"3) called. "<< container_name <<"2 printed below : " << endl;
	cout << "-> "<< container_name <<"2 : ";
	for(auto iter=container2.iterator(); iter.hasNext()!=0; iter++)
		cout << *iter << " ";
	cout << endl;
}

template <template <class, template <class...> class> class container_type>
void test_string(string container_name){

	container_type<string,vector> container1;
	container_type<string,std::set> container2;
	container_type<string,std::list> container3;

 	cout<< "--> TYPE = STRING --> CLASS = "<<container_name<< endl				
		<< "We have 3 different types of storing(vector,set,list)" << endl
		<< "Variables :" << endl
		<< "-> ArrayList<int,std::vector>"<< container_name << "1" <<  endl
		<< "-> ArrayList<int,std::set> "<< container_name <<"2" << endl
		<< "-> ArrayList<int,std::list> "<< container_name <<"3" << endl;


	cout << "Check for [isEmpty] method before adding elements. Now, arrlists are empty." << endl
		<< "If any error occurs, error message will print to the screen" << endl;

	if(container1.isEmpty()==0)
		cerr << "\033[1;31m# Error occured : \033[0m [variable : "<< container_name <<"1, method : isEmpty]" << endl;
	if(container2.isEmpty()==0)
		cerr << "\033[1;31m# Error occured : \033[0m [variable : "<< container_name <<"2, method : isEmpty]" << endl;
	if(container3.isEmpty()==0)
		cerr << "\033[1;31m# Error occured : \033[0m [variable : "<< container_name <<"3, method : isEmpty]" << endl;

	cout << "--------------------------------------------------------------" << endl;

	cout << "Check for [add] method for theese variables, arrlist will be printed below after adding." << endl;
	for (int i = 0; i <= 10; ++i)
		container1.add(std::to_string(i));
	for (int i = 0; i <= 5; ++i)
		container2.add(std::to_string(i));
	for (int i = 0; i <= 3; ++i)
		container3.add(std::to_string(i));

	cout << "-> "<< container_name <<"1 : ";
	for(auto iter=container1.iterator(); iter.hasNext()!=0; iter++)
		cout << *iter << " ";
	cout << endl;
	cout << "-> "<< container_name <<"2 : ";
	for(auto iter=container2.iterator(); iter.hasNext()!=0; iter++)
		cout << *iter << " ";
	cout << endl;
	cout << "-> "<< container_name <<"3 : ";
	for(auto iter=container3.iterator(); iter.hasNext()!=0; iter++)
		cout << *iter << " ";
	cout << endl;
	
	cout << "--------------------------------------------------------------" << endl;
	
	cout << "Check for [containsAll] method for containers with different types." << endl
		<< "If any error occurs, error message will print to the screen" << endl;

	cout << "-> "<< container_name <<"1.containsAll("<< container_name <<"2) checked." << endl;
	if(container1.containsAll(container1)==0)
		cerr << "\033[1;31m# Error occured : \033[0m [variable : "<< container_name <<"1,"<< container_name <<"2 , method : containsAll]" << endl;
	cout << "-> "<< container_name <<"2.containsAll("<< container_name <<"1) checked." << endl;
	if(container2.containsAll(container1)==1)
		cerr << "\033[1;31m# Error occured : \033[0m [variable : "<< container_name <<"2,"<< container_name <<"1 , method : containsAll]" << endl;
	cout << "-> "<< container_name <<"2.containsAll("<< container_name <<"3) checked." << endl;
	if(container2.containsAll(container3)==0)
		cerr << "\033[1;31m# Error occured : \033[0m [variable : "<< container_name <<"2,"<< container_name <<"3 , method : containsAll]" << endl;

	cout << "--------------------------------------------------------------" << endl;
	
	cout << "Check for [remove] and [contains] method for containers with different types." << endl
		<< "If any error occurs, error message will print to the screen" << endl;
	cout << "Removing 1(int) from all arrlists. And test with contains(1) function." << endl;
	container1.remove("1");
	container2.remove("1");
	container3.remove("1");
	cout << "Check for [contains] method for containers now. Checking variable 1(int) which is removed." << endl
		<< "(containerX.contains(\"1\") method..)" << endl;
	if(container1.contains("1")==1)
		cerr << "\033[1;31m# Error occured : \033[0m [variable : "<< container_name <<"1, method : contains or remove]" << endl;
	if(container2.contains("1")==1)
		cerr << "\033[1;31m# Error occured : \033[0m [variable : "<< container_name <<"2, method : contains or remove]" << endl;
	if(container3.contains("1")==1)
		cerr << "\033[1;31m# Error occured : \033[0m [variable : "<< container_name <<"3, method : contains or remove]" << endl;

	cout << "--------------------------------------------------------------" << endl;

	cout << "Check for [removeAll] method before adding elements. Now, arrlists are empty." << endl
		<< "If any error occurs, error message will print to the screen" << endl;

	cout << "Before removeAll method, arrlists are : " << endl;
	cout << "-> "<< container_name <<"1 : ";
	for(auto iter=container1.iterator(); iter.hasNext()!=0; iter++)
		cout << *iter << " ";
	cout << endl;
	cout << "-> "<< container_name <<"2 : ";
	for(auto iter=container2.iterator(); iter.hasNext()!=0; iter++)
		cout << *iter << " ";
	cout << endl;
	cout << "-> "<< container_name <<"3 : ";
	for(auto iter=container3.iterator(); iter.hasNext()!=0; iter++)
		cout << *iter << " ";
	cout << endl;
	cout<<"-------" << endl;

	cout << "-> "<< container_name <<"1.removeAll("<< container_name <<"2) called. (<int,std::vector> "<< container_name <<"1, <int,std::set> "<< container_name <<"2)" << endl
		<< "-> "<< container_name <<"2.removeAll("<< container_name <<"3) called. (<int,std::set> "<< container_name <<"2, <int,std::list> "<< container_name <<"3)" << endl
		<< "Removed : " << endl;
	container1.removeAll(container2);
	container2.removeAll(container3);
	cout << "-> "<< container_name <<"1 : ";
	for(auto iter=container1.iterator(); iter.hasNext()!=0; iter++)
		cout << *iter << " ";
	cout << endl;
	cout << "-> "<< container_name <<"2 : ";
	for(auto iter=container2.iterator(); iter.hasNext()!=0; iter++)
		cout << *iter << " ";
	cout << endl;

	cout << "--------------------------------------------------------------" << endl;

	cout << "Check for [retainAll] method before adding elements. Now, arrlists are empty." << endl
		<< "If any error occurs, error message will print to the screen" << endl;
	cout << "You can see current containers up. ^^" << endl;
	cout << "-> "<< container_name <<"1.retainAll("<< container_name <<"2) called. (<int,std::vector> "<< container_name <<"1, <int,std::set> "<< container_name <<"2)" << endl
		<< "We expect, there will be no element in "<< container_name <<"1" << endl;

	container1.retainAll(container2);
	cout << "-> "<< container_name <<"1 : ";
	for(auto iter=container1.iterator(); iter.hasNext()!=0; iter++)
		cout << *iter << " ";
	cout << endl;

	cout << "--------------------------------------------------------------" << endl;

	cout << "Check for [addAll] method.Before adding,old containers will be printed." << endl 
		<< "Check the results: " << endl;
	cout << "-> "<< container_name <<"2 : ";
	for(auto iter=container2.iterator(); iter.hasNext()!=0; iter++)
		cout << *iter << " ";
	cout << endl;
	cout << "-> "<< container_name <<"3 : ";
	for(auto iter=container3.iterator(); iter.hasNext()!=0; iter++)
		cout << *iter << " ";
	cout << endl;
	container2.addAll(container3);
	cout << "* "<< container_name <<"2.addAll("<< container_name <<"3) called. "<< container_name <<"2 printed below : " << endl;
	cout << "-> "<< container_name <<"2 : ";
	for(auto iter=container2.iterator(); iter.hasNext()!=0; iter++)
		cout << *iter << " ";
	cout << endl;

}
void test_specific_linkedlist(){

	LinkedList<int,std::vector> llist1;
	cout << "\033[1;32m# Testing specific methods for LinkedList class\033[0m" << endl << endl;
	for (int i = 0; i < 10; ++i)
		llist1.add(i);

	cout << "We have llist1, current values are : " << endl
		<< "llist1 : ";
	for(auto iter = llist1.iterator(); iter.hasNext()!=0; ++iter)
		cout << *iter << " ";
	cout << endl << endl;

	cout << "llist1.element() method called, retrieved : " << llist1.element() << endl;
	cout << "llist1.poll() method called, poll :" << llist1.poll() << endl
		<< "After poll, current llist1 : ";
	for(auto iter = llist1.iterator(); iter.hasNext()!=0; ++iter)
		cout << *iter << " ";
	cout << endl << endl;

	llist1.offer(61);
	cout << "llist1.offer(61) method called, element added" << endl
		<< "After offer called, current llist1 is : ";
	for(auto iter = llist1.iterator(); iter.hasNext()!=0; ++iter)
		cout << *iter << " ";
	cout << endl << endl;	
}

void test_specific_set(){

	HashSet<int,std::vector> hset1;
	cout << "\033[1;32m# Testing specific methods for HashSet class\033[0m" << endl << endl;
	for (int i = 0; i < 10; ++i)
		hset1.add(i);

	cout << "We have hset1, current values are : " << endl
		<< "hset1 : ";
	for(auto iter = hset1.iterator(); iter.hasNext()!=0; ++iter)
		cout << *iter << " ";
	cout << endl << endl;

	cout << "Now, calling hset1.add(3), when 3 is already in the set" << endl
		<< "We expect, 3 will not pushing again." << endl;

	hset1.add(3);
	cout << "Called, print the current hset" << endl
		<< "hset1 : ";
	for(auto iter = hset1.iterator(); iter.hasNext()!=0; ++iter)
		cout << *iter << " ";
	cout << endl;

}

void test_exceptions()
{

	cout << "Testing some exceptions." << endl
		<< "Error(exception) messages will be prin the screen by this format : " << endl
		<< "--------------------------------------------------------" << endl
		<< "\033[1;31m# Exception generated : \033[0m [_exception_message]" << endl	
		<< "--------------------------------------------------------" << endl << endl;
	LinkedList<int,std::vector> emptylist;
	LinkedList<int,std::vector> emptylist2;

	cout << "Calling poll method from empty LinkedList..."  << endl;
	try{
		emptylist.poll();
	}catch(exception& ex){
		cout << "\033[1;31m# Exception generated : \033[0m" << ex.what() << endl << endl;
	}
	cout << "Calling element method from empty LinkedList."  << endl;
	try{
		emptylist.element();
	}catch(exception& ex){

		cout << "\033[1;31m# Exception generated : \033[0m" << ex.what() << endl << endl;
	}
	cout << "Passing empty LinkedList to another container.."
		<< "emptylist.addAll(emptylist2) called " << endl;
	try{
		emptylist.addAll(emptylist2);
	}
	catch(exception& ex){
		cout << "\033[1;31m# Exception generated : \033[0m" << ex.what() << endl;
	}

}
