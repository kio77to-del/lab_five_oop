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
    void simpleAction() const;
    void virtualAction() const override;
    string className() const override;
    void onlyRectangleMethod() const;
};

#endif