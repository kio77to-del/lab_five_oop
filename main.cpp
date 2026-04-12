#include <iostream>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"

using namespace std;

void demoSimpleObjects() {
    cout << "\n=== Обычные объекты ===" << endl;

    Shape s1;
    s1.info();
    s1.draw();

    cout << endl;

    Circle c1;
    c1.info();
    c1.draw();
    c1.onlyCircleMethod();

    cout << endl;

    Rectangle r1;
    r1.info();
    r1.draw();
    r1.onlyRectangleMethod();
}

void demoBasePointers() {
    cout << "\n=== Указатели на базовый класс ===" << endl;

    Shape* p1 = new Shape();
    Shape* p2 = new Circle(5.0);
    Shape* p3 = new Rectangle(4.0, 6.0);

    cout << "\nВызов draw() через Shape*:" << endl;
    p1->draw();
    p2->draw();
    p3->draw();

    cout << "\nУдаление объектов через Shape*:" << endl;
    delete p1;
    delete p2;
    delete p3;
}

int main() {
    cout << "Lab 5 started" << endl;

    demoSimpleObjects();
    demoBasePointers();

    cout << "\nProgram finished" << endl;
    return 0;
}