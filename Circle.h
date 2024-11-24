#pragma once

#define CIRCLE_H

#include "snape.h"
#include <cmath>
#include <iostream>
#include"Line.h"
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif




class Circle : public Shape {
public:
    Circle(double x, double y, double radius) : x_(x), y_(y), radius_(radius) {}

    double area() const override {
        return M_PI * radius_ * radius_;
    }

    double perimeter() const override {
        return 2 * M_PI * radius_;
    }

    bool intersects(const Shape& other) const override {
        // Пересечение с другим объектом
        // Пока просто пример, логика может быть сложнее
        return false;
    }

    void draw() const override {
        std::cout << "Drawing circle at (" << x_ << ", " << y_ << ") with radius " << radius_ << "\n";
    }

private:
    double x_, y_, radius_;
};



