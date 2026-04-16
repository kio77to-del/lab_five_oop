#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <string>

using namespace std;

class Base {
protected:
    string name;

public:
    Base();
    Base(Base* obj);
    Base(Base& obj);
    virtual ~Base();

    virtual void show() const;
};

#endif