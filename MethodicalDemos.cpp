#include <iostream>
#include <memory>
#include "MethodicalDemos.h"
#include "Desc.h"

using namespace std;

void func1(Base obj) {
    cout << "\nfunc1(Base obj) start" << endl;
    obj.show();
    cout << "func1(Base obj) end" << endl;
}

void func2(Base* obj) {
    cout << "\nfunc2(Base* obj) start" << endl;
    if (obj != nullptr) {
        obj->show();
    }
    cout << "func2(Base* obj) end" << endl;
}

void func3(Base& obj) {
    cout << "\nfunc3(Base& obj) start" << endl;
    obj.show();
    cout << "func3(Base& obj) end" << endl;
}

Base returnFunc1() {
    cout << "\nreturnFunc1() start" << endl;
    static Base obj;
    cout << "returnFunc1() returns Base by value" << endl;
    return obj;
}

Base* returnFunc2() {
    cout << "\nreturnFunc2() start" << endl;
    static Base obj;
    cout << "returnFunc2() returns Base* to static object" << endl;
    return &obj;
}

Base& returnFunc3() {
    cout << "\nreturnFunc3() start" << endl;
    static Base obj;
    cout << "returnFunc3() returns Base& to static object" << endl;
    return obj;
}

Base returnFunc4() {
    cout << "\nreturnFunc4() start" << endl;
    Base* obj = new Base();
    cout << "returnFunc4() created dynamic Base and returns object by value" << endl;
    Base temp = *obj;
    delete obj;
    return temp;
}

Base* returnFunc5() {
    cout << "\nreturnFunc5() start" << endl;
    Base* obj = new Base();
    cout << "returnFunc5() returns Base* to dynamic object" << endl;
    return obj;
}

Base& returnFunc6() {
    cout << "\nreturnFunc6() start" << endl;
    Base* obj = new Base();
    cout << "returnFunc6() returns Base& to dynamic object" << endl;
    return *obj;
}

void demoPassingObjects() {
    cout << "\n==============================" << endl;
    cout << "Передача объектов в функции" << endl;
    cout << "==============================" << endl;

    cout << "\n--- Base object ---" << endl;
    Base b;
    func1(b);
    func2(&b);
    func3(b);

    cout << "\n--- Desc object ---" << endl;
    Desc d;
    func1(d);
    func2(&d);
    func3(d);
}

void demoReturningObjects() {
    cout << "\n==============================" << endl;
    cout << "Возврат объектов из функций" << endl;
    cout << "==============================" << endl;

    cout << "\n--- returnFunc1 ---" << endl;
    Base b1 = returnFunc1();
    b1.show();

    cout << "\n--- returnFunc2 ---" << endl;
    Base* b2 = returnFunc2();
    b2->show();

    cout << "\n--- returnFunc3 ---" << endl;
    Base& b3 = returnFunc3();
    b3.show();

    cout << "\n--- returnFunc4 ---" << endl;
    Base b4 = returnFunc4();
    b4.show();

    cout << "\n--- returnFunc5 ---" << endl;
    Base* b5 = returnFunc5();
    b5->show();
    delete b5;

    cout << "\n--- returnFunc6 ---" << endl;
    Base& b6 = returnFunc6();
    b6.show();
    delete &b6;
}

void takeUniquePtr(unique_ptr<Base> obj) {
    cout << "\ntakeUniquePtr() start" << endl;
    if (obj) {
        obj->show();
    }
    cout << "takeUniquePtr() end" << endl;
}

shared_ptr<Base> makeSharedBase() {
    cout << "\nmakeSharedBase() start" << endl;
    shared_ptr<Base> ptr = make_shared<Desc>();
    cout << "makeSharedBase(): use_count = " << ptr.use_count() << endl;
    return ptr;
}

void demoSmartPointersMethodical() {
    cout << "\n==============================" << endl;
    cout << "Умные указатели по методичке" << endl;
    cout << "==============================" << endl;

    cout << "\n--- unique_ptr ---" << endl;
    unique_ptr<Base> uptr = make_unique<Desc>();
    uptr->show();

    takeUniquePtr(move(uptr));

    if (uptr == nullptr) {
        cout << "uptr is nullptr after move" << endl;
    }

    cout << "\n--- shared_ptr ---" << endl;
    shared_ptr<Base> sptr1 = makeSharedBase();
    cout << "sptr1 use_count = " << sptr1.use_count() << endl;

    {
        shared_ptr<Base> sptr2 = sptr1;
        cout << "after copy, sptr1 use_count = " << sptr1.use_count() << endl;
        sptr2->show();
    }

    cout << "after inner scope, sptr1 use_count = " << sptr1.use_count() << endl;
}