#pragma once

#include <initializer_list>
#include <string>
#include <iostream>
#include <utility>


class point{
    public:
    point();
    point(const std::initializer_list<double>& init);
    point(const point& other);
    bool operator== (const point& other) const;
    double get_x();
    double get_y();
    void set_x(double x1);
    void set_y(double y1);
    virtual ~point() noexcept;
    private:
    double x;
    double y;

};

class Figure {
    public:
    Figure();
    Figure(const std::initializer_list<point>&init);
    Figure(const Figure& other);
    Figure(Figure&& other) noexcept;
    point center_count();
    bool operator==(const Figure& other) const;
    friend std::ostream& operator<<(std::ostream& os, Figure& num);
    friend std::istream& operator>>(std::istream& os, Figure& num);
    virtual operator double() const;
    virtual ~Figure() noexcept;

    protected:
    size_t array_size;
    point *data;
};