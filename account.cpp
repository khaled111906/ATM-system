#include "account.h"

Account::Account() : checkingBalance(0.0), savingsBalance(0.0) {}

Account::Account(std::string _id, std::string _pw, std::string _name, double cb, double sb)
    : id(_id), password(_pw), name(_name), checkingBalance(cb), savingsBalance(sb) {}

std::string Account::getID() const { return id; }
std::string Account::getPassword() const { return password; }
std::string Account::getName() const { return name; }
void Account::setPassword(std::string newPass) { password = newPass; }
double& Account::getCheckingBalance() { return checkingBalance; }
double& Account::getSavingsBalance() { return savingsBalance; }
