#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string>

using namespace std;

class Shape {
protected:
    string name;

public:
    Shape();
    Shape(const string& name);
    Shape(const Shape& other);
    virtual ~Shape();

    void info() const;

    void simpleAction() const;
    virtual void virtualAction() const;
    void testCalls() const;

    virtual void draw() const;
};

#endif