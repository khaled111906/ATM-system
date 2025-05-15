#include "customer.h"

Customer::Customer() : Account() {}

Customer::Customer(std::string id, std::string pw, std::string name, double cb, double sb)
    : Account(id, pw, name, cb, sb) {}

bool Customer::authenticate(std::string inputID, std::string inputPW) {
    return id == inputID && password == inputPW;
}
