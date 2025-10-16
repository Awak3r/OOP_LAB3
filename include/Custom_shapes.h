#pragma once

#include "Figure.h"
#include <initializer_list>
#include <stdexcept>
#include <string>
#include <iostream>
#include <utility>


class Trapezoid : public Figure {
    public:
    Trapezoid(const std::initializer_list<point>&init);
    virtual operator double() const override;
    virtual ~Trapezoid() noexcept override = default;


};


class Rhombus : public Figure {
    public:
    Rhombus(const std::initializer_list<point>&init);
    virtual operator double() const override;
    virtual ~Rhombus() noexcept override = default;


};

class Five : public Figure {
    public:
    Five(const std::initializer_list<point>&init);
    virtual operator double() const override;
    virtual ~Five() noexcept override = default;


};