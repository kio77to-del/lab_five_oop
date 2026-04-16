#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape {
private:
    int radius;

public:
    Circle();
    Circle(int r);
    Circle(const Circle& other);
    ~Circle() override;

    void draw() const override;
    void virtualAction() const override;
    string className() const override;
    bool isA(const string& className) const override;
    void simpleAction() const;
    void onlyCircleMethod() const;
};

#endif