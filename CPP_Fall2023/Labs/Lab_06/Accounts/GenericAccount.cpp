#include "GenericAccount.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>

GenericAccount::GenericAccount() {
}
GenericAccount::GenericAccount(float startingAmount) {
    this->balance = 0;
    this->balance += startingAmount;
    strcpy_s(accNum, generateAccountNumber().c_str());
}

void GenericAccount::print()
{
    std::cout << "########################\n";
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Generic Account Object:\n Account Number: #" << getAccNum() << "\n";
    std::cout << "------------------------------------\n";
    std::cout << "Current Account Balance: $" << getBalance() << "\n";
}

const float GenericAccount::getBalance() {
    return this->balance;
}

std::string GenericAccount::getAccNum()
{
    return this->accNum;
}

const bool GenericAccount::validateBalance(float validate)
{
    if (this->balance >= validate) {
        return true;
    }
    else {
        std::cout << "Attempting to withdraw $" << validate << "\n";
        std::cout << "Insufficient funds.\n";
        std::cout << "You will be charged a $0.50 overdraft fee.\n";
        this->balance -= 0.50;
        return true;
    }
}

const bool GenericAccount::validateInput(float validate)
{
    if (validate < 0) {
        std::cout << "Cannot withdraw or deposit negative numbers.\n";
        return false;
    }
    else {
        return true;
    }
}


void GenericAccount::withdraw(float withdrawal)
{
    if (validateBalance(withdrawal) && validateInput(withdrawal)) {
     this->balance -= withdrawal;
     std::cout << "Withdrew $" << withdrawal << "\n";
     std::cout << std::fixed << std::setprecision(2);
     std::cout << "Your new balance: $" << this->balance << "\n";
    }
}


void GenericAccount::deposit(float deposit)
{
    if (validateInput(deposit)) {
    this->balance += deposit;
    std::cout << "Deposited $" << deposit << "\n";
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Your new balance: $" << this->balance << "\n";
    }
}

std::string GenericAccount::generateAccountNumber()
{
    for (int j = 0; j < 1000; j++) {} // wait for a bit so the system doesn't draw the same number twice
    int code[6];
    code[5] = 1;

    for (int i = 0; i < 5; ++i)
        code[i] = rand() % 10;

    std::string result;

    for (int i = 0; i < 5; i++) {
        result += std::to_string(code[i]);
    }

    return result;
}