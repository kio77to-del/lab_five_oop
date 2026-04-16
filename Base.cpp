#include "Base.h"

Base::Base() : name("Base") {
    cout << "Base()" << endl;
}

Base::Base(Base* obj) : name("Base_from_pointer") {
    cout << "Base(Base* obj)" << endl;
}

Base::Base(Base& obj) : name(obj.name) {
    cout << "Base(Base& obj)" << endl;
}

Base::~Base() {
    cout << "~Base()" << endl;
}

void Base::show() const {
    cout << "Base::show()" << endl;
}