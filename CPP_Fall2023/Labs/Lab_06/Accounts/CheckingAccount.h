#include "GenericAccount.h"
class CheckingAccount : public GenericAccount {
public:
	CheckingAccount(float startingBalance);
	void print();
	void withdraw(float withdrawal);
private:
};