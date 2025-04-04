#ifndef CAKE_H
#define CAKE_H

#include "Dessert.h"
#include <iostream>

class Cake : public Dessert
{
public:
    void serve() const override;
    virtual ~Cake() = default; // Use default destructor
};

#endif // CAKE_H
