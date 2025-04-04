// main.cpp
#include "Desserts/DessertFactory.h"

int main()
{
    DessertFactory factory;
    factory.createDessert("cake")->serve();
    factory.createDessert("brownie")->serve();
    return 0;
}