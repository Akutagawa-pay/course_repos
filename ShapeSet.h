#pragma once
#ifndef SHAPESET_H
#define SHAPESET_H

#include <vector>
#include "snape.h"

class ShapeSet {
public:
    void addShape(Shape* shape) {
        shapes_.push_back(shape);
    }

    void removeShape(Shape* shape) {
        shapes_.erase(std::remove(shapes_.begin(), shapes_.end(), shape), shapes_.end());
    }

    // Операции над множествами
    ShapeSet unionWith(const ShapeSet& other) const {
        ShapeSet result = *this;
        for (auto shape : other.shapes_) {
            result.addShape(shape);
        }
        return result;
    }

    ShapeSet intersectionWith(const ShapeSet& other) const {
        ShapeSet result;
        for (auto shape : shapes_) {
            for (auto otherShape : other.shapes_) {
                if (shape->intersects(*otherShape)) {
                    result.addShape(shape);
                    break;
                }
            }
        }
        return result;
    }

    // Вывод всех объектов
    void drawAll() const {
        for (auto shape : shapes_) {
            shape->draw();
        }
    }

private:
    std::vector<Shape*> shapes_;
};

#endif // SHAPESET_H

