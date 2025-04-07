#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <memory>             // for std::unique_ptr
#include "Desserts/Dessert.h" // forward or full include if needed

class Transaction
{
public:
    Transaction(int amount, std::unique_ptr<Dessert> type);
    void details();
    virtual ~Transaction() = default;
    static int orders;

private:
    int amount_;
    std::unique_ptr<Dessert> type;
    int uid;
};

#endif // TRANSACTION_H