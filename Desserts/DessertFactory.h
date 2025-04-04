#ifndef DESSERTFACTORY_H
#define DESSERTFACTORY_H

#include "Dessert.h"
#include "Cake.h"    // Assuming Cake is a separate file
#include "Brownie.h" // Assuming Brownie is a separate file

class DessertFactory
{
public:
    static Dessert *createDessert(const std::string &type);
    virtual ~DessertFactory() = default; // Use default destructor
};

#endif // DESSERTFACTORY_H
