// Transaction.cpp
#include "Transaction.h"
#include "Desserts/Dessert.h"
#include <memory> // for std::unique_ptr

int Transaction::orders = 0; // Also need to define the static member

Transaction::Transaction(int amount, std::unique_ptr<Dessert> type)
{
    this->amount_ = amount;
    this->type = std::move(type);

    uid = ++orders;
}

void Transaction::details()
{
    std::cout << "Transaction ID: " << uid << std::endl;
    std::cout << "Amount: " << amount_ << std::endl;
    if (type)
    {
        type->serve();
    }
    else
    {
        std::cout << "No dessert type available." << std::endl;
    }
}
