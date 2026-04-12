#include "Rectangle.h"

Rectangle::Rectangle() : Shape("Rectangle"), width(1.0), height(1.0) {
    cout << "Rectangle default constructor, width = " << width
         << ", height = " << height << endl;
}

Rectangle::Rectangle(double width, double height)
    : Shape("Rectangle"), width(width), height(height) {
    cout << "Rectangle constructor with parameters, width = " << width
         << ", height = " << height << endl;
}

Rectangle::Rectangle(const Rectangle& other)
    : Shape(other), width(other.width), height(other.height) {
    cout << "Rectangle copy constructor, width = " << width
         << ", height = " << height << endl;
}

Rectangle::~Rectangle() {
    cout << "Rectangle destructor, width = " << width
         << ", height = " << height << endl;
}

void Rectangle::draw() const {
    cout << "Rectangle::draw(), width = " << width
         << ", height = " << height << endl;
}

void Rectangle::simpleAction() const {
    cout << "Rectangle::simpleAction()" << endl;
}

void Rectangle::virtualAction() const {
    cout << "Rectangle::virtualAction()" << endl;
}

void Rectangle::onlyRectangleMethod() const {
    cout << "Rectangle specific method, width = " << width
         << ", height = " << height << endl;
}