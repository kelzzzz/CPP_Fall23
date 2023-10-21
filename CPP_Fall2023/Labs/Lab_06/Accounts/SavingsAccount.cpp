#include "SavingsAccount.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>

SavingsAccount::SavingsAccount(float startingAmount) {
    this->balance = 0;
    this->balance += startingAmount;
    strcpy_s(accNum, generateAccountNumber().c_str());
}
std::string SavingsAccount::print() {
    std::string str;
    str.append("Savings Account Object:\n Account Number: #");
    str.append(this->getAccNum());
    str.append("\n");
    str.append("------------------------------------\n");
    str.append("Current Account Balance: $");
    str.append(std::to_string(this->getBalance()));
    str.append("\n");
    return str;
}