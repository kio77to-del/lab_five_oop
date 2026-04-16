#ifndef DESC_H
#define DESC_H

#include "Base.h"

class Desc : public Base {
public:
    Desc();
    Desc(Desc* obj);
    Desc(Desc& obj);
    ~Desc() override;

    void show() const override;
    void onlyDescMethod() const;
};

#endif