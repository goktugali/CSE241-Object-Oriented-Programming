#ifndef _RECTANGLE_H
#define _RECTANGLE_H

#include "shape.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

namespace gtuShapes
{
class rectangle : public shape {
  private:
    double _height;
    double _width;
    double _cx;
    double _cy;
    static double _current_area;
    static double _current_perimeter;

  public:
    rectangle();
    rectangle(double height, double width, double cx, double cy)throw (invalidshapevalue);
    rectangle(double height, double width)throw (invalidshapevalue);
    double get_cx() const{return _cx;}
    double get_cy() const{return _cy;}
    double get_height() const{return _height;}
    double get_width() const{return _width;}
    void set_cx(double cx)throw (invalidshapevalue);
    void set_cy(double cy)throw (invalidshapevalue);
    void set_height(double height)throw (invalidshapevalue);
    void set_width(double width)throw (invalidshapevalue);
    static double get_current_area(){return _current_area;}
    static double get_current_perimeter(){return _current_perimeter;}
    friend std::ostream& operator<<(std::ostream& outputStream,const rectangle& rect);
    virtual std::ostream& print(std::ostream& outputStream)const override;
    const rectangle operator+(double plus)const;
    const rectangle operator-(double minus)const;
    virtual const shape& operator++()override;
    virtual const shape& operator++(int ignore)throw (notavailable) override;
    virtual const shape& operator--()override;
    virtual const shape& operator--(int ignore)throw (notavailable) override;
    virtual double area() const override;
    virtual double perimeter() const override;

};
}
#endif
