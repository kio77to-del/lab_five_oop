#include <iostream>
#include <memory>

#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"

using namespace std;

void demoSimpleObjects() {
    cout << "\n=== Обычные объекты ===" << endl;

    Shape s;
    s.info();
    s.draw();
    cout << endl;

    Circle c;
    c.info();
    c.draw();
    c.onlyCircleMethod();
    cout << endl;

    Rectangle r;
    r.info();
    r.draw();
    r.onlyRectangleMethod();
}

void demoBasePointers() {
    cout << "\n=== Указатели на базовый класс ===" << endl;

    Shape* p1 = new Shape();
    Shape* p2 = new Circle(5);
    Shape* p3 = new Rectangle(4, 6);

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

    Circle c1(8);
    cout << "Создаем копию Circle:" << endl;
    Circle c2 = c1;

    cout << "Исходный объект Circle:" << endl;
    c1.draw();

    cout << "Скопированный объект Circle:" << endl;
    c2.draw();

    cout << endl;

    Rectangle r1(2, 9);
    cout << "Создаем копию Rectangle:" << endl;
    Rectangle r2 = r1;

    cout << "Исходный объект Rectangle:" << endl;
    r1.draw();

    cout << "Скопированный объект Rectangle:" << endl;
    r2.draw();
}

void demoVirtualAndNonVirtual() {
    cout << "\n=== Невиртуальный и виртуальный вызов ===" << endl;

    Shape* p1 = new Shape();
    Shape* p2 = new Circle(10);
    Shape* p3 = new Rectangle(7, 3);

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

    Shape* p1 = new Circle(12);
    Shape* p2 = new Rectangle(5, 8);
    Shape* p3 = new Shape();

    Circle* c1 = dynamic_cast<Circle*>(p1);
    Circle* c2 = dynamic_cast<Circle*>(p2);
    Circle* c3 = dynamic_cast<Circle*>(p3);

    if (c1) {
        cout << "p1 успешно приведен к Circle*" << endl;
        c1->onlyCircleMethod();
    } else {
        cout << "p1 не является Circle" << endl;
    }

    if (c2) {
        cout << "p2 успешно приведен к Circle*" << endl;
        c2->onlyCircleMethod();
    } else {
        cout << "p2 не является Circle" << endl;
    }

    if (c3) {
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

    Shape* objects[3];
    objects[0] = new Circle(3);
    objects[1] = new Rectangle(6, 2);
    objects[2] = new Shape();

    for (int i = 0; i < 3; i++) {
        cout << "\nОбъект " << i + 1 << ":" << endl;
        cout << "className() = " << objects[i]->className() << endl;

        cout << "Проверка через isA:" << endl;
        cout << "isA(\"Shape\") = "
             << (objects[i]->isA("Shape") ? "true" : "false") << endl;
        cout << "isA(\"Circle\") = "
             << (objects[i]->isA("Circle") ? "true" : "false") << endl;
        cout << "isA(\"Rectangle\") = "
             << (objects[i]->isA("Rectangle") ? "true" : "false") << endl;

        if (objects[i]->isA("Circle")) {
            cout << "Ручная проверка: это Circle" << endl;
            Circle* c = static_cast<Circle*>(objects[i]);
            c->onlyCircleMethod();
        } else if (objects[i]->isA("Rectangle")) {
            cout << "Ручная проверка: это Rectangle" << endl;
            Rectangle* r = static_cast<Rectangle*>(objects[i]);
            r->onlyRectangleMethod();
        } else {
            cout << "Ручная проверка: это базовый Shape" << endl;
        }
    }

    for (int i = 0; i < 3; i++) {
        delete objects[i];
    }
}

void demoCastingComparison() {
    cout << "\n=== Сравнение static_cast и dynamic_cast ===" << endl;

    Shape* p1 = new Circle(9);
    Shape* p2 = new Rectangle(4, 5);
    Shape* p3 = new Shape();

    cout << "\nПробуем ручную проверку через isA + static_cast:" << endl;

    if (p1->isA("Circle")) {
        cout << "p1 действительно Circle, можно делать static_cast" << endl;
        Circle* c1 = static_cast<Circle*>(p1);
        c1->onlyCircleMethod();
    } else {
        cout << "p1 не Circle" << endl;
    }

    if (p2->isA("Circle")) {
        cout << "p2 действительно Circle, можно делать static_cast" << endl;
        Circle* c2 = static_cast<Circle*>(p2);
        c2->onlyCircleMethod();
    } else {
        cout << "p2 не Circle, делать static_cast опасно" << endl;
    }

    if (p3->isA("Circle")) {
        cout << "p3 действительно Circle, можно делать static_cast" << endl;
        Circle* c3 = static_cast<Circle*>(p3);
        c3->onlyCircleMethod();
    } else {
        cout << "p3 не Circle, делать static_cast опасно" << endl;
    }

    cout << "\nТеперь пробуем dynamic_cast:" << endl;

    Circle* dc1 = dynamic_cast<Circle*>(p1);
    Circle* dc2 = dynamic_cast<Circle*>(p2);
    Circle* dc3 = dynamic_cast<Circle*>(p3);

    if (dc1) {
        cout << "dynamic_cast для p1 прошел успешно" << endl;
        dc1->onlyCircleMethod();
    } else {
        cout << "dynamic_cast: p1 не Circle" << endl;
    }

    if (dc2) {
        cout << "dynamic_cast для p2 прошел успешно" << endl;
        dc2->onlyCircleMethod();
    } else {
        cout << "dynamic_cast: p2 не Circle" << endl;
    }

    if (dc3) {
        cout << "dynamic_cast для p3 прошел успешно" << endl;
        dc3->onlyCircleMethod();
    } else {
        cout << "dynamic_cast: p3 не Circle" << endl;
    }

    delete p1;
    delete p2;
    delete p3;
}

void takeByValue(Circle c) {
    cout << "Функция takeByValue() начала работу" << endl;
    c.draw();
    cout << "Функция takeByValue() завершена" << endl;
}

void takeByReference(const Circle& c) {
    cout << "Функция takeByReference() начала работу" << endl;
    c.draw();
    cout << "Функция takeByReference() завершена" << endl;
}

void takeByPointer(const Circle* c) {
    cout << "Функция takeByPointer() начала работу" << endl;
    c->draw();
    cout << "Функция takeByPointer() завершена" << endl;
}

Circle createCircle() {
    cout << "Функция createCircle() начала работу" << endl;
    Circle temp(15);
    cout << "Функция createCircle() возвращает объект" << endl;
    return temp;
}

Shape createShapeObject() {
    cout << "Функция createShapeObject() начала работу" << endl;
    Shape temp("LocalShape");
    cout << "Функция createShapeObject() возвращает объект" << endl;
    return temp;
}

void demoFunctionLifecycle() {
    cout << "\n=== Передача и возврат объектов из функций ===" << endl;

    Circle c(20);

    cout << "\n------------------------------------------\n" << endl;
    cout << "Передача по значению:" << endl;
    takeByValue(c);

    cout << "\n------------------------------------------\n" << endl;
    cout << "Передача по ссылке:" << endl;
    takeByReference(c);

    cout << "\n------------------------------------------\n" << endl;
    cout << "Передача по указателю:" << endl;
    takeByPointer(&c);

    cout << "\n------------------------------------------\n" << endl;
    cout << "Возврат Circle из функции:" << endl;
    Circle newCircle = createCircle();
    cout << "Объект, полученный из createCircle():" << endl;
    newCircle.draw();

    cout << "\n------------------------------------------\n" << endl;
    cout << "Возврат Shape из функции:" << endl;
    Shape newShape = createShapeObject();
    cout << "Объект, полученный из createShapeObject():" << endl;
    newShape.draw();
}

void demoUniquePtr() {
    cout << "\n=== unique_ptr ===" << endl;

    unique_ptr<Shape> ptr1 = make_unique<Circle>(25);

    cout << "Объект внутри unique_ptr:" << endl;
    ptr1->draw();

    cout << "Передаем владение другому unique_ptr" << endl;
    unique_ptr<Shape> ptr2 = move(ptr1);

    if (!ptr1) {
        cout << "ptr1 теперь пустой после move()" << endl;
    }

    cout << "Теперь объектом владеет ptr2:" << endl;
    ptr2->draw();

    cout << "При выходе из функции объект удалится автоматически" << endl;
}

void demoSharedPtr() {
    cout << "\n=== shared_ptr ===" << endl;

    shared_ptr<Shape> ptr1 = make_shared<Rectangle>(11, 4);
    cout << "После создания ptr1, use_count = " << ptr1.use_count() << endl;

    {
        shared_ptr<Shape> ptr2 = ptr1;
        cout << "После копирования в ptr2, use_count = " << ptr1.use_count() << endl;

        {
            shared_ptr<Shape> ptr3 = ptr1;
            cout << "После копирования в ptr3, use_count = " << ptr1.use_count() << endl;
            ptr3->draw();
        }

        cout << "После уничтожения ptr3, use_count = " << ptr1.use_count() << endl;
    }

    cout << "После уничтожения ptr2, use_count = " << ptr1.use_count() << endl;
    cout << "Когда последний shared_ptr исчезнет, объект удалится автоматически" << endl;
}

void demoSmartPointers() {
    cout << "\n=== Умные указатели ===" << endl;

    demoUniquePtr();

    cout << "\n------------------------------------------\n" << endl;

    demoSharedPtr();
}

int main() {
    cout << "Lab 5 started" << endl;

    demoSimpleObjects();
    demoBasePointers();
    demoCopyConstructors();
    demoVirtualAndNonVirtual();
    demoDynamicCast();
    demoManualTypeCheck();
    demoCastingComparison();
    demoFunctionLifecycle();
    demoSmartPointers();

    cout << "\nProgram finished" << endl;
    return 0;
}