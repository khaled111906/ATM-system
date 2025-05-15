#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "account.h"
#include "transaction.h"

class Customer : public Account, public Transaction {
public:
    Customer();
    Customer(std::string id, std::string pw, std::string name, double cb, double sb);
    bool authenticate(std::string inputID, std::string inputPW);
};

#endif // CUSTOMER_H
