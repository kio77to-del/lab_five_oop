#include <iostream>
#include "Shape.h"

using namespace std;

Shape::Shape() : name("Shape") {
    cout << "Shape default constructor: " << name << endl;
}

Shape::Shape(string n) : name(n) {
    cout << "Shape constructor with parameter: " << name << endl;
}

Shape::Shape(const Shape& other) : name(other.name) {
    cout << "Shape copy constructor: " << name << endl;
}

Shape::~Shape() {
    cout << "Shape destructor: " << name << endl;
}

void Shape::info() const {
    cout << "Object name: " << name << endl;
}

void Shape::simpleAction() const {
    cout << "Shape::simpleAction()" << endl;
}

void Shape::virtualAction() const {
    cout << "Shape::virtualAction()" << endl;
}

void Shape::testCalls() const {
    cout << "Shape::testCalls() start" << endl;
    cout << "Calling simpleAction(): ";
    simpleAction();
    cout << "Calling virtualAction(): ";
    virtualAction();
    cout << "Shape::testCalls() end" << endl;
}

void Shape::draw() const {
    cout << "Shape::draw()" << endl;
}

string Shape::className() const {
    return "Shape";
}

bool Shape::isA(const string& className) const {
    return className == "Shape";
}