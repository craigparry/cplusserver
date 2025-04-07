#include "DessertFactory.h"

std::unique_ptr<Dessert> DessertFactory::createDessert(const std::string &type)
{
    if (type == "cake")
    {
        return std::unique_ptr<Cake>(); // Create a new Cake object
    }
    else if (type == "brownie")
    {
        return std::unique_ptr<Brownie>(); // Create a new Brownie object
    }
    else
    {
        return nullptr; // If an unknown type is provided, return nullptr
    }
}
