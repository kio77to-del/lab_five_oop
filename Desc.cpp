#include "Desc.h"

Desc::Desc() : Base() {
    name = "Desc";
    cout << "Desc()" << endl;
}

Desc::Desc(Desc* obj) : Base(obj) {
    name = "Desc_from_pointer";
    cout << "Desc(Desc* obj)" << endl;
}

Desc::Desc(Desc& obj) : Base(obj) {
    name = obj.name;
    cout << "Desc(Desc& obj)" << endl;
}

Desc::~Desc() {
    cout << "~Desc()" << endl;
}

void Desc::show() const {
    cout << "Desc::show()" << endl;
}

void Desc::onlyDescMethod() const {
    cout << "Desc::onlyDescMethod()" << endl;
}