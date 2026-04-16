#include <iostream>
#include "MethodicalDemos.h"

using namespace std;

void func1(Base obj) {
    cout << "func1(Base obj) started" << endl;
    obj.show();
    cout << "func1(Base obj) finished" << endl;
}

void func2(Base* obj) {
    cout << "func2(Base* obj) started" << endl;
    if (obj != nullptr) {
        obj->show();
    }
    cout << "func2(Base* obj) finished" << endl;
}

void func3(Base& obj) {
    cout << "func3(Base& obj) started" << endl;
    obj.show();
    cout << "func3(Base& obj) finished" << endl;
}

void demoMethodicalTransfer() {
    cout << "\n=== Передача объектов по методичке ===" << endl;

    Base b;
    Desc d;

    cout << "\n--- Передаем Base ---" << endl;
    func1(b);
    func2(&b);
    func3(b);

    cout << "\n--- Передаем Desc ---" << endl;
    func1(d);
    func2(&d);
    func3(d);
}