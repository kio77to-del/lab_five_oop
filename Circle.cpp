#include "Circle.h"

Circle::Circle() : Shape("Circle"), radius(1.0) {
    cout << "Circle default constructor, radius = " << radius << endl;
}

Circle::Circle(double radius) : Shape("Circle"), radius(radius) {
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

void Circle::simpleAction() const {
    cout << "Circle::simpleAction()" << endl;
}

void Circle::virtualAction() const {
    cout << "Circle::virtualAction()" << endl;
}

string Circle::className() const {
    return "Circle";
}

void Circle::onlyCircleMethod() const {
    cout << "Circle specific method, radius = " << radius << endl;
}