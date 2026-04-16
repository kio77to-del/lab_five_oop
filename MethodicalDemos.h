#ifndef METHODICALDEMOS_H
#define METHODICALDEMOS_H

#include "Base.h"
#include <memory>

void func1(Base obj);
void func2(Base* obj);
void func3(Base& obj);

Base returnFunc1();
Base* returnFunc2();
Base& returnFunc3();

Base returnFunc4();
Base* returnFunc5();
Base& returnFunc6();

void demoPassingObjects();
void demoReturningObjects();
void demoSmartPointersMethodical();

#endif