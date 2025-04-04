#ifndef DESSERT_H
#define DESSERT_H

#include <iostream>

class Dessert
{
public:
    virtual void serve() const = 0;
    virtual ~Dessert() = default; // Use default destructor
};

#endif // DESSERT_H
