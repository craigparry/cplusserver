#include "DessertFactory.h"

Dessert *DessertFactory::createDessert(const std::string &type)
{
    if (type == "cake")
    {
        return new Cake(); // Create a new Cake object
    }
    else if (type == "brownie")
    {
        return new Brownie(); // Create a new Brownie object
    }
    else
    {
        return nullptr; // If an unknown type is provided, return nullptr
    }
}
