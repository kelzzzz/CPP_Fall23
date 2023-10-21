#include "GenericAccount.h"
class CheckingAccount : public GenericAccount {
public:
	CheckingAccount(float startingBalance);
	std::string print();
	void withdraw(float withdrawal);
private:
};