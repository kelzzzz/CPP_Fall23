#include "GenericAccount.h"
class SavingsAccount : public GenericAccount {
public:
	SavingsAccount(float startingBalance);
	std::string print();
private:
};