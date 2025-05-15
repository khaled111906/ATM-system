#include "ATMsystem.h"

ATM::ATM() {
    customers.push_back(Customer("CUST01", "cu123", "Ali Ahmed", 1000.0, 500.0));
}

bool ATM::loginAdmin(const std::string& id, const std::string& pw) {
    return admin.authenticate(id, pw);
}

bool ATM::loginCustomer(const std::string& id, const std::string& pw) {
    for (auto& customer : customers) {
        if (customer.authenticate(id, pw)) {
            currentCustomer = &customer;
            return true;
        }
    }
    return false;
}

void ATM::addCustomer(const Customer& customer) {
    customers.push_back(customer);
}

void ATM::removeCustomer(const std::string& id) {
    for (auto it = customers.begin(); it != customers.end(); ++it) {
        if (it->getID() == id) {
            customers.erase(it);
            return;
        }
    }
}

Customer* ATM::getCurrentCustomer() {
    return currentCustomer;
}
