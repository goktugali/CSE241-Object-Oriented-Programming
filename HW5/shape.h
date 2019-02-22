#ifndef _SHAPE_H
#define _SHAPE_H
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include "gtuexceptions.h"

using namespace gtuExceptions;

namespace gtuShapes
{

class shape {
    public:
        shape();
        virtual ~shape()=default;
      	virtual std::ostream& print(std::ostream& outputStream)const = 0;
        virtual double area() const = 0;
        virtual double perimeter() const = 0;
        virtual const shape& operator++() = 0;
        virtual const shape& operator++(int ignore)=0;
        virtual const shape& operator--() = 0;
        virtual const shape& operator--(int ignore)=0;
        bool operator==(const shape * other) const;
        bool operator!=(const shape * other) const;
        bool operator<(const shape * other) const;
        bool operator<=(const shape * other) const;
        bool operator>(const shape * other) const;
        bool operator>=(const shape * other) const;
        std::string getColor()const{return _color;}
        void setColor(const std::string& color);
    private:
        std::string _color;

};

std::ostream& operator<<(std::ostream& outputStream, const shape* shp);

}
#endif
