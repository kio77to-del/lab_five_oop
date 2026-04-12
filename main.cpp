#include <iostream>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"

using namespace std;

int main() {
    cout << "Lab 5 started" << endl;

    cout << "\n--- Shape object ---" << endl;
    Shape s1;
    s1.info();
    s1.draw();

    cout << "\n--- Circle object ---" << endl;
    Circle c1;
    c1.info();
    c1.draw();
    c1.onlyCircleMethod();

    cout << "\n--- Rectangle object ---" << endl;
    Rectangle r1;
    r1.info();
    r1.draw();
    r1.onlyRectangleMethod();

    cout << "\nProgram finished" << endl;
    return 0;
}