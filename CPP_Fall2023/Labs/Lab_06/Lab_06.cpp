

#include <iostream>
#include "GenericAccount.h"
#include <SavingsAccount.h>
#include <CheckingAccount.h>
#include <time.h>
#include <iostream>
#include <fstream>  


bool fileExists(std::string filename) {
    std::ifstream infile(filename);
    return infile.good();
}

void handleFile(std::string output, std::string transaction, bool isdep) {
    if (!fileExists("accounts.dat")) {
        std::ofstream outfile("accounts.dat");
    }
    std::time_t timestamp = std::time(nullptr);
    std::ofstream out;
    out.open("accounts.dat", std::ios::app);
    out << "Activity on " << timestamp << "\n";
    out << output;
    if (isdep) {
        out << "Attempted Deposit of $" << transaction << "\n";
    }
    else {
        out << "Attempted Withdraw of $" << transaction << "\n";
    }
    out << "--------------------" << "\n";
}

int main()
{
    srand(time(NULL));
    CheckingAccount ca = CheckingAccount(1000.00);    
    SavingsAccount sa = SavingsAccount(11054.00);
    GenericAccount** accounts = new GenericAccount*[2];
    accounts[0] = &ca;
    accounts[1] = &sa;

    for (int i = 0; i < 2; i++) {
        accounts[i]->print();
        accounts[i]->deposit(46.75);
        handleFile(accounts[i]->print(), "46.75", true);
        accounts[i]->withdraw(100);
        handleFile(accounts[i]->print(), "100.00", false);
        accounts[i]->withdraw(1000);
        handleFile(accounts[i]->print(), "1000.00", false);
    }
}

