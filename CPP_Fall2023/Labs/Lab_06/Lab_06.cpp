

#include <iostream>
#include "GenericAccount.h"
#include <SavingsAccount.h>
#include <CheckingAccount.h>
#include <time.h>

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
        accounts[i]->withdraw(100);
        accounts[i]->withdraw(1000);
        accounts[i]->print();
    }
}
