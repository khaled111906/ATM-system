#ifndef TRANSACTION_H
#define TRANSACTION_H

class Transaction {
public:
    void deposit(double& balance, double amount);
    void withdraw(double& balance, double amount);
    void transfer(double& from, double& to, double amount);
};

#endif // TRANSACTION_H
