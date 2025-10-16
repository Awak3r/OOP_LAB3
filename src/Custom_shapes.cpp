#include "../include/Figure.h"
#include "../include/Custom_shapes.h"
#include <cmath>
#include <cstddef>
#include <stdexcept>
#include <math.h>



Trapezoid::Trapezoid(const std::initializer_list<point>&init){
    array_size = init.size();
    if (array_size != 4){
        throw std::logic_error("error: invalid figure\n");
    }
    data = new point[array_size];
    size_t i = 0;
    for(auto& value : init){
        data[i++] = value;
    }
}

Trapezoid::operator double() const{
    double S =  \
    (((data[0].get_x()*data[1].get_y()) \
    + (data[1].get_x()*data[2].get_y()) \
    + (data[2].get_x()*data[3].get_y()) \
    + (data[3].get_x()*data[0].get_y())) \
    - ((data[0].get_y()*data[1].get_x()) \
    + (data[1].get_y()*data[2].get_x()) \
    + (data[2].get_y()*data[3].get_x()) \
    + (data[3].get_y()*data[0].get_x())));
    return abs(S)/2;
};


Rhombus::Rhombus(const std::initializer_list<point>&init){
    array_size = init.size();
    if (array_size != 4){
        throw std::logic_error("error: invalid figure\n");
    }
    data = new point[array_size];
    size_t i = 0;
    for(auto& value : init){
        data[i++] = value;
    }
}

Rhombus::operator double() const{
    double d1, d2, S;
    d1=sqrt(pow(data[2].get_x() - data[0].get_x(), 2) 
     + pow(data[2].get_y() - data[0].get_y(), 2));
    d2=sqrt(pow(data[3].get_x() - data[1].get_x(), 2) 
     + pow(data[3].get_y() - data[1].get_y(), 2)); 
    S = (d1*d2)/2;
    return S;
}

Five::Five(const std::initializer_list<point>&init){
    array_size = init.size();
    if (array_size != 5){
        throw std::logic_error("error: invalid figure\n");
    }
    data = new point[array_size];
    size_t i = 0;
    for(auto& value : init){
        data[i++] = value;
    }
}

Five::operator double() const{
    double S = 0;
    for (size_t i =0; i<array_size; i++){
        S+=(data[i].get_x()*data[(i+1)%array_size].get_y() - data[i].get_y()*data[(i+1)%array_size].get_x());
    }
    return abs(S)/2;
}

