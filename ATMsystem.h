#ifndef ATMSYSTEM_H
#define ATMSYSTEM_H

#include "customer.h"
#include "admin.h"
#include <vector>

class ATM {
private:
    std::vector<Customer> customers;
    Admin admin;
    Customer* currentCustomer = nullptr;

public:
    ATM();
    bool loginAdmin(const std::string& id, const std::string& pw);
    bool loginCustomer(const std::string& id, const std::string& pw);
    void addCustomer(const Customer& customer);
    void removeCustomer(const std::string& id);
    Customer* getCurrentCustomer();
};

#endif // ATMSYSTEM_H
