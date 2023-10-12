#pragma once
class Account
{
public:
	float getBalance();
	float getAccruedInterest();
	bool validateBalance(float validate);
	bool validateInput(float validate);
	float accrueInterest(float balance);
	void withdraw(float withdrawal);
	void deposit(float deposit);
	float lastBalance=0;

	Account(float startingAmount) {
		this->balance += startingAmount;
		this->accruedInterest = 0;
	}

private:
	float balance = 0;
	float accruedInterest;
};

