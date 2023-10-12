#include "SalariedEmployee.h"
#include <iostream>

SalariedEmployee::SalariedEmployee(std::string name)
{
	this->empName = name;
	this->empID = generateEmpId();
	std::cout << "SalariedEmployee object constructed.\n";
}

void SalariedEmployee::Display()
{
	std::cout << "Name: " << this->empName << "\n";
	std::cout << "ID: " << this->empID << "\n";
	applyBonus();
	std::cout << "Annual Salary: $" << this->annualSalary + bonus << "\n";
	std::cout << "Gross pay: $" << this->getGrossPay() << "\n";
	std::cout << "Annual Bonus: $" << this->bonus;

}

float SalariedEmployee::getGrossPay()
{
	return this->annualSalary/26;
}

float SalariedEmployee::getAnnualSalary()
{
	return this->annualSalary;
}

void SalariedEmployee::setAnnualSalary(float annual)
{
	this->annualSalary = annual;
}
void SalariedEmployee::applyBonus() {
	this->bonus = annualSalary * .005;
}
