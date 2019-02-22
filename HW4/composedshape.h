#ifndef COMPOSEDSHAPE_H_
#define COMPOSEDSHAPE_H_
#include <vector>
#include "polygon.h"
#include <cmath>

namespace gtuComposedShape
{
	class composedshape{
	public:
		/** Constructors for composed shape with different possiblities 
		  * There are 6 constructors because I cannot code the situation 
			where circle shape is main container.
		**/
		composedshape(const gtuShapes::rectangle& container,const gtuShapes::rectangle& small);
		composedshape(const gtuShapes::rectangle& container,const gtuShapes::circle& small);
		composedshape(const gtuShapes::rectangle& container,const gtuShapes::triangle& small);
		composedshape(const gtuShapes::triangle& container,const gtuShapes::rectangle& small);
		composedshape(const gtuShapes::triangle& container,const gtuShapes::circle& small);
		composedshape(const gtuShapes::triangle& container,const gtuShapes::triangle& small);
		
		void optimalFit(const gtuShapes::rectangle& container, const gtuShapes::rectangle& small);
		void optimalFit(const gtuShapes::rectangle& container, const gtuShapes::circle& small);
		void optimalFit(const gtuShapes::rectangle& container, const gtuShapes::triangle& small);
		void optimalFit(const gtuShapes::triangle& container, const gtuShapes::triangle& small);
		void optimalFit(const gtuShapes::triangle& container, const gtuShapes::circle& small);
		void optimalFit(const gtuShapes::triangle& container, const gtuShapes::rectangle& small);

		int get_size_shape()const{return _mainshape.size();}

		/** overloaded operators **/
		friend std::ostream& operator<<(std::ostream& outputStream,const composedshape& mainshape);
		const composedshape& operator+=(const gtuPolygon::polygon& p1);
		const gtuPolygon::polygon& operator[](int index)const;
		gtuPolygon::polygon& operator[](int index);

	private:
		std::vector<gtuPolygon::polygon> _mainshape;
		/** This vector holds all shapes. First element is big shape,
			others are smallers. **/
	};
}
#endif	
