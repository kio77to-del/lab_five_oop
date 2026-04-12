#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle();
    Rectangle(double width, double height);
    Rectangle(const Rectangle& other);
    ~Rectangle() override;

    void draw() const override;
    void onlyRectangleMethod() const;
};

#endif