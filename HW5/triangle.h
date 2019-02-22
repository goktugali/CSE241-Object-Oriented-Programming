#ifndef _TRIANGLE_H
#define _TRIANGLE_H

#include "shape.h"
#include <fstream>
#include <iostream>

namespace gtuShapes
{
class triangle : public shape {
  private:
    long double _cr1[2];
    long double _cr2[2];
    long double _cr3[2];
    long double _tri_edge;
    static long double _current_area;
    static long double _current_perimeter;

  public:
    triangle();
    triangle(long double tri_edge, const long double cr1[2], const long double cr2[2], const long double cr3[2])throw(invalidshapevalue);
    triangle(long double tri_edge, const long double cr1[2], const long double cr2[2])throw(invalidshapevalue);
    triangle(long double tri_edge)throw(invalidshapevalue);
    const long double* get_cr1() const{return _cr1;}
    const long double* get_cr2() const{return _cr2;}
    const long double* get_cr3() const{return _cr3;}
    double get_tri_edge() const{return _tri_edge;}
    void set_cr1(long double cr1[2])throw(invalidshapevalue);
    void set_cr2(long double cr2[2])throw(invalidshapevalue);
    void set_cr3(long double cr3[2])throw(invalidshapevalue);
    void set_tri_edge(long double tri_edge)throw(invalidshapevalue);
    static long double get_current_area(){ return _current_area;}
    static long double get_current_perimeter(){  return _current_perimeter;}
    friend std::ostream& operator<<(std::ostream& outputStream,const triangle& tri);
    virtual std::ostream& print(std::ostream& outputStream)const override;
    const triangle operator+(double plus)const;
	const triangle operator-(double minus)const;
    virtual const shape& operator++()override;
    virtual const shape& operator++(int ignore)override;
    virtual const shape& operator--()override;
    virtual const shape& operator--(int ignore)override;
    virtual double area() const override;
    virtual double perimeter() const override;

};
}
#endif
