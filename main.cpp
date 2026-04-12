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

void demoCopyConstructors() {
    cout << "\n=== Конструкторы копирования ===" << endl;

    Circle c1(8.0);
    cout << "Создаем копию Circle:" << endl;
    Circle c2 = c1;

    cout << "Исходный объект Circle:" << endl;
    c1.draw();

    cout << "Скопированный объект Circle:" << endl;
    c2.draw();

    cout << endl;

    Rectangle r1(2.0, 9.0);
    cout << "Создаем копию Rectangle:" << endl;
    Rectangle r2(r1);

    cout << "Исходный объект Rectangle:" << endl;
    r1.draw();

    cout << "Скопированный объект Rectangle:" << endl;
    r2.draw();
}

void demoVirtualAndNonVirtual() {
    cout << "\n=== Невиртуальный и виртуальный вызов ===" << endl;

    Shape* p1 = new Shape();
    Shape* p2 = new Circle(10.0);
    Shape* p3 = new Rectangle(7.0, 3.0);

    cout << "\nПрямой вызов simpleAction() через Shape*:" << endl;
    p1->simpleAction();
    p2->simpleAction();
    p3->simpleAction();

    cout << "\nПрямой вызов virtualAction() через Shape*:" << endl;
    p1->virtualAction();
    p2->virtualAction();
    p3->virtualAction();

    cout << "\nВызов testCalls() через Shape*:" << endl;
    p1->testCalls();
    cout << endl;
    p2->testCalls();
    cout << endl;
    p3->testCalls();

    delete p1;
    delete p2;
    delete p3;
}

void demoDynamicCast() {
    cout << "\n=== dynamic_cast ===" << endl;

    Shape* p1 = new Circle(12.0);
    Shape* p2 = new Rectangle(5.0, 8.0);
    Shape* p3 = new Shape();

    Circle* c1 = dynamic_cast<Circle*>(p1);
    Circle* c2 = dynamic_cast<Circle*>(p2);
    Circle* c3 = dynamic_cast<Circle*>(p3);

    if (c1 != nullptr) {
        cout << "p1 успешно приведен к Circle*" << endl;
        c1->onlyCircleMethod();
    } else {
        cout << "p1 не является Circle" << endl;
    }

    if (c2 != nullptr) {
        cout << "p2 успешно приведен к Circle*" << endl;
        c2->onlyCircleMethod();
    } else {
        cout << "p2 не является Circle" << endl;
    }

    if (c3 != nullptr) {
        cout << "p3 успешно приведен к Circle*" << endl;
        c3->onlyCircleMethod();
    } else {
        cout << "p3 не является Circle" << endl;
    }

    delete p1;
    delete p2;
    delete p3;
}

void demoManualTypeCheck() {
    cout << "\n=== Ручная проверка типа ===" << endl;

    Shape* arr[3];
    arr[0] = new Circle(3.0);
    arr[1] = new Rectangle(6.0, 2.0);
    arr[2] = new Shape();

    for (int i = 0; i < 3; i++) {
        cout << "Объект " << i + 1 << ": " << arr[i]->className() << endl;

        if (arr[i]->className() == "Circle") {
            Circle* c = static_cast<Circle*>(arr[i]);
            cout << "Ручная проверка: это Circle" << endl;
            c->onlyCircleMethod();
        } else if (arr[i]->className() == "Rectangle") {
            Rectangle* r = static_cast<Rectangle*>(arr[i]);
            cout << "Ручная проверка: это Rectangle" << endl;
            r->onlyRectangleMethod();
        } else {
            cout << "Ручная проверка: это базовый Shape" << endl;
        }

        cout << endl;
    }

    for (int i = 0; i < 3; i++) {
        delete arr[i];
    }
}

int main() {
    cout << "Lab 5 started" << endl;

    demoSimpleObjects();
    demoBasePointers();
    demoCopyConstructors();
    demoVirtualAndNonVirtual();
    demoDynamicCast();
    demoManualTypeCheck();

    cout << "\nProgram finished" << endl;
    return 0;
}