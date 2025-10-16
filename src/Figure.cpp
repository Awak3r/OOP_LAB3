#include "../include/Figure.h"
#include <cstddef>
#include <stdexcept>

point::point() : x(0), y(0){}

point::point(const std::initializer_list<double>& init){
    auto it = init.begin();
    if (init.size() != 2){
        throw std::logic_error("error: invalid point\n");
    }
    x = *it;
    y = *(it+1);
}

point::point(const point& other){
    x = other.x;
    y = other.y;
}



double point::get_x(){
    return x;
}

double point::get_y(){
    return y;
}
void point::set_x(double x1) {
    x = x1;
}
void point::set_y(double y1) {
    y = y1;
}
point::~point() noexcept{}

bool point::operator==(const point& other) const{
    if (this->x == other.x && this->y == other.y){
        return true;
    }
    return false;
}

Figure::Figure(): array_size(0), data(nullptr){}

Figure::Figure(const std::initializer_list<point>&init){
    array_size = init.size();
    if (array_size < 3){
        throw std::logic_error("error: invalid figure\n");
    }
    data = new point[array_size];
    size_t i = 0;
    for(auto& value : init){
        data[i++] = value;
    }
}

Figure::Figure(const Figure& other){
    array_size = other.array_size;
    data = new point[array_size];
    for (size_t i = 0; i<array_size; i++){
        data[i] = other.data[i];
    }
}

Figure::Figure(Figure&& other) noexcept{
    array_size = other.array_size;
    data= other.data;
    other.array_size = 0;
    other.data = nullptr;
}

bool Figure::operator==(const Figure& other) const{
    if (this->array_size != other.array_size){
        return false;
    }
    for (size_t i =0; i<this->array_size; i++){
        if (!(this->data[i] == other.data[i])){
            return false;
        }
    }
    return true;
}

point Figure::center_count(){
    double A = 0;
    size_t I;
    for (size_t i = 0; i<array_size; i++){
        I = (i + 1)%array_size;
        A+= data[i].get_x() * data[I].get_y() - data[I].get_x() * data[i].get_y();
    }
    A/=2;
    double x = 0, y = 0;
    for (size_t i = 0; i<array_size; i++){
        I = (i + 1)%array_size;;
        x+= (data[i].get_x() + data[I].get_x()) * (data[i].get_x() * data[I].get_y() - data[I].get_x() * data[i].get_y());
    }
    x/=(6*A);
    for (size_t i = 0; i<array_size; i++){
        I = (i + 1)%array_size;;
        y+= (data[i].get_y() + data[I].get_y()) * (data[i].get_x() * data[I].get_y() - data[I].get_x() * data[i].get_y());
    }
    y/=(6*A);
    point result{x,y};
    return result;
}

std::ostream& operator<<(std::ostream& os, Figure& num){
    for (size_t i = 0; i < num.array_size; ++i){
        os << "("<<num.data[i].get_x()<<", "<<num.data[i].get_y()<<") ";
    }
    return os;
}

std::istream& operator>>(std::istream& is, Figure& num){
    delete[] num.data;
    is >> num.array_size;
    if (num.array_size < 3){
        throw std::logic_error("error: invalid figure\n");
    }
    num.data = new point[num.array_size];
    double x,y;
    for(size_t i =0; i<num.array_size; i++){
        is>>x>>y;
        num.data[i] = point{x,y};
    }
    return is;
}
Figure::operator double() const{
    return 0;
}

Figure::~Figure() noexcept{
    delete[] data;
    array_size = 0;
}


