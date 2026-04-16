#include <iostream>
#include "Circle.h"

using namespace std;

Circle::Circle() : Shape("Circle"), radius(1) {
    cout << "Circle default constructor, radius = " << radius << endl;
}

Circle::Circle(int r) : Shape("Circle"), radius(r) {
    cout << "Circle constructor with parameter, radius = " << radius << endl;
}

Circle::Circle(const Circle& other) : Shape(other), radius(other.radius) {
    cout << "Circle copy constructor, radius = " << radius << endl;
}

Circle::~Circle() {
    cout << "Circle destructor, radius = " << radius << endl;
}

void Circle::draw() const {
    cout << "Circle::draw(), radius = " << radius << endl;
}

void Circle::virtualAction() const {
    cout << "Circle::virtualAction()" << endl;
}

string Circle::className() const {
    return "Circle";
}

bool Circle::isA(const string& className) const {
    return className == "Circle" || Shape::isA(className);
}

void Circle::simpleAction() const {
    cout << "Circle::simpleAction()" << endl;
}

void Circle::onlyCircleMethod() const {
    cout << "Circle specific method, radius = " << radius << endl;
}