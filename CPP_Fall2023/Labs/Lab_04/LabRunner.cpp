#include "LabRunner.h"
#include <string>
#include <iostream>
#include <iomanip>

void LabRunner::setUp() {
    std::cout << std::setprecision(2);
    std::cout << std::fixed;
    std::cout << "Please enter a starting deposit amount...\n";
    std::cin >> this->input;
    this->account = new Account(input);
    std::cout << "New account balance opened with amount $" << this->account->getBalance() << "\n";
    this->firstRun = false;
}

void LabRunner::run()
{
    if (firstRun) {
        setUp();
    }

    do {
        std::cout << "D for deposit, W for withdrawal\n";
        std::cin >> state;

        switch (state) {
        case('D'):
        case('d'):
            strcpy_s(stateDescription, "Deposit");
            obtainData(state);
            printReport();
            break;

        case('w'):
        case('W'):
            strcpy_s(stateDescription, "Withdraw");
            obtainData(state);
            printReport();
            break;

        default:
            strcpy_s(stateDescription, "Invalid input");
            break;
        }

        std::cout << "Press R to make another transaction, or any key to exit\n";
        std::cin >> state;
    } while (stateIsValid(state));
}


void LabRunner::obtainData(char state)
{
    if (state == 'D' || state == 'd') {
        std::cout << "How much would you like to deposit?\n";
        std::cin >> input;
        account->deposit(input);
    }
    else if (state == 'W' || state == 'w') {
        std::cout << "How much would you like to withdraw?\n";
        std::cin >> input;
        account->withdraw(input);
    }
}


void LabRunner::printReport()
{
    std::cout << "############# REPORT #############\n";
    std::cout << "Previous account balance: $" << this->account->lastBalance << "\n";
    std::cout << "Your new balance: $" << this->account->getBalance() << "\n";
    std::cout << "Interest Accrued To Date: $" << this->account->getAccruedInterest() << "\n";
    std::cout << "##################################\n";
}

bool LabRunner::stateIsValid(char state) {
    if (state == 'D' || state == 'd' || state == 'W' || state == 'w' || state == 'r' || state == 'R') {
        return true;
    }
    else {
        return false;
    }
}
