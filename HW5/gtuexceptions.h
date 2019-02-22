#ifndef GTUEXCEPTIONS_H_
#define GTUEXCEPTIONS_H_
#include <iostream>
#include <exception>

namespace gtuExceptions
{
class invalidptr : public std::exception{
	public:
		virtual const char* what()const noexcept override{return "Invalid pointer(addres) passing";}
};
class invalidsize : public std::exception{
	public :
		virtual const char* what()const noexcept override{return "Invalid size passing";}
};
class invalidshapevalue : public std::exception{
	public :
		virtual const char* what()const noexcept override{return "Invalid shape value(coordinate or size) passing";}
};
class outofrange : public std::exception{
	public :
		virtual const char* what()const noexcept override{return "Value that passed is out of range( < 0 ?)";}
};
class notavailable : public std::exception{
	public :
		virtual const char* what()const noexcept override{return "Method is not available now.(not implemented)";}
};
}
#endif