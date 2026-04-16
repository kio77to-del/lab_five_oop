#include <iostream>
#include "Rectangle.h"

using namespace std;

Rectangle::Rectangle() : Shape("Rectangle"), width(1), height(1) {
    cout << "Rectangle default constructor, width = " << width
         << ", height = " << height << endl;
}

Rectangle::Rectangle(int w, int h) : Shape("Rectangle"), width(w), height(h) {
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

void Rectangle::virtualAction() const {
    cout << "Rectangle::virtualAction()" << endl;
}

string Rectangle::className() const {
    return "Rectangle";
}

bool Rectangle::isA(const string& className) const {
    return className == "Rectangle" || Shape::isA(className);
}

void Rectangle::onlyRectangleMethod() const {
    cout << "Rectangle specific method, width = " << width
         << ", height = " << height << endl;
}