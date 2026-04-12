#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape {
private:
    double radius;

public:
    Circle();
    Circle(double radius);
    Circle(const Circle& other);
    ~Circle() override;

    void draw() const override;
    void onlyCircleMethod() const;
};

#endif