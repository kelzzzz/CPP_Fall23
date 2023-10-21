#pragma once
#include <string>
class GenericAccount
{
public:
	//constructors
	GenericAccount();
	GenericAccount(float startingAmount);

	//virtual
	virtual std::string print();

	//methods - get
	const float getBalance();
	std::string getAccNum();

	//methods
	const bool validateBalance(float validate);
	const bool validateInput(float validate);
	virtual void withdraw(float withdrawal);
	void deposit(float deposit);
	std::string generateAccountNumber();

	//member vars
protected:
	float balance=0;
	char accNum[6];
};

