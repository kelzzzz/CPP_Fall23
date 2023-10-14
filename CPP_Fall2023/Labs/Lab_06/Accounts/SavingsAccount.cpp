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
void SavingsAccount::print() {
    std::cout << "########################\n";
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Savings Account Object:\n Account Number: #" << this->getAccNum() << "\n";
    std::cout << "------------------------------------\n";
    std::cout << "Current Account Balance: $" << this->getBalance() << "\n";

}