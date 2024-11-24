#pragma once
#ifndef POINT_H
#define POINT_H
#include"Line.h"
#include "snape.h"

class Point : public Shape {
public:
    Point(double x, double y) : x_(x), y_(y) {}

    double area() const override {
        return 0.0;  // Точка не имеет площади
    }

    double perimeter() const override {
        return 0.0;  // Точка не имеет периметра
    }

    bool intersects(const Shape& other) const override {
        return false;  // Точка не может пересекаться с другим примитивом
    }

    void draw() const override {
        std::cout << "Drawing point at (" << x_ << ", " << y_ << ")\n";
    }

private:
    double x_, y_;
};

#endif // POINT_H

