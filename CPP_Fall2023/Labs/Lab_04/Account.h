#pragma once
class Account
{
public:
	float getBalance();
	bool validateBalance(float validate);
	bool validateInput(float validate);
	void withdraw(float withdrawl);
	void deposit(float deposit);
	float lastBalance=0;

	Account(float startingAmount) {
		this->balance += startingAmount;
	}

private:
	float balance = 0;
};

