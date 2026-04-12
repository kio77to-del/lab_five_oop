#include "Shape.h"

Shape::Shape() : name("Shape") {
    cout << "Shape default constructor: " << name << endl;
}

Shape::Shape(const string& name) : name(name) {
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

void Shape::draw() const {
    cout << "Shape::draw()" << endl;
}