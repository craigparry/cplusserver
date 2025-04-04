#ifndef BROWNIE_H
#define BROWNIE_H

#include "Dessert.h"
#include <iostream>

class Brownie : public Dessert
{
public:
    void serve() const override;
    virtual ~Brownie() = default; // Use default destructor
};

#endif // BROWNIE_H
