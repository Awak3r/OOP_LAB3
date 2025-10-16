#include <gtest/gtest.h>
#include "../include/Figure.h"
#include "../include/Custom_shapes.h"
#include <sstream>


TEST(TrapezoidTest, ConstructorValidAndInvalid) {
    std::initializer_list<point> pts{{0,0}, {1,0}, {1,1}, {0,1}};
    Trapezoid trapezoid(pts);
    ASSERT_EQ(static_cast<double>(trapezoid), 1.0);

    std::initializer_list<point> bad{{0,0}, {1,0}, {1,1}};
    ASSERT_THROW(Trapezoid badTrap(bad), std::logic_error);
}

TEST(RhombusTest, AreaCalculation) {
    Rhombus rhombus({{0,0}, {1,1}, {2,0}, {1,-1}});
    double expected_area = 2.0; // диагонали = 2 и 2 => площадь = 2*2/2 = 2
    ASSERT_NEAR(static_cast<double>(rhombus), expected_area, 1e-6);
}

TEST(FiveTest, AreaCalculationSimple) {
    Five pentagon({{0,0}, {2,0}, {3,1}, {1,3}, {-1,1}});
    double area = static_cast<double>(pentagon);
    ASSERT_GT(area, 0);
}

TEST(FigureTest, CenterCount) {
    Figure* f = new Trapezoid({{0,0},{4,0},{4,2},{0,2}});
    point center = f->center_count();
    ASSERT_NEAR(center.get_x(), 2.0, 1e-6);
    ASSERT_NEAR(center.get_y(), 1.0, 1e-6);
    delete f;
}

TEST(PointTest, Equality) {
    point p1{0,0};
    point p2{0,0};
    point p3{1,1};
    ASSERT_TRUE(p1 == p2);
    ASSERT_FALSE(p1 == p3);
}

TEST(FigureTest, Equality) {
    Trapezoid t1({{0,0},{1,0},{1,1},{0,1}});
    Trapezoid t2({{0,0},{1,0},{1,1},{0,1}});
    Trapezoid t3({{0,0},{2,0},{2,2},{0,2}});
    ASSERT_TRUE(t1 == t2);
    ASSERT_FALSE(t1 == t3);
}


TEST(FigureIOTest, StreamInputInvalid) {
    std::stringstream ss("2\n0 0\n1 1\n");
    Figure f;
    ASSERT_THROW(ss >> f, std::logic_error);
}

TEST(FigureTest, CopyConstructor) {
    Trapezoid t1({{0,0},{1,0},{1,1},{0,1}});
    Figure* t2 = new Trapezoid(t1);
    ASSERT_TRUE(*t2 == t1);
    delete t2;
}

TEST(FigureTest, MoveConstructor) {
    Trapezoid t1({{0,0},{1,0},{1,1},{0,1}});
    Trapezoid t2(std::move(t1));
    ASSERT_EQ(t2.center_count().get_x(), 0.5);
}

TEST(FiveTest, CenterCount) {
    Five pent({{0,0}, {2,0}, {3,1}, {1,3}, {-1,1}});
    point c = pent.center_count();
    ASSERT_GT(c.get_x(), 0);
    ASSERT_GT(c.get_y(), 0);
}

TEST(TrapezoidTest, AreaWithNegativeCoords) {
    Trapezoid trap({{-1,-1},{1,-1},{1,1},{-1,1}});
    double area = static_cast<double>(trap);
    ASSERT_NEAR(area, 4.0, 1e-6);
}

TEST(RhombusTest, AreaWithRotatedRhombus) {
    Rhombus rh({{0,0},{1,1},{2,0},{1,-1}});
    double area = static_cast<double>(rh);
    ASSERT_NEAR(area, 2.0, 1e-6);
}

TEST(FigureTest, EqualityDifferentSize) {
    Trapezoid t({{0,0},{1,0},{1,1},{0,1}});
    Five f({{0,0},{1,0},{1,1},{0,1},{0.5,1.5}});
    ASSERT_FALSE(t == f);
}

TEST(PointTest, InvalidPointInitializer) {
    ASSERT_THROW(point p({0}), std::logic_error);
}
