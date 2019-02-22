#include "shape.h"
#include <iostream>
namespace gtuShapes
{	
	shape::shape() : _color("green") {/* */}

	bool shape::operator==(const shape * other) const {
		return (area()==other->area());
	}

	bool shape::operator!=(const shape * other) const {
		return !(area()==other->area());
	}

	bool shape::operator<(const shape * other) const {
		return (area()<other->area());
	}
	bool shape::operator<=(const shape * other) const {
		return (area()<=other->area());
	}
	bool shape::operator>(const shape * other) const {
		return (area()>other->area());
	}
	bool shape::operator>=(const shape * other) const {
		return (area()>=other->area());
	}
	void shape::setColor(const std::string& color){
		_color = color;
	}
	std::ostream& operator<<(std::ostream& outputStream, const shape* shp){
		shp->print(outputStream);
		return outputStream;
	}

}