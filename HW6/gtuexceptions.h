#ifndef GTUEXCEPTIONS_H_
#define GTUEXCEPTIONS_H_
#include <iostream>
#include <exception>

/* 			CSE-241 HW6 
		JAVA COLLECTION HIERARCYH 
*/
/*----------------------------------------*/
/*	@ author : 		Goktug Ali Akin		 */
/*	@ student id :  161044018 			*/
/*-------------------------------------*/

/**********  EXCEPTONS *********/

namespace gtuExceptions
{

class empty_param_container : public std::exception{
	public :
		virtual const char* what()const noexcept override{return "Container that passing as a parameter is empty!";}
};
class empty_container : public std::exception{
	public :
		virtual const char* what()const noexcept override{return "Container(this->) is empty!";}
};
}
#endif