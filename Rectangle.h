#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape {
private:
    int width;
    int height;

public:
    Rectangle();
    Rectangle(int w, int h);
    Rectangle(const Rectangle& other);
    ~Rectangle() override;

    void draw() const override;
    void virtualAction() const override;
    string className() const override;
    bool isA(const string& className) const override;
    void onlyRectangleMethod() const;
};

#endif