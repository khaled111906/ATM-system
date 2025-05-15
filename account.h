#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account {
protected:
    std::string id, password, name;
    double checkingBalance, savingsBalance;

public:
    Account();
    Account(std::string _id, std::string _pw, std::string _name, double cb, double sb);
    std::string getID() const;
    std::string getPassword() const;
    std::string getName() const;
    void setPassword(std::string newPass);
    double& getCheckingBalance();
    double& getSavingsBalance();
};

#endif // ACCOUNT_H
