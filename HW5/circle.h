#ifndef _CIRCLE_H
#define _CIRCLE_H

#include "shape.h"
#include <fstream>
#include <cstdlib>
#include <iostream>
namespace gtuShapes
{

class circle : public shape {
  private:
    double _cx;
    double _cy;
    double _radius;
    static double _current_area;
    static double _current_perimeter;

  public:
    circle();
    circle(double radius)throw(invalidshapevalue);
    circle(double radius, double cx, double cy)throw(invalidshapevalue);
    double get_radius() const{return _radius;}
    double get_cx() const{return _cx;}
    double get_cy() const{return _cy;}
    void set_radius(double radius)throw(invalidshapevalue);
    void set_cx(double cx)throw(invalidshapevalue);
    void set_cy(double cy)throw(invalidshapevalue);
    static double get_current_area(){return _current_area;}
    static double get_current_perimeter(){return _current_perimeter;}
    friend std::ostream& operator<<(std::ostream& outputStream,const circle& circle);
    virtual std::ostream& print(std::ostream& outputStream)const override;
    const circle operator+(const double plus)const;
	const circle operator-(const double minus)const;
    virtual const shape& operator++()override;
    virtual const shape& operator++(int ignore)throw(notavailable) override;
    virtual const shape& operator--()override;
    virtual const shape& operator--(int ignore)throw(notavailable) override;
    virtual double area() const override;
    virtual double perimeter() const override;

};
}
#endif
