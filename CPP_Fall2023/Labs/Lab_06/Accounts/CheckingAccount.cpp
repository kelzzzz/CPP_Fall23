#include "CheckingAccount.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>

CheckingAccount::CheckingAccount(float startingAmount) {
    this->balance = 0;
    this->balance += startingAmount;
    strcpy_s(accNum, generateAccountNumber().c_str());
}

void CheckingAccount::print() {
    std::cout << "########################\n";
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Checking Account Object:\n Account Number: #" << this->getAccNum() << "\n";
    std::cout << "------------------------------------\n";
    std::cout << "Current Account Balance: $" << this->getBalance() << "\n";
}

void CheckingAccount::withdraw(float withdrawal)
{
    if (validateBalance(withdrawal) && validateInput(withdrawal)) {
        this->balance -= withdrawal;
        std::cout << std::fixed << std::setprecision(2);
        if (this->balance < 1000) {
            std::cout << "Checking balance has fallen below minimum.\n";
            std::cout << "You have been charged a $0.50 fee.\n";
            this->balance -= 0.50;
        }
        std::cout << "Withdrew $" << withdrawal << "\n";
        std::cout << "Your new balance: $" << this->balance << "\n";
    }
}