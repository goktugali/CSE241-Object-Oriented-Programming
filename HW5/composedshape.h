#ifndef COMPOSEDSHAPE_H_
#define COMPOSEDSHAPE_H_
#include "shape.h"
#include "rectangle.h"
#include "triangle.h"
#include "circle.h"
#include "polygon.h"
#include <vector>

using namespace gtuShapes;
namespace gtuComposedShape
{
	class composedshape : public shape{
	public:
		/* Constructor takes shape pointers. 
		 It Dont uses the coming pointer(const), 
		 It allocates for new memory */
		composedshape(const shape* container,const shape* small)throw(invalidptr);
		composedshape(const composedshape& copy);
		composedshape& operator=(const composedshape& other);/* Big Three */
		~composedshape();
		void optimalFit();
		int get_size_shape()const{return _mainshape.size();}

      	virtual std::ostream& print(std::ostream& outputStream)const override;
        virtual double area() const override;
        virtual double perimeter() const override;
        virtual const shape& operator++() override;
        virtual const shape& operator++(int ignore)throw(notavailable) override;
        virtual const shape& operator--() override;
        virtual const shape& operator--(int ignore)throw(notavailable) override;

		/** overloaded operators **/
		friend std::ostream& operator<<(std::ostream& outputStream,const composedshape& mainshape);
		const composedshape& operator+=(shape* shptr);
		const shape* operator[](int index)const throw (outofrange);
		shape* operator[](int index)throw (outofrange);
	public:
		std::vector<shape *> _mainshape;
		/** This vector holds all shapes. First element is big shape,
			others are smallers. **/
	};
}
#endif