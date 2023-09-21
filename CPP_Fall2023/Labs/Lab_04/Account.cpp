#include "Account.h"
#include <iostream>

float Account::getBalance() {
    return balance;
}
bool Account::validateBalance(float validate)
{
    if (this->balance >= validate) {
        return true;
    }
    else {
        std::cout << "Insufficient funds.\n";
        return false;
    }
}

bool Account::validateInput(float validate)
{
    if (validate < 0) {
        std::cout << "Cannot withdraw or deposit negative numbers.\n";
        return false;
    }
    else {
        return true;
    }
}


void Account::withdraw(float withdrawl)
{
    if (validateBalance(withdrawl) && validateInput(withdrawl)) {
     this->lastBalance = 0;
     this->lastBalance += this->balance;
     this->balance -= withdrawl;
    }
}


void Account::deposit(float deposit)
{
    if (validateInput(deposit)) {
    this->lastBalance = 0;
    this->lastBalance += this->balance;
    this->balance += deposit;
    }
}

