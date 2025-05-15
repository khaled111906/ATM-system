#include "transaction.h"

void Transaction::deposit(double& balance, double amount) {
    if (amount > 0) {
        balance += amount;
    }
}

void Transaction::withdraw(double& balance, double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
    }
}

void Transaction::transfer(double& from, double& to, double amount) {
    if (amount > 0 && amount <= from) {
        from -= amount;
        to += amount;
    }
}
